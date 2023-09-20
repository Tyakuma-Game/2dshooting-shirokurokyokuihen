
//－－－－－－－－－－－－－－－－－－－－－/
// 定数に関する事全般
//－－－－－－－－－－－－－－－－－－－－－/

//－－－－－－－－－－/
//円周率
//－－－－－－－－－－/
#define PI 3.1415926535898	//π（円周率）
#define PI2 (PI*2)			//π^2（円周率の二乗）


//－－－－－－－－－－/
//ステージ
//－－－－－－－－－－/
#define FMX 384				//X座標最大値
#define FMY 448				//Y座標最大値

#define FX 32				//左上のX座標
#define FY 16				//左上のY座標

#define STAGE_NUM 5			//ステージ数


//ーーーーーーーーー/
// プレイヤー
//ーーーーーーーーー/

//当たり判定
#define CRANGE 2.0			//自機当たり判定
#define CRANGE11 5.0		//自機当たり判定
#define CRANGE_COLOR 35.0	//色当たり判定

//ボムで消費するパワー（エネルギー）
#define BOM_ENERGY 100

//クールタイム
#define COLOR_COOL_TIME 12 //色変更クールタイム

//スコア範囲
#define SCORE_MAX 999999999
#define SCORE_MIN 0

//パワー範囲
#define POWER_MAX 500
#define POWER_MIN 1

//その他の範囲
#define OTHER_MAX 9999


//－－－－－－－－－－/
//ボスに関する事
//－－－－－－－－－－/
#define BOSS_POS_X (FMX/2)		//ボスの出現位置X座標
#define BOSS_POS_Y (FMY/4)		//ボスの出現位置Y座標


//－－－－－－－－－－/
// 敵に関する事
//－－－－－－－－－－/
#define ENEMY_MAX 30			//敵の同時表示最大数
#define ENEMY_ORDER_MAX 500		//敵の出現情報最大数
#define ENEMY_PATTERN_MAX 11	//敵の行動パターンの最大数


//－－－－－－－－－－/
// 弾幕
//－－－－－－－－－－/
#define DANMAKU_MAX 50	//弾幕最大数
#define SHOT_MAX 30		//一度に画面に表示できる敵の弾幕の最大数
#define SHOT_KND_MAX 18	//ショットの種類の最大数

#define LAZER_MAX 100	//レーザー

#define CSHOT_MAX 200			//自機ショットの登録最大数
#define SHOT_BULLET_MAX 1000	//敵１匹が持つ弾の最大数
#define BOSS_BULLET_MAX 3000	//ボスが持つ弾の最大数


//－－－－－－－－－－/
// サウンド
//－－－－－－－－－－/
#define SE_MAX 100	//効果音の種類の最大数


//－－－－－－－－－－/
// パッド
//－－－－－－－－－－/
#define PAD_MAX 16	//パッドキーの最大数


//－－－－－－－－－－/
// エフェクト
//－－－－－－－－－－/
#define EFFECT_MAX 100		//エフェクト登録最大数
#define DEL_EFFECT_MAX 30	//消滅エフェクト登録最大数
#define PARTICLE_MAX 200	//パーティクルの最大数

#define CHILD_MAX 20


//－－－－－－－－－－/
// アイテム
//－－－－－－－－－－/
#define ITEM_MAX 100				//アイテムの表示最大数
#define ITEM_GET_BORDER_LINE 100	//アイテムゲットボーダーライン
#define ITEM_INDRAW_RANGE 70		//アイテムの吸収範囲
#define ITEM_HIT_BOX 20				//アイテムの当たり判定


//－－－－－－－－－－/
// スコアに関する事
//－－－－－－－－－－/
#define RANKING_MAX 10//ランキングの最大数

//ランク付け
#define RANKING_BORDER_BRONZE 100000
#define RANKING_BORDER_SILVER	(RANKING_BORDER_BRONZE*2)
#define RANKING_BORDER_GOLD		(RANKING_BORDER_BRONZE*3)
#define RANKING_BORDER_PLATINUM (RANKING_BORDER_BRONZE*4)

//アイテムのボーナス値
#define POWER_BONUS_SCORE 100//パワー
#define KILL_BONUS_SCORE  110//敵討伐数
#define MONEY_BONUS_SCORE 150//お金
#define GRAZE_BONUS_SCORE 200//グレイズ
#define POINT_BONUS_SCORE 500//ポイント

#include "struct.h"