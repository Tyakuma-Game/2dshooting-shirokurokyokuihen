#include "../include/GV.h"


void descending_sort();

void load(){
	int t;
	SetCreateSoundDataType( DX_SOUNDDATATYPE_MEMPRESS ) ;

	t=GetNowCount();

	//−−−−−−−−−−−−−−−−−−−−−/
	// 画像読み込み
	//−−−−−−−−−−−−−−−−−−−−−/

	//−−−−−−−−−−/
	// 画面
	//−−−−−−−−−−/

	//タイトル画面
	img_title[0] = LoadGraph("../dat/img/title/title0.png");
	img_title[1] = LoadGraph("../dat/img/title/title1.png");
	
	//難易度選択画面
	img_levelselection[0][0] = LoadGraph("../dat/img/levelselection/00.png");
	img_levelselection[0][1] = LoadGraph("../dat/img/levelselection/01.png");
	img_levelselection[0][2] = LoadGraph("../dat/img/levelselection/02.png");
	img_levelselection[1][0] = LoadGraph("../dat/img/levelselection/10.png");
	img_levelselection[1][1] = LoadGraph("../dat/img/levelselection/11.png");
	img_levelselection[1][2] = LoadGraph("../dat/img/levelselection/12.png");

	//メニュー画面
	img_menu[0] = LoadGraph("../dat/img/menu/menu1.png");
	img_menu[1] = LoadGraph("../dat/img/menu/menu2.png");
	img_menu[2] = LoadGraph("../dat/img/menu/menu3.png");
	img_menu[3] = LoadGraph("../dat/img/menu/menu4.png");

	//ゲームオーバー画面
	img_gameover[0] = LoadGraph("../dat/img/gameover/gameover1.png");
	img_gameover[1] = LoadGraph("../dat/img/gameover/gameover2.png");
	img_gameover[2] = LoadGraph("../dat/img/gameover/gameover3.png");

	//リザルト画面
	img_result[0] = LoadGraph("../dat/img/result/result_bronze.png");
	img_result[1] = LoadGraph("../dat/img/result/result_silver.png");
	img_result[2] = LoadGraph("../dat/img/result/result_gold.png");
	img_result[3] = LoadGraph("../dat/img/result/result_platinum.png");
	img_result[4] = LoadGraph("../dat/img/result/result_diamond.png");

	//ランキング画面
	img_ranking = LoadGraph("../dat/img/ranking/ranking.png");

	//プレイ画面
	img_board[10] = LoadGraph("../dat/img/board/10.png");
	img_board[11] = LoadGraph("../dat/img/board/11.png");
	img_board[12] = LoadGraph("../dat/img/board/12.png");
	img_board[20] = LoadGraph("../dat/img/board/scoreboard.png");

	//−−−−−−−/
	// 背景画像
	//−−−−−−−/

	//通常
	img_back[0] = LoadGraph("../dat/img/back/normal/back0.png");//川

	//ボス
	img_back[10] = LoadGraph("../dat/img/back/boss/fixation.png");	 //固定　大樹
	img_back[11] = LoadGraph("../dat/img/back/boss/scroll.png");	 //移動　紫


	//−−−−−−−−−−/
	// プレイヤー
	//−−−−−−−−−−/

	//ドット絵
	LoadDivGraph("../dat/img/char/char1.png", 3, 3, 1, 32, 36, img_ch);

	//周りの白い球
	img_bb = LoadGraph("../dat/img/char/ball.png");

	//魔法陣の画像
	img_magic[0] = LoadGraph("../dat/img/enemy/red1.png");
	img_magic[1] = LoadGraph("../dat/img/enemy/blue1.png");

	//当たり判定
	img_ch_hit = LoadGraph("../dat/img/char/atari.png");


	//−−−−−−−−−−/
	// 敵
	//−−−−−−−−−−/

	//敵ドット絵
	LoadDivGraph("../dat/img/enemy/0.png", 9, 3, 3, 32, 32, img_enemy[0]);

	//ボスドット絵
	img_boss = LoadGraph("../dat/img/char/boss.png");

	img_etc[1] = LoadGraph("../dat/img/enemy/hp.png");			//敵のHPバー
	img_etc[2] = LoadGraph("../dat/img/enemy/bossback.png");	//ボスの魔法陣　大円
	img_etc[5] = LoadGraph("../dat/img/enemy/bossback3.png");	//ボスの魔法陣　五芒星
	img_etc[6] = LoadGraph("../dat/img/enemy/bossback4.png");	//ボスの魔法陣　四角
	img_etc[7] = LoadGraph("../dat/img/enemy/hp_boss.png");		//ボスのHPバー


	//−−−−−−−−−−/
	// エフェクト
	//−−−−−−−−−−/

	//ボム
	img_eff_bom[0] = LoadGraph( "../dat/img/effect/bom0.png" );			//ボムの画像１
	img_eff_bom[1] = LoadGraph( "../dat/img/effect/bom1.png" );			//ボムの画像２
	img_eff_bom[3] = LoadGraph( "../dat/img/bullet/bom_title0.png" );	//ボムの縦帯
	img_eff_bom[2] = LoadGraph( "../dat/img/char/body.png" );			//表示する立ち絵

	//敵撃破
	LoadDivGraph("../dat/img/enemy/hit_effect.png", 5, 5, 1, 140, 140, img_del_effect);

	//パーティクル
	img_particle[0] = LoadGraph("../dat/img/effect/particle_red.png"); //パーティクル赤
	img_particle[1] = LoadGraph("../dat/img/effect/particle_blue.png");//パーティクル青


	//−−−−−−−−−−/
	//弾の画像
	//−−−−−−−−−−/
	
	//弾幕画像読み込み
	LoadDivGraph("../dat/img/bullet/bullet_red.png", 24, 24, 1, 32, 32, img_bullet2[0]);	//赤色
	LoadDivGraph("../dat/img/bullet/bullet_blue.png", 24, 24, 1, 32, 32, img_bullet2[1]);	//青色

	//赤色弾幕
	img_cshot[0][0] = LoadGraph("../dat/img/char/red_ch0.png");//弾丸のような奴
	img_cshot[0][1] = LoadGraph("../dat/img/char/red_ch1.png");//鋭いやつ

	//青色弾幕
	img_cshot[1][0] = LoadGraph("../dat/img/char/blue_ch0.png");//弾丸のような奴
	img_cshot[1][1] = LoadGraph("../dat/img/char/blue_ch1.png");//鋭いやつ


	//−−−−−−−−−−/
	// アイテム画像
	//−−−−−−−−−−/
	
	LoadDivGraph("../dat/img/item/p0.png", 2, 2, 1, 35, 35, img_item[0]);
	LoadDivGraph("../dat/img/item/p1.png", 2, 2, 1, 35, 35, img_item[1]);
	LoadDivGraph("../dat/img/item/p2.png", 2, 2, 1, 15, 15, img_item[2]);
	LoadDivGraph("../dat/img/item/p3.png", 2, 2, 1, 35, 35, img_item[3]);
	LoadDivGraph("../dat/img/item/p4.png", 2, 2, 1, 35, 35, img_item[4]);
	LoadDivGraph("../dat/img/item/p5.png", 2, 2, 1, 35, 35, img_item[5]);
	

	//−−−−−−−−−−/
	// その他画像
	//−−−−−−−−−−/
	
	//プレイヤーの残機（★）
	img_etc[8] = LoadGraph("../dat/img/board/hoshi.png");

	//スコア表示用　数字
	LoadDivGraph("../dat/img/num/2.png", 10, 10, 1, 16, 18, img_num[0]);
	

	//−−−−−−−−−−−−−−−−−−−−−/
	// 音楽読み込み
	//−−−−−−−−−−−−−−−−−−−−−/

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

	//音量設定
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


	//−−−−−−−−−−−−−−−−−−−−−/
	//色情報取得
	//−−−−−−−−−−−−−−−−−−−−−/
	color[0] = GetColor(255,255,255);//白
	color[1] = GetColor(  0,  0,  0);//黒
	color[2] = GetColor(255,  0,  0);//赤
	color[3] = GetColor(  0,255,  0);//緑
	color[4] = GetColor(  0,  0,255);//青
	color[5] = GetColor(255,255,  0);//黄色
	color[6] = GetColor(  0,255,255);//青緑
	color[7] = GetColor(255,  0,255);//紫


	//−−−−−−−−−−−−−−−−−−−−−/
	//フォントを指定
	//−−−−−−−−−−−−−−−−−−−−−/
	font[0] = CreateFontToHandle( "HGPｺﾞｼｯｸE" , 15 , 2 , DX_FONTTYPE_ANTIALIASING_EDGE);
}


//−−−−−−−−−−−−−−−−−−−−−/
//敵の出現情報をエクセルから読み込んで格納
//−−−−−−−−−−−−−−−−−−−−−/
void load_story(){
	int n,num,i,fp;
	int input[64];
	char inputc[64];
	
	//難易度別にファイル読み込み
	char fname0[32] = { "../dat/csv/story0_normal.csv" };
	char fname1[32] = { "../dat/csv/story0_hard.csv" };
	char fname2[32] = { "../dat/csv/story0_lunatic.csv" };

	//難易度基準で格納ファイル変更
	switch (game_level){
	case normal : fp = FileRead_open(fname0); break;
	case hard   : fp = FileRead_open(fname1); break;
	case lunatic: fp = FileRead_open(fname2); break;
	}

	//失敗したらエラーを表示
	if(fp == NULL){
		printfDx("read error\n");
		return;
	}

	//最初の2行読み飛ばす
	for(i=0;i<2;i++){
		while(FileRead_getc(fp)!='\n');
	}

	n=0 , num=0;
	while(1){
		// データ取り出し
		for(i=0;i<64;i++){
			//1文字取得する
			inputc[i]=input[i]=FileRead_getc(fp);

			//スラッシュがあれば
			if(inputc[i]=='/'){
				while(FileRead_getc(fp)!='\n');//改行までループ
				i=-1;						   //カウンタを最初に戻して
				continue;					   //再度実行する
			}

			//カンマか改行なら
			if(input[i]==',' || input[i]=='\n'){
				inputc[i]='\0';	//そこまでを文字列とし
				break;			//shitchで格納する
			}

			//ファイルの終わりなら
			if(input[i]==EOF){
				goto EXFILE;//終了
			}
		}

		//データ格納
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

	//終了
EXFILE:
	FileRead_close(fp);//ファイル解放
}


//−−−−−−−−−−−−−−−−−−−−−/
//ランキングの読み込み
//−−−−−−−−−−−−−−−−−−−−−/
void ranking_load() {
	int i;
	FILE* fp;//ファイルハンドル
	fp = fopen("../dat/ranking/score.txt", "r");//rankingを呼び出す

	//値を格納
	for (i = 0; i < RANKING_MAX; i++) {//１つづつ格納
		fscanf(fp, "%d", &(ranking_score[i]));
	}

	fclose(fp);//ファイルを閉じる
}


//−−−−−−−−−−−−−−−−−−−−−/
// 降順ソート処理
//−−−−−−−−−−−−−−−−−−−−−/
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


//−−−−−−−−−−−−−−−−−−−−−/
// ランキングの書き込み
//−−−−−−−−−−−−−−−−−−−−−/
void ranking_entry(int score) {
	int i;
	FILE* fp;//ファイルハンドル
	fp = fopen("../dat/ranking/score.txt", "w");//書き込みモードでファイルを呼び出し

	//ゲーム終了時の合計点を最後尾に格納
	ranking_score[RANKING_MAX] = score;

	//降順ソート
	descending_sort();

	//同じ値を排除
	for (i = 0; i < RANKING_MAX + 1; i++) {
		if (ranking_score[i] == ranking_score[i + 1]){
			ranking_score[i] = 0;//同じ値があったら０にしてランキング外に出す
		}
	}

	//降順ソート
	descending_sort();

	//ファイルに書き込み
	for (i = 0; i < RANKING_MAX; i++) {
		fprintf(fp, "%d\n", ranking_score[i]);
	}

	//ファイルを閉じる
	fclose(fp);
}