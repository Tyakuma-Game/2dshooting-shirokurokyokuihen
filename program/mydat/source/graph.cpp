#include "../include/GV.h"

extern void graph_back_main();
extern void draw_fps(int,int);
extern void draw_func_tm(int,int);

int DrawRotaGraphF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
	return DrawRotaGraphF((float)xd,(float)yd,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}

int DrawModiGraphF( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int GrHandle, int TransFlag ){
	return DrawModiGraphF( (float)x1, (float)y1, (float)x2, (float)y2, (float)x3, (float)y3, (float)x4, (float)y4, GrHandle, TransFlag ) ;
}

int DrawRotaGraphFdF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
	return DrawRotaGraphF((float)xd+FX+dn.x,(float)yd+FY+dn.y,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}

int DrawModiGraphFdF( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int GrHandle, int TransFlag ){
	return DrawModiGraphF( (float)x1+FX+dn.x, (float)y1+FY+dn.y, (float)x2+FX+dn.x, (float)y2+FY+dn.y, 
		(float)x3+FX+dn.x, (float)y3+FY+dn.y, (float)x4+FX+dn.x, (float)y4+FY+dn.y, GrHandle, TransFlag ) ;
}

int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag) {
	return DrawGraph(xd+FX+dn.x,yd+FY+dn.y,GrHandle,TransFlag);
}


//|||||||||||||||||||||/
// ƒGƒtƒFƒNƒg•`‰æ
//|||||||||||||||||||||/
void graph_effect(int knd){
	for(int i=0;i<EFFECT_MAX;i++){
		if(effect[i].flag>0 && effect[i].knd==knd){
			if(effect[i].eff==1)//ƒGƒtƒFƒNƒg‚ªŒõƒGƒtƒFƒNƒg‚È‚ç
				SetDrawBlendMode( DX_BLENDMODE_ADD, (int)effect[i].brt) ;
			if(effect[i].eff==2)//ƒGƒtƒFƒNƒg‚ªƒ¿ƒGƒtƒFƒNƒg‚È‚ç
				SetDrawBlendMode( DX_BLENDMODE_ALPHA, (int)effect[i].brt) ;
			DrawRotaGraphFdF(effect[i].x,effect[i].y,effect[i].r,effect[i].ang,effect[i].img,TRUE);
			if(effect[i].eff==1 || effect[i].eff==2)
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
		}
	}
}


//|||||||||||||||||||||/
//child•`‰æ
//|||||||||||||||||||||/
void graph_child(){
	int i;
	for(i=0;i<CHILD_MAX;i++){
		if(child[i].flag==1){
			DrawRotaGraphFdF(child[i].x,child[i].y,child[i].range,PI2*(count%60)/60,img_etc[6],TRUE);
		}
	}
}


//|||||||||||||||||||||/
// ƒAƒCƒeƒ€•`‰æ
//|||||||||||||||||||||/
void graph_item(){
	int i;
	for(i=0;i<ITEM_MAX;i++){
		if(item[i].flag==1){
			DrawRotaGraphFdF(item[i].x,item[i].y,item[i].r,PI2*(count%120)/120,img_item[item[i].knd][1],TRUE);
			DrawRotaGraphFdF(item[i].x,item[i].y,item[i].r*0.8,-PI2*(count%120)/120,img_item[item[i].knd][1],TRUE);
			DrawRotaGraphFdF(item[i].x,item[i].y,item[i].r,0,img_item[item[i].knd][0],TRUE);
		}
	}
}


//|||||||||||||||||||||/
//“G•`‰æ
//|||||||||||||||||||||/
void graph_enemy(){
	int i;
	for(i=0;i<ENEMY_MAX;i++){
		if(enemy[i].flag==1){
			DrawRotaGraphFdF(enemy[i].x,enemy[i].y,1.0f,0.0f,img_enemy[0][enemy[i].img],TRUE);
		}
	}
}


//|||||||||||||||||||||/
// ƒ{ƒXƒGƒtƒFƒNƒg•`‰æ
//|||||||||||||||||||||/
void graph_boss_effect(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);

	DrawRotaGraphFdF(boss.dx, boss.dy, (0.4 + 0.05 * sin(PI2 / 360 * (count % 360))) * 3, 2 * PI * (count % 580) / 580, img_etc[5], TRUE);
	DrawRotaGraphFdF(boss.dx, boss.dy, (0.5 + 0.1 * sin(PI2 / 360 * (count % 360))) * 2, 2 * PI * (count % 340) / 340, img_etc[2], TRUE);
	DrawRotaGraphFdF(boss.dx + 60 * sin(PI2 / 153 * (count % 153)), boss.dy + 80 * sin(PI2 / 120 * (count % 120)), 0.4 + 0.05 * sin(PI2 / 120 * (count % 120)), 2 * PI * (count % 30) / 30, img_etc[6], TRUE);
	DrawRotaGraphFdF(boss.dx + 60 * sin(PI2 / 200 * ((count + 20) % 200)), boss.dy + 80 * sin(PI2 / 177 * ((count + 20) % 177)), 0.3 + 0.05 * sin(PI2 / 120 * (count % 120)), 2 * PI * (count % 35) / 35, img_etc[6], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraphFdF(boss.dx + 60 * sin(PI2 / 230 * ((count + 40) % 230)), boss.dy + 80 * sin(PI2 / 189 * ((count + 40) % 189)), 0.6 + 0.05 * sin(PI2 / 120 * (count % 120)), 2 * PI * (count % 40) / 40, img_etc[6], TRUE);
}


//|||||||||||||||||||||/
// ƒ{ƒX‚Ì•`‰æ
//|||||||||||||||||||||/
void graph_boss(int flg) {
	int i;

	//ƒ{ƒX‚ªoŒ»‚µ‚Ä‚¢‚È‚¢‚È‚ç
	if (boss.flag == 0) {
		return;//ˆ—I—¹
	}

	//ƒ{ƒX‚Æ–‚–@w‚Ì•`‰æ
	if(flg == 0){
		//ƒ{ƒX‚ÌƒGƒtƒFƒNƒg•\¦
		graph_boss_effect();
		//ƒ{ƒX‰æ‘œ•`‰æ
		DrawRotaGraphFdF(boss.dx, boss.dy, 1.0f, 0.0f, img_boss, TRUE);
		return;
	}

	//ƒ{ƒX‚ÌHPƒo[•\¦
	if (boss.hp_max == 0) {
		printfDx("graph_boss“à0Š„‚è\n");
		return;
	}

	//ƒ{ƒX‚ÌHPƒo[•\¦
	for(i=0;i<FMX*0.98*boss.hp/boss.hp_max;i++){
		if(boss.back_knd[boss.knd]==1){
			DrawGraphFd(3+i,2,img_etc[7],FALSE);
		}
		else{
			DrawGraphFd(3+i,2,img_etc[1],FALSE);
		}
	}
}


//|||||||||||||||||||||/
// ƒvƒŒƒCƒ„[‚Ì•`‰æ
//|||||||||||||||||||||/
void graph_ch(){
	double sx,sy,ny=(sin(2.0*PI*(count%50)/50)*3),ang=2.0*PI*(count%120)/120;

	//’á‘¬ˆÚ“®’†‚È‚ç
	if(CheckStatePad(configpad.slow)>0){
		sx=15,sy=15+ny;		//ˆø‚«Šñ‚¹‚é
		magic_time = 360;	//–‚–@w‚Ì‰ñ“]‘¬“x‚ğ’x‚­‚·‚é
	}
	else{
		sx=30,sy=30+ny;		//•’Ê‚ÌˆÊ’u‚É
		magic_time = 180;	//–‚–@w‚Ì‰ñ“]‘¬“x‚ğ•’Ê‚É‚·‚é
	}


	//–‚–@w‚ğ‘å‚«‚­‚·‚é
	if (magic_size < 1.0f)magic_size += 0.01f;
		

	//–³“G’†‚È‚ç“_–Å
	if(ch.mutekicnt%2==0){

		//–‚–@w•\¦
		DrawRotaGraphFdF(ch.x, ch.y, magic_size, PI2 * (count % magic_time) / magic_time, img_magic[ch.color], TRUE);

		//©‹@•\¦
		DrawRotaGraphFdF(ch.x,ch.y,1.0f,0.0f,img_ch[ch.img],TRUE);

		//’á‘¬ˆÚ“®’†‚È‚ç“–‚½‚è”»’è•\¦
		if(CheckStatePad(configpad.slow)>0){
			DrawRotaGraphFdF( ch.x, ch.y, 1.0f, 2.0*PI*(count%120)/120, img_ch_hit, TRUE );
		}
	}
}


//|||||||||||||||||||||/
// ©‹@‚Ì’e–‹•`‰æ
//|||||||||||||||||||||/
void graph_cshot(){
	for(int i=0;i<CSHOT_MAX;i++){
		if(cshot[i].flag>0){
			DrawRotaGraphFdF(cshot[i].x,cshot[i].y,1,cshot[i].angle+PI/2,cshot[i].img, TRUE);
		}
	}
	for(int i=0;i<2;i++){//(49)
		if(option_bb[i].flag>0){
			DrawRotaGraphFdF(option_bb[i].x,option_bb[i].y,1.0,0,option_bb[i].img,TRUE);
		}
	}
}

void myDrawSquare(double x0, double y0,double x1, double y1,double x2, double y2,double x3, double y3){
	DrawTriangle((int)x0,(int)y0,(int)x1,(int)y1,(int)x2,(int)y2,GetColor(255,0,0),TRUE);
	DrawTriangle((int)x0,(int)y0,(int)x3,(int)y3,(int)x2,(int)y2,GetColor(255,0,0),TRUE);
}


//|||||||||||||||||||||/
// ƒŒ[ƒU[‚Ì•`‰æˆ—
//|||||||||||||||||||||/
void graph_lazer(){
	int i;

	SetDrawMode( DX_DRAWMODE_BILINEAR ) ;//üŒ`•âŠ®•`‰æ

	//“G‚Ì’e–‹”•ªƒ‹[ƒv
	for(i=0;i<LAZER_MAX;i++){

		//’e–‹ƒf[ƒ^‚ªƒIƒ“‚È‚ç
		if(lazer[i].flag>0){

			SetDrawBlendMode( DX_BLENDMODE_ADD, 255);

			//”­ËˆÊ’u‚ÌƒGƒtƒFƒNƒg‚ğ•`‰æ
			DrawRotaGraphFdF(lazer[i].startpt.x,lazer[i].startpt.y,1.0,0,img_lazer_moto[lazer[i].knd][lazer[i].col],TRUE);
			
			//ƒŒ[ƒU[‚ğ•`‰æ
			DrawModiGraphFdF(lazer[i].disppt[0].x, lazer[i].disppt[0].y, lazer[i].disppt[1].x, lazer[i].disppt[1].y,
				lazer[i].disppt[2].x, lazer[i].disppt[2].y,lazer[i].disppt[3].x, lazer[i].disppt[3].y, img_lazer[lazer[i].knd][lazer[i].col],TRUE);

			SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;

		}
	}
}


//|||||||||||||||||||||/
// ƒ{ƒX‚ÌFX•`‰æ
//|||||||||||||||||||||/
void boss_assist_img(){

	int j,eff;
	double disp_angle;

	//’e–‹ƒf[ƒ^‚ªƒIƒ“‚È‚ç
	if(boss_shot.flag > 0){

		//‚»‚Ì’e–‹‚ª‚Â’e‚ÌÅ‘å”•ªƒ‹[ƒv
		for(j=0; j < 5; j++){

			//’eƒf[ƒ^‚ªƒIƒ“‚È‚ç
			if(boss_shot.assist[j].flag != 0){

				//ŒvZ•”//
				boss_shot.assist[j].x += cos(boss_shot.assist[j].angle) * boss_shot.assist[j].spd;
				boss_shot.assist[j].y += sin(boss_shot.assist[j].angle) * boss_shot.assist[j].spd;
				boss_shot.assist[j].cnt ++;

				//‚±‚±‚Ü‚Å//
				eff = 0;

				if(boss_shot.assist[j].kaiten==1){
					disp_angle = PI2*(boss_shot.assist[j].cnt%120)/120;
				}
				else{
					disp_angle = boss_shot.assist[j].angle+PI/2;
				}

				//||||||||||/
				//ƒGƒtƒFƒNƒg•”
				//||||||||||/
				if(boss_shot.assist[j].eff == 1){
					SetDrawBlendMode(DX_BLENDMODE_ADD, 255),eff = 1;
				}
				if(boss_shot.assist[j].eff == 2){
					SetDrawBlendMode(DX_BLENDMODE_ADD, 255+GetRand(100)),eff = 1 ;
				}


				//||||||||||/
				// ’e–‹•”
				//||||||||||/
				if(boss_shot.assist[j].c_flag == 0){
					DrawRotaGraphFdF((float)boss_shot.assist[j].x, (float)boss_shot.assist[j].y, 1.0, disp_angle,
						img_bullet2[boss_shot.assist[j].col][boss_shot.assist[j].knd], TRUE);
				}
				else{
					DrawRotaGraph2F((float)boss_shot.assist[j].x, (float)boss_shot.assist[j].y, (float)boss_shot.assist[j].cx, (float)boss_shot.assist[j].cy, 1.0, disp_angle,
						img_bullet2[boss_shot.assist[j].col][boss_shot.assist[j].knd], TRUE);
				}

				if(eff == 1){
					SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
				}
			}
		}
	}

	return;
}


//|||||||||||||||||||||/
//’eŠÛ‚Ì•`‰æ
//|||||||||||||||||||||/
void graph_bullet(){
	int i,j,eff;
	double disp_angle;

	SetDrawMode( DX_DRAWMODE_BILINEAR ) ;//üŒ`•âŠ®•`‰æ
	
	//“G‚Ì’e–‹”•ªƒ‹[ƒv
	for(i=0;i<SHOT_MAX;i++){

		//’e–‹ƒf[ƒ^‚ªƒIƒ“‚È‚ç
		if(shot[i].flag>0){
			//‚»‚Ì’e–‹‚ª‚Â’e‚ÌÅ‘å”•ªƒ‹[ƒv
			for(j=0;j<SHOT_BULLET_MAX;j++){
				if(shot[i].bullet[j].flag!=0){//’eƒf[ƒ^‚ªƒIƒ“‚È‚ç

					if(shot[i].bullet[j].eff==1){
						SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;
					}
					if(bullet_info[shot[i].bullet[j].knd].kaiten==1){
						disp_angle=PI2*(shot[i].bullet[j].cnt%120)/120;
					}
					else{
						disp_angle=shot[i].bullet[j].angle+PI/2;
					}

					//’e–‹‚Ì•`‰æ
					DrawRotaGraphFdF(
						shot[i].bullet[j].x, shot[i].bullet[j].y,
						1.0, disp_angle,
						img_bullet2[shot[i].bullet[j].col][shot[i].bullet[j].knd] , TRUE);//’e‚ÌF@Œ`ó

					if(shot[i].bullet[j].eff==1){
						SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
					}
				}
			}
		}
	}

	boss_assist_img();
	//ƒ{ƒX
	if(boss_shot.flag>0){					//’e–‹ƒf[ƒ^‚ªƒIƒ“‚È‚ç
		for(j=0;j<BOSS_BULLET_MAX;j++){		//‚»‚Ì’e–‹‚ª‚Â’e‚ÌÅ‘å”•ªƒ‹[ƒv
			if(boss_shot.bullet[j].flag!=0){//’eƒf[ƒ^‚ªƒIƒ“‚È‚ç
				eff=0;

				if(boss_shot.bullet[j].kaiten==1){
					disp_angle=PI2*(boss_shot.bullet[j].cnt%120)/120;
				}
				else {
					disp_angle = boss_shot.bullet[j].angle + PI / 2;
				}

				//•—‰J‚É‚à•‰‚¯‚¸—p’eƒGƒtƒFƒNƒg
				if(boss_shot.bullet[j].eff_detail==1){
					SetDrawBlendMode( DX_BLENDMODE_ADD, 100+GetRand(155)),eff=1 ;
					DrawRotaGraphFdF(
						boss_shot.bullet[j].x, boss_shot.bullet[j].y,
						1.3, disp_angle,
						img_bullet2[boss_shot.bullet[j].col][boss_shot.bullet[j].knd],TRUE);
				}

				if(boss_shot.bullet[j].eff==1){
					SetDrawBlendMode( DX_BLENDMODE_ADD, 255),eff=1 ;
				}
				if(boss_shot.bullet[j].eff==2){
					SetDrawBlendMode( DX_BLENDMODE_ADD, 255+GetRand(100)),eff=1 ;
				}

				DrawRotaGraphFdF(
					boss_shot.bullet[j].x, boss_shot.bullet[j].y,
					1.0, disp_angle,
					img_bullet2[boss_shot.bullet[j].col][boss_shot.bullet[j].knd],TRUE);
				
				
				if(eff==1){
					SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
				}
			}
		}
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);//•`‰æŒ`®‚ğ–ß‚·
}


//|||||||||||||||||||||/
//ƒ^ƒCƒgƒ‹‚Ì•\¦
//|||||||||||||||||||||/
void graph_stage_title(){
	if(stage_title.flag>0){
		SetDrawBlendMode( DX_BLENDMODE_ALPHA, stage_title.brt );
		DrawGraph(120,10,stage_title.img,TRUE);
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
	}
}


//|||||||||||||||||||||/
//ƒXƒRƒAƒ{[ƒh•\¦(41)
//|||||||||||||||||||||/
void graph_board_states(){

	//ƒXƒRƒA‚ÌÅ‘å’l•Û‘¶
	if (ch.score_max < ch.score) {
		ch.score_max = ch.score;
	}

	int i;
	int score=ch.score;
	int score_max=ch.score_max;
	int power=ch.power;
	int graze=ch.graze;
	int point=ch.point;
	int money=ch.money;
	
	//ƒXƒRƒA•\¦
	for(i=0;i<9;i++){
		DrawRotaGraph(625-15*i,30,1.0f,0.0f,img_num[0][score_max%10],TRUE);
		DrawRotaGraph(625-15*i,50,1.0f,0.0f,img_num[0][score%10],TRUE);
		score_max/=10;
		score/=10;
	}
	
	//c‹@•`‰æ
	for(i=0;i<ch.life;i++)//c‹@”•\¦
		DrawGraph(499+12*i,63,img_etc[8],TRUE);
	

	//Power•`‰æ
	DrawRotaGraph(547,91,0.9f,0.0f,img_num[0][power%10],TRUE);power/=10;
	DrawRotaGraph(536,91,0.9f,0.0f,img_num[0][power%10],TRUE);power/=10;
	DrawRotaGraph(513,91,1.0f,0.0f,img_num[0][power%10],TRUE);
	DrawString(522,82,".",color[0]);//ƒ`ƒ‡ƒ“

	//ƒOƒŒƒCƒY•\¦
	for(i=0;i<6;i++){
		DrawRotaGraph(578-14*i,111,1.0f,0.0f,img_num[0][graze%10],TRUE);
		graze/=10;
	}
	
	//ƒ|ƒCƒ“ƒg•\¦
	for(i=0;i<4;i++){
		DrawRotaGraph(550-14*i,131,1.0f,0.0f,img_num[0][point%10],TRUE);
		point/=10;
	}

	//ƒ}ƒl[•\¦
	for(i=0;i<6;i++){
		DrawRotaGraph(578-14*i,154,1.0f,0.0f,img_num[0][money%10],TRUE);
		money/=10;
	}
}


//|||||||||||||||||||||/
//ƒ{[ƒh•`‰æ
//|||||||||||||||||||||/
void graph_board(){
	DrawGraph(	0,	0,img_board[10],FALSE);
	DrawGraph(	0, 16,img_board[11],FALSE);
	DrawGraph(	0,464,img_board[12],FALSE);
	DrawGraph(416,	0,img_board[20],FALSE);

	//ƒXƒRƒAƒ{[ƒh•`‰æ
	graph_board_states();
}

//|||||||||||||||||||||/
//ƒtƒ‰ƒbƒVƒ…•`‰æ(42)
//|||||||||||||||||||||/
void graph_flash(){
	if(flash.flag>0){
		SetDrawBlendMode( DX_BLENDMODE_ALPHA, (int)(flash.brt) );
		DrawBox(FX,FY,FX+FMX,FY+FMY,color[0],TRUE);
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
	}
}


//|||||||||||||||||||||/
// Œ»İ‚Ìi‚İ‹ï‡‚ğ•\¦
//|||||||||||||||||||||/
void graph_develop(){
	DrawFormatString(0,0,GetColor(255,255,255),"%d",stage_count);
}


//|||||||||||||||||||||/
// ƒ^ƒCƒgƒ‹‰æ–Ê•`‰æ
//|||||||||||||||||||||/
void graph_title() {
	//‰æ‘œ•\¦
	DrawGraph(0, 0, img_title[title_pattern], FALSE);
}


//|||||||||||||||||||||/
// “ïˆÕ“x‘I‘ğ‰æ–Ê‚Ì•`‰æ
//|||||||||||||||||||||/
void graph_levelselection() {
	//‰æ‘œ•\¦
	DrawGraph(0, 0, img_levelselection[game_mode][game_level], FALSE);
}


//|||||||||||||||||||||/
// ƒŠƒUƒ‹ƒg‰æ–Ê•`‰æ
//|||||||||||||||||||||/
void graph_result() {
	//‰æ‘œ•\¦
	DrawGraph(0, 0, img_result[result_rank], FALSE);

	//“ïˆÕ“xƒ{[ƒiƒX
	DrawFormatString(550, 25, color[0], "“ïˆÕ“x");
	DrawFormatString(570, 42, color[2], "%d”{", bonus);

	//ƒXƒRƒA•\¦
	DrawFormatString(460, 90, color[0], "%d“_", ch.score);

	//Œo‰ßŠÔ
	DrawFormatString(460, 125, color[0], "%0.2lf•b", elapsed_time);

	//c‹@
	DrawFormatString(460, 164, color[0], "ƒ~ƒX‰ñ”F%d‰ñ", ch.miss);

	//ƒpƒ[
	DrawFormatString(460, 200, color[0], "%0.1f~%d = %d“_", (float)ch.power / 10, 100, ch.power * 10);

	//“G
	DrawFormatString(460, 237, color[0], "%d‘Ì~%d = %d“_", ch.kill_count, 100, ch.kill_count * 100);

	//‹àŠz
	DrawFormatString(460, 275, color[0], "%d~%d = %d“_", ch.money, 150, ch.money * 150);

	//ƒOƒŒƒCƒY
	DrawFormatString(460, 313, color[0], "%d~%d = %d“_", ch.graze, 200, ch.graze * 100);

	//ƒ|ƒCƒ“ƒg
	DrawFormatString(460, 350, color[0], "%d~%d = %d“_", ch.point, 1000, ch.point * 1000);

	//‡Œv“_
	DrawFormatString(400, 400, color[0], "‡Œv%9d“_ ~@%d”{", sum_score, bonus);
	DrawFormatString(460, 430, color[0], "%d“_", final_score);
}


//|||||||||||||||||||||/
// ƒ‰ƒ“ƒLƒ“ƒO•`‰æ
//|||||||||||||||||||||/
void graph_ranking() {
	//‰æ‘œ•`‰æ
	DrawGraph(0, 0, img_ranking, FALSE);

	
	//‚ ‚È‚½‚Ì“¾“_•\¦
	DrawFormatString(15, 8, color[0], "‹M•û‚Ì“¾“_");
	DrawFormatString(70, 42, color[2], "%9d“_", final_score);


	//ãˆÊ‚R–¼‚ğ•`‰æ
	for (int i = 0; i < 3; i++) {
		if (ranking_score[i] == final_score) {//“üÜ‚ª‚ ‚Á‚½‚ç
			DrawFormatString(390, 90 + (i * 37), color[2], "‚ ‚È‚½");
			DrawFormatString(460, 90 + (i * 37), color[2], "%2dˆÊ@%9d“_", i + 1, ranking_score[i]);
		}
		else {
			DrawFormatString(460, 90 + (i * 37), color[0], "%2dˆÊ@%9d“_", i + 1, ranking_score[i]);
		}
	}

	//c‚è•`‰æ
	for (int i = 3; i < RANKING_MAX; i++) {
		if (ranking_score[i] == final_score) {
			DrawFormatString(390, 105 + (i * 37), color[2], "‚ ‚È‚½");
			DrawFormatString(460, 105 + (i * 37), color[2], "%2dˆÊ@%9d“_", i + 1, ranking_score[i]);
		}
		else {
			DrawFormatString(460, 105 + (i * 37), color[0], "%2dˆÊ@%9d“_", i + 1, ranking_score[i]);
		}
	}
}


//|||||||||||||||||||||/
//@ƒp[ƒeƒBƒNƒ‹‚Ì•`‰æ
//|||||||||||||||||||||/
void graph_particle() {

	//“o˜^‚³‚ê‚Ä‚¢‚é‚Ì‚ğ’T‚·
	for (int i=0; i < PARTICLE_MAX; i++) {
		if (particle[i].flag == 1) {
			//‰æ‘œ‚ğ•`‰æ
			DrawGraph(particle[i].x, particle[i].y, img_particle[particle[i].color], TRUE);
		}
	}
}


//|||||||||||||||||||||/
// •`‰æƒƒCƒ“
//|||||||||||||||||||||/
void graph_main(){

	if (bright_set.brt != 255) {
		SetDrawBright(bright_set.brt, bright_set.brt, bright_set.brt);
	}

	graph_back_main();	//”wŒi•`‰æƒƒCƒ“
	graph_effect(0);	//“G‚ª€‚ÊƒGƒtƒFƒNƒg

	if (bright_set.brt != 255) {
		SetDrawBright(255, 255, 255);
	}

	//‹ò‚ç‚¢ƒ{ƒ€‚ÌƒGƒtƒFƒNƒg
	graph_effect(4);

	if (bright_set.brt != 255) {
		SetDrawBright(bright_set.brt, bright_set.brt, bright_set.brt);
	}

	graph_child();	//ƒ{ƒX‚ÌƒAƒVƒXƒg•`‰æ
	graph_item();	//ƒAƒCƒeƒ€•`‰æ

	graph_particle();//ƒp[ƒeƒBƒNƒ‹•`‰æ

	graph_boss(0);	//ƒ{ƒX‰æ‘œ•`‰æ
	graph_enemy();	//“G‚Ì•`‰æ
	graph_cshot();	//©‹@ƒVƒ‡ƒbƒg‚Ì•`‰æ

	if (bright_set.brt != 255) {
		SetDrawBright(255, 255, 255);
	}

	//©‹@‚Ì•`‰æ
	graph_ch();

	if (bright_set.brt != 255) {
		SetDrawBright(bright_set.brt, bright_set.brt, bright_set.brt);
	}
	
	graph_lazer();	//ƒŒ[ƒU[‚Ì•`‰æ
	graph_bullet();	//’e–‹‚Ì•`‰æ
	
	graph_boss(1);	//ƒ{ƒX‘Ì—Íƒo[•\¦

	if (bright_set.brt != 255) {
		SetDrawBright(255, 255, 255);
	}

	graph_effect(1);	//ƒ{ƒ€‚ÌƒGƒtƒFƒNƒg
	graph_effect(2);	//ƒ{ƒ€ü‚ÌƒGƒtƒFƒNƒg
	graph_effect(3);	//ƒ{ƒ€ƒLƒƒƒ‰‚ÌƒGƒtƒFƒNƒg
	graph_stage_title();//ƒ^ƒCƒgƒ‹‚Ì•\¦
	graph_board();		//ƒ{[ƒh‚Ì•`‰æ
	graph_flash();		//ƒtƒ‰ƒbƒVƒ…•`‰æ

	graph_develop();		//Ê“x‚ğ•\¦
	draw_fps(0,465);		//fps•`‰æ
	draw_func_tm(450,250);	//ˆ—ŠÔ•`‰æ
}