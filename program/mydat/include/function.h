
//|||||||||||||||||||||/
// Φvg^CvιΎexternιΎ
//|||||||||||||||||||||/

//||||||||||||||||||/
//boss_shot.cpp

	GLOBAL void boss_shot_main();
	GLOBAL void enter_boss_shot(int flg);


//||||||||||||||||||/
//calc.cpp

	GLOBAL void calc_game_ply();	//Q[vCΜκΚ
	GLOBAL void calc_result();		//UgζΚΜκΚ

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
	GLOBAL void CreateParticle(float x, float y);//p[eBNΜo^

//||||||||||||||||||/
//fps.cpp

	GLOBAL void fps_wait();
	GLOBAL void draw_fps(int x, int y);


//||||||||||||||||||/
//graph.cpp

	GLOBAL void graph_main();
	GLOBAL void graph_title();	//^Cg`ζ
	GLOBAL void graph_levelselection();
	GLOBAL void graph_result();	//Ug`ζ
	GLOBAL void graph_ranking();//LO`ζ


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

	//L[όΝ
	GLOBAL int GetHitKeyStateAll_2();				//»έΜL[όΝπs€
	GLOBAL int CheckStateKey(unsigned char Handle);	//σ―ζΑ½L[ΤΜ»έΜόΝσΤπΤ·

	//pbhόΝ
	GLOBAL void GetHitPadStateAll();				//»έΜpbhόΝπs€Φ
	GLOBAL int CheckStatePad(unsigned int Handle);	//σ―ζΑ½pbhΤΜ»έΜόΝσΤπΤ·

	//κΚΜόΝ
	GLOBAL void TitleInput();
	GLOBAL void LevelSelectionInput();
	GLOBAL void GamePlyInput();
	GLOBAL void GameOverInput();
	GLOBAL void MenuInput();
	GLOBAL void ResultInput();
	GLOBAL void RankingInput();


//||||||||||||||||||/
//laod.cpp

	//f[^Μ[h
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
