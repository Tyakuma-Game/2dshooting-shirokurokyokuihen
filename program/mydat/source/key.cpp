#include "../include/GV.h"

//キーの入力状態を格納する変数
unsigned int stateKey[256];

//パッドの入力状態を格納する変数
pad_t pad;


//ーーーーーーーーーーーーーーーーーーーー/
// キー入力情報を取得
//ーーーーーーーーーーーーーーーーーーーー/
int GetHitKeyStateAll_2(){
    char GetHitKeyStateAll_Key[256];			//キー情報を格納
    GetHitKeyStateAll( GetHitKeyStateAll_Key );	//キー情報を持ってくる

	//どの入力か確かめる
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


//ーーーーーーーーーーーーーーーーーーーー/
// そのキーが押されているか確かめる
//ーーーーーーーーーーーーーーーーーーーー/
int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}


//ーーーーーーーーーーーーーーーーーーーー/
//引数１と引数２のうち大きい方を引数１に代入
//ーーーーーーーーーーーーーーーーーーーー/
void input_pad_or_key(int *p, int k){
	*p = *p>k ? *p : k;
}


//ーーーーーーーーーーーーーーーーーーーー/
//パッドとキーボードの両方の入力をチェック
//ーーーーーーーーーーーーーーーーーーーー/
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//パッドの入力状態を取得
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}

	//ーーーーーーーーー/
	// キーとパッド確かめる
	//ーーーーーーーーー/
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));//左
	input_pad_or_key(&pad.key[configpad.up]	    ,CheckStateKey(KEY_INPUT_UP	     ));//上
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));//右
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));//下
	input_pad_or_key(&pad.key[configpad.shot]	,CheckStateKey(KEY_INPUT_Z	     ));//弾幕発射
	input_pad_or_key(&pad.key[configpad.bom]	,CheckStateKey(KEY_INPUT_X		 ));//ボム使用
	input_pad_or_key(&pad.key[configpad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));//低速移動
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));//ゲーム終了
}


//−−−−−−−−−−−−−−−−−−−−−/
//渡されたパッドキー番号の入力状態を返す
//−−−−−−−−−−−−−−−−−−−−−/
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("CheckStatePadに渡した値が不正です\n");
		return -1;
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// タイトル画面の入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void TitleInput() {
	
	//選択切り替え
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && title_pattern != 0) {
		se_flag[17] = 1;//カーソル移動の音
		title_pattern--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && title_pattern != 1) {
		se_flag[17] = 1;//カーソル移動の音
		title_pattern++;
	}

	//エンターキー / start入力で実行
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		switch (title_pattern){
		case 0:func_state = levelselection; break;			//難易度選択画面
		case 1:ranking_load(); func_state = ranking; break;	//ランキング
		}		
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// 難易度選択の入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void LevelSelectionInput() {
	//ゲームモード変更
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && game_mode != score) {
		se_flag[17] = 1;//カーソル移動の音
		game_mode++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && game_mode != life) {
		se_flag[17] = 1;//カーソル移動の音
		game_mode--;
	}

	//難易度変更
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && game_level != normal) {
		se_flag[17] = 1;//カーソル移動の音
		game_level--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && game_level != lunatic) {
		se_flag[17] = 1;//カーソル移動の音
		game_level++;
	}

	//ゲーム開始  エンター入力 / start入力
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		StopSoundMem(area.bgm.handle);
		mode_tmp = game_mode;		//ゲームモード格納
		level_tmp = game_level;		//ゲーム難易度格納
		func_state = game_setting;	//場面をセッティングに変更
	}

}


//−−−−−−−−−−−−−−−−−−−−−/
// ゲーム内の入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void GamePlyInput() {
	//色変更
	ch.color_count++;
	if ((CheckStateKey(KEY_INPUT_C) == 1 || CheckStatePad(7) == 1) && ch.color_count > COLOR_COOL_TIME) {//Cキー、Bボタンで色変更
		se_flag[19] = 1;		//色変更の音
		ch.color_count = 0;		//クールタイム用
		ch.color ^= blue;		//二色を切り替え
		magic_size = 0.9f;		//魔法陣の大きさ
	}

	//メニュー表示　 エンター / start入力
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		menu_pattern = 0;	//表示画像を指定
		func_state = menu;	//場面をメニュー表示中に変更
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// メニュー画面の入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void MenuInput() {
	//選択切り替え
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && menu_pattern != 3) {
		se_flag[17] = 1;//カーソル移動の音
		menu_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && menu_pattern != 0) {
		se_flag[17] = 1;//カーソル移動の音
		menu_pattern--;
	}

	//エンターキー / start入力で実行
	if ((CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1)) {
		se_flag[18] = 1;//決定の音
		switch (menu_pattern) {
		case 0:  func_state = game_play; break;							//ゲームを再開
		case 1: enter_boss_shot(1); func_state = game_setting; StopSoundMem(area.bgm.handle); break;	//ニューゲーム
		case 2: enter_boss_shot(1); func_state = result; break;			//result画面に
		case 3: enter_boss_shot(1);	func_state = title; StopSoundMem(area.bgm.handle); area.bgm.flag = 0; break;			//title画面に
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// ゲームオーバーの入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void GameOverInput() {
	//選択切り替え
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && gameover_pattern != 2) {
		se_flag[17] = 1;//カーソル移動の音
		gameover_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && gameover_pattern != 0) {
		se_flag[17] = 1;//カーソル移動の音
		gameover_pattern--;
	}

	//エンターキー / start入力で実行
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		switch (gameover_pattern) {
		case 0: func_state = result; enter_boss_shot(1);							break;	//リザルト画面に進む
		case 1: func_state = game_play; ch.life = 3; ch.power = 200; ch.retry++;	break;	//ゲームを再開する
		case 2: func_state = title; enter_boss_shot(1);	StopSoundMem(area.bgm.handle);area.bgm.flag = 0;	break;	//タイトル画面に戻る
		}
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// リザルト画面の入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void ResultInput() {
	//Rankingに進む　 エンター / start入力
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		result_flg = 0;
		ranking_load();				//Rankingを読み込む
		ranking_entry(final_score);	//Rankingに書き込み
		func_state = ranking;		//場面をランキングに
		StopSoundMem(area.bgm.handle);	//音楽を止める
		area.bgm.flag = 0;
	}
}


//−−−−−−−−−−−−−−−−−−−−−/
// ランキングの入力処理
//−−−−−−−−−−−−−−−−−−−−−/
void RankingInput() {
	//title画面に行く エンター / start入力
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//決定の音
		func_state = title;	//場面をタイトルに変更
	}
}