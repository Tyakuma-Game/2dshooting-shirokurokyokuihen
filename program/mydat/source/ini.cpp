#include "../include/GV.h"

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �e�̓����蔻��쐬
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void input_bullet_info(bullet_info_t *binfo,int size_x,int size_y,int col_num,double range,int kaiten){
	binfo->size_x =size_x;	binfo->size_y =size_y;
	binfo->col_num=col_num;	binfo->range  =range;
	binfo->kaiten=kaiten;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//��ԍŏ��̏�����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void first_ini(){

	//�[�[�[�[�[�[�[�[�[/
	// �p�b�h���͐ݒ�
	//�[�[�[�[�[�[�[�[�[/
	configpad.down=0;	//��
	configpad.left=1;	//��
	configpad.right=2;	//�E
	configpad.up=3;		//��
	configpad.bom=6;	//�{��
	configpad.shot=11;	//�e����
	configpad.slow=10;	//�ᑬ�ړ�
	configpad.start=15;	//�Q�[���J�n
	configpad.change=6;	//�ϐg


	//�|�|�|�|�|�|�|�|�|�|/
	// �l������
	//�|�|�|�|�|�|�|�|�|�|/
	stage=0;					//���݂̃X�e�[�W��
	stage_title_count[0]=200;	//�X�e�[�W�^�C�g������


	//�[�[�[�[�[�[�[�[�[/
	// �e�������蔻��ݒ�
	//�[�[�[�[�[�[�[�[�[/
	input_bullet_info(&bullet_info[0], 35, 32, 8, 2.0, 0);    //���e��
	input_bullet_info(&bullet_info[1], 38, 38, 10, 2.0, 0);   //���ʒe��
	input_bullet_info(&bullet_info[2], 22, 22, 6, 4.0, 0);    //��ʒe��
	input_bullet_info(&bullet_info[3], 38, 38, 10, 2.0, 0);   //(��)���ʒe��
	input_bullet_info(&bullet_info[4], 22, 22, 6, 4.0, 0);    //(��)��ʒe��
	input_bullet_info(&bullet_info[5], 19, 34, 5, 2.0, 0);    //�i�C�t�e��
	input_bullet_info(&bullet_info[6], 13, 19, 3, 2.0, 0);    //���v�̐j
	input_bullet_info(&bullet_info[7], 30, 40, 10, 2.0, 0);   //���[�U�[
	input_bullet_info(&bullet_info[8], 30, 40, 10, 2.0, 0);   //�呾��
	input_bullet_info(&bullet_info[9], 14, 16, 3, 3.5, 0);    //�D
	input_bullet_info(&bullet_info[10], 22, 22, 6, 4.0, 0);   //���e��
	input_bullet_info(&bullet_info[11], 14, 18, 3, 2.0, 0);   //�ؒe��
	input_bullet_info(&bullet_info[12], 13, 19, 3, 2.0, 0);   //�ė��e
	input_bullet_info(&bullet_info[13], 13, 19, 3, 2.0, 0);   //������
	input_bullet_info(&bullet_info[14], 13, 19, 3, 2.0, 0);   //�􂯖�
	input_bullet_info(&bullet_info[15], 22, 34, 5, 3.0, 0);	  //��e��
	input_bullet_info(&bullet_info[16], 19, 34, 5, 2.0, 0);	  //�e��
	input_bullet_info(&bullet_info[17], 13, 19, 3, 2.0, 0);   //����
	input_bullet_info(&bullet_info[18], 22, 22, 6, 4.0, 0);   //�启
	input_bullet_info(&bullet_info[19], 38, 38, 10, 2.0, 0);  //���邮��
	input_bullet_info(&bullet_info[20], 22, 22, 6, 4.0, 0);   //�f��
	input_bullet_info(&bullet_info[21], 35, 32, 8, 2.0, 0);	  //���
	input_bullet_info(&bullet_info[22], 22, 22, 6, 4.0, 0);   //�n�[�g
	input_bullet_info(&bullet_info[23], 13, 19, 3, 2.0, 0);   //�_�C��
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�Q�[���̏�����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void ini(){

	//�֐�����p
	stage_count=1;

	//�[�[�[�[�[�[�[�[�[/
	// �������m��
	//�[�[�[�[�[�[�[�[�[/
	memset(&ch,0,sizeof(ch_t));										//�v���C���[
	memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);						//�G
	memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);						//���[�U�[
	memset(enemy_order,0,sizeof(enemy_order_t)*ENEMY_ORDER_MAX);	//�G�̏o�����
	memset(shot,0,sizeof(shot_t)*SHOT_MAX);							//�e��
	memset(cshot,0,sizeof(cshot_t)*CSHOT_MAX);						//�v���C���[�e��
	memset(effect,0,sizeof(effect_t)*EFFECT_MAX);					//�G�t�F�N�g
	memset(particle, 0, sizeof(Particle) * PARTICLE_MAX);			//�p�[�e�B�N��
	memset(del_effect,0,sizeof(del_effect_t)*DEL_EFFECT_MAX);		//���ŃG�t�F�N�g
	memset(&bom,0,sizeof(bom_t));									//�{���̏��
	memset(&bright_set,0,sizeof(bright_set_t));						//��ʂ̖��邳
	memset(&dn,0,sizeof(dn_t));										//�h��
	memset(&boss,0,sizeof(boss_t));									//�{�X�̏��
	memset(child,0,sizeof(child_t)*CHILD_MAX);						//�e�����˂̃G�t�F�N�g
	memset(&stage_title,0,sizeof(stage_title_t));					//�X�e�[�W�^�C�g��
	memset(item,0,sizeof(item_t)*ITEM_MAX);							//�A�C�e��
	memset(&area,0,sizeof(area_t));									//(48)�@�G���A�̏��
	memset(option_bb,0,sizeof(option_bb_t)*2);						//(49)�@Schott�̃I�v�V�����i�{���{���j


	//�[�[�[�[�[�[�[�[�[/
	// �v���C���[������
	//�[�[�[�[�[�[�[�[�[/
	ch.x=FMX/2;			//X���W������
	ch.y=FMY*3/4;		//Y���W������
	ch.power=400;		//�����p���[
	ch.miss = 0;		//�~�X�̉񐔂��L�^

	ch.retry = 0;		//������
	magic_size = 1.0f;	//���@�w�̑傫��

	if (game_mode == 0) {//�c�@
		ch.life = 5;
	}

	//�[�[�[�[�[�[�[�[�[/
	//�^�C�g�����䏉����
	//�[�[�[�[�[�[�[�[�[/
	stage_title.appear_cnt=stage_title_count[stage];
	

	//�[�[�[�[�[�[�[�[�[/
	//�{�X�̍s���ݒ�
	//�[�[�[�[�[�[�[�[�[/
	
	//boss.appear_count[0]=50;	//�f�o�b�O�p�@���{�X���o�����鎞��

	boss.appear_count[0]=1700;	//���{�X���o�����鎞��
	boss.appear_count[1]=2850;	//�Ō�{�X���o�����鎞��

	boss.danmaku_num[0]=1;		//���{�X�����ڂ܂ł̒e�����o����
	boss.danmaku_num[1]=4;		//�Ō�ɏo��{�X�����ڂ܂ł̒e�����o����

	//�[�[�[�[�[�[�[�[�[/
	// �{�X�̗̑͐ݒ�
	//�[�[�[�[�[�[�[�[�[/

	//�̗͐ݒ�
	int boss_hp_normal[DANMAKU_MAX] = {
		15000,30000,16000,25000,30000,
	};
	int boss_hp_hard[DANMAKU_MAX] = {
		18000,32000,18000,28000,33000,
	};
	int boss_hp_lunatic[DANMAKU_MAX] = {
		20000,35000,20000,30000,36000,
	};

	//�e�����ꂼ���HP���i�[����
	for(int i=0;i<DANMAKU_MAX;i++){
		switch (game_level){//��Փx�ɉ����ĕύX
		case normal : boss.set_hp[i] = boss_hp_normal[i]; break;
		case hard   : boss.set_hp[i] = boss_hp_hard[i]; break;
		case lunatic: boss.set_hp[i] = boss_hp_lunatic[i]; break;
		}
	}

	//�{�X�̗͂̍ő�l
	boss.hp_max=boss.set_hp[0];

	//�[�[�[�[�[�[�[�[�[/
	//�{�X�e���̔w�i�ݒ�
	//�[�[�[�[�[�[�[�[�[/

	//�{�X�e���̔w�i
	int back_knd[DANMAKU_MAX] = {
		1,1,1,1,1,
	};

	//�e�����ꂼ��̔w�i���i�[����
	for(int i=0;i<DANMAKU_MAX;i++){
		boss.back_knd[i]=back_knd[i];
	}
	

	//�[�[�[�[�[�[�[�[�[/
	// ���y�Ɋւ��邱��
	//�[�[�[�[�[�[�[�[�[/
	

	area.bgm.flag=1;			//���y�Đ��t���O��������(48)
	area.bgm.loop_pos[0]=26672;	//�ʏ�BGM�̃��[�v�ʒu
	area.bgm.loop_pos[1]=27010;	//�{�XBGM�̃��[�v�ʒu


	//�[�[�[�[�[�[�[�[�[/
	//�I�v�V�����{���{���̉摜���
	//�[�[�[�[�[�[�[�[�[/
	option_bb[0].img=img_bb;
	option_bb[1].img=img_bb;


	//�[�[�[�[�[�[�[�[�[/
	// �ʓx
	//�[�[�[�[�[�[�[�[�[/
	bright_set.brt=255;//�����P�x�͍ő�
}