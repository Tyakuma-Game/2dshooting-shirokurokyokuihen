#include "../include/GV.h"


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�@�������m��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void music_ini(){
	memset(se_flag,0,sizeof(int)*SE_MAX);
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���ʉ��Đ�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void music_play(){
	int i;
	for(i=0;i<SE_MAX;i++){
		if(se_flag[i]==1){//���ʉ��t���O�������Ă���
			if (CheckSoundMem(sound_se[i]) != 0) {
				if(i==8)continue;
				StopSoundMem(sound_se[i]);//���ʉ����~�߂�
			}
			PlaySoundMem(sound_se[i],DX_PLAYTYPE_BACK);//�Đ�
		}
	}
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
// BGM��ǂݍ���
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void load_bgm(int flag){
	char str[64];
	sprintf(str,"../dat/music/%d_%d.ogg",stage,flag);
	area.bgm.handle=LoadSoundMem(str);
	ChangeVolumeSoundMem(64, area.bgm.handle);//���ʐݒ�
}

//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
// BGM���폜����
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void delete_bgm(){
	DeleteSoundMem(area.bgm.handle);//���y�폜
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
// BGM����
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void bgm_main(){

	//�^�C�g��BGM
	if(area.bgm.flag==0){
		load_bgm(0);//�ǂݍ���
		SetLoopPosSoundMem(area.bgm.loop_pos[0], area.bgm.handle);//���[�v�ʒu�Z�b�g
		PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//�Đ��J�n
		area.bgm.flag=1;//�t���O�ύX
	}

	//�ʏ�BGM
	if(area.bgm.flag==1){
		if (stage_count == 60) {//�J�n����n�b��ɊJ�n
			delete_bgm();//�폜
			load_bgm(1); //�ǂݍ���
			SetLoopPosSoundMem(area.bgm.loop_pos[0], area.bgm.handle);//���[�v�ʒu�Z�b�g
			PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//�Đ��J�n
			area.bgm.flag = 2;//�t���O�ύX
		}
	}

	//�{�XBGM
	if(area.bgm.flag==2){
		if(stage_count==boss.appear_count[1]){//�{�X�̏o�����ԂƓ����Ȃ�
			StopSoundMem(area.bgm.handle);	//��~
			delete_bgm();					//�폜
			load_bgm(2);					//�ǂݍ���
			SetLoopPosSoundMem( area.bgm.loop_pos[1], area.bgm.handle );//���[�v�ʒu�Z�b�g
			PlaySoundMem(area.bgm.handle, DX_PLAYTYPE_LOOP);//�Đ�
			area.bgm.flag=3;//�t���O�ύX
		}
	}
}