
extern void boss_shot_bulletH000();//円形発射
extern void boss_shot_bulletH001();//サイレントセレナ
extern void boss_shot_bulletH002();//パーフェクトフリーズ
extern void boss_shot_bulletH003();//恋の迷路
extern void boss_shot_bulletH004();//ケロちゃん雨風にも負けず
extern void boss_shot_bulletH005();//★弾幕
extern void boss_shot_bulletH006();//周りから中央に
extern void boss_shot_bulletH007();//周りから直線
extern void boss_shot_bulletH008();//反魂蝶
extern void boss_shot_bulletH015();//円形発射とサイレントセレナ
extern void boss_shot_bulletH016();//中央に合わせて２つ迫ってくる
extern void boss_shot_bulletH017();//パーフェクトフリーズと周りから直線
extern void boss_shot_bulletH018();//反魂蝶と円形発射
extern void boss_shot_bulletH019();//中央に合わせて２つ迫ってくる 円形発射


//－－－－－－－－－－－－－－－/
// 難易度ノーマルのボス弾幕
//－－－－－－－－－－－－－－－/
void (*boss_shot_bullet_normal[DANMAKU_MAX])() = {

//中ボス（２つ弾幕）
    boss_shot_bulletH000,//円形発射
    boss_shot_bulletH006,//周りから中央に

//ラスボス（３つ弾幕）
    boss_shot_bulletH007,//周りから直線
    boss_shot_bulletH002,//パーフェクトフリーズ
    boss_shot_bulletH001,//サイレントセレナ

//終り
    boss_shot_bulletH000,//ぬるぽ回避用(この弾幕は出てこない)
};


//－－－－－－－－－－－－－－－/
// 難易度ハードのボス弾幕
//－－－－－－－－－－－－－－－/
void (*boss_shot_bullet_hard[DANMAKU_MAX])() = {

//中ボス（２つ弾幕）
    boss_shot_bulletH005,//星型弾幕
    boss_shot_bulletH001,//サイレントセレナ

//ラスボス（３つ弾幕）
    boss_shot_bulletH016,//中央に合わせて２つ迫ってくる
    boss_shot_bulletH004,//ケロちゃん雨風にも負けず
    boss_shot_bulletH015,//円形発射とサイレントセレナ

//終り
    boss_shot_bulletH000,//ぬるぽ回避用(この弾幕は出てこない)
};


//－－－－－－－－－－－－－－－/
// 難易度ルナティックのボス弾幕
//－－－－－－－－－－－－－－－/
void (*boss_shot_bullet_lunatic[DANMAKU_MAX])() = {

//中ボス（２つ弾幕）
    boss_shot_bulletH015,//円形発射とサイレントセレナ
    boss_shot_bulletH017,//パーフェクトフリーズと周りから直線

//ラスボス（３つ弾幕）
    boss_shot_bulletH003,//恋の迷路
    boss_shot_bulletH019,//中央に合わせて２つ迫ってくる 円形発射
    boss_shot_bulletH018,//反魂蝶と円形発射

//終り
    boss_shot_bulletH000,//ぬるぽ回避用(この弾幕は出てこない)
};
