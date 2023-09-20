#include "../include/GV.h"


//－－－－－－－－－－－－－－－－－－－－－/
//　メモリ確保
//－－－－－－－－－－－－－－－－－－－－－/
void music_ini(){
	memset(se_flag,0,sizeof(int)*SE_MAX);
}


//－－－－－－－－－－－－－－－－－－－－－/
// 効果音再生
//－－－－－－－－－－－－－－－－－－－－－/
void music_play(){
	int i;
	for(i=0;i<SE_MAX;i++){
		if(se_flag[i]==1){//効果音フラグが立っている
			if (CheckSoundMem(sound_se[i]) != 0) {
				if(i==8)continue;
				StopSoundMem(sound_se[i]);//効果音を止める
			}
			PlaySoundMem(sound_se[i],DX_PLAYTYPE_BACK);//再生
		}
	}
}


//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
// BGMを読み込む
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
void load_bgm(int flag){
	char str[64];
	sprintf(str,"../dat/music/%d_%d.ogg",stage,flag);
	area.bgm.handle=LoadSoundMem(str);
	ChangeVolumeSoundMem(64, area.bgm.handle);//音量設定
}

//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
// BGMを削除する
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
void delete_bgm(){
	DeleteSoundMem(area.bgm.handle);//音楽削除
}


//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
// BGM制御
//ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー/
void bgm_main(){

	//タイトルBGM
	if(area.bgm.flag==0){
		load_bgm(0);//読み込み
		SetLoopPosSoundMem(area.bgm.loop_pos[0], area.bgm.handle);//ループ位置セット
		PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//再生開始
		area.bgm.flag=1;//フラグ変更
	}

	//通常BGM
	if(area.bgm.flag==1){
		if (stage_count == 60) {//開始からn秒後に開始
			delete_bgm();//削除
			load_bgm(1); //読み込み
			SetLoopPosSoundMem(area.bgm.loop_pos[0], area.bgm.handle);//ループ位置セット
			PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//再生開始
			area.bgm.flag = 2;//フラグ変更
		}
	}

	//ボスBGM
	if(area.bgm.flag==2){
		if(stage_count==boss.appear_count[1]){//ボスの出現時間と同じなら
			StopSoundMem(area.bgm.handle);	//停止
			delete_bgm();					//削除
			load_bgm(2);					//読み込み
			SetLoopPosSoundMem( area.bgm.loop_pos[1], area.bgm.handle );//ループ位置セット
			PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//再生
			area.bgm.flag=3;//フラグ変更
		}
	}
}