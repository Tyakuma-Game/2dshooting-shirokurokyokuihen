
//|||||||||||||||||||||/
// ŠÖ”ƒvƒƒgƒ^ƒCƒvéŒ¾•externéŒ¾•”
//|||||||||||||||||||||/

//||||||||||||||||||/
//boss_shot.cpp

	GLOBAL void boss_shot_main();
	GLOBAL void enter_boss_shot(int flg);


//||||||||||||||||||/
//calc.cpp

	GLOBAL void calc_game_ply();	//ƒQ[ƒ€ƒvƒŒƒC’†‚Ìê–Êˆ—
	GLOBAL void calc_result();		//ƒŠƒUƒ‹ƒg‰æ–Ê‚Ìê–Êˆ—

	GLOBAL void calc_main();


//||||||||||||||||||/
//check_time.cpp

	GLOBAL void enter_func_tm(char st[], int flag = 0);
	GLOBAL void draw_func_tm(int x, int y);


//||||||||||||||||||/
//enemy.cpp

	GLOBAL void enemy_main();


//||||||||||||||||||/
//enemy_act_pattern.cpp

	GLOBAL double rang(double);


//||||||||||||||||||/
//cshot.cpp

	GLOBAL void cshot_main();


//||||||||||||||||||/
//char.cpp

	GLOBAL void calc_ch();
	GLOBAL void ch_move();


//||||||||||||||||||/
//dn.cpp

	GLOBAL  void enter_dn(int size,int time);


//||||||||||||||||||/
//effect.cpp

	GLOBAL void effect_main();
	GLOBAL void CreateParticle(float x, float y);//ƒp[ƒeƒBƒNƒ‹‚Ì“o˜^

//||||||||||||||||||/
//fps.cpp

	GLOBAL void fps_wait();
	GLOBAL void draw_fps(int x, int y);


//||||||||||||||||||/
//graph.cpp

	GLOBAL void graph_main();
	GLOBAL void graph_title();	//ƒ^ƒCƒgƒ‹•`‰æ
	GLOBAL void graph_levelselection();
	GLOBAL void graph_result();	//ƒŠƒUƒ‹ƒg•`‰æ
	GLOBAL void graph_ranking();//ƒ‰ƒ“ƒLƒ“ƒO•`‰æ


//||||||||||||||||||/
//ini.cpp

	GLOBAL void first_ini();
	GLOBAL void ini();


//||||||||||||||||||/
//shot.cpp

	GLOBAL double shotatan2(int n);
	GLOBAL int shot_search(int n);
	GLOBAL void shot_main();
	

//||||||||||||||||||/
//key.cpp

	//ƒL[“ü—Í
	GLOBAL int GetHitKeyStateAll_2();				//Œ»İ‚ÌƒL[“ü—Íˆ—‚ğs‚¤
	GLOBAL int CheckStateKey(unsigned char Handle);	//ó‚¯æ‚Á‚½ƒL[”Ô†‚ÌŒ»İ‚Ì“ü—Íó‘Ô‚ğ•Ô‚·

	//ƒpƒbƒh“ü—Í
	GLOBAL void GetHitPadStateAll();				//Œ»İ‚Ìƒpƒbƒh“ü—Íˆ—‚ğs‚¤ŠÖ”
	GLOBAL int CheckStatePad(unsigned int Handle);	//ó‚¯æ‚Á‚½ƒpƒbƒh”Ô†‚ÌŒ»İ‚Ì“ü—Íó‘Ô‚ğ•Ô‚·

	//ê–Ê‚Ì“ü—Í
	GLOBAL void TitleInput();
	GLOBAL void LevelSelectionInput();
	GLOBAL void GamePlyInput();
	GLOBAL void GameOverInput();
	GLOBAL void MenuInput();
	GLOBAL void ResultInput();
	GLOBAL void RankingInput();


//||||||||||||||||||/
//laod.cpp

	//ƒf[ƒ^‚Ìƒ[ƒh
	GLOBAL void load();
	GLOBAL void load_story();

	GLOBAL void ranking_load();
	GLOBAL void ranking_entry(int score);

//||||||||||||||||||/
//music.cpp

	GLOBAL void music_ini();
	GLOBAL void music_play();
	GLOBAL void delete_bgm();
	GLOBAL void bgm_main();


//||||||||||||||||||/
//out.cpp

	GLOBAL void out_main();
