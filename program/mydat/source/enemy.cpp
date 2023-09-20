#include "../include/GV.h"

extern void enemy_pattern0(int);extern void enemy_pattern1(int);extern void enemy_pattern2(int);
extern void enemy_pattern3(int);extern void enemy_pattern4(int);extern void enemy_pattern5(int);
extern void enemy_pattern6(int);extern void enemy_pattern7(int);extern void enemy_pattern8(int);
extern void enemy_pattern9(int);extern void enemy_pattern10(int);


//−−−−−−−−−−−−−−−−−−−−−/
// 敵の行動パターンを分ける
//−−−−−−−−−−−−−−−−−−−−−/
void (*enemy_pattern[ENEMY_PATTERN_MAX])(int) = {
    enemy_pattern0,    enemy_pattern1,    enemy_pattern2,    enemy_pattern3,    enemy_pattern4,
    enemy_pattern5,    enemy_pattern6,    enemy_pattern7,    enemy_pattern8,    enemy_pattern9,
    enemy_pattern10,
};


//−−−−−−−−−−−−−−−−−−−−−/
//空いている敵番号を検索
//−−−−−−−−−−−−−−−−−−−−−/
int enemy_num_search(){

    //フラグのたって無いenemyを探す
    for(int i=0;i<ENEMY_MAX;i++){
        if(enemy[i].flag==0){
            return i;//使用可能番号を返す
        }
    }

    //全部埋まっていたらエラーを返す
    return -1;
}


//−−−−−−−−−−−−−−−−−−−−−/
//敵の行動を登録・制御
//−−−−−−−−−−−−−−−−−−−−−/
void enemy_enter(){
    int i,j,t;

    //ボス戦中は出現させない
    if (boss.flag != 0) {
        return;
    }

    //敵の出現最大数までやる
    for(t=0;t<ENEMY_ORDER_MAX;t++){

        //現在の瞬間がオーダーの瞬間なら
        if(enemy_order[t].cnt==stage_count){
            if((i=enemy_num_search())!=-1){//敵に空きがあれば

                //−−−−−−−−−−/
                // 登録
                //−−−−−−−−−−/

                enemy[i].flag    = 1;//フラグ
                enemy[i].cnt     = 0;//カウンタ
                enemy[i].pattern = enemy_order[t].pattern;  //移動パターン
                enemy[i].muki    = 1;                       //向き
                enemy[i].knd     = enemy_order[t].knd;      //敵の種類
                enemy[i].x       = enemy_order[t].x;        //座標
                enemy[i].y       = enemy_order[t].y;        //座標
                enemy[i].sp      = enemy_order[t].sp;       //スピード
                enemy[i].bltime  = enemy_order[t].bltime;   //弾の発射時間
                enemy[i].blknd   = enemy_order[t].blknd;    //攻撃パターン
                enemy[i].blknd1  = enemy_order[t].blknd1;   //使用弾幕
                enemy[i].col     = enemy_order[t].col;      //色
                enemy[i].wait    = enemy_order[t].wait;     //色
                enemy[i].hp      = enemy_order[t].hp;       //体力
                enemy[i].hp_max  = enemy[i].hp;             //体力最大値
                enemy[i].back_col= GetRand(4);
                enemy[i].vx      = 0;//水平成分の速度
                enemy[i].vy      = 0;//鉛直成分の速度
                enemy[i].ang     = 0;//角度


                //落とすアイテム
                for(j=0;j<6;j++){
                    enemy[i].item_n[j]=enemy_order[t].item_n[j];
                }
            }
        }
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
// 敵の弾幕登録処理
//−−−−−−−−−−−−−−−−−−−−−/
void enter_shot(int i){
	int j;

    //フラグのたって無いenemyを探す
	for(j=0;j<SHOT_MAX;j++){

        //未使用の弾幕データがあれば
		if(shot[j].flag==0){

            //初期化して登録
			memset(&shot[j],0,sizeof(shot_t));//メモリ確保
			shot[j].flag=1;                   //フラグをたてる
			shot[j].knd=enemy[i].blknd;       //攻撃パターン登録
            shot[j].knd1 = enemy[i].blknd1;   //使用弾幕登録
			shot[j].num=i;                    //num=どの敵から発射されたものか。
			shot[j].cnt=0;                    //弾幕制御を初期化

			return;
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
//敵の行動制御
//−−−−−−−−−−−−−−−−−−−−−/
void enemy_act(){
    int i;

    //敵の最大出現数まで実行
    for(i=0;i<ENEMY_MAX;i++){

        //その敵のフラグがオンになってたら
        if(enemy[i].flag==1){
            if(0<=enemy[i].pattern && enemy[i].pattern<ENEMY_PATTERN_MAX){//エラーがないかチェック
                //行動パターンを渡す
                enemy_pattern[enemy[i].pattern](i);

                //座標移動
                enemy[i].x+=cos(enemy[i].ang)*enemy[i].sp;
                enemy[i].y+=sin(enemy[i].ang)*enemy[i].sp;
                enemy[i].x+=enemy[i].vx;
                enemy[i].y+=enemy[i].vy;

                //制御用カウント
                enemy[i].cnt++;

                //敵のアニメーション
                enemy[i].img=enemy[i].muki*3+(enemy[i].cnt%18)/6;

                //敵が画面外に外れたら消す
                if(enemy[i].x<-20 || FMX+20<enemy[i].x || enemy[i].y<-20 || FMY+20<enemy[i].y){
                    enemy[i].flag=0;
                }

                //弾幕開始時間になったら弾幕発射
				if(enemy[i].bltime==enemy[i].cnt){
					enter_shot(i);
                }
			}
            else
                printfDx("enemy[i].patternの%d値が不正です。",enemy[i].pattern);
        }
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
//敵処理メイン
//−−−−−−−−−−−−−−−−−−−−−/
void enemy_main(){
    enemy_enter();  //敵情報を登録
    enemy_act();    //敵行動を制御
}