#include "../include/GV.h"

extern void dn_calc();

//−−−−−−−−−−−−−−−−−−−−−/
//エフェクトの登録空き番号を探す
//−−−−−−−−−−−−−−−−−−−−−/
int search_effect(){
    for(int i=0;i<EFFECT_MAX;i++){  //エフェクトの最大数まで探す
        if(effect[i].flag==0){      //空きがあったら返す
            return i;
        }
    }
    return -1;//空きがなかった
}


//−−−−−−−−−−−−−−−−−−−−−/
//エフェクトを計算する
//−−−−−−−−−−−−−−−−−−−−−/
void calc_effect(){

    for(int i=0;i<EFFECT_MAX;i++){  //エフェクトの最大数まで探す
        if(effect[i].flag>0){       //エフェクトが登録されていたら
            //座標計算
            effect[i].x+=cos(effect[i].mvang)*effect[i].spd;
            effect[i].y+=sin(effect[i].mvang)*effect[i].spd;
            
            //エフェクトの種類によって分岐
            switch(effect[i].knd){

                //−−−−−−−−−−−−−−−−−−−−−/
                //敵の消滅エフェクト
                case 0:
                    effect[i].cnt++;    //制御用
                    effect[i].r+=0.08;  //エフェクトの大きさを段々大きくする
                    
                    //10カウント以上になったら
                    if(effect[i].cnt>10){
                        effect[i].brt-=25;//明るさを少なくする
                    }

                    //20カウント以上になったら
                    if(effect[i].cnt>20){
                        effect[i].flag=0;//消す
                    }

                    break;

                //−−−−−−−−−−−−−−−−−−−−−/
                //ボムのエフェクト
                case 1:
                    //スピード計算
                    if(effect[i].cnt<60){
                        effect[i].spd-=(0.2+effect[i].cnt*effect[i].cnt/3000.0);
                    }
                    if(effect[i].cnt==60){
                        effect[i].spd=0;
                        se_flag[15]=1;
						enter_dn(11,20);//(45)
                    }

                    //明るさと大きさ計算
                    effect[i].r+=0.015;//エフェクトの大きさを段々大きくする
                    if(effect[i].cnt<51){
                        effect[i].brt+=5;//明るさを多くする
                    }

                    if(effect[i].cnt>=60){
                        effect[i].r+=0.04;      //エフェクトの大きさを段々大きくする
                        effect[i].brt-=255/30.0;//明るさを少なくする
                    }

                    effect[i].cnt++;//制御用

                    //カウントが９０以上になったら
                    if(effect[i].cnt>=90){
                        effect[i].flag=0;//消す
                    }

                    break;

                //−−−−−−−−−−−−−−−−−−−−−/
                //ボムエフェクト（キャラ）
                case 2:
                    //明るさ計算
                    if(effect[i].cnt<51)
                        effect[i].brt+=4;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=4;
                    //カウントアップと消去計算
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;

                //−−−−−−−−−−−−−−−−−−−−−/
                //ボムのエフェクト（ライン）
                case 3:
                    //明るさ計算
                    if(effect[i].cnt<51)
                        effect[i].brt+=2;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=2;
                    //カウントアップと消去計算
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;          

                //−−−−−−−−−−−−−−−−−−−−−/
                //喰らいボムエフェクト
                case 4:
                    //明るさ計算
                    if(effect[i].cnt>=6){
                        effect[i].brt-=255/6;
                    }
                    effect[i].r+=0.12;
                    effect[i].cnt++;
                    if(effect[i].cnt>=12 || ch.flag!=1){
                        effect[i].flag=0;
                    }
                    break;                
                
                //−−−−−−−−−−−−−−−−−−−−−/
                //エラー
                default:
                    printfDx("effect設定エラー\n");
                    break;
            }
        }
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
//消滅エフェクトの登録空き番号を探す
//−−−−−−−−−−−−−−−−−−−−−/
int search_del_effect(){
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag==0){
            return i;//あった
        }
    }
    return -1;//無かった
}


//−−−−−−−−−−−−−−−−−−−−−/
//消滅エフェクトを登録する
//−−−−−−−−−−−−−−−−−−−−−/
void enter_del_effect(int s){
    int k=search_del_effect();
    if(k!=-1){
        del_effect[k].flag=1;               //フラグを立てる
        del_effect[k].cnt=0;                //制御用カウントを初期化
        del_effect[k].col=enemy[s].back_col;//敵の背景色を消滅色に設定する
        del_effect[k].x=enemy[s].x;         //敵の座標を消滅位置にセット
        del_effect[k].y=enemy[s].y;         //敵の座標を消滅位置にセット
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
//消滅エフェクトを計算・エフェクトを登録する
//−−−−−−−−−−−−−−−−−−−−−/
void calc_del_effect(){
    int k;
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag>0){
            if(del_effect[i].cnt%2==0){// 1/30秒ずつセット
                if((k=search_effect())!=-1){//空き番号検索
                    memset(&effect[k],0,sizeof(effect_t));//初期化
                    effect[k].flag=1;//フラグを立てる
                    effect[k].brt=255;//輝度を最大値に
                    effect[k].ang=rang(PI);//角度をランダムに
                    effect[k].col=del_effect[i].col;//色をセット
                    effect[k].eff=1;//1は光エフェクト。光エフェクトにセットする
                    effect[k].img=img_del_effect[effect[k].col];//消滅する画像をセット
                    effect[k].knd=0;//エフェクトの種類は0番(消滅エフェクトは0とする)
                    effect[k].x=del_effect[i].x;//座標をセット
                    effect[k].y=del_effect[i].y;
                    effect[k].spd=0;
                }
            }
            if(del_effect[i].cnt>8){
                del_effect[i].flag=0;
            }
            del_effect[i].cnt++;
        }
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
//ボムを登録
//−−−−−−−−−−−−−−−−−−−−−/
void enter_bom(){
    int k;
    bom.flag=1;
    bom.cnt=0;
    bom.knd=0;
    ch.flag=0;
    ch.mutekicnt=1;//無敵に
    se_flag[14]=1;//キュイーン音
    //縦線
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;//ボムの線のエフェクト
        effect[k].brt=0;
        effect[k].ang=PI/2;
        effect[k].mvang=-PI/2;
        effect[k].spd=1;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[3];
        effect[k].x=70;
        effect[k].y=300;
    }
    //横線
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;//ボムの線のエフェクト
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=0;
        effect[k].spd=1;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[3];
        effect[k].x=100;
        effect[k].y=350;
    }
    //キャラ
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=2;//ボムのキャラ・線のエフェクト
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=-PI/2;
        effect[k].spd=0.7;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[2];//表示するキャラクター絵挿入
        effect[k].x=260;
        effect[k].y=300;
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
//ボム計算
//−−−−−−−−−−−−−−−−−−−−−/
void bom_calc(){
    int n,k;
	double shot_angle[4]={0,PI,PI/2,PI*1.5};//4発エフェクトが飛ぶ角度

    //キャラが通常か喰らいボム状態で、ボムがオフなら
    if((ch.flag==0||ch.flag==1) && bom.flag==0){

        //ボムボタンが押されたら
        if(CheckStatePad(configpad.bom)==1 && ch.power >= BOM_ENERGY){
            enter_bom();            //ボムを発射する
            ch.power -= BOM_ENERGY; //ボムのエネルギーを消費する

        }
    }
    
    //ボムが登録されていたら
    if(bom.flag==1){

        //1/6秒に１回
        if(bom.cnt%10==0){
            n=(bom.cnt/10);

            if(n<4 && (k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=1;//エフェクト番号１：ボムのエフェクト
                effect[k].brt=0;
                effect[k].ang=rang(PI);//画像の向きはランダム
                effect[k].mvang=shot_angle[n]-PI/4;//飛ぶ方向
                effect[k].spd=13+rang(2);//スピード
                effect[k].r=0.5;//大きさ
                effect[k].eff=2;//αブレンド
                effect[k].img= img_eff_bom[(bom.cnt/10)/3];//画像
                effect[k].x=ch.x;//座標
                effect[k].y=ch.y;
            }
        }
        bom.cnt++;

        //ーーーーーーーーー/
        //ボム用に明るさ
        //ーーーーーーーーー/
        if(bom.cnt<40){
            bright_set.brt=255-bom.cnt*5;//画面の明るさ設定(暗く)
        }
        if(bom.cnt>90){
            bright_set.brt=255-40*5+(bom.cnt-90)*5;//画面の明るさ設定(明るく)
        }

        //ボムを終了する
        if(bom.cnt>130){
            bom.flag=0;
            bright_set.brt=255;
        }
    }
}


//−−−−−−−−−−−−−−−−−−−−−/
// 喰らいボムのエフェクト
//−−−−−−−−−−−−−−−−−−−−−/
void enter_crybom_effect(){
    int k;
    if(ch.flag==1){
        if(ch.cnt%2==0){
            if((k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=4;//喰らいボムエフェクト
                effect[k].brt=255;
                effect[k].ang=rang(PI);
                effect[k].spd=0;
                effect[k].r=0;
                effect[k].eff=2;
                effect[k].img=img_del_effect[GetRand(4)];
                effect[k].x=ch.x;
                effect[k].y=ch.y;
            }
        }
    }
}

void calc_child(){
	for(int i=0;i<CHILD_MAX;i++){
		if(child[i].flag>0){
			child[i].x+=cos(child[i].angle)*child[i].spd;
			child[i].y+=sin(child[i].angle)*child[i].spd;
			child[i].cnt++;
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
//パーティクルの空き番号を探す
//−−−−−−−−−−−−−−−−−−−−−/
int search_del_pa_particle() {
    for (int i = 0; i < PARTICLE_MAX; i++) {
        if (particle[i].flag == 0) {
            return i;//あった
        }
    }
    return -1;//無かった
}



//−−−−−−−−−−−−−−−−−−−−−/
//　パーティクルを登録
//−−−−−−−−−−−−−−−−−−−−−/
void CreateParticle(float x,float y) {
    int k;
    //空きを探す
    k = search_del_pa_particle();

    //空きがあれば
    if (k != -1) {
        //フラグを立てる
        particle[k].flag = 1;
        particle[k].color = ch.color;

        //座標
        particle[k].x = x;
        particle[k].y = y;

        //加速度
        particle[k].vx = (float)(rand() % 25 - 5) / 10.0f;//ランダムな方向に
        particle[k].vy = (float)(rand() % 25 - 5) / 10.0f;//ランダムな方向に
    }   
}



//−−−−−−−−−−−−−−−−−−−−−/
// パーティクルの計算
//−−−−−−−−−−−−−−−−−−−−−/
void particle_calc() {
    //登録されているのを探す
    for (int i=0; i < PARTICLE_MAX; i++) {
        if (particle[i].flag == 1) {
            //座標移動
            particle[i].x += particle[i].vx;
            particle[i].y += particle[i].vy;

            //カウントを進める
            particle[i].cnt_time++;

            //消滅判定
            if (particle[i].cnt_time > 30) {
                particle[i].flag = 0;		//フラグを立ってない状態に
                particle[i].cnt_time = 0;	//時間を０に
            }
        }
    }
}



//−−−−−−−−−−−−−−−−−−−−−/
// エフェクト制御
//−−−−−−−−−−−−−−−−−−−−−/
void effect_main(){
	calc_child();
    dn_calc();              //ドガーンとゆれる画面の処理
    calc_del_effect();      //消滅エフェクトの計算
    calc_effect();          //エフェクトの計算
    bom_calc();             //ボム計算
    particle_calc();        //パーティクルの計算
    enter_crybom_effect();
}