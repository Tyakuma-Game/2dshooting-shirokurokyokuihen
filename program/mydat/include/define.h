
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �萔�Ɋւ��鎖�S��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/

//�|�|�|�|�|�|�|�|�|�|/
//�~����
//�|�|�|�|�|�|�|�|�|�|/
#define PI 3.1415926535898	//�΁i�~�����j
#define PI2 (PI*2)			//��^2�i�~�����̓��j


//�|�|�|�|�|�|�|�|�|�|/
//�X�e�[�W
//�|�|�|�|�|�|�|�|�|�|/
#define FMX 384				//X���W�ő�l
#define FMY 448				//Y���W�ő�l

#define FX 32				//�����X���W
#define FY 16				//�����Y���W

#define STAGE_NUM 5			//�X�e�[�W��


//�[�[�[�[�[�[�[�[�[/
// �v���C���[
//�[�[�[�[�[�[�[�[�[/

//�����蔻��
#define CRANGE 2.0			//���@�����蔻��
#define CRANGE11 5.0		//���@�����蔻��
#define CRANGE_COLOR 35.0	//�F�����蔻��

//�{���ŏ����p���[�i�G�l���M�[�j
#define BOM_ENERGY 100

//�N�[���^�C��
#define COLOR_COOL_TIME 12 //�F�ύX�N�[���^�C��

//�X�R�A�͈�
#define SCORE_MAX 999999999
#define SCORE_MIN 0

//�p���[�͈�
#define POWER_MAX 500
#define POWER_MIN 1

//���̑��͈̔�
#define OTHER_MAX 9999


//�|�|�|�|�|�|�|�|�|�|/
//�{�X�Ɋւ��鎖
//�|�|�|�|�|�|�|�|�|�|/
#define BOSS_POS_X (FMX/2)		//�{�X�̏o���ʒuX���W
#define BOSS_POS_Y (FMY/4)		//�{�X�̏o���ʒuY���W


//�|�|�|�|�|�|�|�|�|�|/
// �G�Ɋւ��鎖
//�|�|�|�|�|�|�|�|�|�|/
#define ENEMY_MAX 30			//�G�̓����\���ő吔
#define ENEMY_ORDER_MAX 500		//�G�̏o�����ő吔
#define ENEMY_PATTERN_MAX 11	//�G�̍s���p�^�[���̍ő吔


//�|�|�|�|�|�|�|�|�|�|/
// �e��
//�|�|�|�|�|�|�|�|�|�|/
#define DANMAKU_MAX 50	//�e���ő吔
#define SHOT_MAX 30		//��x�ɉ�ʂɕ\���ł���G�̒e���̍ő吔
#define SHOT_KND_MAX 18	//�V���b�g�̎�ނ̍ő吔

#define LAZER_MAX 100	//���[�U�[

#define CSHOT_MAX 200			//���@�V���b�g�̓o�^�ő吔
#define SHOT_BULLET_MAX 1000	//�G�P�C�����e�̍ő吔
#define BOSS_BULLET_MAX 3000	//�{�X�����e�̍ő吔


//�|�|�|�|�|�|�|�|�|�|/
// �T�E���h
//�|�|�|�|�|�|�|�|�|�|/
#define SE_MAX 100	//���ʉ��̎�ނ̍ő吔


//�|�|�|�|�|�|�|�|�|�|/
// �p�b�h
//�|�|�|�|�|�|�|�|�|�|/
#define PAD_MAX 16	//�p�b�h�L�[�̍ő吔


//�|�|�|�|�|�|�|�|�|�|/
// �G�t�F�N�g
//�|�|�|�|�|�|�|�|�|�|/
#define EFFECT_MAX 100		//�G�t�F�N�g�o�^�ő吔
#define DEL_EFFECT_MAX 30	//���ŃG�t�F�N�g�o�^�ő吔
#define PARTICLE_MAX 200	//�p�[�e�B�N���̍ő吔

#define CHILD_MAX 20


//�|�|�|�|�|�|�|�|�|�|/
// �A�C�e��
//�|�|�|�|�|�|�|�|�|�|/
#define ITEM_MAX 100				//�A�C�e���̕\���ő吔
#define ITEM_GET_BORDER_LINE 100	//�A�C�e���Q�b�g�{�[�_�[���C��
#define ITEM_INDRAW_RANGE 70		//�A�C�e���̋z���͈�
#define ITEM_HIT_BOX 20				//�A�C�e���̓����蔻��


//�|�|�|�|�|�|�|�|�|�|/
// �X�R�A�Ɋւ��鎖
//�|�|�|�|�|�|�|�|�|�|/
#define RANKING_MAX 10//�����L���O�̍ő吔

//�����N�t��
#define RANKING_BORDER_BRONZE 100000
#define RANKING_BORDER_SILVER	(RANKING_BORDER_BRONZE*2)
#define RANKING_BORDER_GOLD		(RANKING_BORDER_BRONZE*3)
#define RANKING_BORDER_PLATINUM (RANKING_BORDER_BRONZE*4)

//�A�C�e���̃{�[�i�X�l
#define POWER_BONUS_SCORE 100//�p���[
#define KILL_BONUS_SCORE  110//�G������
#define MONEY_BONUS_SCORE 150//����
#define GRAZE_BONUS_SCORE 200//�O���C�Y
#define POINT_BONUS_SCORE 500//�|�C���g

#include "struct.h"