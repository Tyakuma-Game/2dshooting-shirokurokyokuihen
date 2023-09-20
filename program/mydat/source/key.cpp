#include "../include/GV.h"

//�L�[�̓��͏�Ԃ��i�[����ϐ�
unsigned int stateKey[256];

//�p�b�h�̓��͏�Ԃ��i�[����ϐ�
pad_t pad;


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
// �L�[���͏����擾
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int GetHitKeyStateAll_2(){
    char GetHitKeyStateAll_Key[256];			//�L�[�����i�[
    GetHitKeyStateAll( GetHitKeyStateAll_Key );	//�L�[���������Ă���

	//�ǂ̓��͂��m���߂�
    for(int i=0;i<256;i++){
		if (GetHitKeyStateAll_Key[i] == 1) {
			stateKey[i]++;
		}
		else {
			stateKey[i] = 0;
		}
    }

    return 0;
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
// ���̃L�[��������Ă��邩�m���߂�
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�����P�ƈ����Q�̂����傫�����������P�ɑ��
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void input_pad_or_key(int *p, int k){
	*p = *p>k ? *p : k;
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�p�b�h�ƃL�[�{�[�h�̗����̓��͂��`�F�b�N
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void GetHitPadStateAll(){
	int i,PadInput,mul=1;
	PadInput = GetJoypadInputState( DX_INPUT_PAD1 );//�p�b�h�̓��͏�Ԃ��擾
	for(i=0;i<16;i++){
		if(PadInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
		mul*=2;
	}

	//�[�[�[�[�[�[�[�[�[/
	// �L�[�ƃp�b�h�m���߂�
	//�[�[�[�[�[�[�[�[�[/
	input_pad_or_key(&pad.key[configpad.left]	,CheckStateKey(KEY_INPUT_LEFT	 ));//��
	input_pad_or_key(&pad.key[configpad.up]	    ,CheckStateKey(KEY_INPUT_UP	     ));//��
	input_pad_or_key(&pad.key[configpad.right]  ,CheckStateKey(KEY_INPUT_RIGHT	 ));//�E
	input_pad_or_key(&pad.key[configpad.down]	,CheckStateKey(KEY_INPUT_DOWN	 ));//��
	input_pad_or_key(&pad.key[configpad.shot]	,CheckStateKey(KEY_INPUT_Z	     ));//�e������
	input_pad_or_key(&pad.key[configpad.bom]	,CheckStateKey(KEY_INPUT_X		 ));//�{���g�p
	input_pad_or_key(&pad.key[configpad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	 ));//�ᑬ�ړ�
	input_pad_or_key(&pad.key[configpad.start]  ,CheckStateKey(KEY_INPUT_ESCAPE	 ));//�Q�[���I��
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�n���ꂽ�p�b�h�L�[�ԍ��̓��͏�Ԃ�Ԃ�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
int CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return pad.key[Handle];
	}
	else{
		printfDx("CheckStatePad�ɓn�����l���s���ł�\n");
		return -1;
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �^�C�g����ʂ̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void TitleInput() {
	
	//�I��؂�ւ�
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && title_pattern != 0) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		title_pattern--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && title_pattern != 1) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		title_pattern++;
	}

	//�G���^�[�L�[ / start���͂Ŏ��s
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		switch (title_pattern){
		case 0:func_state = levelselection; break;			//��Փx�I�����
		case 1:ranking_load(); func_state = ranking; break;	//�����L���O
		}		
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ��Փx�I���̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void LevelSelectionInput() {
	//�Q�[�����[�h�ύX
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && game_mode != score) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		game_mode++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && game_mode != life) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		game_mode--;
	}

	//��Փx�ύX
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && game_level != normal) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		game_level--;
	}
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && game_level != lunatic) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		game_level++;
	}

	//�Q�[���J�n  �G���^�[���� / start����
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		StopSoundMem(area.bgm.handle);
		mode_tmp = game_mode;		//�Q�[�����[�h�i�[
		level_tmp = game_level;		//�Q�[����Փx�i�[
		func_state = game_setting;	//��ʂ��Z�b�e�B���O�ɕύX
	}

}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �Q�[�����̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void GamePlyInput() {
	//�F�ύX
	ch.color_count++;
	if ((CheckStateKey(KEY_INPUT_C) == 1 || CheckStatePad(7) == 1) && ch.color_count > COLOR_COOL_TIME) {//C�L�[�AB�{�^���ŐF�ύX
		se_flag[19] = 1;		//�F�ύX�̉�
		ch.color_count = 0;		//�N�[���^�C���p
		ch.color ^= blue;		//��F��؂�ւ�
		magic_size = 0.9f;		//���@�w�̑傫��
	}

	//���j���[�\���@ �G���^�[ / start����
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		menu_pattern = 0;	//�\���摜���w��
		func_state = menu;	//��ʂ����j���[�\�����ɕύX
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���j���[��ʂ̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void MenuInput() {
	//�I��؂�ւ�
	if ((CheckStateKey(KEY_INPUT_DOWN) == 1 || CheckStatePad(configpad.down) == 1) && menu_pattern != 3) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		menu_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_UP) == 1 || CheckStatePad(configpad.up) == 1) && menu_pattern != 0) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		menu_pattern--;
	}

	//�G���^�[�L�[ / start���͂Ŏ��s
	if ((CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1)) {
		se_flag[18] = 1;//����̉�
		switch (menu_pattern) {
		case 0:  func_state = game_play; break;							//�Q�[�����ĊJ
		case 1: enter_boss_shot(1); func_state = game_setting; StopSoundMem(area.bgm.handle); break;	//�j���[�Q�[��
		case 2: enter_boss_shot(1); func_state = result; break;			//result��ʂ�
		case 3: enter_boss_shot(1);	func_state = title; StopSoundMem(area.bgm.handle); area.bgm.flag = 0; break;			//title��ʂ�
		}
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �Q�[���I�[�o�[�̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void GameOverInput() {
	//�I��؂�ւ�
	if ((CheckStateKey(KEY_INPUT_RIGHT) == 1 || CheckStatePad(configpad.right) == 1) && gameover_pattern != 2) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		gameover_pattern++;
	}
	if ((CheckStateKey(KEY_INPUT_LEFT) == 1 || CheckStatePad(configpad.left) == 1) && gameover_pattern != 0) {
		se_flag[17] = 1;//�J�[�\���ړ��̉�
		gameover_pattern--;
	}

	//�G���^�[�L�[ / start���͂Ŏ��s
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		switch (gameover_pattern) {
		case 0: func_state = result; enter_boss_shot(1);							break;	//���U���g��ʂɐi��
		case 1: func_state = game_play; ch.life = 3; ch.power = 200; ch.retry++;	break;	//�Q�[�����ĊJ����
		case 2: func_state = title; enter_boss_shot(1);	StopSoundMem(area.bgm.handle);area.bgm.flag = 0;	break;	//�^�C�g����ʂɖ߂�
		}
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���U���g��ʂ̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void ResultInput() {
	//Ranking�ɐi�ށ@ �G���^�[ / start����
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		result_flg = 0;
		ranking_load();				//Ranking��ǂݍ���
		ranking_entry(final_score);	//Ranking�ɏ�������
		func_state = ranking;		//��ʂ������L���O��
		StopSoundMem(area.bgm.handle);	//���y���~�߂�
		area.bgm.flag = 0;
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �����L���O�̓��͏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void RankingInput() {
	//title��ʂɍs�� �G���^�[ / start����
	if (CheckStateKey(KEY_INPUT_RETURN) == 1 || CheckStatePad(configpad.start) == 1) {
		se_flag[18] = 1;//����̉�
		func_state = title;	//��ʂ��^�C�g���ɕύX
	}
}