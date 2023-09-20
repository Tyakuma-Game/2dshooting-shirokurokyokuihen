#include "../include/GV.h"

extern int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag);


//|||||||||||||||||||||/
// ’Êí”wŒi
//|||||||||||||||||||||/
void graph_back00(){

	//•`‰æ‰Â”\ƒGƒŠƒA‚ğİ’è
	SetDrawArea( 32 , 16 , 416 , 464 ) ;

	//•`‰æŠÖ”‚É“n‚·
	DrawGraphFd(0,count%700-700,img_back[0],FALSE);
	DrawGraphFd(0,count%700    ,img_back[0],FALSE);
	
	//ƒGƒŠƒA‚ğ–ß‚·
	SetDrawArea( 0, 0, 640, 480);
}


//|||||||||||||||||||||/
// ƒXƒyƒ‹ƒJ[ƒh—p”wŒi
//|||||||||||||||||||||/
void graph_back01(){

	//•`‰æ‰Â”\ƒGƒŠƒA‚ğİ’è
	SetDrawArea( 32 , 16 , 416 , 464 ) ;

	//•`‰æŠÖ”‚É“n‚·
	DrawGraphFd(0,-count%480,img_back[11],FALSE);
	DrawGraphFd(0,-count%480+480,img_back[11],FALSE);
	DrawGraphFd(0,0,img_back[10],TRUE);

	//ƒGƒŠƒA‚ğ–ß‚·
	SetDrawArea( 0, 0, 640, 480);
}


//|||||||||||||||||||||/
// ”wŒi•\¦ƒƒCƒ“
//|||||||||||||||||||||/
void graph_back_main(){
	//ƒ{ƒX‚ªƒIƒ“‚ÅAƒXƒyƒ‹ƒJ[ƒh‚È‚ç
	if(boss.flag==1 && boss.back_knd[boss.knd]==1){
		graph_back01();
	}
	else{//‚»‚êˆÈŠO
		graph_back00();
	}
}