#include "../include/GV.h"

extern void shot_bullet_H000(int);extern void shot_bullet_H001(int);extern void shot_bullet_H002(int);
extern void shot_bullet_H003(int);extern void shot_bullet_H004(int);extern void shot_bullet_H005(int);
extern void shot_bullet_H006(int);extern void shot_bullet_H007(int);extern void shot_bullet_H008(int);
extern void shot_bullet_H009(int);extern void shot_bullet_H010(int);extern void shot_bullet_H011(int);
extern void shot_bullet_H012(int);extern void shot_bullet_H013(int);extern void shot_bullet_H014(int);
extern void shot_bullet_H015(int);extern void shot_bullet_H016(int);extern void shot_bullet_H017(int);


//|||||||||||||||||||||/
// æ“¾î•ñ‚©‚çUŒ‚è’i‚ğU‚è•ª‚¯
//|||||||||||||||||||||/
void (*shot_bullet[SHOT_KND_MAX])(int) ={
	shot_bullet_H000,shot_bullet_H001,shot_bullet_H002,shot_bullet_H003,shot_bullet_H004,
	shot_bullet_H005,shot_bullet_H006,shot_bullet_H007,shot_bullet_H008,shot_bullet_H009,
	shot_bullet_H010,shot_bullet_H011,shot_bullet_H012,shot_bullet_H013,shot_bullet_H014,
	shot_bullet_H015,shot_bullet_H016,shot_bullet_H017,
};


//|||||||||||||||||||||/
//n”Ô–Ú‚ÌƒVƒ‡ƒbƒg‚ğ“o˜^‚µ‚½“G‚Æ©‹@‚Æ‚ÌŠp“x‚ğ•Ô‚·
//|||||||||||||||||||||/
double shotatan2(int n){
	return atan2(ch.y-enemy[shot[n].num].y,ch.x-enemy[shot[n].num].x);
}


//|||||||||||||||||||||/
//À•W‰ñ“]
//(x0,y0)‚©‚ç(mx,my)‚ğŠî€‚ÉangŠp‰ñ“]‚µ‚½Šp“x‚ğ(x,y)‚É‚¢‚ê‚é
//|||||||||||||||||||||/
void conv_pos0(double *x, double *y, double x0, double y0, double mx, double my,double ang){
	double ox=x0-mx,oy=y0-my;
	*x=ox*cos(ang) +oy*sin(ang);
	*y=-ox*sin(ang)+oy*cos(ang);
	*x+=mx;
	*y+=my;
}


//|||||||||||||||||||||/
//‹ó‚¢‚Ä‚¢‚é’e‚ğ’T‚·
//|||||||||||||||||||||/
int shot_search(int n){
	int i;
	for(i=0;i<SHOT_BULLET_MAX;i++){
		if(shot[n].bullet[i].flag==0){
			return i;//‚ ‚Á‚½
		}
	}
	return -1;//‚È‚©‚Á‚½
}


//|||||||||||||||||||||/
// ƒVƒ‡ƒbƒg‚ğ•ú‚Â‚©
//|||||||||||||||||||||/
void shot_calc(int n){
	int i,max=0;

	//“G‚ª“|‚³‚ê‚½‚ç
	if(enemy[shot[n].num].flag!=1){
		shot[n].flag=2;//‚»‚êˆÈãƒVƒ‡ƒbƒg‚ğ“o˜^‚µ‚È‚¢ƒtƒ‰ƒO‚É
	}

	//n”Ô–Ú‚Ì’e–‹ƒf[ƒ^‚Ì’e‚ğŒvZ
	for(i=0;i<SHOT_BULLET_MAX;i++){

		//‚»‚Ì’e‚ª“o˜^‚³‚ê‚Ä‚¢‚½‚ç
		if(shot[n].bullet[i].flag>0){
			shot[n].bullet[i].x+=cos(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
			shot[n].bullet[i].y+=sin(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
			shot[n].bullet[i].cnt++;

			//‰æ–ÊŠO‚ÉŠO‚ê‚½‚ç
			if(shot[n].bullet[i].x<-60 || shot[n].bullet[i].x>FMX+60 || shot[n].bullet[i].y<-60 || shot[n].bullet[i].y>FMY+60){
				if(shot[n].bullet[i].till<shot[n].bullet[i].cnt){//Å’áÁ‚¦‚È‚¢ŠÔ‚æ‚è’·‚¯‚ê‚Î
					shot[n].bullet[i].flag=0;//Á‚·
				}
			}
		}
	}

	//Œ»İ•\¦’†‚Ì’e‚ªˆê‚Â‚Å‚à‚ ‚é‚©‚Ç‚¤‚©’²‚×‚é
	for(i=0;i<SHOT_BULLET_MAX;i++){
		if(shot[n].bullet[i].flag>0){
			return;//‚ ‚Á‚½‚çŸ‚É
		}
	}

	//Œ»İ•\¦’†‚Ì’e‚ªˆê‚Â‚à‚È‚¯‚ê‚Î
	if(enemy[shot[n].num].flag!=1){
		shot[n].flag=0;				//I—¹
		enemy[shot[n].num].flag=0;	//I—¹
	}
}


//|||||||||||||||||||||/
// ƒŒ[ƒU[§Œä
//|||||||||||||||||||||/
void lazer_calc(){
	int i;
	for(i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag>0){

			//•\¦ˆÊ’u‚ğİ’è
			lazer[i].disppt[0].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*lazer[i].haba;
			lazer[i].disppt[0].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*lazer[i].haba;
			lazer[i].disppt[1].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*lazer[i].haba;
			lazer[i].disppt[1].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*lazer[i].haba;
			lazer[i].disppt[2].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*lazer[i].haba+cos(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[2].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*lazer[i].haba+sin(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[3].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*lazer[i].haba+cos(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[3].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*lazer[i].haba+sin(lazer[i].angle)*lazer[i].length;

			//‚ ‚½‚è”ÍˆÍ‚ğİ’è
			lazer[i].outpt[0].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[0].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[1].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[1].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[2].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*lazer[i].hantei+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[2].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*lazer[i].hantei+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[3].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*lazer[i].hantei+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[3].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*lazer[i].hantei+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			
			double ymax=lazer[i].lphy.angle,ty=lazer[i].lphy.time,t=lazer[i].cnt;
			double delt=(2*ymax*t/ty - ymax*t*t/(ty*ty));

			//‰ñ“]ˆÚ“®ŠÔ“à‚È‚ç
			if(lazer[i].lphy.time!=0){
				lazer[i].angle=lazer[i].lphy.base_ang+delt;//‰ñ“]‚·‚é
			}

			//À•W•ÏŠ·‚ğ‚·‚é‚©
			if(lazer[i].lphy.conv_flag==1){
				conv_pos0(&lazer[i].startpt.x,&lazer[i].startpt.y,lazer[i].lphy.conv_x,lazer[i].lphy.conv_y,lazer[i].lphy.conv_base_x,lazer[i].lphy.conv_base_y,-delt);//ŒğŠ·
			}
			if(lazer[i].cnt>lazer[i].lphy.time){//‰ñ“]ŠÔ‚ğ‰ß‚¬‚é‚Æ‚â‚ß‚é
				lazer[i].lphy.time=0;
				lazer[i].lphy.conv_flag=0;
			}
			lazer[i].cnt++;
		}
	}
}


//|||||||||||||||||||||/
// ’e–‹ŒvZƒƒCƒ“
//|||||||||||||||||||||/
void shot_main(){
	int i;

	//’e–‹ƒf[ƒ^ŒvZ
	for(i=0;i<SHOT_MAX;i++){

		//ƒtƒ‰ƒO‚ª—§‚Á‚Ä‚¢‚ÄAİ’è‚µ‚½í—Ş‚ªŠÔˆá‚Á‚Ä‚¢‚È‚¯‚ê‚Î(ƒI[ƒo[ƒtƒ[‘Îô)
		if(shot[i].flag!=0 && 0<=shot[i].knd && shot[i].knd<SHOT_KND_MAX){
			shot_bullet[shot[i].knd](i);	//.knd‚Ì’e–‹ŒvZŠÖ”‚ğŒÄ‚ÔŠÖ”ƒ|ƒCƒ“ƒ^
			shot_calc(i);					//i”Ô–Ú‚Ì’e–‹‚ğŒvZ
			shot[i].cnt++;					//’e–‹§Œä‚ği‚ß‚é
		}
	}

	//ƒŒ[ƒU[§Œä
	lazer_calc();
}