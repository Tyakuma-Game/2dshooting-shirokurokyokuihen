#include "../include/GV.h"

//−−−−−−−−−−−−−−−−−−−−−/
// 章名表示処理
//−−−−−−−−−−−−−−−−−−−−−/
void calc_stage_title(){

	//今が表示開始時なら
	if(stage_title.appear_cnt==stage_count){
		stage_title.flag=1;//フラグを表示するに変更

		//対応した画像を読み込む
		stage_title.img = LoadGraph("../dat/img/board/subject1.png");
	}

	//フラグが立ってないならここで終了
	if (stage_title.flag == 0) {
		return;//処理終了
	}

	//最初の128の間段々明るく
	if (stage_title.cnt < 128) {
		stage_title.brt += 2;
	}
	
	//段々暗く
	if(stage_title.cnt>128+128){
		stage_title.brt-=2;
	}

	//終り
	if(stage_title.cnt>128+128+128){
		stage_title.cnt=0;	//経過時間を０に
		stage_title.brt=0;	//明るさ調整値を０に
		stage_title.flag=0;	//フラグを立ってない状態に
		DeleteGraph(stage_title.img);//画像解放

		return;//処理終了
	}

	stage_title.cnt++;
}


//−−−−−−−−−−−−−−−−−−−−−/
//アイテムの吸収処理
//−−−−−−−−−−−−−−−−−−−−−/
void calc_item_indraw(int i){
	double v = item[i].state ? 8 : 3;					//state1ならスピード8、違うなら2
	double angle=atan2(ch.y-item[i].y,ch.x-item[i].x);	//自機への角度を計算して
	item[i].x += cos(angle)*v;
	item[i].y += sin(angle)*v;
}


//−−−−−−−−−−−−−−−−−−−−−/
//アイテム移動など計算
//−−−−−−−−−−−−−−−−−−−−−/
void calc_item(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].flag>0){
			if(item[i].state==0){
				//吸収状態なら
				if(ch.y<ITEM_GET_BORDER_LINE){
					item[i].state=1;
				}
			}

			//普通の状態なら
			if(item[i].state==0){
				double x=ch.x-item[i].x,y=ch.y-item[i].y;

				//低速状態で自機付近なら
				if(CheckStatePad(configpad.slow)>0 &&
						x*x+y*y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE){
					calc_item_indraw(i);//吸収
				}
				else{
					if(item[i].v<2.5){//速度アップ
						item[i].v+=0.06;
					}
					item[i].y+=item[i].v;//移動
				}
			}
			else{//吸収状態なら
				calc_item_indraw(i);
			}

			item[i].cnt++;

			if(item[i].y>FMY+50){
				item[i].flag=0;
			}
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
//フラッシュ(42)
//−−−−−−−−−−−−−−−−−−−−−/
void calc_flash(){
	if(flash.flag>0){
		if(flash.knd==0){

			if (flash.cnt == 0) {
				flash.brt = 0;
			}

			if(flash.cnt<flash.to_cnt){
				flash.brt+=255.0/flash.to_cnt;
			}
			else{
				flash.brt-=255.0/flash.to_cnt;
			}
		}
		if(flash.knd==1){
			if (flash.cnt == 0) {
				flash.brt = 255;
			}
			flash.brt-=255.0/flash.to_cnt;
		}

		flash.cnt++;

		if(flash.knd==0){
			if(flash.cnt>flash.to_cnt*2){
				flash.flag=0;
			}
		}
		if(flash.knd==1){
			if(flash.cnt>flash.to_cnt){
				flash.flag=0;
			}
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// ゲーム中の処理
//−−−−−−−−−−−−−−−−−−−−−/
void calc_game_ply() {
	//関数制御用変数
	if (boss.flag == 0) {
		stage_count++;
	}

	//リザルト画面を表示するか判定
	if (stage_count > 2900) {
		func_state = result;//場面をリザルト画面に変更
	}

	//ゲームオーバー判定
	if (game_mode == 0 && ch.life == 0) {//残機モード＆残機が０になった
		func_state = game_over;//場面をゲームオーバーに
	}

	count++;
}


//−−−−−−−−−−−−−−−−−−−−−/
// リザルト画面の処理
//−−−−−−−−−−−−−−−−−−−−−/
void calc_result() {

	//初回なら
	if (result_flg == 0) {
		
		//時間
		end = clock();											//計測終了
		elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;	//経過時間計算

		//モード設定
		mode_tmp ^= 1;					//モード反転
		if (mode_tmp == 1)mode_tmp++;	//残機モードでプレイしていたなら

		//ボーナス倍率を計算
		bonus = mode_tmp + level_tmp + 3 - ch.retry;
		if (bonus < 1)bonus = 1;//ボーナス最小補正

		//合計点数計算
		sum_score = ch.score_max + ch.power * POWER_BONUS_SCORE + ch.kill_count * KILL_BONUS_SCORE +
			ch.money * MONEY_BONUS_SCORE + ch.graze * GRAZE_BONUS_SCORE + ch.point * POINT_BONUS_SCORE;

		//ボーナス計算と上限修正
		final_score = sum_score * bonus;
		if (final_score > SCORE_MAX) final_score = SCORE_MAX;

		//ランク付け
		if (final_score <= RANKING_BORDER_BRONZE) {
			result_rank = bronze;
		}
		else if (final_score <= RANKING_BORDER_SILVER) {
			result_rank = silver;
		}
		else if (final_score <= RANKING_BORDER_GOLD) {
			result_rank = gold;
		}
		else if (final_score <= RANKING_BORDER_PLATINUM) {
			result_rank = platinum;
		}
		else {
			result_rank = diamond;
		}

		//フラグを実行済みに変える
		result_flg = 1;
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// 一元管理
//−−−−−−−−−−−−−−−−−−−−−/
void calc_main(){
	calc_stage_title();	//章名を表示する
	calc_item();		//アイテム計算
	calc_flash();		//フラッシュ(42)
}