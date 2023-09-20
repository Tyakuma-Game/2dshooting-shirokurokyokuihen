#include "../../../include/DxLib.h"
#include "define.h"
#include "math.h"
#include <time.h>

//－－－－－－－－－－－－－－－－－－－－－/
// externを付けるか判定
//－－－－－－－－－－－－－－－－－－－－－/
#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 
#endif

#include "function.h"


//－－－－－－－－－－－－－－－－－－－－－/
// 共有変数宣言部
//－－－－－－－－－－－－－－－－－－－－－/

//－－－－－－－－－－/
// 画像変数
//－－－－－－－－－－/

//－－－－－/
//画面
//－－－－－/
GLOBAL int img_title[2];	//タイトル画面
GLOBAL int img_levelselection[2][3];//難易度選択
GLOBAL int img_menu[4];		//メニュー画面
GLOBAL int img_result[5];	//リザルト画面
GLOBAL int img_gameover[3];	//ゲームオーバー画面
GLOBAL int img_board[40];	//ボードにつかう画像
GLOBAL int img_back[20];	//背景用画像
GLOBAL int img_ranking;		//ランキングの画像


//－－－－－/
//プレイヤー
//－－－－－/
GLOBAL int img_ch[3];	//プレイヤードット絵
GLOBAL int img_bb;		//オプションのボンボン
GLOBAL int img_ch_hit;	//当たり判定
GLOBAL int img_magic[2];//魔法陣の画像


//－－－－－/
// 敵
//－－－－－/
GLOBAL int img_enemy[3][9];	//敵ドット絵
GLOBAL int img_boss;		//ボスドット絵


//－－－－－/
//弾幕
//－－－－－/
GLOBAL int img_bullet2[2][24];							//弾幕画像　色情報　形状
GLOBAL int img_lazer[10][10], img_lazer_moto[10][10];	//レーザー画像
GLOBAL int img_cshot[2][2];								//プレイヤー弾幕　赤と青　２種類ずつ


//－－－－－/
//エフェクト
//－－－－－/
GLOBAL int img_del_effect[5];	//消滅エフェクト用画像
GLOBAL int img_eff_bom[5];		//ボムのエフェクト画像
GLOBAL int img_particle[2];		//パーティクルの画像

//－－－－－/
//その他
//－－－－－/
GLOBAL int img_etc[50];		//その他の画像
GLOBAL int img_item[6][2];	//アイテムの画像
GLOBAL int img_num[3][12];	//数字の画像(41)


//－－－－－－－－－－/
//音楽ファイル用変数
//－－－－－－－－－－/
GLOBAL int sound_se[SE_MAX];


//－－－－－－－－－－/
//フラグ・ステータス変数
//－－－－－－－－－－/
GLOBAL int func_state, stage_count, count, stage;	//関数制御用変数
GLOBAL int se_flag[SE_MAX];							//サウンドフラグ


//－－－－－－－－－－/
//制御用変数
//－－－－－－－－－－/
GLOBAL int stage_title_count[STAGE_NUM];

//画面制御
GLOBAL int title_pattern;		//タイトル画面　切り替え
GLOBAL int menu_pattern;		//メニュー画面　切り替え
GLOBAL int gameover_pattern;	//ゲームオーバー画面　切り替え
GLOBAL int result_flg;			//リザルト画面　処理制御
GLOBAL int result_rank;			//リザルト画面　ランク処理

//難易度とモード
GLOBAL int game_level;	//難易度
GLOBAL int game_mode;	//０残機　１スコアから引く

//魔法陣
GLOBAL float magic_size;	//魔法陣の大きさ
GLOBAL int magic_time;		//魔法陣の回転速度


//－－－－－－－－－－/
// リザルト計算用
//－－－－－－－－－－/

GLOBAL double elapsed_time;		//経過時間
GLOBAL int final_score;			//最終的なスコア
GLOBAL int sum_score;			//スコアの合計点
GLOBAL int bonus;				//難易度ボーナス
GLOBAL int mode_tmp, level_tmp;	//ゲームモード、ゲーム難易度の仮保存


//－－－－－－－－－－/
// ランキング用変数
//－－－－－－－－－－/
GLOBAL int ranking_score[RANKING_MAX + 1];	//ランキングスコア + クリア時のスコア


//－－－－－－－－－－/
//色とフォント
//－－－－－－－－－－/
GLOBAL int color[20],font[20];//色(41) フォント(44)



//－－－－－－－－－－－－－－－－－－－－－/
//構造体変数宣言部
//－－－－－－－－－－－－－－－－－－－－－/
GLOBAL ch_t ch;										//キャラクタデータ宣言
GLOBAL enemy_t enemy[ENEMY_MAX];					//敵情報
GLOBAL configpad_t configpad;						//コンフィグで設定したキー情報
GLOBAL enemy_order_t enemy_order[ENEMY_ORDER_MAX];	//敵の出現情報
GLOBAL shot_t shot[SHOT_MAX];						//ショット情報
GLOBAL boss_shot_t boss_shot;						//ボスショット情報
GLOBAL cshot_t cshot[CSHOT_MAX];					//自機ショット
GLOBAL del_effect_t del_effect[DEL_EFFECT_MAX];		//消滅エフェクト
GLOBAL effect_t effect[EFFECT_MAX];					//エフェクト
GLOBAL bullet_info_t bullet_info[24];				//弾情報
GLOBAL bom_t bom;									//ボム
GLOBAL bright_set_t bright_set;						//描画の輝度
GLOBAL dn_t dn;										//ドンと揺れる
GLOBAL boss_t boss;									//ボス情報
GLOBAL lazer_t lazer[LAZER_MAX];					//レーザー
GLOBAL child_t child[CHILD_MAX];					//弾幕の発射位置に表示するエフェクト
GLOBAL stage_title_t stage_title;					//ステージタイトル
GLOBAL item_t item[ITEM_MAX];						//アイテム
GLOBAL flash_t flash;								//(42)
GLOBAL area_t area;									//そのエリアで持っているデータ(48)
GLOBAL option_bb_t option_bb[2];					//オプション発射元ボンボン(49)

//パーティクル
GLOBAL Particle particle[PARTICLE_MAX];

//経過時間用
GLOBAL clock_t start;	//開始時間
GLOBAL clock_t end;		//終了時間


//－－－－－－－－－－－－－－－－－－－－－/
// 列挙型宣言
//－－－－－－－－－－－－－－－－－－－－－/

//色情報
GLOBAL enum {
	red=0,	//赤色弾幕　
	blue=1,	//青色弾幕
};

//ゲームの場面
GLOBAL enum {
	start_loading,	//一番最初のダウンロード
	title,			//タイトル表示状態
	levelselection,	//難易度選択
	game_setting,	//STGの開始前セッティング
	game_play,		//ゲームプレイ中
	game_over,		//ゲームオーバー
	menu,			//メニュー表示中
	result,			//結果画面
	ranking,		//ランキング表示中
};

//ゲームの難易度
GLOBAL enum {
	normal,		//普通
	hard,		//難しい
	lunatic,	//狂気
};

//ゲームモード
GLOBAL enum {
	life,	//残機を使用して復活
	score,	//スコアを使用して復活
};

//リザルトのランク
GLOBAL enum {
	bronze=0,	//銅
	silver,		//銀
	gold,		//金
	platinum,	//プラチナ
	diamond,	//ダイヤモンド
};