
//|||||||||||||||||||||/
//ƒLƒƒƒ‰ƒNƒ^[‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int color;		//Fî•ñ
	int color_count;//F•ÏXƒN[ƒ‹ƒ^ƒCƒ€
	int kill_count;	//“G‚ğ“|‚µ‚½”
	int miss;		//ƒ~ƒX‚Ì‰ñ”
	int retry;		//•œŠˆ‰ñ”
	int flag;		//ƒtƒ‰ƒO
	int cnt;		//ƒJƒEƒ“ƒ^
	int power;		//ƒpƒ[
	int point;		//ƒ|ƒCƒ“ƒg
	int score;		//ƒXƒRƒA
	int score_max;	//ƒXƒRƒA‚ÌÅ‘å’l
	int life;		//c‹@”
	int mutekicnt;	//–³“Gó‘Ô‚ÆƒJƒEƒ“ƒg
	int shot_mode;	//ƒVƒ‡ƒbƒgƒ‚[ƒh
	int money;		//‚¨‹à
	int img;		//‰æ‘œ
	int slow;		//ƒXƒ[‚©‚Ç‚¤‚©
	double x,y;		//À•W
	int shot_cnt;	//ƒVƒ‡ƒbƒgƒJƒEƒ“ƒg
	int graze;		//ƒOƒŒƒCƒY(41)
}ch_t;

typedef struct{
	double x,y;
}pt_t;


//|||||||||||||||||||||/
//“G‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,pattern,muki,knd,hp,hp_max,item_n[6],img,back_col;
	//ƒtƒ‰ƒOAƒJƒEƒ“ƒ^AˆÚ“®ƒpƒ^[ƒ“AŒü‚«A“G‚Ìí—ŞAHPÅ‘å’lA—‚Æ‚·ƒAƒCƒeƒ€A”wŒiF
	double x,y,vx,vy,sp,ang;
	//À•WA‘¬“xx¬•ªA‘¬“xy¬•ªAƒXƒs[ƒhAŠp“x
	int bltime, blknd, blknd1, col, state, wtime, wait;
	//’e–‹ŠJnŠÔA’e‚Ìí—ŞAFAó‘ÔA‘Ò‹@ŠÔA’â‘ØŠÔ
}enemy_t;

typedef struct{
	//ƒJƒEƒ“ƒ^AˆÚ“®ƒpƒ^[ƒ“A“G‚Ìí—Ş
	int cnt,pattern,knd;
	//‰ŠúÀ•W‚ÆˆÚ“®ƒXƒs[ƒh
	double x,y,sp;
	//’e–‹ŠJnŠÔA’e–‹‚Ìí—ŞAFA‘Ì—ÍA’e‚Ìí—ŞA’â‘ØŠÔAƒAƒCƒeƒ€(6í—Ş)
	int bltime, blknd, blknd1, col, hp, wait, item_n[6];
}enemy_order_t;


//|||||||||||||||||||||/
//ƒpƒbƒh‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int key[PAD_MAX];
}pad_t;


//|||||||||||||||||||||/
//ƒRƒ“ƒtƒBƒO‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;


//|||||||||||||||||||||/
// ƒp[ƒeƒBƒNƒ‹
//|||||||||||||||||||||/
typedef struct{
	int cnt_time;	//Á–ÅŠÔ
	int flag;		//ê–Ê‚É‘¶İ‚µ‚Ä‚¢‚é‚©
	int color;		//F
	float x, y;		//À•W
	float vx, vy;	//‰Á‘¬“x
} Particle;


//|||||||||||||||||||||/
//’e‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAí—ŞAƒJƒEƒ“ƒ^AFAó‘ÔA­‚È‚­‚Æ‚àÁ‚³‚È‚¢ŠÔAƒGƒtƒFƒNƒg‚Ìí—Ş
	int flag,knd,knd1,cnt,col,state,till,eff,kaiten,eff_detail;
	int cnt_till,cnt_stt;
	//À•WAŠp“xA‘¬“xAƒx[ƒX‚ÌŠp“xAˆê‹L‰¯ƒXƒs[ƒh
	double x,y,vx,vy,angle,spd,base_angle[1],rem_spd[1];
	int c_flag;
	double cx,cy;
}bullet_t;


//|||||||||||||||||||||/
//ƒVƒ‡ƒbƒg‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAí—ŞAƒJƒEƒ“ƒ^A‚Ç‚Ì“G‚©‚ç”­Ë‚³‚ê‚½‚©‚Ì”Ô†AF
	int flag,knd,knd1,cnt,num;
	//ƒx[ƒXŠp“xAƒx[ƒXƒXƒs[ƒh
	double base_angle[1],base_spd[1];

	bullet_t bullet[SHOT_BULLET_MAX];
}shot_t;


//|||||||||||||||||||||/
//ƒVƒ‡ƒbƒg‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAí—ŞAƒJƒEƒ“ƒ^A‚Ç‚Ì“G‚©‚ç”­Ë‚³‚ê‚½‚©‚Ì”Ô†AF
	int flag,knd,cnt,num;
	//ƒx[ƒXŠp“xAƒx[ƒXƒXƒs[ƒh
	double base_angle[10],base_spd[1];
	bullet_t bullet[BOSS_BULLET_MAX];
	bullet_t assist[6];
}boss_shot_t;


//|||||||||||||||||||||/
//ƒLƒƒƒ‰ƒNƒ^[ƒVƒ‡ƒbƒg‚ÉŠÖ‚·‚é\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int flag;		//ƒtƒ‰ƒO
	int power;		//ƒpƒ[
	int cnt;		//ƒJƒEƒ“ƒ^
	int knd;		//í—Ş

	//‚±‚±‚É•ÏX‚ğ‰Á‚¦‚Ä‚é
	int img;		//‰æ‘œ(49)
	
	
	double x,y;		//À•W
	double angle;	//Šp“x
	double spd;		//ƒXƒs[ƒh
}cshot_t;


//|||||||||||||||||||||/
//ƒVƒ‡ƒbƒg‚ÌƒIƒvƒVƒ‡ƒ“”­ËŒ³ƒ{ƒ“ƒ{ƒ“
//|||||||||||||||||||||/
typedef struct{
	int flag;	//ƒtƒ‰ƒO
	int img;	//‰æ‘œ
	int cnt;	//ƒJƒEƒ“ƒ^
	double x,y;	//À•W
}option_bb_t;


//|||||||||||||||||||||/
//ƒGƒtƒFƒNƒg
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,col,knd,img,eff;
	double x,y,r,ang,spd,mvang,brt;
}effect_t;


//|||||||||||||||||||||/
//Á–ÅƒGƒtƒFƒNƒg
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,col;
	double x,y;
}del_effect_t;


//|||||||||||||||||||||/
//’e‚Ìî•ñ@“–‚½‚è”»’è
//|||||||||||||||||||||/
typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;


//|||||||||||||||||||||/
//ƒ{ƒ€‚Ìî•ñ
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,knd;
	double x,y;
}bom_t;


//|||||||||||||||||||||/
//‰æ–Ê‚Ì–¾‚é‚³î•ñ
//|||||||||||||||||||||/
typedef struct{
	unsigned char brt;
}bright_set_t;


//|||||||||||||||||||||/
//ƒhƒ“I‚Æ—h‚ê‚é‰æ–Ê‚Ìî•ñ
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,time,size;
	int x,y;
}dn_t;


//|||||||||||||||||||||/
//•¨—“IŒvZ‚ğs‚¤ˆ×‚Ì\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,set_t;
	double ax,v0x,ay,v0y,vx,vy,prex,prey;
}phy_t;


//|||||||||||||||||||||/
//ƒŒ[ƒU[‚Ì•¨—“IŒvZ‚ğs‚¤ˆ×‚Ì\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int conv_flag;
	double time,base_ang,angle;
	double conv_x,conv_y,conv_base_x,conv_base_y;
}lphy_t;


//|||||||||||||||||||||/
//ƒ{ƒX‚Ìî•ñ
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAƒJƒEƒ“ƒ^Aí—ŞA‘Ò‹@ŠÔAó‘ÔA’e–‹I—¹‚Ü‚Å‚ÌƒJƒEƒ“ƒ^AŒã‚ë‚Ì‰HˆßA•\¦ƒtƒ‰ƒO
	int flag,cnt,knd,wtime,state,endtime,hagoromo,graph_flag;
	//HP,Å‘åHP
	int hp,hp_max;
	//oŒ»ƒJƒEƒ“ƒ^”AŠe’e–‹‚ÌHPA”wŒi‚Ìí—ŞA’†ƒ{ƒX-ƒ‰ƒXƒ{ƒX‚Ì’e–‹”(45)
	int appear_count[2],set_hp[DANMAKU_MAX],back_knd[DANMAKU_MAX],danmaku_num[2];
	//À•W
	double x,y,dx,dy,ang,spd;
	//•¨—ˆÚ“®‚Ì‚½‚ß‚Ì•Ï”
	phy_t phy;
}boss_t;


//|||||||||||||||||||||/
//ƒŒ[ƒU[‚Ì\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,knd,col,state;//ƒtƒ‰ƒOAƒJƒEƒ“ƒ^Aí—ŞAF
	double haba,angle,length,hantei;//•AŠp“xA’·‚³A”»’è”ÍˆÍ(•\¦•‚É‘Î‚µ‚Ä0~1‚Åw’è)A‰ñ“]‘¬“x
	pt_t startpt,disppt[4],outpt[4];//ƒŒ[ƒU[‚ğ”­Ë‚·‚én“_A•\¦À•WA“–‚½‚è”»’è”ÍˆÍ
	lphy_t lphy;
}lazer_t;


//|||||||||||||||||||||/
//’e–‹‚Ì”­ËˆÊ’u‚É•\¦‚·‚éƒGƒtƒFƒNƒg
//|||||||||||||||||||||/
typedef struct{
	int flag,cnt,knd,col,state;
	double x,y,angle,spd,range;
}child_t;


//|||||||||||||||||||||/
//ƒQ[ƒ€ƒXƒe[ƒWƒ^ƒCƒgƒ‹
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOA‰æ‘œƒnƒ“ƒhƒ‹AƒJƒEƒ“ƒ^A‹P“xAoŒ»ƒJƒEƒ“ƒg
	int flag,img,cnt,brt,appear_cnt;
}stage_title_t;


//|||||||||||||||||||||/
//ƒAƒCƒeƒ€‚Ì\‘¢‘Ì
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAƒJƒEƒ“ƒ^Aí—ŞAó‘Ô
	int flag,cnt,knd,state;
	//‘¬“xAÀ•WA‘å‚«‚³
	double v,x,y,r;
}item_t;


//|||||||||||||||||||||/
//ƒtƒ‰ƒbƒVƒ…(42)
//|||||||||||||||||||||/
typedef struct{
	//ƒtƒ‰ƒOAƒJƒEƒ“ƒ^Aƒtƒ‰ƒbƒVƒ…‚Ìí—ŞA‰½ƒJƒEƒ“ƒg‚Å•\Œ»‚·‚é‚©
	int flag,cnt,knd,to_cnt;
	//–¾‚é‚³
	double brt;
}flash_t;


//|||||||||||||||||||||/
//BGMî•ñ(area_t‚Åg—p
//|||||||||||||||||||||/
typedef struct{
	//BGM‚ÌÄ¶ƒtƒ‰ƒOAÄ¶ƒnƒ“ƒhƒ‹A‚¢‚Â‚È‚ç‚·‚©Ä¶í—Ş”Ô†‚ğ‚¢‚ê‚éAƒ‹[ƒvˆÊ’u
	int flag,handle,knd[3],loop_pos[3];
}bgm_t;


//|||||||||||||||||||||/
//‚»‚ÌƒGƒŠƒA‚ª‚Á‚Ä‚¢‚éî•ñ(48)
//|||||||||||||||||||||/
typedef struct{
	bgm_t bgm;
}area_t;