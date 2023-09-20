#include "../include/GV.h"

//－－－－－－－－－－－－－－－－－－－－－/
// 弾の当たり判定作成
//－－－－－－－－－－－－－－－－－－－－－/
void input_bullet_info(bullet_info_t *binfo,int size_x,int size_y,int col_num,double range,int kaiten){
	binfo->size_x =size_x;	binfo->size_y =size_y;
	binfo->col_num=col_num;	binfo->range  =range;
	binfo->kaiten=kaiten;
}


//－－－－－－－－－－－－－－－－－－－－－/
//一番最初の初期化
//－－－－－－－－－－－－－－－－－－－－－/
void first_ini(){

	//ーーーーーーーーー/
	// パッド入力設定
	//ーーーーーーーーー/
	configpad.down=0;	//下
	configpad.left=1;	//左
	configpad.right=2;	//右
	configpad.up=3;		//上
	configpad.bom=6;	//ボム
	configpad.shot=11;	//弾発射
	configpad.slow=10;	//低速移動
	configpad.start=15;	//ゲーム開始
	configpad.change=6;	//変身


	//－－－－－－－－－－/
	// 値初期化
	//－－－－－－－－－－/
	stage=0;					//現在のステージ数
	stage_title_count[0]=200;	//ステージタイトル制御


	//ーーーーーーーーー/
	// 弾幕当たり判定設定
	//ーーーーーーーーー/
	input_bullet_info(&bullet_info[0], 35, 32, 8, 2.0, 0);    //小弾幕
	input_bullet_info(&bullet_info[1], 38, 38, 10, 2.0, 0);   //中玉弾幕
	input_bullet_info(&bullet_info[2], 22, 22, 6, 4.0, 0);    //大玉弾幕
	input_bullet_info(&bullet_info[3], 38, 38, 10, 2.0, 0);   //(光)中玉弾幕
	input_bullet_info(&bullet_info[4], 22, 22, 6, 4.0, 0);    //(光)大玉弾幕
	input_bullet_info(&bullet_info[5], 19, 34, 5, 2.0, 0);    //ナイフ弾幕
	input_bullet_info(&bullet_info[6], 13, 19, 3, 2.0, 0);    //時計の針
	input_bullet_info(&bullet_info[7], 30, 40, 10, 2.0, 0);   //レーザー
	input_bullet_info(&bullet_info[8], 30, 40, 10, 2.0, 0);   //大太刀
	input_bullet_info(&bullet_info[9], 14, 16, 3, 3.5, 0);    //札
	input_bullet_info(&bullet_info[10], 22, 22, 6, 4.0, 0);   //蝶弾幕
	input_bullet_info(&bullet_info[11], 14, 18, 3, 2.0, 0);   //鱗弾幕
	input_bullet_info(&bullet_info[12], 13, 19, 3, 2.0, 0);   //米粒弾
	input_bullet_info(&bullet_info[13], 13, 19, 3, 2.0, 0);   //小太刀
	input_bullet_info(&bullet_info[14], 13, 19, 3, 2.0, 0);   //裂け目
	input_bullet_info(&bullet_info[15], 22, 34, 5, 3.0, 0);	  //大弾丸
	input_bullet_info(&bullet_info[16], 19, 34, 5, 2.0, 0);	  //弾丸
	input_bullet_info(&bullet_info[17], 13, 19, 3, 2.0, 0);   //小星
	input_bullet_info(&bullet_info[18], 22, 22, 6, 4.0, 0);   //大星
	input_bullet_info(&bullet_info[19], 38, 38, 10, 2.0, 0);  //ぐるぐる
	input_bullet_info(&bullet_info[20], 22, 22, 6, 4.0, 0);   //惑星
	input_bullet_info(&bullet_info[21], 35, 32, 8, 2.0, 0);	  //銀河
	input_bullet_info(&bullet_info[22], 22, 22, 6, 4.0, 0);   //ハート
	input_bullet_info(&bullet_info[23], 13, 19, 3, 2.0, 0);   //ダイヤ
}


//－－－－－－－－－－－－－－－－－－－－－/
//ゲームの初期化
//－－－－－－－－－－－－－－－－－－－－－/
void ini(){

	//関数制御用
	stage_count=1;

	//ーーーーーーーーー/
	// メモリ確保
	//ーーーーーーーーー/
	memset(&ch,0,sizeof(ch_t));										//プレイヤー
	memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);						//敵
	memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);						//レーザー
	memset(enemy_order,0,sizeof(enemy_order_t)*ENEMY_ORDER_MAX);	//敵の出現情報
	memset(shot,0,sizeof(shot_t)*SHOT_MAX);							//弾幕
	memset(cshot,0,sizeof(cshot_t)*CSHOT_MAX);						//プレイヤー弾幕
	memset(effect,0,sizeof(effect_t)*EFFECT_MAX);					//エフェクト
	memset(particle, 0, sizeof(Particle) * PARTICLE_MAX);			//パーティクル
	memset(del_effect,0,sizeof(del_effect_t)*DEL_EFFECT_MAX);		//消滅エフェクト
	memset(&bom,0,sizeof(bom_t));									//ボムの情報
	memset(&bright_set,0,sizeof(bright_set_t));						//画面の明るさ
	memset(&dn,0,sizeof(dn_t));										//揺れ
	memset(&boss,0,sizeof(boss_t));									//ボスの情報
	memset(child,0,sizeof(child_t)*CHILD_MAX);						//弾幕発射のエフェクト
	memset(&stage_title,0,sizeof(stage_title_t));					//ステージタイトル
	memset(item,0,sizeof(item_t)*ITEM_MAX);							//アイテム
	memset(&area,0,sizeof(area_t));									//(48)　エリアの情報
	memset(option_bb,0,sizeof(option_bb_t)*2);						//(49)　Schottのオプション（ボンボン）


	//ーーーーーーーーー/
	// プレイヤー初期化
	//ーーーーーーーーー/
	ch.x=FMX/2;			//X座標初期化
	ch.y=FMY*3/4;		//Y座標初期化
	ch.power=400;		//初期パワー
	ch.miss = 0;		//ミスの回数を記録

	ch.retry = 0;		//復活回数
	magic_size = 1.0f;	//魔法陣の大きさ

	if (game_mode == 0) {//残機
		ch.life = 5;
	}

	//ーーーーーーーーー/
	//タイトル制御初期化
	//ーーーーーーーーー/
	stage_title.appear_cnt=stage_title_count[stage];
	

	//ーーーーーーーーー/
	//ボスの行動設定
	//ーーーーーーーーー/
	
	//boss.appear_count[0]=50;	//デバッグ用　中ボスが出現する時刻

	boss.appear_count[0]=1700;	//中ボスが出現する時刻
	boss.appear_count[1]=2850;	//最後ボスが出現する時刻

	boss.danmaku_num[0]=1;		//中ボスが何個目までの弾幕を出すか
	boss.danmaku_num[1]=4;		//最後に出るボスが何個目までの弾幕を出すか

	//ーーーーーーーーー/
	// ボスの体力設定
	//ーーーーーーーーー/

	//体力設定
	int boss_hp_normal[DANMAKU_MAX] = {
		15000,30000,16000,25000,30000,
	};
	int boss_hp_hard[DANMAKU_MAX] = {
		18000,32000,18000,28000,33000,
	};
	int boss_hp_lunatic[DANMAKU_MAX] = {
		20000,35000,20000,30000,36000,
	};

	//弾幕それぞれのHPを格納する
	for(int i=0;i<DANMAKU_MAX;i++){
		switch (game_level){//難易度に応じて変更
		case normal : boss.set_hp[i] = boss_hp_normal[i]; break;
		case hard   : boss.set_hp[i] = boss_hp_hard[i]; break;
		case lunatic: boss.set_hp[i] = boss_hp_lunatic[i]; break;
		}
	}

	//ボス体力の最大値
	boss.hp_max=boss.set_hp[0];

	//ーーーーーーーーー/
	//ボス弾幕の背景設定
	//ーーーーーーーーー/

	//ボス弾幕の背景
	int back_knd[DANMAKU_MAX] = {
		1,1,1,1,1,
	};

	//弾幕それぞれの背景を格納する
	for(int i=0;i<DANMAKU_MAX;i++){
		boss.back_knd[i]=back_knd[i];
	}
	

	//ーーーーーーーーー/
	// 音楽に関すること
	//ーーーーーーーーー/
	

	area.bgm.flag=1;			//音楽再生フラグを初期化(48)
	area.bgm.loop_pos[0]=26672;	//通常BGMのループ位置
	area.bgm.loop_pos[1]=27010;	//ボスBGMのループ位置


	//ーーーーーーーーー/
	//オプションボンボンの画像代入
	//ーーーーーーーーー/
	option_bb[0].img=img_bb;
	option_bb[1].img=img_bb;


	//ーーーーーーーーー/
	// 彩度
	//ーーーーーーーーー/
	bright_set.brt=255;//初期輝度は最大
}