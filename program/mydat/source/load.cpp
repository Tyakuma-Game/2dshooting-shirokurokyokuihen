#include "../include/GV.h"


void descending_sort();

void load(){
	int t;
	SetCreateSoundDataType( DX_SOUNDDATATYPE_MEMPRESS ) ;

	t=GetNowCount();

	//|||||||||||||||||||||/
	// ‰æ‘œ“Ç‚İ‚İ
	//|||||||||||||||||||||/

	//||||||||||/
	// ‰æ–Ê
	//||||||||||/

	//ƒ^ƒCƒgƒ‹‰æ–Ê
	img_title[0] = LoadGraph("../dat/img/title/title0.png");
	img_title[1] = LoadGraph("../dat/img/title/title1.png");
	
	//“ïˆÕ“x‘I‘ğ‰æ–Ê
	img_levelselection[0][0] = LoadGraph("../dat/img/levelselection/00.png");
	img_levelselection[0][1] = LoadGraph("../dat/img/levelselection/01.png");
	img_levelselection[0][2] = LoadGraph("../dat/img/levelselection/02.png");
	img_levelselection[1][0] = LoadGraph("../dat/img/levelselection/10.png");
	img_levelselection[1][1] = LoadGraph("../dat/img/levelselection/11.png");
	img_levelselection[1][2] = LoadGraph("../dat/img/levelselection/12.png");

	//ƒƒjƒ…[‰æ–Ê
	img_menu[0] = LoadGraph("../dat/img/menu/menu1.png");
	img_menu[1] = LoadGraph("../dat/img/menu/menu2.png");
	img_menu[2] = LoadGraph("../dat/img/menu/menu3.png");
	img_menu[3] = LoadGraph("../dat/img/menu/menu4.png");

	//ƒQ[ƒ€ƒI[ƒo[‰æ–Ê
	img_gameover[0] = LoadGraph("../dat/img/gameover/gameover1.png");
	img_gameover[1] = LoadGraph("../dat/img/gameover/gameover2.png");
	img_gameover[2] = LoadGraph("../dat/img/gameover/gameover3.png");

	//ƒŠƒUƒ‹ƒg‰æ–Ê
	img_result[0] = LoadGraph("../dat/img/result/result_bronze.png");
	img_result[1] = LoadGraph("../dat/img/result/result_silver.png");
	img_result[2] = LoadGraph("../dat/img/result/result_gold.png");
	img_result[3] = LoadGraph("../dat/img/result/result_platinum.png");
	img_result[4] = LoadGraph("../dat/img/result/result_diamond.png");

	//ƒ‰ƒ“ƒLƒ“ƒO‰æ–Ê
	img_ranking = LoadGraph("../dat/img/ranking/ranking.png");

	//ƒvƒŒƒC‰æ–Ê
	img_board[10] = LoadGraph("../dat/img/board/10.png");
	img_board[11] = LoadGraph("../dat/img/board/11.png");
	img_board[12] = LoadGraph("../dat/img/board/12.png");
	img_board[20] = LoadGraph("../dat/img/board/scoreboard.png");

	//|||||||/
	// ”wŒi‰æ‘œ
	//|||||||/

	//’Êí
	img_back[0] = LoadGraph("../dat/img/back/normal/back0.png");//ì

	//ƒ{ƒX
	img_back[10] = LoadGraph("../dat/img/back/boss/fixation.png");	 //ŒÅ’è@‘å÷
	img_back[11] = LoadGraph("../dat/img/back/boss/scroll.png");	 //ˆÚ“®@‡


	//||||||||||/
	// ƒvƒŒƒCƒ„[
	//||||||||||/

	//ƒhƒbƒgŠG
	LoadDivGraph("../dat/img/char/char1.png", 3, 3, 1, 32, 36, img_ch);

	//ü‚è‚Ì”’‚¢‹…
	img_bb = LoadGraph("../dat/img/char/ball.png");

	//–‚–@w‚Ì‰æ‘œ
	img_magic[0] = LoadGraph("../dat/img/enemy/red1.png");
	img_magic[1] = LoadGraph("../dat/img/enemy/blue1.png");

	//“–‚½‚è”»’è
	img_ch_hit = LoadGraph("../dat/img/char/atari.png");


	//||||||||||/
	// “G
	//||||||||||/

	//“GƒhƒbƒgŠG
	LoadDivGraph("../dat/img/enemy/0.png", 9, 3, 3, 32, 32, img_enemy[0]);

	//ƒ{ƒXƒhƒbƒgŠG
	img_boss = LoadGraph("../dat/img/char/boss.png");

	img_etc[1] = LoadGraph("../dat/img/enemy/hp.png");			//“G‚ÌHPƒo[
	img_etc[2] = LoadGraph("../dat/img/enemy/bossback.png");	//ƒ{ƒX‚Ì–‚–@w@‘å‰~
	img_etc[5] = LoadGraph("../dat/img/enemy/bossback3.png");	//ƒ{ƒX‚Ì–‚–@w@ŒÜäŠ¯
	img_etc[6] = LoadGraph("../dat/img/enemy/bossback4.png");	//ƒ{ƒX‚Ì–‚–@w@lŠp
	img_etc[7] = LoadGraph("../dat/img/enemy/hp_boss.png");		//ƒ{ƒX‚ÌHPƒo[


	//||||||||||/
	// ƒGƒtƒFƒNƒg
	//||||||||||/

	//ƒ{ƒ€
	img_eff_bom[0] = LoadGraph( "../dat/img/effect/bom0.png" );			//ƒ{ƒ€‚Ì‰æ‘œ‚P
	img_eff_bom[1] = LoadGraph( "../dat/img/effect/bom1.png" );			//ƒ{ƒ€‚Ì‰æ‘œ‚Q
	img_eff_bom[3] = LoadGraph( "../dat/img/bullet/bom_title0.png" );	//ƒ{ƒ€‚Ìc‘Ñ
	img_eff_bom[2] = LoadGraph( "../dat/img/char/body.png" );			//•\¦‚·‚é—§‚¿ŠG

	//“GŒ‚”j
	LoadDivGraph("../dat/img/enemy/hit_effect.png", 5, 5, 1, 140, 140, img_del_effect);

	//ƒp[ƒeƒBƒNƒ‹
	img_particle[0] = LoadGraph("../dat/img/effect/particle_red.png"); //ƒp[ƒeƒBƒNƒ‹Ô
	img_particle[1] = LoadGraph("../dat/img/effect/particle_blue.png");//ƒp[ƒeƒBƒNƒ‹Â


	//||||||||||/
	//’e‚Ì‰æ‘œ
	//||||||||||/
	
	//’e–‹‰æ‘œ“Ç‚İ‚İ
	LoadDivGraph("../dat/img/bullet/bullet_red.png", 24, 24, 1, 32, 32, img_bullet2[0]);	//ÔF
	LoadDivGraph("../dat/img/bullet/bullet_blue.png", 24, 24, 1, 32, 32, img_bullet2[1]);	//ÂF

	//ÔF’e–‹
	img_cshot[0][0] = LoadGraph("../dat/img/char/red_ch0.png");//’eŠÛ‚Ì‚æ‚¤‚È“z
	img_cshot[0][1] = LoadGraph("../dat/img/char/red_ch1.png");//‰s‚¢‚â‚Â

	//ÂF’e–‹
	img_cshot[1][0] = LoadGraph("../dat/img/char/blue_ch0.png");//’eŠÛ‚Ì‚æ‚¤‚È“z
	img_cshot[1][1] = LoadGraph("../dat/img/char/blue_ch1.png");//‰s‚¢‚â‚Â


	//||||||||||/
	// ƒAƒCƒeƒ€‰æ‘œ
	//||||||||||/
	
	LoadDivGraph("../dat/img/item/p0.png", 2, 2, 1, 35, 35, img_item[0]);
	LoadDivGraph("../dat/img/item/p1.png", 2, 2, 1, 35, 35, img_item[1]);
	LoadDivGraph("../dat/img/item/p2.png", 2, 2, 1, 15, 15, img_item[2]);
	LoadDivGraph("../dat/img/item/p3.png", 2, 2, 1, 35, 35, img_item[3]);
	LoadDivGraph("../dat/img/item/p4.png", 2, 2, 1, 35, 35, img_item[4]);
	LoadDivGraph("../dat/img/item/p5.png", 2, 2, 1, 35, 35, img_item[5]);
	

	//||||||||||/
	// ‚»‚Ì‘¼‰æ‘œ
	//||||||||||/
	
	//ƒvƒŒƒCƒ„[‚Ìc‹@išj
	img_etc[8] = LoadGraph("../dat/img/board/hoshi.png");

	//ƒXƒRƒA•\¦—p@”š
	LoadDivGraph("../dat/img/num/2.png", 10, 10, 1, 16, 18, img_num[0]);
	

	//|||||||||||||||||||||/
	// ‰¹Šy“Ç‚İ‚İ
	//|||||||||||||||||||||/

	sound_se[0]=LoadSoundMem("../dat/se/enemy_shot.wav");
	sound_se[1]=LoadSoundMem("../dat/se/enemy_death.wav");

	sound_se[2]=LoadSoundMem("../dat/se/cshot.wav");
	sound_se[3]=LoadSoundMem("../dat/se/char_death.wav");

	sound_se[8]=LoadSoundMem("../dat/se/hit.wav");

	sound_se[9]=LoadSoundMem("../dat/se/boss_death.wav");
	sound_se[11]=LoadSoundMem("../dat/se/boss_change.wav");

	sound_se[14]=LoadSoundMem("../dat/se/bom0.wav");
	sound_se[15]=LoadSoundMem("../dat/se/bom1.wav");

	sound_se[17] = LoadSoundMem("../dat/se/cursor_control.wav");
	sound_se[18] = LoadSoundMem("../dat/se/decision.wav");
	sound_se[19] = LoadSoundMem("../dat/se/color_change.wav");

	sound_se[33]=LoadSoundMem("../dat/se/lazer.wav");
	sound_se[34]=LoadSoundMem("../dat/se/item_get.wav");

	//‰¹—Êİ’è
	ChangeVolumeSoundMem( 64, sound_se[0] ) ;
	ChangeVolumeSoundMem( 64, sound_se[1] ) ;
	ChangeVolumeSoundMem( 64, sound_se[2] ) ;
	ChangeVolumeSoundMem( 64, sound_se[3] ) ;
	ChangeVolumeSoundMem( 64, sound_se[8] ) ;
	ChangeVolumeSoundMem( 64, sound_se[9] ) ;
	ChangeVolumeSoundMem( 64, sound_se[11] ) ;
	ChangeVolumeSoundMem( 64, sound_se[14] ) ;
	ChangeVolumeSoundMem( 64, sound_se[15] ) ;
	ChangeVolumeSoundMem( 64, sound_se[17] ) ;
	ChangeVolumeSoundMem( 64, sound_se[18] ) ;
	ChangeVolumeSoundMem( 86, sound_se[19] ) ;
	ChangeVolumeSoundMem( 64, sound_se[33] ) ;
	ChangeVolumeSoundMem( 64, sound_se[34] ) ;
	//(41)


	//|||||||||||||||||||||/
	//Fî•ñæ“¾
	//|||||||||||||||||||||/
	color[0] = GetColor(255,255,255);//”’
	color[1] = GetColor(  0,  0,  0);//•
	color[2] = GetColor(255,  0,  0);//Ô
	color[3] = GetColor(  0,255,  0);//—Î
	color[4] = GetColor(  0,  0,255);//Â
	color[5] = GetColor(255,255,  0);//‰©F
	color[6] = GetColor(  0,255,255);//Â—Î
	color[7] = GetColor(255,  0,255);//‡


	//|||||||||||||||||||||/
	//ƒtƒHƒ“ƒg‚ğw’è
	//|||||||||||||||||||||/
	font[0] = CreateFontToHandle( "HGPºŞ¼¯¸E" , 15 , 2 , DX_FONTTYPE_ANTIALIASING_EDGE);
}


//|||||||||||||||||||||/
//“G‚ÌoŒ»î•ñ‚ğƒGƒNƒZƒ‹‚©‚ç“Ç‚İ‚ñ‚ÅŠi”[
//|||||||||||||||||||||/
void load_story(){
	int n,num,i,fp;
	int input[64];
	char inputc[64];
	
	//“ïˆÕ“x•Ê‚Éƒtƒ@ƒCƒ‹“Ç‚İ‚İ
	char fname0[32] = { "../dat/csv/story0_normal.csv" };
	char fname1[32] = { "../dat/csv/story0_hard.csv" };
	char fname2[32] = { "../dat/csv/story0_lunatic.csv" };

	//“ïˆÕ“xŠî€‚ÅŠi”[ƒtƒ@ƒCƒ‹•ÏX
	switch (game_level){
	case normal : fp = FileRead_open(fname0); break;
	case hard   : fp = FileRead_open(fname1); break;
	case lunatic: fp = FileRead_open(fname2); break;
	}

	//¸”s‚µ‚½‚çƒGƒ‰[‚ğ•\¦
	if(fp == NULL){
		printfDx("read error\n");
		return;
	}

	//Å‰‚Ì2s“Ç‚İ”ò‚Î‚·
	for(i=0;i<2;i++){
		while(FileRead_getc(fp)!='\n');
	}

	n=0 , num=0;
	while(1){
		// ƒf[ƒ^æ‚èo‚µ
		for(i=0;i<64;i++){
			//1•¶šæ“¾‚·‚é
			inputc[i]=input[i]=FileRead_getc(fp);

			//ƒXƒ‰ƒbƒVƒ…‚ª‚ ‚ê‚Î
			if(inputc[i]=='/'){
				while(FileRead_getc(fp)!='\n');//‰üs‚Ü‚Åƒ‹[ƒv
				i=-1;						   //ƒJƒEƒ“ƒ^‚ğÅ‰‚É–ß‚µ‚Ä
				continue;					   //Ä“xÀs‚·‚é
			}

			//ƒJƒ“ƒ}‚©‰üs‚È‚ç
			if(input[i]==',' || input[i]=='\n'){
				inputc[i]='\0';	//‚»‚±‚Ü‚Å‚ğ•¶š—ñ‚Æ‚µ
				break;			//shitch‚ÅŠi”[‚·‚é
			}

			//ƒtƒ@ƒCƒ‹‚ÌI‚í‚è‚È‚ç
			if(input[i]==EOF){
				goto EXFILE;//I—¹
			}
		}

		//ƒf[ƒ^Ši”[
		switch(num){
			case 0:	enemy_order[n].cnt		=atoi(inputc);break;
			case 1:	enemy_order[n].pattern	=atoi(inputc);break;
			case 2:	enemy_order[n].knd		=atoi(inputc);break;
			case 3:	enemy_order[n].x		=atof(inputc);break;
			case 4:	enemy_order[n].y		=atof(inputc);break;
			case 5:	enemy_order[n].sp		=atof(inputc);break;
			case 6:	enemy_order[n].bltime	=atoi(inputc);break;
			case 7:	enemy_order[n].blknd	=atoi(inputc);break;
			case 8: enemy_order[n].blknd1   =atoi(inputc);break;
			case 9:	enemy_order[n].col		=atoi(inputc);break;
			case 10:enemy_order[n].hp		=atoi(inputc);break;
			case 11:enemy_order[n].wait		=atoi(inputc);break;
			case 12:enemy_order[n].item_n[0]=atoi(inputc);break;
			case 13:enemy_order[n].item_n[1]=atoi(inputc);break;
			case 14:enemy_order[n].item_n[2]=atoi(inputc);break;
			case 15:enemy_order[n].item_n[3]=atoi(inputc);break;
			case 16:enemy_order[n].item_n[4]=atoi(inputc);break;
			case 17:enemy_order[n].item_n[5]=atoi(inputc);break;
		}

		num++;
		if(num==18){
			num=0;
			n++;
		}
	}

	//I—¹
EXFILE:
	FileRead_close(fp);//ƒtƒ@ƒCƒ‹‰ğ•ú
}


//|||||||||||||||||||||/
//ƒ‰ƒ“ƒLƒ“ƒO‚Ì“Ç‚İ‚İ
//|||||||||||||||||||||/
void ranking_load() {
	int i;
	FILE* fp;//ƒtƒ@ƒCƒ‹ƒnƒ“ƒhƒ‹
	fp = fopen("../dat/ranking/score.txt", "r");//ranking‚ğŒÄ‚Ño‚·

	//’l‚ğŠi”[
	for (i = 0; i < RANKING_MAX; i++) {//‚P‚Â‚Ã‚ÂŠi”[
		fscanf(fp, "%d", &(ranking_score[i]));
	}

	fclose(fp);//ƒtƒ@ƒCƒ‹‚ğ•Â‚¶‚é
}


//|||||||||||||||||||||/
// ~‡ƒ\[ƒgˆ—
//|||||||||||||||||||||/
void descending_sort() {
	int i,j,tmp;

	for (i = 0; i < RANKING_MAX + 1; ++i) {
		for (j = i + 1; j < RANKING_MAX + 1; ++j) {
			if (ranking_score[i] < ranking_score[j]) {
				tmp = ranking_score[i];
				ranking_score[i] = ranking_score[j];
				ranking_score[j] = tmp;
			}
		}
	}
}


//|||||||||||||||||||||/
// ƒ‰ƒ“ƒLƒ“ƒO‚Ì‘‚«‚İ
//|||||||||||||||||||||/
void ranking_entry(int score) {
	int i;
	FILE* fp;//ƒtƒ@ƒCƒ‹ƒnƒ“ƒhƒ‹
	fp = fopen("../dat/ranking/score.txt", "w");//‘‚«‚İƒ‚[ƒh‚Åƒtƒ@ƒCƒ‹‚ğŒÄ‚Ño‚µ

	//ƒQ[ƒ€I—¹‚Ì‡Œv“_‚ğÅŒã”ö‚ÉŠi”[
	ranking_score[RANKING_MAX] = score;

	//~‡ƒ\[ƒg
	descending_sort();

	//“¯‚¶’l‚ğ”rœ
	for (i = 0; i < RANKING_MAX + 1; i++) {
		if (ranking_score[i] == ranking_score[i + 1]){
			ranking_score[i] = 0;//“¯‚¶’l‚ª‚ ‚Á‚½‚ç‚O‚É‚µ‚Äƒ‰ƒ“ƒLƒ“ƒOŠO‚Éo‚·
		}
	}

	//~‡ƒ\[ƒg
	descending_sort();

	//ƒtƒ@ƒCƒ‹‚É‘‚«‚İ
	for (i = 0; i < RANKING_MAX; i++) {
		fprintf(fp, "%d\n", ranking_score[i]);
	}

	//ƒtƒ@ƒCƒ‹‚ğ•Â‚¶‚é
	fclose(fp);
}