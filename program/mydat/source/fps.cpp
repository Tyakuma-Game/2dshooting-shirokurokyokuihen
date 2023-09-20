#include "../include/GV.h"

//ƒtƒŒ[ƒ€”
#define FLAME 60

//fps‚ÌƒJƒEƒ“ƒ^A60ƒtƒŒ[ƒ€‚É1‰ñŠî€‚Æ‚È‚é‚ğ‹L˜^‚·‚é•Ï”
int fps_count,count0t;

//•½‹Ï‚ğŒvZ‚·‚é‚½‚ß60‰ñ‚Ì1üŠÔ‚ğ‹L˜^
int f[FLAME];

//•½‹Ïfps
double ave;


//|||||||||||||||||||||/
// ƒtƒŒ[ƒ€ŒvZ
//|||||||||||||||||||||/
void fps_wait(){
    int term,i,gnt;
    static int t=0;

    //60ƒtƒŒ[ƒ€‚Ì1‰ñ–Ú‚È‚ç
    if(fps_count==0){
        if(t==0){//Š®‘S‚ÉÅ‰‚È‚ç‚Ü‚½‚È‚¢
            term=0;
        }
        else{   //‘O‰ñ‹L˜^‚µ‚½ŠÔ‚ğŒ³‚ÉŒvZ
            term=count0t+1000-GetNowCount();
        }
    }
    else{       //‘Ò‚Â‚×‚«ŠÔ=Œ»İ‚ ‚é‚×‚«-Œ»İ‚Ì
        term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
    }

    //‘Ò‚Â‚×‚«ŠÔ‚¾‚¯‘Ò‚Â
    if(term>0){
        Sleep(term);
    }

    gnt=GetNowCount();

    //60ƒtƒŒ[ƒ€‚É1“xŠî€‚ğì‚é
    if(fps_count==0){
        count0t=gnt;
    }
    
    //‚Pü‚µ‚½ŠÔ‚ğ‹L˜^
    f[fps_count]=gnt-t;
    t=gnt;
    
    //•½‹ÏŒvZ
    if(fps_count==FLAME-1){
        ave=0;
        for(i=0;i<FLAME;i++){
            ave+=f[i];
        }
        ave/=FLAME;
    }
    fps_count = (++fps_count)%FLAME ;
}


//|||||||||||||||||||||/
// ƒtƒŒ[ƒ€”‚ğ•\¦‚·‚é
//|||||||||||||||||||||/
void draw_fps(int x, int y){
    if(ave!=0){
        DrawFormatString(x, y,color[0],"[%.1f]",1000/ave);
    }
    return;
}