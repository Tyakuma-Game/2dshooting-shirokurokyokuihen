#include "../include/GV.h"

extern void enter_char_item();//(39章)


//−−−−−−−−−−−−−−−−−−−−−/
// キャラクターの状態計算
//−−−−−−−−−−−−−−−−−−−−−/
void calc_ch(){

    //喰らいボム受付中
    if(ch.flag==1){
        bright_set.brt=80;//暗く

        if(ch.cnt>20){//0.33秒受け付ける
            ch.flag   =2;    //1:喰らいボム受付中　2:死んで浮き上がり中
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }

    //今の瞬間死んだら
    if(ch.cnt==0 && ch.flag==2){
		enter_char_item();//キャラのアイテム登録(39章)

        //座標初期化
        ch.x=FMX/2;
        ch.y=FMY+30;

        //無敵状態へ移行
        ch.mutekicnt++;
    }

    //死んで浮上中なら
    if(ch.flag==2){
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//キャラを上に上げる


        //１秒以上か、キャラがある程度上にいて、何かおされたら
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//キャラステータスを元に戻す
        }
    }

    //無敵状態
    if(ch.mutekicnt>0){//０じゃなかったら
        ch.mutekicnt++;

        //150以上たったら
        if(ch.mutekicnt>150){
            ch.mutekicnt=0;//無敵状態を解除
        }
    }

    //プレイヤー制御用
    ch.cnt++;//キャラクタカウントアップ

    //アニメーション計算
    ch.img=(ch.cnt%18)/6;//現在の画像決定
}


//−−−−−−−−−−−−−−−−−−−−−/
// キャラクター計算
//−−−−−−−−−−−−−−−−−−−−−/
void ch_move(){
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    //喰らいボム受付中は動かせない
    if (ch.flag == 1) {
        return;
    }

    //−−−−−−−−−−/
    // 移動計算
    //−−−−−−−−−−/

    //左右分
    for(i=0;i<2;i++){
        if(inputpad[i]>0){  //左右どちらかの入力があれば
            sayu_flag=1;    //左右入力フラグを立てる
        }
    }

    //上下分
    for(i=2;i<4;i++){
        if(inputpad[i]>0){  //上下どちらかの入力があれば
            joge_flag=1;    //上下入力フラグを立てる
        }
    }

    //斜め移動か判定
    if(sayu_flag==1 && joge_flag==1){//左右、上下両方の入力があれば斜め
        naname=sqrt(2.0);//移動スピードを1/ルート2に
    }


    //−−−−−−−−−−/
    //実際に計算
    //−−−−−−−−−−/
    for(int i=0;i<4;i++){//4方向分ループ
        if(inputpad[i]>0){//i方向のキーボード、パッドどちらかの入力があれば

            //今の座標をとりあえずx,yに格納
            x=ch.x , y=ch.y;

            //移動分をmx,myに代入
            mx=move_x[i];    my=move_y[i];

            //低速移動なら
            if(CheckStatePad(configpad.slow)>0){
                mx=move_x[i]/3;    my=move_y[i]/3;//移動スピードを1/3に
            }

            //仮計算
            x+=mx/naname , y+=my/naname;//今の座標と移動分を足す

            //仮計算結果移動可能範囲内なら
            if(!(x<10 || x>
                FMX-10 || y<5 || y>FMY-5)){
                ch.x=x , ch.y=y;//実際に移動
            }
        }
    }
}