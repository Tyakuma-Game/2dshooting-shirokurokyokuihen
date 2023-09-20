#include "../include/GV.h"

int cshot0num[2]  ={2,4};
int cshot0pos_x[4]={-10, 10,-30, 30};
int cshot0pos_y[4]={-30,-30,-10,-10};

//ƒIƒvƒVƒ‡ƒ“ƒ{ƒ“ƒ{ƒ“‚ÌÀ•W
#define OPTION_X 25
#define OPTION_Y 35

int option0num[2]  ={2,4};
double option0ang[4] = {-PI/2,-PI/2,-PI/2-PI/4,-PI/2+PI/4};//ƒIƒvƒVƒ‡ƒ“‚Ì”­ËŠp“x(49)


//|||||||||||||||||||||/
//©‹@ƒVƒ‡ƒbƒg‚Ì“o˜^‰Â”\”Ô†‚ğ•Ô‚·
//|||||||||||||||||||||/
int search_cshot(){
	for(int i=0;i<CSHOT_MAX;i++){
		if (cshot[i].flag == 0) {
			return i;//‚ ‚Á‚½
		}
	}
	return -1;//‚È‚©‚Á‚½
}


//|||||||||||||||||||||/
//’ÊíƒVƒ‡ƒbƒg“o˜^
//|||||||||||||||||||||/
void ch0_shot_pattern(){
	int k;
	int n=cshot0num[ch.power<200?0:1];

	for(int i=0;i<n;i++){
		if((k=search_cshot())!=-1){
			cshot[k].flag=1;
			cshot[k].cnt=0;
			cshot[k].angle=-PI/2;
			cshot[k].spd=20;
			cshot[k].x=ch.x+cshot0pos_x[i];
			cshot[k].y=ch.y+cshot0pos_y[i];
			cshot[k].power= (n<2 ? 20 : 12) +ch.power/100;//2‹Ø‚È‚ç20,4‹Ø‚È‚ç12(50)
			cshot[k].knd=0;
			
			//Fó‘Ô‚É‰‚¶‚Ä‰æ‘œ‚ğØ‚è‘Ö‚¦
			cshot[k].img = img_cshot[ch.color][0];
		}
	}

	se_flag[2]=1;//”­Ë‰¹ƒIƒ“
	
	if(ch.power>=100){
		for(int i=0;i<(ch.power<300?2:4);i++){
			if((k=search_cshot())!=-1){
				cshot[k].flag=1;
				cshot[k].cnt=0;
				cshot[k].angle=option0ang[i];
				cshot[k].spd=20;
				cshot[k].x=option_bb[i%2].x;
				cshot[k].y=option_bb[i%2].y;
				cshot[k].power=10-7*(i/2);//ƒ}ƒCƒiƒX‚É‚È‚ç‚È‚¢‚æ‚¤’ˆÓ(50)
				cshot[k].knd=1;
				
				//Fó‘Ô‚É‰‚¶‚Ä‰æ‘œ‚ğØ‚è‘Ö‚¦
				cshot[k].img = img_cshot[ch.color][1];
			}
		}
	}
}


//|||||||||||||||||||||/
//’á‘¬’ÊíƒVƒ‡ƒbƒg“o˜^
//|||||||||||||||||||||/
void ch1_shot_pattern(){
	int k;
	int n=cshot0num[ch.power<200?0:1];
	for(int i=0;i<n;i++){
		if((k=search_cshot())!=-1){
			cshot[k].flag=1;
			cshot[k].cnt=0;
			cshot[k].angle=-PI/2;
			cshot[k].spd=20;
			cshot[k].x=ch.x+cshot0pos_x[i]/3;//’á‘¬’†‚È‚çˆÊ’u‚ğ’†S‘¤‚Ö
			cshot[k].y=ch.y+cshot0pos_y[i]/2;
			cshot[k].power= (n<2 ? 20 : 12) +ch.power/100;//2‹Ø‚È‚ç20,4‹Ø‚È‚ç12(50)
			cshot[k].knd=0;

			//Fó‘Ô‚É‰‚¶‚Ä‰æ‘œ‚ğØ‚è‘Ö‚¦
			cshot[k].img = img_cshot[ch.color][0];
		}
	}
	se_flag[2]=1;//”­Ë‰¹ƒIƒ“

	if(ch.power>=100){
		for(int i=0;i<(ch.power<300?2:4);i++){
			if((k=search_cshot())!=-1){
				cshot[k].flag=1;
				cshot[k].cnt=0;
				cshot[k].angle=option0ang[i];
				cshot[k].spd=20;
				cshot[k].x=option_bb[i%2].x;
				cshot[k].y=option_bb[i%2].y;
				cshot[k].power=10-7*(i/2);//ƒ}ƒCƒiƒX‚É‚È‚ç‚È‚¢‚æ‚¤’ˆÓ(50)
				cshot[k].knd=1;
				
				//Fó‘Ô‚É‰‚¶‚Ä‰æ‘œ‚ğØ‚è‘Ö‚¦
				cshot[k].img = img_cshot[ch.color][1];
			}
		}
	}
}


//|||||||||||||||||||||/
//ƒIƒvƒVƒ‡ƒ“‚Ì‚Ú‚ñ‚Ú‚ñŒvZ
//|||||||||||||||||||||/
void calc_option_bb(){

	//ƒpƒ[100ˆÈã‚È‚çƒIƒvƒVƒ‡ƒ“‚ğ‚Â‚¯‚é
	if(ch.power>=100){
		for(int i=0;i<2;i++){
			//’á‘¬ˆÚ“®’†‚¶‚á‚È‚¢‚È‚ç
			if(CheckStatePad(configpad.slow)==0){
				option_bb[i].x=ch.x+OPTION_X*(i==0 ? -1 : 1);
				option_bb[i].y=ch.y+OPTION_Y+sin(PI2/150*option_bb[i].cnt)*20;
			}
			else{
				option_bb[i].x=ch.x+OPTION_X/2*(i==0 ? -1 : 1);
				option_bb[i].y=ch.y+OPTION_Y/2;
			}
			option_bb[i].cnt++;
		}
		if(option_bb[0].flag==0)
			option_bb[0].flag = option_bb[1].flag = 1;
	}
	else{
		if(option_bb[0].flag==1)
			option_bb[0].flag = option_bb[1].flag = 0;
	}
}


//|||||||||||||||||||||/
//ƒVƒ‡ƒbƒg“o˜^•”
//|||||||||||||||||||||/
void enter_shot(){

	//ƒVƒ‡ƒbƒgƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚Ä‚¢‚½‚ç
	if(CheckStatePad(configpad.shot)>0){
		ch.shot_cnt++;

		//3ƒJƒEƒ“ƒg‚É1‰ñ
		if(ch.shot_cnt%3==0){
			//’á‘¬ˆÚ“®’†‚È‚ç
			if (CheckStatePad(configpad.slow) > 0){
				ch1_shot_pattern();//’á‘¬”­Ë
			}
			else{
				ch0_shot_pattern();//’Êí”­Ë
			}
		}
	}
	else{
		ch.shot_cnt=0;
	}
}


//|||||||||||||||||||||/
//ˆê”Ô‹ß‚¢“G‚ğ’T‚µ‚ÄŠp“x‚ğƒZƒbƒg‚·‚é
//|||||||||||||||||||||/
void calc_homing(int k){
	int i,d, num=-1, min=-1;
	double x,y;

	//ƒ{ƒX‚ª‹‚È‚¢
	if(boss.flag==0){
		for(i=0;i<ENEMY_MAX;i++){//“G‚Ì‘”•ª
			if(enemy[i].flag==1){
				x=(enemy[i].x-cshot[k].x);
				y=(enemy[i].y-cshot[k].y);
				d=(int)(x*x+y*y);//ƒVƒ‡ƒbƒg‚Æ“G‚Ì‹——£

				//ŒvZŒ‹‰Ê‚ªÅ¬’l‚©‚Ü‚¾Ši”[‚µ‚Ä‚¢‚È‚¢‚È‚ç
				if(d<min || min==-1){
					num=i;//”Ô†‹L˜^
					min=d;//‹——£‹L˜^
				}
			}
		}
	}

	//‹ß‚¢“G‚ªŒ©‚Â‚©‚Á‚½‚çA‚ ‚é‚¢‚Íƒ{ƒX‚ª‚¢‚ÄAHP‚ª‚ ‚é‚Æ‚«‚ÍŠp“x‚ğƒZƒbƒg
	if(num!=-1 || boss.flag==1 && boss.hp>0){
		if(boss.flag==0){
			x=enemy[num].x-cshot[k].x;
			y=enemy[num].y-cshot[k].y;
		}
		else{
			x=boss.x-cshot[k].x;
			y=boss.y-cshot[k].y;
		}
		cshot[k].angle=atan2(y,x);
	}
}


//|||||||||||||||||||||/
//ƒVƒ‡ƒbƒg‚ÌˆÚ“®ŒvZ
//|||||||||||||||||||||/
void calc_cshot(){
	for(int i=0;i<CSHOT_MAX;i++){
		if(cshot[i].flag==1){
			int dranx=(int)(cshot[i].spd+11/2),drany=(int)(cshot[i].spd+55/2);
			
			//ƒz[ƒ~ƒ“ƒOŒvZ
			if(cshot[i].knd==1){
				calc_homing(i);
			}

			//ÀŒvZ
			cshot[i].x+=cos(cshot[i].angle)*cshot[i].spd;
			cshot[i].y+=sin(cshot[i].angle)*cshot[i].spd;
			cshot[i].cnt++;

			//‰æ–Ê‚©‚çŠO‚ê‚½‚ç
			if(cshot[i].x<-dranx || cshot[i].x>FMX+dranx || cshot[i].y<-drany || cshot[i].y>FMY+drany){
				cshot[i].flag=0;//Á‚·
			}
		}
	}
}



//|||||||||||||||||||||/
//ƒLƒƒƒ‰ƒVƒ‡ƒbƒg§Œä
//|||||||||||||||||||||/
void cshot_main(){
	calc_option_bb();	//ƒIƒvƒVƒ‡ƒ“‚Ì‚Ú‚ñ‚Ú‚ñŒvZ(49)
	calc_cshot();		//ƒVƒ‡ƒbƒg‚Ì‹N“®ŒvZ
	enter_shot();		//ƒVƒ‡ƒbƒg“o˜^
}
