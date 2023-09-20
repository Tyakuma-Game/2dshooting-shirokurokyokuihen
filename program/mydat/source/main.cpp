#define GLOBAL_INSTANCE 
#include "../include/GV.h"


//−−−−−−−−−−−−−−−−−−−−−/
//ループで必ず行う処理
//−−−−−−−−−−−−−−−−−−−−−/
int ProcessLoop() {

	//プロセス処理がエラーなら-1を返す
	if (ProcessMessage() != 0) {
		return -1;
	}

	//画面クリアがエラーなら-1を返す
	if (ClearDrawScreen() != 0) {
		return -1;
	}

	GetHitKeyStateAll_2();	//現在のキー入力処理を行う
	GetHitPadStateAll();	//現在のパッド入力処理を行う

	return 0;
}


//−−−−−−−−−−−−−−−−−−−−−/
// メイン関数
//−−−−−−−−−−−−−−−−−−−−−/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//−−−−−−−−−−−−/
	// 基本設定
	//−−−−−−−−−−−−/

	//ライブラリ初期化
	if (DxLib_Init() == -1){
		return -1;
	}

	SetMainWindowText("白黒極異変");	//ウィンドウ名称指定
	ChangeWindowMode(FALSE);			//ウインドウモードで起動しない
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面化

	//ゲームの状態を初回の処理に
	func_state = start_loading;

	//−−−−−−−−−−−−−−−−−−−−−/
	// メインループ
	//−−−−−−−−−−−−−−−−−−−−−/
	while (ProcessLoop() == 0) {

		//音楽設定
		music_ini();

		//ゲームの場面に応じて処理を変更
		switch (func_state) {

			//−−−−−−−−−−−−−−−−−−−−−/
			//初回の処理
		case start_loading:
			load();				//データロード
			first_ini();		//初回の初期化
			func_state = title;	//場面をタイトルに
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//タイトル画面表示
		case title:
			TitleInput();	//入力
			graph_title();	//描画
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//難易度選択画面
		case levelselection:
			LevelSelectionInput();	//入力
			graph_levelselection();	//描画
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//STGの開始前セッティング
		case game_setting:
			ini();					//初期化
			load_story();			//敵情報格納
			func_state = game_play;	//場面をゲームプレイ中に変更
			start = clock();		//開始時間取得
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//ゲームプレイ中
		case game_play:
			//enter_func_tm("最初");
			calc_ch();       //enter_func_tm("キャラ計算");
			ch_move();       //enter_func_tm("キャラ移動");
			cshot_main();    //enter_func_tm("自機ショットメイン");
			enemy_main();	 //enter_func_tm("敵処理メイン");
			boss_shot_main();//enter_func_tm("ボスショットメイン");
			shot_main();	 //enter_func_tm("ショットメイン");
			out_main();  	 //enter_func_tm("当たり判定");
			effect_main();   //enter_func_tm("エフェクトメイン");
			calc_main();	 //enter_func_tm("計算メイン");
			graph_main();    //enter_func_tm("描画メイン");
			GamePlyInput();	 //入力
			calc_game_ply(); //ゲーム中の場面処理
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//メニュー画面表示
		case menu:
			MenuInput();									//入力
			DrawGraph(0, 0, img_menu[menu_pattern], FALSE);	//表示
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//ゲームオーバー
		case game_over:
			GameOverInput();										//入力
			DrawGraph(0, 0, img_gameover[gameover_pattern], FALSE);	//表示
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//リザルト画面
		case result:
			calc_result();	//場面の処理
			ResultInput();	//入力
			graph_result();	//描画
			break;

			//−−−−−−−−−−−−−−−−−−−−−/
			//ランキング
		case ranking:
			RankingInput();	//ランキングの入力
			graph_ranking();//ランキング描画
			break;

		//−−−−−−−−−−−−−−−−−−−−−/
		//エラー
		default:
			printfDx("不明なfunc_state\n");
			break;
		}

		bgm_main();		//enter_func_tm("BGMメイン");
		music_play();	//enter_func_tm("音楽再生");
		fps_wait();		//enter_func_tm("待機した時間", 1);

		//エスケープが入力されたらゲーム終了
		if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//裏画面反映
		ScreenFlip();
	}

	//−−−−−−−−−−/
	// 終了処理
	//−−−−−−−−−−/
	DxLib_End();	//Dxライブラリ終了
	return 0;		//正常終了
}