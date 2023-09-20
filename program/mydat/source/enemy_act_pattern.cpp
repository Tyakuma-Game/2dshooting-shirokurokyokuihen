#include "../include/GV.h"


//|||||||||||||||||||||/
//“n‚³‚ê‚½-ang`ang‚Ü‚Å‚Ìƒ‰ƒ“ƒ_ƒ€‚ÈŠp“x‚ğ•Ô‚·
//|||||||||||||||||||||/
double rang(double ang){
    return ( -ang + ang*2 * GetRand(10000)/10000.0 );
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“0
//‰º‚ª‚Á‚Ä‚«‚Ä’â‘Ø‚µ‚Äã‚ª‚Á‚Ä‚¢‚­
void enemy_pattern0(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if(t==0){
        enemy[i].vy=3;
    }

    //~‚Ü‚é
    if(t==40){
        enemy[i].vy=0;
    }

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==40+enemy[i].wait){
        enemy[i].vy=-3;//ã‚ª‚Á‚Ä‚¢‚­
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“1
//‰º‚ª‚Á‚Ä‚«‚Ä’â‘Ø‚µ‚Ä¶‰º‚És‚­
void enemy_pattern1(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if(t==0){
        enemy[i].vy=3;
    }

    //~‚Ü‚é
    if(t==40){
        enemy[i].vy=0;
    }

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==40+enemy[i].wait){
        enemy[i].vx=-1; //~‚Ü‚é
        enemy[i].vy=2;  //ã‚ª‚Á‚Ä‚¢‚­
        enemy[i].muki=0;//¶Œü‚«ƒZƒbƒg
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“2
//‰º‚ª‚Á‚Ä‚«‚Ä’â‘Ø‚µ‚Ä‰E‰º‚És‚­
void enemy_pattern2(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if (t == 0) {
        enemy[i].vy = 3;
    }

    //~‚Ü‚é
    if (t == 40) {
        enemy[i].vy = 0;
    }

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==40+enemy[i].wait){
        enemy[i].vx=1;  //ã‚ª‚Á‚Ä‚¢‚­
        enemy[i].vy=2;  //~‚Ü‚é
        enemy[i].muki=2;//‰EŒü‚«ƒZƒbƒg
    }
}


//|||||||||||||||||||||/
//s“®ƒpƒ^[ƒ“3
//‚·‚Î‚â‚­~‚è‚Ä‚«‚Ä¶‚Ö
void enemy_pattern3(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if(t==0){
        enemy[i].vy=5;
    }

    //“r’†‚Å¶Œü‚«‚É
    if(t==30){
        enemy[i].muki=0;
    }

    //¶Œü‚«‚ÉˆÚ“®
    if(t<100){
        enemy[i].vx-=5/100.0;//¶Œü‚«‰Á‘¬
        enemy[i].vy-=5/100.0;//Œ¸‘¬
    }
}


//|||||||||||||||||||||/
//s“®ƒpƒ^[ƒ“4
//‚·‚Î‚â‚­~‚è‚Ä‚«‚Ä‰E‚Ö
void enemy_pattern4(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if(t==0){
        enemy[i].vy=5;
    }

    //“r’†‚Å‰EŒü‚«‚É
    if(t==30){
        enemy[i].muki=2;
    }

    //‰EŒü‚«‚ÉˆÚ“®
    if(t<100){
        enemy[i].vx+=5/100.0;//‰EŒü‚«‰Á‘¬
        enemy[i].vy-=5/100.0;//Œ¸‘¬
    }
}


//|||||||||||||||||||||/
//s“®ƒpƒ^[ƒ“5
//Î‚ß¶‰º‚Ö
void enemy_pattern5(int i){
    int t=enemy[i].cnt;

    //Î‚ß¶‰º‚ÖˆÚ“®
    if(t==0){
        enemy[i].vx-=1; //¶‚ÖˆÚ“®
        enemy[i].vy=2;  //‰º‚ÖˆÚ“®
        enemy[i].muki=0;//‰æ‘œ‚ğ¶Œü‚«‚É
    }
}


//|||||||||||||||||||||/
//s“®ƒpƒ^[ƒ“6
//Î‚ß‰E‰º‚Ö
void enemy_pattern6(int i){
    int t=enemy[i].cnt;

    //Î‚ß‰E‰º‚ÉˆÚ“®
    if(t==0){
        enemy[i].vx+=1; //‰E‚ÖˆÚ“®
        enemy[i].vy=2;  //‰º‚ÖˆÚ“®
        enemy[i].muki=2;//‰æ‘œ‚ÌŒü‚«‚ğ‰EŒü‚«‚É
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“7
//’â‘Ø‚µ‚Ä‚»‚Ì‚Ü‚Ü¶ã‚É
void enemy_pattern7(int i){
    int t=enemy[i].cnt;

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==enemy[i].wait){
        enemy[i].vx=-0.7;   //¶‚Ö
        enemy[i].vy=-0.3;   //ã‚ª‚Á‚Ä‚¢‚­
        enemy[i].muki=0;    //¶Œü‚«
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“8
//’â‘Ø‚µ‚Ä‚»‚Ì‚Ü‚Ü‰Eã‚É
void enemy_pattern8(int i){
    int t=enemy[i].cnt;

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==enemy[i].wait){
        enemy[i].vx=+0.7;   //‰E‚Ö
        enemy[i].vy=-0.3;   //ã‚ª‚Á‚Ä‚¢‚­
        enemy[i].muki=2;    //‰EŒü‚«
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“9
//’â‘Ø‚µ‚Ä‚»‚Ì‚Ü‚Üã‚É
void enemy_pattern9(int i){
    int t=enemy[i].cnt;

    //“o˜^‚³‚ê‚½’â‘ØŠÔ‚¾‚¯‚µ‚Ä
    if(t==enemy[i].wait){
        enemy[i].vy=-1;//ã‚ª‚Á‚Ä‚¢‚­
    }
}


//|||||||||||||||||||||/
//ˆÚ“®ƒpƒ^[ƒ“10
//‰º‚ª‚Á‚Ä‚«‚ÄƒEƒƒEƒ‚µ‚Äã‚ª‚Á‚Ä‚¢‚­
void enemy_pattern10(int i){
    int t=enemy[i].cnt;

    //‰º‚ª‚Á‚Ä‚­‚é
    if (t == 0) {
        enemy[i].vy = 4;
    }

    //’â~
    if(t==40){
        enemy[i].vy=0;//~‚Ü‚é
    }

    //‚¤‚ë‚¤‚ë‚µ‚Äã¸‚·‚é
    if(t>=40){
        if(t%60==00){
            int r=cos(enemy[i].ang)< 0 ? 0 : 1;
            enemy[i].sp=6+rang(2);
            enemy[i].ang=rang(PI/4)+PI*r;
            enemy[i].muki=2-2*r;
        }
        enemy[i].sp*=0.95;
    }
    if(t>=40+enemy[i].wait){
        enemy[i].vy-=0.05;
    }
}