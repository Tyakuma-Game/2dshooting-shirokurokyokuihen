#include "../include/GV.h"

extern void enter_char_item();//(39Í)


//|||||||||||||||||||||/
// ƒLƒƒƒ‰ƒNƒ^[‚Ìó‘ÔŒvZ
//|||||||||||||||||||||/
void calc_ch(){

    //‹ò‚ç‚¢ƒ{ƒ€ó•t’†
    if(ch.flag==1){
        bright_set.brt=80;//ˆÃ‚­

        if(ch.cnt>20){//0.33•bó‚¯•t‚¯‚é
            ch.flag   =2;    //1:‹ò‚ç‚¢ƒ{ƒ€ó•t’†@2:€‚ñ‚Å•‚‚«ã‚ª‚è’†
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }

    //¡‚ÌuŠÔ€‚ñ‚¾‚ç
    if(ch.cnt==0 && ch.flag==2){
		enter_char_item();//ƒLƒƒƒ‰‚ÌƒAƒCƒeƒ€“o˜^(39Í)

        //À•W‰Šú‰»
        ch.x=FMX/2;
        ch.y=FMY+30;

        //–³“Gó‘Ô‚ÖˆÚs
        ch.mutekicnt++;
    }

    //€‚ñ‚Å•‚ã’†‚È‚ç
    if(ch.flag==2){
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//ƒLƒƒƒ‰‚ğã‚Éã‚°‚é


        //‚P•bˆÈã‚©AƒLƒƒƒ‰‚ª‚ ‚é’ö“xã‚É‚¢‚ÄA‰½‚©‚¨‚³‚ê‚½‚ç
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//ƒLƒƒƒ‰ƒXƒe[ƒ^ƒX‚ğŒ³‚É–ß‚·
        }
    }

    //–³“Gó‘Ô
    if(ch.mutekicnt>0){//‚O‚¶‚á‚È‚©‚Á‚½‚ç
        ch.mutekicnt++;

        //150ˆÈã‚½‚Á‚½‚ç
        if(ch.mutekicnt>150){
            ch.mutekicnt=0;//–³“Gó‘Ô‚ğ‰ğœ
        }
    }

    //ƒvƒŒƒCƒ„[§Œä—p
    ch.cnt++;//ƒLƒƒƒ‰ƒNƒ^ƒJƒEƒ“ƒgƒAƒbƒv

    //ƒAƒjƒ[ƒVƒ‡ƒ“ŒvZ
    ch.img=(ch.cnt%18)/6;//Œ»İ‚Ì‰æ‘œŒˆ’è
}


//|||||||||||||||||||||/
// ƒLƒƒƒ‰ƒNƒ^[ŒvZ
//|||||||||||||||||||||/
void ch_move(){
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    //‹ò‚ç‚¢ƒ{ƒ€ó•t’†‚Í“®‚©‚¹‚È‚¢
    if (ch.flag == 1) {
        return;
    }

    //||||||||||/
    // ˆÚ“®ŒvZ
    //||||||||||/

    //¶‰E•ª
    for(i=0;i<2;i++){
        if(inputpad[i]>0){  //¶‰E‚Ç‚¿‚ç‚©‚Ì“ü—Í‚ª‚ ‚ê‚Î
            sayu_flag=1;    //¶‰E“ü—Íƒtƒ‰ƒO‚ğ—§‚Ä‚é
        }
    }

    //ã‰º•ª
    for(i=2;i<4;i++){
        if(inputpad[i]>0){  //ã‰º‚Ç‚¿‚ç‚©‚Ì“ü—Í‚ª‚ ‚ê‚Î
            joge_flag=1;    //ã‰º“ü—Íƒtƒ‰ƒO‚ğ—§‚Ä‚é
        }
    }

    //Î‚ßˆÚ“®‚©”»’è
    if(sayu_flag==1 && joge_flag==1){//¶‰EAã‰º—¼•û‚Ì“ü—Í‚ª‚ ‚ê‚ÎÎ‚ß
        naname=sqrt(2.0);//ˆÚ“®ƒXƒs[ƒh‚ğ1/ƒ‹[ƒg2‚É
    }


    //||||||||||/
    //ÀÛ‚ÉŒvZ
    //||||||||||/
    for(int i=0;i<4;i++){//4•ûŒü•ªƒ‹[ƒv
        if(inputpad[i]>0){//i•ûŒü‚ÌƒL[ƒ{[ƒhAƒpƒbƒh‚Ç‚¿‚ç‚©‚Ì“ü—Í‚ª‚ ‚ê‚Î

            //¡‚ÌÀ•W‚ğ‚Æ‚è‚ ‚¦‚¸x,y‚ÉŠi”[
            x=ch.x , y=ch.y;

            //ˆÚ“®•ª‚ğmx,my‚É‘ã“ü
            mx=move_x[i];    my=move_y[i];

            //’á‘¬ˆÚ“®‚È‚ç
            if(CheckStatePad(configpad.slow)>0){
                mx=move_x[i]/3;    my=move_y[i]/3;//ˆÚ“®ƒXƒs[ƒh‚ğ1/3‚É
            }

            //‰¼ŒvZ
            x+=mx/naname , y+=my/naname;//¡‚ÌÀ•W‚ÆˆÚ“®•ª‚ğ‘«‚·

            //‰¼ŒvZŒ‹‰ÊˆÚ“®‰Â”\”ÍˆÍ“à‚È‚ç
            if(!(x<10 || x>
                FMX-10 || y<5 || y>FMY-5)){
                ch.x=x , ch.y=y;//ÀÛ‚ÉˆÚ“®
            }
        }
    }
}