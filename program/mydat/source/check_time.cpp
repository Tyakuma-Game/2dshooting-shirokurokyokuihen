#include "../include/GV.h"


#define STR_MAX 64	//–¼‘O‚ÌÅ‘å•¶š”
#define FUNC_MAX 30	//’²‚×‚ç‚ê‚éŠÖ”‚ÌÅ‘å”

//¡‰½ŒÂ–Ú‚©‚ğƒJƒEƒ“ƒg‚·‚é
int func_count;

//‘O‰ñ‘ª’è‚µ‚½ŠÔ‚ğ•Û‘¶‚·‚é
LONGLONG lt;

//‘ª’èƒf[ƒ^Ši”[—p•Ï”
typedef struct{
	int tm;
	char str[STR_MAX];
}func_tm_t;
func_tm_t func_tm[FUNC_MAX];


//|||||||||||||||||||||/
//st‚Æ‚¢‚¤–¼‘O‚Åó‚¯æ‚Á‚½ƒf[ƒ^‚ğ“o˜^‚·‚éBflag‚ª1‚È‚çƒŠƒZƒbƒg
//|||||||||||||||||||||/
void enter_func_tm(char st[], int flag){
	int i;
	LONGLONG nowtm;
	if(func_count>=FUNC_MAX){
		printfDx("func_count‚Ì’l%d‚ªˆÙí‚Å‚·\n",func_count);
		return;
	}

	nowtm=GetNowHiPerformanceCount() ;

	//int‚Ìˆµ‚¦‚é”ÍˆÍ‚È‚ç
	if(nowtm-lt<INT_MAX){
		func_tm[func_count].tm=(int)(nowtm-lt);			//ˆ—ŠÔŠi”[
		memcpy(func_tm[func_count].str,st,STR_MAX-1);	//•¶š—ñƒRƒs[
		func_tm[func_count].str[STR_MAX-1]=0;			//I’[‹L†“ü‚ê‚é
	}
	else{//ˆµ‚¦‚È‚©‚Á‚½‚ç
		func_tm[func_count].tm=-1;//ƒGƒ‰[
	}

	//‘O‰ñ‹L˜^‚µ‚½‚Æ‚µ‚Ä•Û‘¶
	lt = nowtm;

	//ƒŠƒZƒbƒg
	if(flag==1){
		for(i=func_count+1;i<FUNC_MAX;i++){
			func_tm[i].str[0]=0;
		}
		func_count=0;
	}
	else{
		func_count++;
	}
}


//|||||||||||||||||||||/
//ƒf[ƒ^‚ğ•`‰æ
//|||||||||||||||||||||/
void draw_func_tm(int x, int y){
	int i;
	unsigned int total=0;
	for(i=0;i<FUNC_MAX;i++){
		if (func_tm[i].str[0] == 0) {
			break;
		}
		DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"%05.2f:%s",func_tm[i].tm/1000.0,func_tm[i].str );
		total+=func_tm[i].tm;
	}

	//DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"‡Œv:%05.2f",total/1000.0);
}