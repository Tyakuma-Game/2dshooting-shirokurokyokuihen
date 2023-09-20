#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define BRANGE 40.0//ボスの当たり判定

#define ABSORPTION_SCORE 200   //弾幕吸収のスコア追加値
#define ABSORPTION_POWER 1     //弾幕吸収のパワー追加値

#define DECREASE_LIFE 1         //被弾時減少　残機
#define DECREASE_SCORE 10000    //被弾時減少　スコア
#define DECREASE_POWER 200      //被弾時減少　パワー

#define EMY_HIT_SCORE 20       //敵に攻撃あてた　増加スコア
#define BOSS_HIT_SCORE 100     //ボスに攻撃あてた　増加スコア


extern int out_lazer();


//ーーーーーーーーーーーーーーーーーーーー/
//敵の当たり判定範囲
//ーーーーーーーーーーーーーーーーーーーー/
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};


//ーーーーーーーーーーーーーーーーーーーー/
//自機ショットの当たり判定範囲
//ーーーーーーーーーーーーーーーーーーーー/
int cshot_range[CSHOT_RANGE_MAX]={6,};


//ーーーーーーーーーーーーーーーーーーーー/
//当たり判定
//ショットの座標:1  当たりを判定する物体:2
//ーーーーーーーーーーーーーーーーーーーー/
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;

    //敵と自機ショットとの距離
    double x=x1-x2;
    double y=y1-y2;

    //敵の当たり判定と自機ショットの当たり判定の範囲
    double r=range1+range2;

    //中間を計算する必要があれば
    if(spd1>r){
        //１フレーム前にいた位置を格納する
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;

        //進んだ分÷当たり判定分ループ
        for(j=0;j<spd1/r;j++){
            px=pre_x-x2;
            py=pre_y-y2;

            //当たり判定内なら
            if(px*px+py*py<r*r){
                return 1;//当たり
            }

            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }

    //当たり判定内なら
    if(x*x+y*y<r*r){
        return 1;//当たり
    }

    return 0;//外れ
}


//ーーーーーーーーーーーーーーーーーーーー/
//敵と自機ショットが当たったかどうかを判定する
//ーーーーーーーーーーーーーーーーーーーー/
int out_judge_cshot(int i,int s){

    //ショットの軌道が１度でも計算されていたら
    if(cshot[i].cnt>0){
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;//当たった
        }
    }

    return 0;//当たらなかった
}


//ーーーーーーーーーーーーーーーーーーーー/
//ボスと自機ショットが当たったかを判定
//ーーーーーーーーーーーーーーーーーーーー/
int out_judge_cshot_boss(int i){
    //ショットの軌道が１度でも計算されていたら
    if(cshot[i].cnt>0){
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;//当たった
        }
    }

    return 0;//当たらなかった
}


//ーーーーーーーーーーーーーーーーーーーー/
//自機と敵ショットが当たったかを判定
//ーーーーーーーーーーーーーーーーーーーー/
int out_judge_enemyshot(int s,int n,double size){
    //ショットの軌道が１度でも計算されていたら
    if(shot[s].bullet[n].cnt>0){
        if(out_judge(
            shot[s].bullet[n].x,shot[s].bullet[n].y,ch.x,ch.y,
            bullet_info[shot[s].bullet[n].knd].range, size,
            shot[s].bullet[n].spd,shot[s].bullet[n].angle
            )){
                return 1;//当たった
        }
    }

    return 0;//当たらなかった
}


//ーーーーーーーーーーーーーーーーーーーー/
//自機とボスショットが当たったか判定
//ーーーーーーーーーーーーーーーーーーーー/
int out_judge_bossshot(int n,double siza){
    //ショットの軌道が１度でも計算されていたら
    if(boss_shot.bullet[n].cnt>0){
        if(out_judge(
            boss_shot.bullet[n].x,boss_shot.bullet[n].y,ch.x,ch.y,
            bullet_info[boss_shot.bullet[n].knd].range,siza,
            boss_shot.bullet[n].spd,boss_shot.bullet[n].angle
            )){
                return 1;//当たった
        }
    }

    return 0;//当たらなかった
}


//－－－－－－－－－－－－－－－－－－－－－/
// アイテムの空き番号を返す
//－－－－－－－－－－－－－－－－－－－－－/
int serch_item(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].flag==0){//空きがあったら
			return i;       //その番号を返す
        }
    }
	return -1;//空きが無かった
}

//－－－－－－－－－－－－－－－－－－－－－/
//アイテム登録
//アイテム　0:小パワー 1:小点 2:弾点 3:小金 4:大パワー 5:大金
//－－－－－－－－－－－－－－－－－－－－－/
void enter_item(double x, double y, int item_n[], int num){//x,y,アイテムの種類,個数
	int k;
	double r[6]={0.6,0.6,1.0,0.6,1.0,1.0};//dat/img/itemの画像の拡大率

    //1つの敵から出るアイテムの最大数は6個
	for(int i=0;i<num;i++){
		if(item_n[i]!=-1){//エクセルで指定したアイテムが-1(なし)なら終り

            //登録出来る番号をさがす
			if((k=serch_item())!=-1){

                //登録する
				item[k].flag=1;
				item[k].v    =-3.5;	//速さ
				item[k].cnt  =0;
				item[k].state=0;
				item[k].x    =x;
				item[k].y    =y;

                //複数なら適当にちらばらせる
				if(i>0){
					item[k].x+=rang(40);
					item[k].y+=rang(40);
				}

                //指定したアイテムを出現させる
				item[k].knd =item_n[i];
				item[k].r   =r[item[k].knd];
			}
		}
	}
}

//－－－－－－－－－－－－－－－－－－－－－/
//敵から出るアイテム
//－－－－－－－－－－－－－－－－－－－－－/
void enter_enemy_item(int s){
	enter_item(enemy[s].x,enemy[s].y,enemy[s].item_n, sizeof(enemy[s].item_n)/sizeof(int));//x,y,アイテムの種類,個数
}

//－－－－－－－－－－－－－－－－－－－－－/
//プレイヤーから出るアイテム
//－－－－－－－－－－－－－－－－－－－－－/
void enter_char_item(){
	int item_n[4]={4,4,4,4};
	enter_item(ch.x, ch.y, item_n, 4);//x,y,アイテムの種類,個数
}

extern void enter_del_effect(int);


//－－－－－－－－－－－－－－－－－－－－－/
//敵が死ぬかどうかの決定
//－－－－－－－－－－－－－－－－－－－－－/
void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//敵に当たった音

    //敵のHPが０未満になったら
    if(enemy[s].hp<0){
        ch.kill_count++;    //敵の討伐数カウント
        enemy[s].flag=0;    //敵を消滅させる
        se_flag[1]=1;       //敵のピチュリ音

        enter_del_effect(s);//敵の消滅エフェクトを出す
		enter_enemy_item(s);//敵のアイテムを出現させる(39章)
        
        //敵総数分
        for(i=0;i<SHOT_MAX;i++){
            if(shot[i].flag!=0){    //登録されている弾幕データがあれば
                if(s==shot[i].num){ //その敵が登録した弾幕があれば
                    shot[i].flag=2; //それ以上弾幕を続けないフラグを立てる
                    break;
                }
            }
        }
    }
}


//－－－－－－－－－－－－－－－－－－－－－/
//sの敵にpower食らわす
//－－－－－－－－－－－－－－－－－－－－－/
void hit_enemy(int s,int power){
    enemy[s].hp-=power;     //弾の持つパワー分HPを減らす
    enemy_death_judge(s);   //敵が死ぬかどうかを決める
}


//－－－－－－－－－－－－－－－－－－－－－/
//ボスにpower食らわす
//－－－－－－－－－－－－－－－－－－－－－/
void hit_boss(int power){
    boss.hp-=power;//弾の持つパワー分HPを減らす
}


//－－－－－－－－－－－－－－－－－－－－－/
//自機ショットと敵との処理
//－－－－－－－－－－－－－－－－－－－－－/
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//自機ショット総数
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//敵総数
                if(enemy[s].flag>0){

                    //自機ショットと敵が当たっていれば
                    if(out_judge_cshot(i,s)){
                        ch.score += EMY_HIT_SCORE;  //スコアを加算する
                        cshot[i].flag=0;            //その自機ショットを消す
                        hit_enemy(s,cshot[i].power);//ダメージ処理
                        CreateParticle(cshot[i].x, cshot[i].y);//パーティクル登録
                        break;
                    }
                }
            }

            //ボスが出現していて、描画しないフラグがオフで、ショット中なら
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    ch.score += BOSS_HIT_SCORE; //スコアを加算
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                    CreateParticle(cshot[i].x, cshot[i].y);//パーティクル登録
                }
            }
        }
    }
}


//－－－－－－－－－－－－－－－－－－－－－/
//敵ショットと自機との処理
//－－－－－－－－－－－－－－－－－－－－－/
void enemyshot_and_ch(){
    int s,n;
	if(ch.flag==0 && ch.mutekicnt==0 && out_lazer()==1){
        ch.cnt=0;
        ch.flag=1;
        se_flag[3]=1;
	}

    //－－－－－－－－－－/
    //雑魚敵のショット
    //－－－－－－－－－－/
    for(s=0;s<SHOT_MAX;s++){//敵ショット総数

        //そのショットが登録されていたら
        if(shot[s].flag>0){
            for(n=0;n<SHOT_BULLET_MAX;n++){//弾総数

                //弾が登録されていたら
                if(shot[s].bullet[n].flag==1){
					if(bom.flag!=0){
						shot[s].bullet[n].flag=0;
						continue;
					}

                    //－－－－－－－－－－/
                    //色の当たり判定
                    //－－－－－－－－－－/
                    if (out_judge_enemyshot(s, n,CRANGE_COLOR) == 1 && shot[s].bullet[n].col == ch.color) {//色判定の範囲内に弾幕が入った　＆　同じ色の弾幕なら
                        shot[s].bullet[n].flag = 0;   //弾をオフ
                        ch.score += ABSORPTION_SCORE; //スコアを吸収
                        ch.power += ABSORPTION_POWER; //パワーを吸収
                        if (ch.power >= POWER_MAX) ch.power = POWER_MAX;//上限修正
                        CreateParticle(shot[s].bullet[n].x, shot[s].bullet[n].y);//パーティクル登録
                    }

                    //－－－－－－－－－－/
                    //自機の当たり判定
                    //－－－－－－－－－－/
                    if(out_judge_enemyshot(s,n,CRANGE)==1){//自機の範囲内に弾幕が入った
                        shot[s].bullet[n].flag=0;//弾をオフ

                        //無敵状態じゃないなら
                        if (ch.flag == 0 && ch.mutekicnt == 0) {//被弾
                            ch.cnt = 0;     //無敵状態に
                            ch.flag = 1;    //無敵状態に
                            se_flag[3] = 1; //ピチュリ音

                            //パワーを減らす
                            ch.power -= DECREASE_POWER;
                            if (ch.power < POWER_MIN) ch.power = POWER_MIN;//下限修正

                            //ミス回数を増やす
                            ch.miss++;

                            switch (game_mode) {//game_mode / = 0 残機モード / = 1 スコアモード
                            case 0: ch.life -= DECREASE_LIFE;   break;
                            case 1: ch.score -= DECREASE_SCORE; if (ch.score < SCORE_MIN)ch.score = SCORE_MIN; break;
                            }
                        }
                    }
                }
            }
        }
    }

    //－－－－－－－－－－/
    //ボスのショット
    //－－－－－－－－－－/
    if(boss_shot.flag>0){//そのショットが登録されていたら
        for(n=0;n<BOSS_BULLET_MAX;n++){//弾総数

            //弾が登録されていたら
            if(boss_shot.bullet[n].flag==1){
				if(bom.flag!=0){
					boss_shot.bullet[n].flag=0;
					continue;
				}

                //－－－－－－－－－－/
                //色の当たり判定
                //－－－－－－－－－－/
                if (out_judge_bossshot(n,CRANGE_COLOR) == 1 && boss_shot.bullet[n].col == ch.color) {//色判定の範囲内に弾幕が入った　＆　同じ色の弾幕なら
                    boss_shot.bullet[n].flag = 0; //弾をオフ
                    ch.score += ABSORPTION_SCORE; //エネルギーを吸収
                    ch.power += ABSORPTION_POWER; //パワーを吸収
                    if (ch.power >= POWER_MAX) ch.power = POWER_MAX;//上限修正
                    CreateParticle(boss_shot.bullet[n].x, boss_shot.bullet[n].y);//パーティクル登録
                }

                //－－－－－－－－－－/
                //自機の当たり判定
                //－－－－－－－－－－/
                if(out_judge_bossshot(n,CRANGE)==1){//自機の範囲内に弾幕が入った
                    boss_shot.bullet[n].flag=0;//弾をオフ

                    //無敵状態じゃないなら
                    if(ch.flag==0 && ch.mutekicnt==0){
                        ch.cnt = 0;     //無敵状態に
                        ch.flag=1;      //無敵状態に
                        se_flag[3]=1;   //ピチュリ音

                        //パワーを減らす
                        ch.power -= DECREASE_POWER;
                        if (ch.power < POWER_MIN) ch.power = POWER_MIN;//下限修正

                        //ミス回数を増やす
                        ch.miss++;
                        
                        switch (game_mode) {//game_mode / = 0 残機モード / = 1 スコアモード
                        case 0: ch.life -= DECREASE_LIFE;   break;
                        case 1: ch.score -= DECREASE_SCORE; if (ch.score < SCORE_MIN)ch.score = SCORE_MIN; break;
                        }
                    }
                }
            }
        }
    }
}


//ーーーーーーーーーーーーーーーーーーーー/
//ボムのダメージを敵に喰らわす
//ーーーーーーーーーーーーーーーーーーーー/
void cbom_and_enemy(){
    int s;
    if (bom.flag != 1) {//ボムを発射していないなら
        return;//終了
    }

    //敵総数
    for(s=0;s<ENEMY_MAX;s++){
        if(enemy[s].flag>0){//その敵がいれば
            hit_enemy(s,ch.power/20);//敵にダメージを与える
        }
    }

    //ボスがいて、描画しないフラグがオフで、ショット中なら
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
        hit_boss(ch.power/20);//ボスにダメージを与える
    }
}


//ーーーーーーーーーーーーーーーーーーーー/
//アイテムとの接触
//アイテム　0:小パワー 1:小点 2:弾点 3:小金 4:大パワー 5:大金
//ーーーーーーーーーーーーーーーーーーーー/
void ch_and_item(){
	for(int i=0;i<ITEM_MAX;i++){

        //アイテムがあるなら
		if(item[i].flag>0){
			double x=item[i].x-ch.x,y=item[i].y-ch.y;

            //当たったか判定
			if(x*x+y*y<ITEM_HIT_BOX*ITEM_HIT_BOX){
				switch(item[i].knd){//当たったならどのアイテム
					case 0:	ch.power+=5; break;
					case 1:	ch.point+=5; break;
					case 2:	ch.graze+=5; break;
					case 3:	ch.money+=5; break;
					case 4:	ch.power+=50;break;
					case 5:	ch.money+=10;break;
				}

                //－－－－－－－－－－/
                //上限値修正
                //－－－－－－－－－－/
				if(ch.power>POWER_MAX)ch.power=POWER_MAX;
				if(ch.point>OTHER_MAX)ch.point=OTHER_MAX;
				if(ch.money>OTHER_MAX)ch.money=OTHER_MAX;
				if(ch.graze>OTHER_MAX)ch.graze=OTHER_MAX;
				

                //－－－－－－－－－－/
                // アイテム後始末
                //－－－－－－－－－－/
                item[i].flag=0; //アイテムを消す
				se_flag[34]=1;  //回収音を鳴らす
			}
		}
	}
}


//ーーーーーーーーーーーーーーーーーーーー/
//当たり判定メイン
//ーーーーーーーーーーーーーーーーーーーー/
void out_main(){
    cbom_and_enemy();   //敵にボムを喰らわせる
    cshot_and_enemy();  //自機ショットと敵との処理
    enemyshot_and_ch(); //敵ショットと自機との処理
	ch_and_item();      //アイテム接触処理
}