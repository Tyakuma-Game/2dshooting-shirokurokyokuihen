#include "../include/GV.h"
#include "../include/func.h"

#define V0 10.0
 

//|||||||||||||||||||||/
//•¨—“IŒvZ‚ğ“_‚Æ‹——£w’è‚Å“o˜^(w’èŠÔt‚Å’èˆÊ’u‚É)
//|||||||||||||||||||||/
void input_phy_pos(double x,double y,int t){//t=ˆÚ“®‚É‚©‚¯‚éŠÔ
	double ymax_x,ymax_y;

	if (t == 0)t=1;

	boss.phy.flag=1;			//“o˜^ƒIƒ“
	boss.phy.cnt=0;				//ƒJƒEƒ“ƒ^‰Šú‰»
	boss.phy.set_t=t;			//ˆÚ“®‚É‚©‚¯‚éŠÔ‚ğƒZƒbƒg
	ymax_x=boss.x-x;			//ˆÚ“®‚µ‚½‚¢…•½‹——£
	boss.phy.v0x=2*ymax_x/t;	//…•½¬•ª‚Ì‰‘¬“x
	boss.phy.ax =2*ymax_x/(t*t);//…•½¬•ª‚Ì‰Á‘¬“x
	boss.phy.prex=boss.x;		//‰ŠúxÀ•W
	ymax_y=boss.y-y;			//ˆÚ“®‚µ‚½‚¢‰”’¼‹——£
	boss.phy.v0y=2*ymax_y/t;	//‰”’¼¬•ª‚Ì‰‘¬“x
	boss.phy.ay =2*ymax_y/(t*t);//‰”’¼¬•ª‚Ì‰Á‘¬“x
	boss.phy.prey=boss.y;		//‰ŠúyÀ•W
}


//|||||||||||||||||||||/
//ƒŒ[ƒU[‚Ì•¨—“IŒvZ“o˜^
//|||||||||||||||||||||/
void input_lphy(lazer_t *laz, int time, double angle){
	laz->lphy.angle   =angle;
	laz->lphy.base_ang=laz->angle;
	laz->lphy.time    =time;
}


//|||||||||||||||||||||/
//Œ»İ‚ÌˆÊ’u‚©‚çdist—£‚ê‚½ˆÊ’u‚ÉtƒJƒEƒ“ƒg‚ÅˆÚ“®
//|||||||||||||||||||||/
int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t){
	int i=0;
	double x,y,angle;
	for(i=0;i<1000;i++){
		x=boss.x,y=boss.y;	//¡‚Ìƒ{ƒX‚ÌˆÊ’u‚ğƒZƒbƒg
		angle=rang(PI);		//“K“–‚ÉŒü‚©‚¤•ûŒü‚ğŒˆ‚ß‚é

		//‚»‚¿‚ç‚ÉˆÚ“®‚³‚¹‚é
		x+=cos(angle)*dist;
		y+=sin(angle)*dist;

		//‚»‚Ì“_‚ªˆÚ“®‰Â”\”ÍˆÍ‚È‚ç
		if(x1<=x&&x<=x2 && y1<=y&&y<=y2){
			input_phy_pos(x,y,t);
			return 0;
		}
	}
	return -1;//1000‰ñ‚µ‚Äƒ_ƒ‚È‚çƒGƒ‰[
}


int search_child(){//‹ó‚«”Ô†‚ğ•Ô‚·
	for(int i=0;i<CHILD_MAX;i++){
		if(child[i].flag==0)
			return i;
	}
	return -1;
}

int search_boss_shot(){//‹ó‚«”Ô†‚ğ•Ô‚·
	for(int i=0;i<BOSS_BULLET_MAX;i++){
		if(boss_shot.bullet[i].flag==0)
			return i;
	}
	return -1;
}
int search_lazer(){//‹ó‚«”Ô†‚ğ•Ô‚·
	for(int i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag==0)
			return i;
	}
	return -1;
}
double bossatan2(){//©‹@‚Æ“G‚Æ‚Ì¬‚·Šp“x
	return atan2(ch.y-boss.y,ch.x-boss.x);
}
double bossatan3(int k,double x,double y){//w’èÀ•W‚Æ’e‚Æ‚Ì¬‚·Šp“x
	return atan2(y-boss_shot.bullet[k].y,x-boss_shot.bullet[k].x);
}


//|||||||||||||||||||||/
//•¨—“IŒvZ‚ğ‚³‚¹‚é“o˜^‚ğ‚·‚é(w’èŠÔt‚Å’èˆÊ’u‚É–ß‚·)
//|||||||||||||||||||||/
void input_phy(int t){
	double ymax_x,ymax_y;

	if(t==0)t=1;

	ymax_x = boss.x - BOSS_POS_X;	//ˆÚ“®‚µ‚½‚¢…•½‹——£
	ymax_y = boss.y - BOSS_POS_Y;	//ˆÚ“®‚µ‚½‚¢‰”’¼‹——£

	boss.phy.flag=1;			//“o˜^ƒIƒ“
	boss.phy.cnt=0;				//ƒJƒEƒ“ƒ^‰Šú‰»
	boss.phy.set_t=t;			//ˆÚ“®‚É‚©‚¯‚éŠÔ‚ğƒZƒbƒg

	boss.phy.v0x=2*ymax_x/t;	//…•½¬•ª‚Ì‰‘¬“x
	boss.phy.ax =2*ymax_x/(t*t);//…•½¬•ª‚Ì‰Á‘¬“x
	boss.phy.prex=boss.x;		//‰ŠúxÀ•W
	boss.phy.prey = boss.y;		//‰ŠúyÀ•W

	boss.phy.v0y=2*ymax_y/t;	//‰”’¼¬•ª‚Ì‰‘¬“x
	boss.phy.ay =2*ymax_y/(t*t);//‰”’¼¬•ª‚Ì‰Á‘¬“x
	
}


//|||||||||||||||||||||/
//•¨—“IƒLƒƒƒ‰ƒNƒ^ˆÚ“®ŒvZ
//|||||||||||||||||||||/
void calc_phy(){
	double t=boss.phy.cnt;
	boss.x=boss.phy.prex-((boss.phy.v0x*t)-0.5*boss.phy.ax*t*t);//Œ»İ‚¢‚é‚×‚«xÀ•WŒvZ
	boss.y=boss.phy.prey-((boss.phy.v0y*t)-0.5*boss.phy.ay*t*t);//Œ»İ‚¢‚é‚×‚«yÀ•WŒvZ
	boss.phy.cnt++;

	//ˆÚ“®‚É‚©‚¯‚éŠÔ•ª‚É‚È‚Á‚½‚ç
	if(boss.phy.cnt>=boss.phy.set_t){
		boss.phy.flag=0;//ƒIƒt
	}
}


//|||||||||||||||||||||/
//ƒ{ƒX‚Ì’e–‹‚ğŒvZ‚·‚é
//|||||||||||||||||||||/
void boss_shot_calc(){
	int i;
	boss.endtime--;

	//ƒ{ƒX‚Ì‘Ì—Í‚ª‚È‚­‚È‚Á‚½‚ç
	if(boss.endtime<0){
		boss.hp=0;//ŒvZI—¹
	}

	//ˆÚ“®ŒvZ
	for(i=0;i<BOSS_BULLET_MAX;i++){

		if(boss_shot.bullet[i].flag>0){
			boss_shot.bullet[i].x+=cos(boss_shot.bullet[i].angle)*boss_shot.bullet[i].spd;
			boss_shot.bullet[i].y+=sin(boss_shot.bullet[i].angle)*boss_shot.bullet[i].spd;
			boss_shot.bullet[i].cnt++;

			if(boss_shot.bullet[i].cnt>boss_shot.bullet[i].till){
				if(boss_shot.bullet[i].x<-50 || boss_shot.bullet[i].x>FMX+50 ||
					boss_shot.bullet[i].y<-50 || boss_shot.bullet[i].y>FMY+50)
					boss_shot.bullet[i].flag=0;
			}
		}
	}
	boss_shot.cnt++;
}


//|||||||||||||||||||||/
//’e–‹‚ğƒZƒbƒg
//|||||||||||||||||||||/
void enter_boss_shot(int flg){
	
	//’eî•ñ‰Šú‰»
	memset(&boss_shot , 0, sizeof(boss_shot_t));
	
	//game‚ÌƒŠƒXƒ^[ƒg—p‰Šú‰»‚¾‚Á‚½‚ç
	if (flg==1)return;//I—¹

	boss_shot.flag=1;
	boss.wtime=0;//‘Ò‹@ŠÔ0
	boss.state=2;//’e–‹’†ó‘Ô‚É
	boss.hp=boss.set_hp[boss.knd];//HPİ’è
	boss.hp_max=boss.hp;
}


//|||||||||||||||||||||/
//ƒ{ƒX‚ğƒZƒbƒg
//|||||||||||||||||||||/
void enter_boss(int num){

	//’†ƒ{ƒXŠJn‚Ì‚Í
	if(num==0){
		memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);	//G‹›“G‚ğÁ‚·
		memset(shot,0,sizeof(shot_t)*SHOT_MAX);		//’e–‹‚ğÁ‚·

		//ƒ{ƒX‚Ì‰ŠúÀ•W
		boss.x=FMX/2;
		boss.y=-30;
		
		//Å‰‚È‚ç
		if(stage_count==boss.appear_count[0]){
			boss.knd=-1;//’e–‹‚Ìí—Ş
		}
	}


	boss.phy.flag=1;
	boss.phy.flag=1;
	boss.flag=1;
	boss.hagoromo=0;//î‚ğL‚°‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
	boss.endtime=99*60;//c‚èŠÔ
	boss.state=1;//‘Ò‹@’†ó‘Ô‚É
	boss.cnt=0;
	boss.graph_flag=0;//•`‰æƒtƒ‰ƒO‚ğ–ß‚·
	boss.knd++;
	boss.wtime=0;//‘Ò‹@ŠÔ‚ğ‰Šú‰»
	memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);//ƒŒ[ƒU[î•ñ‚ğ‰Šú‰»
	input_phy(60);//60ƒJƒEƒ“ƒg‚©‚¯‚Ä•¨—“IŒvZ‚Å’èˆÊ’u‚É–ß‚·
}


//|||||||||||||||||||||/
//ƒ{ƒX‚Ì‘Ò‹@ˆ—
//|||||||||||||||||||||/
void waitandenter(){
	int t=150;
	boss.wtime++;

	//140ƒJƒEƒ“ƒg‘Ò‹@‚µ‚½‚ç’e–‹ƒZƒbƒg
	if(boss.wtime>t){
		enter_boss_shot(0);
	}
}


//|||||||||||||||||||||/
// ƒ{ƒXÀ•WŒvZ
//|||||||||||||||||||||/
void calc_boss(){
	boss.dx=boss.x;
	boss.dy=boss.y+sin(PI2/130*(count%130))*10;
}


//|||||||||||||||||||||/
//ƒ{ƒX‚Ì’e–‹ƒƒCƒ“
//|||||||||||||||||||||/
void boss_shot_main(){

	//ŠJnŠÔ‚È‚ç
	if((stage_count==boss.appear_count[0] || stage_count==boss.appear_count[1]) && boss.flag==0){
		enter_boss(0);//í“¬ŠJn
	}

	//ƒ{ƒX‚ª“o˜^‚³‚ê‚Ä–³‚¯‚ê‚Îˆ—I—¹
	if(boss.flag==0){
		return;
	}

	//ƒ{ƒXÀ•WŒvZ
	calc_boss();

	//•¨—‰‰ZˆÚ“®ƒIƒ“‚È‚ç
	if(boss.phy.flag==1){
		calc_phy();//•¨—ŒvZ
	}

	//’e–‹’†‚Å‘Ì—Í‚ª–³‚­‚È‚Á‚½‚ç
	if(boss.state==2 && (boss.hp<=0 || boss.endtime<=0)){
        se_flag[1]=1;//“G‚Ìƒsƒ`ƒ…ƒŠ‰¹
		se_flag[11]=1;
		input_phy(30);//30ƒJƒEƒ“ƒg‚Å’èˆÊ’u‚É–ß‚·


		memset(&boss_shot,0,sizeof(boss_shot_t));//ƒ{ƒX‚Ì’e–‹î•ñ‚ğ‰Šú‰»
		memset(&lazer,0,sizeof(lazer_t)*LAZER_MAX);//ƒ{ƒX‚ÌƒŒ[ƒU[î•ñ‚ğ‰Šú‰»
		
		flash.flag=0;//ƒtƒ‰ƒbƒVƒ…‚ğÁ‚·

		//o‚·‚×‚«’e–‹‚ğ‚¾‚µ‚«‚Á‚½
		if(boss.knd==boss.danmaku_num[0] || boss.knd==boss.danmaku_num[1]){
			boss.flag=0;//Á‚·
			enter_dn(10,40);//(45)
			se_flag[9]=1;//ƒ{ƒX‚ª€‚ñ‚¾‰¹
			return;
		}
		else{
			enter_boss(1);//Ÿ‚Ì’e–‹‚ğ“o˜^
		}
	}

	//’e–‹ŠÔ‚Ì‘Ò‹@ŠÔ‚È‚ç
	if(boss.state==1){
		waitandenter();//‘Ò‹@ˆ—
	}

	//’e–‹’†‚È‚ç
	if(boss.state==2){
		//“ïˆÕ“x‚²‚Æ‚Ég—p‚·‚é’e–‹‚ğ•ª‚¯‚é
		switch (game_level){
		case normal: boss_shot_bullet_normal[boss.knd]();	break;
		case hard:   boss_shot_bullet_hard[boss.knd]();		break;
		case lunatic:boss_shot_bullet_lunatic[boss.knd]();	break;
		}
		boss_shot_calc();//’e–‹ŒvZ
	}

	//ƒ{ƒX‚Ì§ŒäƒJƒEƒ“ƒg
	boss.cnt++;
}