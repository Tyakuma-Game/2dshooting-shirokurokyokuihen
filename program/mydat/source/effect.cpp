#include "../include/GV.h"

extern void dn_calc();

//|||||||||||||||||||||/
//ƒGƒtƒFƒNƒg‚Ì“o˜^‹ó‚«”Ô†‚ğ’T‚·
//|||||||||||||||||||||/
int search_effect(){
    for(int i=0;i<EFFECT_MAX;i++){  //ƒGƒtƒFƒNƒg‚ÌÅ‘å”‚Ü‚Å’T‚·
        if(effect[i].flag==0){      //‹ó‚«‚ª‚ ‚Á‚½‚ç•Ô‚·
            return i;
        }
    }
    return -1;//‹ó‚«‚ª‚È‚©‚Á‚½
}


//|||||||||||||||||||||/
//ƒGƒtƒFƒNƒg‚ğŒvZ‚·‚é
//|||||||||||||||||||||/
void calc_effect(){

    for(int i=0;i<EFFECT_MAX;i++){  //ƒGƒtƒFƒNƒg‚ÌÅ‘å”‚Ü‚Å’T‚·
        if(effect[i].flag>0){       //ƒGƒtƒFƒNƒg‚ª“o˜^‚³‚ê‚Ä‚¢‚½‚ç
            //À•WŒvZ
            effect[i].x+=cos(effect[i].mvang)*effect[i].spd;
            effect[i].y+=sin(effect[i].mvang)*effect[i].spd;
            
            //ƒGƒtƒFƒNƒg‚Ìí—Ş‚É‚æ‚Á‚Ä•ªŠò
            switch(effect[i].knd){

                //|||||||||||||||||||||/
                //“G‚ÌÁ–ÅƒGƒtƒFƒNƒg
                case 0:
                    effect[i].cnt++;    //§Œä—p
                    effect[i].r+=0.08;  //ƒGƒtƒFƒNƒg‚Ì‘å‚«‚³‚ğ’iX‘å‚«‚­‚·‚é
                    
                    //10ƒJƒEƒ“ƒgˆÈã‚É‚È‚Á‚½‚ç
                    if(effect[i].cnt>10){
                        effect[i].brt-=25;//–¾‚é‚³‚ğ­‚È‚­‚·‚é
                    }

                    //20ƒJƒEƒ“ƒgˆÈã‚É‚È‚Á‚½‚ç
                    if(effect[i].cnt>20){
                        effect[i].flag=0;//Á‚·
                    }

                    break;

                //|||||||||||||||||||||/
                //ƒ{ƒ€‚ÌƒGƒtƒFƒNƒg
                case 1:
                    //ƒXƒs[ƒhŒvZ
                    if(effect[i].cnt<60){
                        effect[i].spd-=(0.2+effect[i].cnt*effect[i].cnt/3000.0);
                    }
                    if(effect[i].cnt==60){
                        effect[i].spd=0;
                        se_flag[15]=1;
						enter_dn(11,20);//(45)
                    }

                    //–¾‚é‚³‚Æ‘å‚«‚³ŒvZ
                    effect[i].r+=0.015;//ƒGƒtƒFƒNƒg‚Ì‘å‚«‚³‚ğ’iX‘å‚«‚­‚·‚é
                    if(effect[i].cnt<51){
                        effect[i].brt+=5;//–¾‚é‚³‚ğ‘½‚­‚·‚é
                    }

                    if(effect[i].cnt>=60){
                        effect[i].r+=0.04;      //ƒGƒtƒFƒNƒg‚Ì‘å‚«‚³‚ğ’iX‘å‚«‚­‚·‚é
                        effect[i].brt-=255/30.0;//–¾‚é‚³‚ğ­‚È‚­‚·‚é
                    }

                    effect[i].cnt++;//§Œä—p

                    //ƒJƒEƒ“ƒg‚ª‚X‚OˆÈã‚É‚È‚Á‚½‚ç
                    if(effect[i].cnt>=90){
                        effect[i].flag=0;//Á‚·
                    }

                    break;

                //|||||||||||||||||||||/
                //ƒ{ƒ€ƒGƒtƒFƒNƒgiƒLƒƒƒ‰j
                case 2:
                    //–¾‚é‚³ŒvZ
                    if(effect[i].cnt<51)
                        effect[i].brt+=4;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=4;
                    //ƒJƒEƒ“ƒgƒAƒbƒv‚ÆÁ‹ŒvZ
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;

                //|||||||||||||||||||||/
                //ƒ{ƒ€‚ÌƒGƒtƒFƒNƒgiƒ‰ƒCƒ“j
                case 3:
                    //–¾‚é‚³ŒvZ
                    if(effect[i].cnt<51)
                        effect[i].brt+=2;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=2;
                    //ƒJƒEƒ“ƒgƒAƒbƒv‚ÆÁ‹ŒvZ
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;          

                //|||||||||||||||||||||/
                //‹ò‚ç‚¢ƒ{ƒ€ƒGƒtƒFƒNƒg
                case 4:
                    //–¾‚é‚³ŒvZ
                    if(effect[i].cnt>=6){
                        effect[i].brt-=255/6;
                    }
                    effect[i].r+=0.12;
                    effect[i].cnt++;
                    if(effect[i].cnt>=12 || ch.flag!=1){
                        effect[i].flag=0;
                    }
                    break;                
                
                //|||||||||||||||||||||/
                //ƒGƒ‰[
                default:
                    printfDx("effectİ’èƒGƒ‰[\n");
                    break;
            }
        }
    }
}


//|||||||||||||||||||||/
//Á–ÅƒGƒtƒFƒNƒg‚Ì“o˜^‹ó‚«”Ô†‚ğ’T‚·
//|||||||||||||||||||||/
int search_del_effect(){
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag==0){
            return i;//‚ ‚Á‚½
        }
    }
    return -1;//–³‚©‚Á‚½
}


//|||||||||||||||||||||/
//Á–ÅƒGƒtƒFƒNƒg‚ğ“o˜^‚·‚é
//|||||||||||||||||||||/
void enter_del_effect(int s){
    int k=search_del_effect();
    if(k!=-1){
        del_effect[k].flag=1;               //ƒtƒ‰ƒO‚ğ—§‚Ä‚é
        del_effect[k].cnt=0;                //§Œä—pƒJƒEƒ“ƒg‚ğ‰Šú‰»
        del_effect[k].col=enemy[s].back_col;//“G‚Ì”wŒiF‚ğÁ–ÅF‚Éİ’è‚·‚é
        del_effect[k].x=enemy[s].x;         //“G‚ÌÀ•W‚ğÁ–ÅˆÊ’u‚ÉƒZƒbƒg
        del_effect[k].y=enemy[s].y;         //“G‚ÌÀ•W‚ğÁ–ÅˆÊ’u‚ÉƒZƒbƒg
    }
}


//|||||||||||||||||||||/
//Á–ÅƒGƒtƒFƒNƒg‚ğŒvZEƒGƒtƒFƒNƒg‚ğ“o˜^‚·‚é
//|||||||||||||||||||||/
void calc_del_effect(){
    int k;
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag>0){
            if(del_effect[i].cnt%2==0){// 1/30•b‚¸‚ÂƒZƒbƒg
                if((k=search_effect())!=-1){//‹ó‚«”Ô†ŒŸõ
                    memset(&effect[k],0,sizeof(effect_t));//‰Šú‰»
                    effect[k].flag=1;//ƒtƒ‰ƒO‚ğ—§‚Ä‚é
                    effect[k].brt=255;//‹P“x‚ğÅ‘å’l‚É
                    effect[k].ang=rang(PI);//Šp“x‚ğƒ‰ƒ“ƒ_ƒ€‚É
                    effect[k].col=del_effect[i].col;//F‚ğƒZƒbƒg
                    effect[k].eff=1;//1‚ÍŒõƒGƒtƒFƒNƒgBŒõƒGƒtƒFƒNƒg‚ÉƒZƒbƒg‚·‚é
                    effect[k].img=img_del_effect[effect[k].col];//Á–Å‚·‚é‰æ‘œ‚ğƒZƒbƒg
                    effect[k].knd=0;//ƒGƒtƒFƒNƒg‚Ìí—Ş‚Í0”Ô(Á–ÅƒGƒtƒFƒNƒg‚Í0‚Æ‚·‚é)
                    effect[k].x=del_effect[i].x;//À•W‚ğƒZƒbƒg
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


//|||||||||||||||||||||/
//ƒ{ƒ€‚ğ“o˜^
//|||||||||||||||||||||/
void enter_bom(){
    int k;
    bom.flag=1;
    bom.cnt=0;
    bom.knd=0;
    ch.flag=0;
    ch.mutekicnt=1;//–³“G‚É
    se_flag[14]=1;//ƒLƒ…ƒC[ƒ“‰¹
    //cü
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;//ƒ{ƒ€‚Ìü‚ÌƒGƒtƒFƒNƒg
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
    //‰¡ü
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;//ƒ{ƒ€‚Ìü‚ÌƒGƒtƒFƒNƒg
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
    //ƒLƒƒƒ‰
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=2;//ƒ{ƒ€‚ÌƒLƒƒƒ‰Eü‚ÌƒGƒtƒFƒNƒg
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=-PI/2;
        effect[k].spd=0.7;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[2];//•\¦‚·‚éƒLƒƒƒ‰ƒNƒ^[ŠG‘}“ü
        effect[k].x=260;
        effect[k].y=300;
    }
}


//|||||||||||||||||||||/
//ƒ{ƒ€ŒvZ
//|||||||||||||||||||||/
void bom_calc(){
    int n,k;
	double shot_angle[4]={0,PI,PI/2,PI*1.5};//4”­ƒGƒtƒFƒNƒg‚ª”ò‚ÔŠp“x

    //ƒLƒƒƒ‰‚ª’Êí‚©‹ò‚ç‚¢ƒ{ƒ€ó‘Ô‚ÅAƒ{ƒ€‚ªƒIƒt‚È‚ç
    if((ch.flag==0||ch.flag==1) && bom.flag==0){

        //ƒ{ƒ€ƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚½‚ç
        if(CheckStatePad(configpad.bom)==1 && ch.power >= BOM_ENERGY){
            enter_bom();            //ƒ{ƒ€‚ğ”­Ë‚·‚é
            ch.power -= BOM_ENERGY; //ƒ{ƒ€‚ÌƒGƒlƒ‹ƒM[‚ğÁ”ï‚·‚é

        }
    }
    
    //ƒ{ƒ€‚ª“o˜^‚³‚ê‚Ä‚¢‚½‚ç
    if(bom.flag==1){

        //1/6•b‚É‚P‰ñ
        if(bom.cnt%10==0){
            n=(bom.cnt/10);

            if(n<4 && (k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=1;//ƒGƒtƒFƒNƒg”Ô†‚PFƒ{ƒ€‚ÌƒGƒtƒFƒNƒg
                effect[k].brt=0;
                effect[k].ang=rang(PI);//‰æ‘œ‚ÌŒü‚«‚Íƒ‰ƒ“ƒ_ƒ€
                effect[k].mvang=shot_angle[n]-PI/4;//”ò‚Ô•ûŒü
                effect[k].spd=13+rang(2);//ƒXƒs[ƒh
                effect[k].r=0.5;//‘å‚«‚³
                effect[k].eff=2;//ƒ¿ƒuƒŒƒ“ƒh
                effect[k].img= img_eff_bom[(bom.cnt/10)/3];//‰æ‘œ
                effect[k].x=ch.x;//À•W
                effect[k].y=ch.y;
            }
        }
        bom.cnt++;

        //[[[[[[[[[/
        //ƒ{ƒ€—p‚É–¾‚é‚³
        //[[[[[[[[[/
        if(bom.cnt<40){
            bright_set.brt=255-bom.cnt*5;//‰æ–Ê‚Ì–¾‚é‚³İ’è(ˆÃ‚­)
        }
        if(bom.cnt>90){
            bright_set.brt=255-40*5+(bom.cnt-90)*5;//‰æ–Ê‚Ì–¾‚é‚³İ’è(–¾‚é‚­)
        }

        //ƒ{ƒ€‚ğI—¹‚·‚é
        if(bom.cnt>130){
            bom.flag=0;
            bright_set.brt=255;
        }
    }
}


//|||||||||||||||||||||/
// ‹ò‚ç‚¢ƒ{ƒ€‚ÌƒGƒtƒFƒNƒg
//|||||||||||||||||||||/
void enter_crybom_effect(){
    int k;
    if(ch.flag==1){
        if(ch.cnt%2==0){
            if((k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=4;//‹ò‚ç‚¢ƒ{ƒ€ƒGƒtƒFƒNƒg
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


//|||||||||||||||||||||/
//ƒp[ƒeƒBƒNƒ‹‚Ì‹ó‚«”Ô†‚ğ’T‚·
//|||||||||||||||||||||/
int search_del_pa_particle() {
    for (int i = 0; i < PARTICLE_MAX; i++) {
        if (particle[i].flag == 0) {
            return i;//‚ ‚Á‚½
        }
    }
    return -1;//–³‚©‚Á‚½
}



//|||||||||||||||||||||/
//@ƒp[ƒeƒBƒNƒ‹‚ğ“o˜^
//|||||||||||||||||||||/
void CreateParticle(float x,float y) {
    int k;
    //‹ó‚«‚ğ’T‚·
    k = search_del_pa_particle();

    //‹ó‚«‚ª‚ ‚ê‚Î
    if (k != -1) {
        //ƒtƒ‰ƒO‚ğ—§‚Ä‚é
        particle[k].flag = 1;
        particle[k].color = ch.color;

        //À•W
        particle[k].x = x;
        particle[k].y = y;

        //‰Á‘¬“x
        particle[k].vx = (float)(rand() % 25 - 5) / 10.0f;//ƒ‰ƒ“ƒ_ƒ€‚È•ûŒü‚É
        particle[k].vy = (float)(rand() % 25 - 5) / 10.0f;//ƒ‰ƒ“ƒ_ƒ€‚È•ûŒü‚É
    }   
}



//|||||||||||||||||||||/
// ƒp[ƒeƒBƒNƒ‹‚ÌŒvZ
//|||||||||||||||||||||/
void particle_calc() {
    //“o˜^‚³‚ê‚Ä‚¢‚é‚Ì‚ğ’T‚·
    for (int i=0; i < PARTICLE_MAX; i++) {
        if (particle[i].flag == 1) {
            //À•WˆÚ“®
            particle[i].x += particle[i].vx;
            particle[i].y += particle[i].vy;

            //ƒJƒEƒ“ƒg‚ği‚ß‚é
            particle[i].cnt_time++;

            //Á–Å”»’è
            if (particle[i].cnt_time > 30) {
                particle[i].flag = 0;		//ƒtƒ‰ƒO‚ğ—§‚Á‚Ä‚È‚¢ó‘Ô‚É
                particle[i].cnt_time = 0;	//ŠÔ‚ğ‚O‚É
            }
        }
    }
}



//|||||||||||||||||||||/
// ƒGƒtƒFƒNƒg§Œä
//|||||||||||||||||||||/
void effect_main(){
	calc_child();
    dn_calc();              //ƒhƒK[ƒ“‚Æ‚ä‚ê‚é‰æ–Ê‚Ìˆ—
    calc_del_effect();      //Á–ÅƒGƒtƒFƒNƒg‚ÌŒvZ
    calc_effect();          //ƒGƒtƒFƒNƒg‚ÌŒvZ
    bom_calc();             //ƒ{ƒ€ŒvZ
    particle_calc();        //ƒp[ƒeƒBƒNƒ‹‚ÌŒvZ
    enter_crybom_effect();
}