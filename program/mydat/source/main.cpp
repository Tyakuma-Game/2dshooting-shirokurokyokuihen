#define GLOBAL_INSTANCE 
#include "../include/GV.h"


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���[�v�ŕK���s������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
int ProcessLoop() {

	//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ProcessMessage() != 0) {
		return -1;
	}

	//��ʃN���A���G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0) {
		return -1;
	}

	GetHitKeyStateAll_2();	//���݂̃L�[���͏������s��
	GetHitPadStateAll();	//���݂̃p�b�h���͏������s��

	return 0;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���C���֐�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//�|�|�|�|�|�|�|�|�|�|�|�|/
	// ��{�ݒ�
	//�|�|�|�|�|�|�|�|�|�|�|�|/

	//���C�u����������
	if (DxLib_Init() == -1){
		return -1;
	}

	SetMainWindowText("�����Ɉٕ�");	//�E�B���h�E���̎w��
	ChangeWindowMode(FALSE);			//�E�C���h�E���[�h�ŋN�����Ȃ�
	SetDrawScreen(DX_SCREEN_BACK);		//����ʉ�

	//�Q�[���̏�Ԃ�����̏�����
	func_state = start_loading;

	//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
	// ���C�����[�v
	//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
	while (ProcessLoop() == 0) {

		//���y�ݒ�
		music_ini();

		//�Q�[���̏�ʂɉ����ď�����ύX
		switch (func_state) {

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//����̏���
		case start_loading:
			load();				//�f�[�^���[�h
			first_ini();		//����̏�����
			func_state = title;	//��ʂ��^�C�g����
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//�^�C�g����ʕ\��
		case title:
			TitleInput();	//����
			graph_title();	//�`��
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//��Փx�I�����
		case levelselection:
			LevelSelectionInput();	//����
			graph_levelselection();	//�`��
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//STG�̊J�n�O�Z�b�e�B���O
		case game_setting:
			ini();					//������
			load_story();			//�G���i�[
			func_state = game_play;	//��ʂ��Q�[���v���C���ɕύX
			start = clock();		//�J�n���Ԏ擾
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//�Q�[���v���C��
		case game_play:
			//enter_func_tm("�ŏ�");
			calc_ch();       //enter_func_tm("�L�����v�Z");
			ch_move();       //enter_func_tm("�L�����ړ�");
			cshot_main();    //enter_func_tm("���@�V���b�g���C��");
			enemy_main();	 //enter_func_tm("�G�������C��");
			boss_shot_main();//enter_func_tm("�{�X�V���b�g���C��");
			shot_main();	 //enter_func_tm("�V���b�g���C��");
			out_main();  	 //enter_func_tm("�����蔻��");
			effect_main();   //enter_func_tm("�G�t�F�N�g���C��");
			calc_main();	 //enter_func_tm("�v�Z���C��");
			graph_main();    //enter_func_tm("�`�惁�C��");
			GamePlyInput();	 //����
			calc_game_ply(); //�Q�[�����̏�ʏ���
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//���j���[��ʕ\��
		case menu:
			MenuInput();									//����
			DrawGraph(0, 0, img_menu[menu_pattern], FALSE);	//�\��
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//�Q�[���I�[�o�[
		case game_over:
			GameOverInput();										//����
			DrawGraph(0, 0, img_gameover[gameover_pattern], FALSE);	//�\��
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//���U���g���
		case result:
			calc_result();	//��ʂ̏���
			ResultInput();	//����
			graph_result();	//�`��
			break;

			//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
			//�����L���O
		case ranking:
			RankingInput();	//�����L���O�̓���
			graph_ranking();//�����L���O�`��
			break;

		//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
		//�G���[
		default:
			printfDx("�s����func_state\n");
			break;
		}

		bgm_main();		//enter_func_tm("BGM���C��");
		music_play();	//enter_func_tm("���y�Đ�");
		fps_wait();		//enter_func_tm("�ҋ@��������", 1);

		//�G�X�P�[�v�����͂��ꂽ��Q�[���I��
		if (CheckStateKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//����ʔ��f
		ScreenFlip();
	}

	//�|�|�|�|�|�|�|�|�|�|/
	// �I������
	//�|�|�|�|�|�|�|�|�|�|/
	DxLib_End();	//Dx���C�u�����I��
	return 0;		//����I��
}