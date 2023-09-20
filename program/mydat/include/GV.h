#include "../../../include/DxLib.h"
#include "define.h"
#include "math.h"
#include <time.h>

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// extern��t���邩����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 
#endif

#include "function.h"


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���L�ϐ��錾��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/

//�|�|�|�|�|�|�|�|�|�|/
// �摜�ϐ�
//�|�|�|�|�|�|�|�|�|�|/

//�|�|�|�|�|/
//���
//�|�|�|�|�|/
GLOBAL int img_title[2];	//�^�C�g�����
GLOBAL int img_levelselection[2][3];//��Փx�I��
GLOBAL int img_menu[4];		//���j���[���
GLOBAL int img_result[5];	//���U���g���
GLOBAL int img_gameover[3];	//�Q�[���I�[�o�[���
GLOBAL int img_board[40];	//�{�[�h�ɂ����摜
GLOBAL int img_back[20];	//�w�i�p�摜
GLOBAL int img_ranking;		//�����L���O�̉摜


//�|�|�|�|�|/
//�v���C���[
//�|�|�|�|�|/
GLOBAL int img_ch[3];	//�v���C���[�h�b�g�G
GLOBAL int img_bb;		//�I�v�V�����̃{���{��
GLOBAL int img_ch_hit;	//�����蔻��
GLOBAL int img_magic[2];//���@�w�̉摜


//�|�|�|�|�|/
// �G
//�|�|�|�|�|/
GLOBAL int img_enemy[3][9];	//�G�h�b�g�G
GLOBAL int img_boss;		//�{�X�h�b�g�G


//�|�|�|�|�|/
//�e��
//�|�|�|�|�|/
GLOBAL int img_bullet2[2][24];							//�e���摜�@�F���@�`��
GLOBAL int img_lazer[10][10], img_lazer_moto[10][10];	//���[�U�[�摜
GLOBAL int img_cshot[2][2];								//�v���C���[�e���@�ԂƐ@�Q��ނ���


//�|�|�|�|�|/
//�G�t�F�N�g
//�|�|�|�|�|/
GLOBAL int img_del_effect[5];	//���ŃG�t�F�N�g�p�摜
GLOBAL int img_eff_bom[5];		//�{���̃G�t�F�N�g�摜
GLOBAL int img_particle[2];		//�p�[�e�B�N���̉摜

//�|�|�|�|�|/
//���̑�
//�|�|�|�|�|/
GLOBAL int img_etc[50];		//���̑��̉摜
GLOBAL int img_item[6][2];	//�A�C�e���̉摜
GLOBAL int img_num[3][12];	//�����̉摜(41)


//�|�|�|�|�|�|�|�|�|�|/
//���y�t�@�C���p�ϐ�
//�|�|�|�|�|�|�|�|�|�|/
GLOBAL int sound_se[SE_MAX];


//�|�|�|�|�|�|�|�|�|�|/
//�t���O�E�X�e�[�^�X�ϐ�
//�|�|�|�|�|�|�|�|�|�|/
GLOBAL int func_state, stage_count, count, stage;	//�֐�����p�ϐ�
GLOBAL int se_flag[SE_MAX];							//�T�E���h�t���O


//�|�|�|�|�|�|�|�|�|�|/
//����p�ϐ�
//�|�|�|�|�|�|�|�|�|�|/
GLOBAL int stage_title_count[STAGE_NUM];

//��ʐ���
GLOBAL int title_pattern;		//�^�C�g����ʁ@�؂�ւ�
GLOBAL int menu_pattern;		//���j���[��ʁ@�؂�ւ�
GLOBAL int gameover_pattern;	//�Q�[���I�[�o�[��ʁ@�؂�ւ�
GLOBAL int result_flg;			//���U���g��ʁ@��������
GLOBAL int result_rank;			//���U���g��ʁ@�����N����

//��Փx�ƃ��[�h
GLOBAL int game_level;	//��Փx
GLOBAL int game_mode;	//�O�c�@�@�P�X�R�A�������

//���@�w
GLOBAL float magic_size;	//���@�w�̑傫��
GLOBAL int magic_time;		//���@�w�̉�]���x


//�|�|�|�|�|�|�|�|�|�|/
// ���U���g�v�Z�p
//�|�|�|�|�|�|�|�|�|�|/

GLOBAL double elapsed_time;		//�o�ߎ���
GLOBAL int final_score;			//�ŏI�I�ȃX�R�A
GLOBAL int sum_score;			//�X�R�A�̍��v�_
GLOBAL int bonus;				//��Փx�{�[�i�X
GLOBAL int mode_tmp, level_tmp;	//�Q�[�����[�h�A�Q�[����Փx�̉��ۑ�


//�|�|�|�|�|�|�|�|�|�|/
// �����L���O�p�ϐ�
//�|�|�|�|�|�|�|�|�|�|/
GLOBAL int ranking_score[RANKING_MAX + 1];	//�����L���O�X�R�A + �N���A���̃X�R�A


//�|�|�|�|�|�|�|�|�|�|/
//�F�ƃt�H���g
//�|�|�|�|�|�|�|�|�|�|/
GLOBAL int color[20],font[20];//�F(41) �t�H���g(44)



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�\���̕ϐ��錾��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
GLOBAL ch_t ch;										//�L�����N�^�f�[�^�錾
GLOBAL enemy_t enemy[ENEMY_MAX];					//�G���
GLOBAL configpad_t configpad;						//�R���t�B�O�Őݒ肵���L�[���
GLOBAL enemy_order_t enemy_order[ENEMY_ORDER_MAX];	//�G�̏o�����
GLOBAL shot_t shot[SHOT_MAX];						//�V���b�g���
GLOBAL boss_shot_t boss_shot;						//�{�X�V���b�g���
GLOBAL cshot_t cshot[CSHOT_MAX];					//���@�V���b�g
GLOBAL del_effect_t del_effect[DEL_EFFECT_MAX];		//���ŃG�t�F�N�g
GLOBAL effect_t effect[EFFECT_MAX];					//�G�t�F�N�g
GLOBAL bullet_info_t bullet_info[24];				//�e���
GLOBAL bom_t bom;									//�{��
GLOBAL bright_set_t bright_set;						//�`��̋P�x
GLOBAL dn_t dn;										//�h���Ɨh���
GLOBAL boss_t boss;									//�{�X���
GLOBAL lazer_t lazer[LAZER_MAX];					//���[�U�[
GLOBAL child_t child[CHILD_MAX];					//�e���̔��ˈʒu�ɕ\������G�t�F�N�g
GLOBAL stage_title_t stage_title;					//�X�e�[�W�^�C�g��
GLOBAL item_t item[ITEM_MAX];						//�A�C�e��
GLOBAL flash_t flash;								//(42)
GLOBAL area_t area;									//���̃G���A�Ŏ����Ă���f�[�^(48)
GLOBAL option_bb_t option_bb[2];					//�I�v�V�������ˌ��{���{��(49)

//�p�[�e�B�N��
GLOBAL Particle particle[PARTICLE_MAX];

//�o�ߎ��ԗp
GLOBAL clock_t start;	//�J�n����
GLOBAL clock_t end;		//�I������


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �񋓌^�錾
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/

//�F���
GLOBAL enum {
	red=0,	//�ԐF�e���@
	blue=1,	//�F�e��
};

//�Q�[���̏��
GLOBAL enum {
	start_loading,	//��ԍŏ��̃_�E�����[�h
	title,			//�^�C�g���\�����
	levelselection,	//��Փx�I��
	game_setting,	//STG�̊J�n�O�Z�b�e�B���O
	game_play,		//�Q�[���v���C��
	game_over,		//�Q�[���I�[�o�[
	menu,			//���j���[�\����
	result,			//���ʉ��
	ranking,		//�����L���O�\����
};

//�Q�[���̓�Փx
GLOBAL enum {
	normal,		//����
	hard,		//���
	lunatic,	//���C
};

//�Q�[�����[�h
GLOBAL enum {
	life,	//�c�@���g�p���ĕ���
	score,	//�X�R�A���g�p���ĕ���
};

//���U���g�̃����N
GLOBAL enum {
	bronze=0,	//��
	silver,		//��
	gold,		//��
	platinum,	//�v���`�i
	diamond,	//�_�C�������h
};