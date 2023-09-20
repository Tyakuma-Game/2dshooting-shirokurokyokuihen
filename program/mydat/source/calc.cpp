#include "../include/GV.h"

//|||||||||||||||||||||/
// Í–¼•\¦ˆ—
//|||||||||||||||||||||/
void calc_stage_title(){

	//¡‚ª•\¦ŠJn‚È‚ç
	if(stage_title.appear_cnt==stage_count){
		stage_title.flag=1;//ƒtƒ‰ƒO‚ğ•\¦‚·‚é‚É•ÏX

		//‘Î‰‚µ‚½‰æ‘œ‚ğ“Ç‚İ‚Ş
		stage_title.img = LoadGraph("../dat/img/board/subject1.png");
	}

	//ƒtƒ‰ƒO‚ª—§‚Á‚Ä‚È‚¢‚È‚ç‚±‚±‚ÅI—¹
	if (stage_title.flag == 0) {
		return;//ˆ—I—¹
	}

	//Å‰‚Ì128‚ÌŠÔ’iX–¾‚é‚­
	if (stage_title.cnt < 128) {
		stage_title.brt += 2;
	}
	
	//’iXˆÃ‚­
	if(stage_title.cnt>128+128){
		stage_title.brt-=2;
	}

	//I‚è
	if(stage_title.cnt>128+128+128){
		stage_title.cnt=0;	//Œo‰ßŠÔ‚ğ‚O‚É
		stage_title.brt=0;	//–¾‚é‚³’²®’l‚ğ‚O‚É
		stage_title.flag=0;	//ƒtƒ‰ƒO‚ğ—§‚Á‚Ä‚È‚¢ó‘Ô‚É
		DeleteGraph(stage_title.img);//‰æ‘œ‰ğ•ú

		return;//ˆ—I—¹
	}

	stage_title.cnt++;
}


//|||||||||||||||||||||/
//ƒAƒCƒeƒ€‚Ì‹zûˆ—
//|||||||||||||||||||||/
void calc_item_indraw(int i){
	double v = item[i].state ? 8 : 3;					//state1‚È‚çƒXƒs[ƒh8Aˆá‚¤‚È‚ç2
	double angle=atan2(ch.y-item[i].y,ch.x-item[i].x);	//©‹@‚Ö‚ÌŠp“x‚ğŒvZ‚µ‚Ä
	item[i].x += cos(angle)*v;
	item[i].y += sin(angle)*v;
}


//|||||||||||||||||||||/
//ƒAƒCƒeƒ€ˆÚ“®‚È‚ÇŒvZ
//|||||||||||||||||||||/
void calc_item(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].flag>0){
			if(item[i].state==0){
				//‹zûó‘Ô‚È‚ç
				if(ch.y<ITEM_GET_BORDER_LINE){
					item[i].state=1;
				}
			}

			//•’Ê‚Ìó‘Ô‚È‚ç
			if(item[i].state==0){
				double x=ch.x-item[i].x,y=ch.y-item[i].y;

				//’á‘¬ó‘Ô‚Å©‹@•t‹ß‚È‚ç
				if(CheckStatePad(configpad.slow)>0 &&
						x*x+y*y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE){
					calc_item_indraw(i);//‹zû
				}
				else{
					if(item[i].v<2.5){//‘¬“xƒAƒbƒv
						item[i].v+=0.06;
					}
					item[i].y+=item[i].v;//ˆÚ“®
				}
			}
			else{//‹zûó‘Ô‚È‚ç
				calc_item_indraw(i);
			}

			item[i].cnt++;

			if(item[i].y>FMY+50){
				item[i].flag=0;
			}
		}
	}
}


//|||||||||||||||||||||/
//ƒtƒ‰ƒbƒVƒ…(42)
//|||||||||||||||||||||/
void calc_flash(){
	if(flash.flag>0){
		if(flash.knd==0){

			if (flash.cnt == 0) {
				flash.brt = 0;
			}

			if(flash.cnt<flash.to_cnt){
				flash.brt+=255.0/flash.to_cnt;
			}
			else{
				flash.brt-=255.0/flash.to_cnt;
			}
		}
		if(flash.knd==1){
			if (flash.cnt == 0) {
				flash.brt = 255;
			}
			flash.brt-=255.0/flash.to_cnt;
		}

		flash.cnt++;

		if(flash.knd==0){
			if(flash.cnt>flash.to_cnt*2){
				flash.flag=0;
			}
		}
		if(flash.knd==1){
			if(flash.cnt>flash.to_cnt){
				flash.flag=0;
			}
		}
	}
}


//|||||||||||||||||||||/
// ƒQ[ƒ€’†‚Ìˆ—
//|||||||||||||||||||||/
void calc_game_ply() {
	//ŠÖ”§Œä—p•Ï”
	if (boss.flag == 0) {
		stage_count++;
	}

	//ƒŠƒUƒ‹ƒg‰æ–Ê‚ğ•\¦‚·‚é‚©”»’è
	if (stage_count > 2900) {
		func_state = result;//ê–Ê‚ğƒŠƒUƒ‹ƒg‰æ–Ê‚É•ÏX
	}

	//ƒQ[ƒ€ƒI[ƒo[”»’è
	if (game_mode == 0 && ch.life == 0) {//c‹@ƒ‚[ƒh•c‹@‚ª‚O‚É‚È‚Á‚½
		func_state = game_over;//ê–Ê‚ğƒQ[ƒ€ƒI[ƒo[‚É
	}

	count++;
}


//|||||||||||||||||||||/
// ƒŠƒUƒ‹ƒg‰æ–Ê‚Ìˆ—
//|||||||||||||||||||||/
void calc_result() {

	//‰‰ñ‚È‚ç
	if (result_flg == 0) {
		
		//ŠÔ
		end = clock();											//Œv‘ªI—¹
		elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;	//Œo‰ßŠÔŒvZ

		//ƒ‚[ƒhİ’è
		mode_tmp ^= 1;					//ƒ‚[ƒh”½“]
		if (mode_tmp == 1)mode_tmp++;	//c‹@ƒ‚[ƒh‚ÅƒvƒŒƒC‚µ‚Ä‚¢‚½‚È‚ç

		//ƒ{[ƒiƒX”{—¦‚ğŒvZ
		bonus = mode_tmp + level_tmp + 3 - ch.retry;
		if (bonus < 1)bonus = 1;//ƒ{[ƒiƒXÅ¬•â³

		//‡Œv“_”ŒvZ
		sum_score = ch.score_max + ch.power * POWER_BONUS_SCORE + ch.kill_count * KILL_BONUS_SCORE +
			ch.money * MONEY_BONUS_SCORE + ch.graze * GRAZE_BONUS_SCORE + ch.point * POINT_BONUS_SCORE;

		//ƒ{[ƒiƒXŒvZ‚ÆãŒÀC³
		final_score = sum_score * bonus;
		if (final_score > SCORE_MAX) final_score = SCORE_MAX;

		//ƒ‰ƒ“ƒN•t‚¯
		if (final_score <= RANKING_BORDER_BRONZE) {
			result_rank = bronze;
		}
		else if (final_score <= RANKING_BORDER_SILVER) {
			result_rank = silver;
		}
		else if (final_score <= RANKING_BORDER_GOLD) {
			result_rank = gold;
		}
		else if (final_score <= RANKING_BORDER_PLATINUM) {
			result_rank = platinum;
		}
		else {
			result_rank = diamond;
		}

		//ƒtƒ‰ƒO‚ğÀsÏ‚İ‚É•Ï‚¦‚é
		result_flg = 1;
	}
}


//|||||||||||||||||||||/
// ˆêŒ³ŠÇ—
//|||||||||||||||||||||/
void calc_main(){
	calc_stage_title();	//Í–¼‚ğ•\¦‚·‚é
	calc_item();		//ƒAƒCƒeƒ€ŒvZ
	calc_flash();		//ƒtƒ‰ƒbƒVƒ…(42)
}