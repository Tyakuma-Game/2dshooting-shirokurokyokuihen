#include "../include/GV.h"

//ƒL[‚Ì“ü—Íó‘Ô‚ğŠi”[‚·‚é•Ï”
unsigned int stateKey[256];

//ƒpƒbƒh‚Ì“ü—Íó‘Ô‚ğŠi”[‚·‚é•Ï”
pad_t pad;


//[[[[[[[[[[[[[[[[[[[[/
// ƒL[“ü—Íî•ñ‚ğæ“¾
//[[[[[[[[[[[[[[[[[[[[/
int GetHitKeyStateAll_2(){
    char GetHitKeyStateAll_Key[256];			//ƒL[î•ñ‚ğŠi”[
    GetHitKeyStateAll( GetHitKeyStateAll_Key );	//ƒL[î•ñ‚ğ‚Á‚Ä‚­‚é

	//‚Ç‚Ì“ü—Í‚©Šm‚©‚ß‚é
    for(int i=0;i<256;i++){
		if (GetHitKeyStateAll_Key[i] == 1) {
			stateKey[i]++;
		}
		else {
			stateKey[i] = 0;
		}
    }

    return 0;
}


//[[[[[[[[[[[[[[[[[[[[/
// ‚»‚ÌƒL[‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚©Šm‚©‚ß‚é
//[[[[[[[[[[[[[[[[[[[[/
int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}


//[[[[[[[[[[[[[[[[[[[[/
//ˆø”‚P‚Æˆø”‚Q‚Ì‚¤‚¿‘å‚«‚¢•û‚ğˆø”‚P‚É‘ã“ü
//[[[[[[[[[[[[[[[[[[[[/
void input_pad_or_key(int *p, int k){
	*p = *p>k ? *p : k;
}


//[[[[[[[[[[[[[[[[[[[[/
//ƒpƒbƒh‚ÆƒL[ƒ{[ƒh‚Ì—¼•û‚Ì“ü—Í‚ğƒ`ƒFƒbƒN
//[[[[[[[[[[[[[[[[[[[[/
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//ƒpƒbƒh‚Ì“ü—Íó‘Ô‚ğæ“¾
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}

	//[[[[[[[[[/
	// ƒL[‚ÆƒpƒbƒhŠm‚©‚ß‚é
	//[[[[[[[[[/
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));//¶
	input_pad_or_key(&pad.key[configpad.up]	    ,CheckStateKey(KEY_INPUT_UP	     ));//ã
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));//‰E
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));//‰º
	input_pad_or_key(&pad.key[configpad.shot]	,CheckStateKey(KEY_INPUT_Z	     ));//’e–‹”­Ë
	input_pad_or_key(&pad.key[configpad.bom]	,CheckStateKey(KEY_INPUT_X		 ));//ƒ{ƒ€g—p
	input_pad_or_key(&pad.key[configpad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));//’á‘¬ˆÚ“®
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));//ƒQ[ƒ€I—¹
}


//|||||||||||||||||||||/
//“n‚³‚ê‚½ƒpƒbƒhƒL[”Ô†‚Ì“ü—Íó‘Ô‚ğ•Ô‚·
//|||||||||||||||||||||/
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("CheckStatePad‚É“n‚µ‚½’l‚ª•s³‚Å‚·\n");
		return -1;
	}
}


//|||||||||||||||||||||/
// ƒ^ƒCƒgƒ‹‰æ–Ê‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void TitleInput() {
	
	//‘I‘ğØ‚è‘Ö‚¦
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && title_pattern != 0) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		title_pattern--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && title_pattern != 1) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		title_pattern++;
	}

	//ƒGƒ“ƒ^[ƒL[ / start“ü—Í‚ÅÀs
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		switch (title_pattern){
		case 0:func_state = levelselection; break;			//“ïˆÕ“x‘I‘ğ‰æ–Ê
		case 1:ranking_load(); func_state = ranking; break;	//ƒ‰ƒ“ƒLƒ“ƒO
		}		
	}
}


//|||||||||||||||||||||/
// “ïˆÕ“x‘I‘ğ‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void LevelSelectionInput() {
	//ƒQ[ƒ€ƒ‚[ƒh•ÏX
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && game_mode != score) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		game_mode++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && game_mode != life) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		game_mode--;
	}

	//“ïˆÕ“x•ÏX
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && game_level != normal) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		game_level--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && game_level != lunatic) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		game_level++;
	}

	//ƒQ[ƒ€ŠJn  ƒGƒ“ƒ^[“ü—Í / start“ü—Í
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		StopSoundMem(area.bgm.handle);
		mode_tmp = game_mode;		//ƒQ[ƒ€ƒ‚[ƒhŠi”[
		level_tmp = game_level;		//ƒQ[ƒ€“ïˆÕ“xŠi”[
		func_state = game_setting;	//ê–Ê‚ğƒZƒbƒeƒBƒ“ƒO‚É•ÏX
	}

}


//|||||||||||||||||||||/
// ƒQ[ƒ€“à‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void GamePlyInput() {
	//F•ÏX
	ch.color_count++;
	if ((CheckStateKey(KEY_INPUT_C) == 1 || CheckStatePad(7) == 1) && ch.color_count > COLOR_COOL_TIME) {//CƒL[ABƒ{ƒ^ƒ“‚ÅF•ÏX
		se_flag[19] = 1;		//F•ÏX‚Ì‰¹
		ch.color_count = 0;		//ƒN[ƒ‹ƒ^ƒCƒ€—p
		ch.color ^= blue;		//“ñF‚ğØ‚è‘Ö‚¦
		magic_size = 0.9f;		//–‚–@w‚Ì‘å‚«‚³
	}

	//ƒƒjƒ…[•\¦@ ƒGƒ“ƒ^[ / start“ü—Í
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		menu_pattern = 0;	//•\¦‰æ‘œ‚ğw’è
		func_state = menu;	//ê–Ê‚ğƒƒjƒ…[•\¦’†‚É•ÏX
	}
}


//|||||||||||||||||||||/
// ƒƒjƒ…[‰æ–Ê‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void MenuInput() {
	//‘I‘ğØ‚è‘Ö‚¦
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && menu_pattern != 3) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		menu_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && menu_pattern != 0) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		menu_pattern--;
	}

	//ƒGƒ“ƒ^[ƒL[ / start“ü—Í‚ÅÀs
	if ((CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1)) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		switch (menu_pattern) {
		case 0:  func_state = game_play; break;							//ƒQ[ƒ€‚ğÄŠJ
		case 1: enter_boss_shot(1); func_state = game_setting; StopSoundMem(area.bgm.handle); break;	//ƒjƒ…[ƒQ[ƒ€
		case 2: enter_boss_shot(1); func_state = result; break;			//result‰æ–Ê‚É
		case 3: enter_boss_shot(1);	func_state = title; StopSoundMem(area.bgm.handle); area.bgm.flag = 0; break;			//title‰æ–Ê‚É
		}
	}
}


//|||||||||||||||||||||/
// ƒQ[ƒ€ƒI[ƒo[‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void GameOverInput() {
	//‘I‘ğØ‚è‘Ö‚¦
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && gameover_pattern != 2) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		gameover_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && gameover_pattern != 0) {
		se_flag[17] = 1;//ƒJ[ƒ\ƒ‹ˆÚ“®‚Ì‰¹
		gameover_pattern--;
	}

	//ƒGƒ“ƒ^[ƒL[ / start“ü—Í‚ÅÀs
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		switch (gameover_pattern) {
		case 0: func_state = result; enter_boss_shot(1);							break;	//ƒŠƒUƒ‹ƒg‰æ–Ê‚Éi‚Ş
		case 1: func_state = game_play; ch.life = 3; ch.power = 200; ch.retry++;	break;	//ƒQ[ƒ€‚ğÄŠJ‚·‚é
		case 2: func_state = title; enter_boss_shot(1);	StopSoundMem(area.bgm.handle);area.bgm.flag = 0;	break;	//ƒ^ƒCƒgƒ‹‰æ–Ê‚É–ß‚é
		}
	}
}


//|||||||||||||||||||||/
// ƒŠƒUƒ‹ƒg‰æ–Ê‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void ResultInput() {
	//Ranking‚Éi‚Ş@ ƒGƒ“ƒ^[ / start“ü—Í
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		result_flg = 0;
		ranking_load();				//Ranking‚ğ“Ç‚İ‚Ş
		ranking_entry(final_score);	//Ranking‚É‘‚«‚İ
		func_state = ranking;		//ê–Ê‚ğƒ‰ƒ“ƒLƒ“ƒO‚É
		StopSoundMem(area.bgm.handle);	//‰¹Šy‚ğ~‚ß‚é
		area.bgm.flag = 0;
	}
}


//|||||||||||||||||||||/
// ƒ‰ƒ“ƒLƒ“ƒO‚Ì“ü—Íˆ—
//|||||||||||||||||||||/
void RankingInput() {
	//title‰æ–Ê‚És‚­ ƒGƒ“ƒ^[ / start“ü—Í
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//Œˆ’è‚Ì‰¹
		func_state = title;	//ê–Ê‚ğƒ^ƒCƒgƒ‹‚É•ÏX
	}
}