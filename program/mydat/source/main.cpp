#define GLOBAL_INSTANCE 
#include "../include/GV.h"


//|||||||||||||||||||||/
//ƒ‹[ƒv‚Å•K‚¸s‚¤ˆ—
//|||||||||||||||||||||/
int ProcessLoop() {

	//ƒvƒƒZƒXˆ—‚ªƒGƒ‰[‚È‚ç-1‚ğ•Ô‚·
	if (ProcessMessage() != 0) {
		return -1;
	}

	//‰æ–ÊƒNƒŠƒA‚ªƒGƒ‰[‚È‚ç-1‚ğ•Ô‚·
	if (ClearDrawScreen() != 0) {
		return -1;
	}

	GetHitKeyStateAll_2();	//Œ»İ‚ÌƒL[“ü—Íˆ—‚ğs‚¤
	GetHitPadStateAll();	//Œ»İ‚Ìƒpƒbƒh“ü—Íˆ—‚ğs‚¤

	return 0;
}


//|||||||||||||||||||||/
// ƒƒCƒ“ŠÖ”
//|||||||||||||||||||||/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//||||||||||||/
	// Šî–{İ’è
	//||||||||||||/

	//ƒ‰ƒCƒuƒ‰ƒŠ‰Šú‰»
	if (DxLib_Init() == -1){
		return -1;
	}

	SetMainWindowText("”’•‹ÉˆÙ•Ï");	//ƒEƒBƒ“ƒhƒE–¼Ìw’è
	ChangeWindowMode(FALSE);			//ƒEƒCƒ“ƒhƒEƒ‚[ƒh‚Å‹N“®‚µ‚È‚¢
	SetDrawScreen(DX_SCREEN_BACK);		//— ‰æ–Ê‰»

	//ƒQ[ƒ€‚Ìó‘Ô‚ğ‰‰ñ‚Ìˆ—‚É
	func_state = start_loading;

	//|||||||||||||||||||||/
	// ƒƒCƒ“ƒ‹[ƒv
	//|||||||||||||||||||||/
	while (ProcessLoop() == 0) {

		//‰¹Šyİ’è
		music_ini();

		//ƒQ[ƒ€‚Ìê–Ê‚É‰‚¶‚Äˆ—‚ğ•ÏX
		switch (func_state) {

			//|||||||||||||||||||||/
			//‰‰ñ‚Ìˆ—
		case start_loading:
			load();				//ƒf[ƒ^ƒ[ƒh
			first_ini();		//‰‰ñ‚Ì‰Šú‰»
			func_state = title;	//ê–Ê‚ğƒ^ƒCƒgƒ‹‚É
			break;

			//|||||||||||||||||||||/
			//ƒ^ƒCƒgƒ‹‰æ–Ê•\¦
		case title:
			TitleInput();	//“ü—Í
			graph_title();	//•`‰æ
			break;

			//|||||||||||||||||||||/
			//“ïˆÕ“x‘I‘ğ‰æ–Ê
		case levelselection:
			LevelSelectionInput();	//“ü—Í
			graph_levelselection();	//•`‰æ
			break;

			//|||||||||||||||||||||/
			//STG‚ÌŠJn‘OƒZƒbƒeƒBƒ“ƒO
		case game_setting:
			ini();					//‰Šú‰»
			load_story();			//“Gî•ñŠi”[
			func_state = game_play;	//ê–Ê‚ğƒQ[ƒ€ƒvƒŒƒC’†‚É•ÏX
			start = clock();		//ŠJnŠÔæ“¾
			break;

			//|||||||||||||||||||||/
			//ƒQ[ƒ€ƒvƒŒƒC’†
		case game_play:
			//enter_func_tm("Å‰");
			calc_ch();       //enter_func_tm("ƒLƒƒƒ‰ŒvZ");
			ch_move();       //enter_func_tm("ƒLƒƒƒ‰ˆÚ“®");
			cshot_main();    //enter_func_tm("©‹@ƒVƒ‡ƒbƒgƒƒCƒ“");
			enemy_main();	 //enter_func_tm("“Gˆ—ƒƒCƒ“");
			boss_shot_main();//enter_func_tm("ƒ{ƒXƒVƒ‡ƒbƒgƒƒCƒ“");
			shot_main();	 //enter_func_tm("ƒVƒ‡ƒbƒgƒƒCƒ“");
			out_main();  	 //enter_func_tm("“–‚½‚è”»’è");
			effect_main();   //enter_func_tm("ƒGƒtƒFƒNƒgƒƒCƒ“");
			calc_main();	 //enter_func_tm("ŒvZƒƒCƒ“");
			graph_main();    //enter_func_tm("•`‰æƒƒCƒ“");
			GamePlyInput();	 //“ü—Í
			calc_game_ply(); //ƒQ[ƒ€’†‚Ìê–Êˆ—
			break;

			//|||||||||||||||||||||/
			//ƒƒjƒ…[‰æ–Ê•\¦
		case menu:
			MenuInput();									//“ü—Í
			DrawGraph(0, 0, img_menu[menu_pattern], FALSE);	//•\¦
			break;

			//|||||||||||||||||||||/
			//ƒQ[ƒ€ƒI[ƒo[
		case game_over:
			GameOverInput();										//“ü—Í
			DrawGraph(0, 0, img_gameover[gameover_pattern], FALSE);	//•\¦
			break;

			//|||||||||||||||||||||/
			//ƒŠƒUƒ‹ƒg‰æ–Ê
		case result:
			calc_result();	//ê–Ê‚Ìˆ—
			ResultInput();	//“ü—Í
			graph_result();	//•`‰æ
			break;

			//|||||||||||||||||||||/
			//ƒ‰ƒ“ƒLƒ“ƒO
		case ranking:
			RankingInput();	//ƒ‰ƒ“ƒLƒ“ƒO‚Ì“ü—Í
			graph_ranking();//ƒ‰ƒ“ƒLƒ“ƒO•`‰æ
			break;

		//|||||||||||||||||||||/
		//ƒGƒ‰[
		default:
			printfDx("•s–¾‚Èfunc_state\n");
			break;
		}

		bgm_main();		//enter_func_tm("BGMƒƒCƒ“");
		music_play();	//enter_func_tm("‰¹ŠyÄ¶");
		fps_wait();		//enter_func_tm("‘Ò‹@‚µ‚½ŠÔ", 1);

		//ƒGƒXƒP[ƒv‚ª“ü—Í‚³‚ê‚½‚çƒQ[ƒ€I—¹
		if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//— ‰æ–Ê”½‰f
		ScreenFlip();
	}

	//||||||||||/
	// I—¹ˆ—
	//||||||||||/
	DxLib_End();	//Dxƒ‰ƒCƒuƒ‰ƒŠI—¹
	return 0;		//³íI—¹
}