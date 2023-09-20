#include "../include/GV.h"


//|||||||||||||||||||||/
//@‚Ç‚ê‚®‚ç‚¢‚â‚é‚©w’è‚·‚é
//|||||||||||||||||||||/
void enter_dn(int size, int time){
	dn.flag=1;
	dn.cnt=0;
	dn.time=time;
	dn.size=size;
}


//|||||||||||||||||||||/
//ƒhƒK[ƒ“‚Æ‚ä‚ê‚é‰æ–Ê‚Ìˆ—
//|||||||||||||||||||||/
void dn_calc(){
    if(dn.flag==1){//ˆ—ƒtƒ‰ƒO‚ªON‚È‚ç

        //—h‚ç‚·
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;

        //w’è‚³‚ê‚½ŠÔ‚ª‚½‚Â‚ÆI‚í‚é
        if(dn.cnt>dn.time){
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}