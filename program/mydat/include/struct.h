
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�L�����N�^�[�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int color;		//�F���
	int color_count;//�F�ύX�N�[���^�C��
	int kill_count;	//�G��|������
	int miss;		//�~�X�̉�
	int retry;		//������
	int flag;		//�t���O
	int cnt;		//�J�E���^
	int power;		//�p���[
	int point;		//�|�C���g
	int score;		//�X�R�A
	int score_max;	//�X�R�A�̍ő�l
	int life;		//�c�@��
	int mutekicnt;	//���G��ԂƃJ�E���g
	int shot_mode;	//�V���b�g���[�h
	int money;		//����
	int img;		//�摜
	int slow;		//�X���[���ǂ���
	double x,y;		//���W
	int shot_cnt;	//�V���b�g�J�E���g
	int graze;		//�O���C�Y(41)
}ch_t;

typedef struct{
	double x,y;
}pt_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,pattern,muki,knd,hp,hp_max,item_n[6],img,back_col;
	//�t���O�A�J�E���^�A�ړ��p�^�[���A�����A�G�̎�ށAHP�ő�l�A���Ƃ��A�C�e���A�w�i�F
	double x,y,vx,vy,sp,ang;
	//���W�A���xx�����A���xy�����A�X�s�[�h�A�p�x
	int bltime, blknd, blknd1, col, state, wtime, wait;
	//�e���J�n���ԁA�e�̎�ށA�F�A��ԁA�ҋ@���ԁA��؎���
}enemy_t;

typedef struct{
	//�J�E���^�A�ړ��p�^�[���A�G�̎��
	int cnt,pattern,knd;
	//�������W�ƈړ��X�s�[�h
	double x,y,sp;
	//�e���J�n���ԁA�e���̎�ށA�F�A�̗́A�e�̎�ށA��؎��ԁA�A�C�e��(6���)
	int bltime, blknd, blknd1, col, hp, wait, item_n[6];
}enemy_order_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�p�b�h�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int key[PAD_MAX];
}pad_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�R���t�B�O�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �p�[�e�B�N��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int cnt_time;	//���Ŏ���
	int flag;		//��ʂɑ��݂��Ă��邩
	int color;		//�F
	float x, y;		//���W
	float vx, vy;	//�����x
} Particle;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�e�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A��ށA�J�E���^�A�F�A��ԁA���Ȃ��Ƃ������Ȃ����ԁA�G�t�F�N�g�̎��
	int flag,knd,knd1,cnt,col,state,till,eff,kaiten,eff_detail;
	int cnt_till,cnt_stt;
	//���W�A�p�x�A���x�A�x�[�X�̊p�x�A�ꎞ�L���X�s�[�h
	double x,y,vx,vy,angle,spd,base_angle[1],rem_spd[1];
	int c_flag;
	double cx,cy;
}bullet_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�V���b�g�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A��ށA�J�E���^�A�ǂ̓G���甭�˂��ꂽ���̔ԍ��A�F
	int flag,knd,knd1,cnt,num;
	//�x�[�X�p�x�A�x�[�X�X�s�[�h
	double base_angle[1],base_spd[1];

	bullet_t bullet[SHOT_BULLET_MAX];
}shot_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�V���b�g�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A��ށA�J�E���^�A�ǂ̓G���甭�˂��ꂽ���̔ԍ��A�F
	int flag,knd,cnt,num;
	//�x�[�X�p�x�A�x�[�X�X�s�[�h
	double base_angle[10],base_spd[1];
	bullet_t bullet[BOSS_BULLET_MAX];
	bullet_t assist[6];
}boss_shot_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�L�����N�^�[�V���b�g�Ɋւ���\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag;		//�t���O
	int power;		//�p���[
	int cnt;		//�J�E���^
	int knd;		//���

	//�����ɕύX�������Ă�
	int img;		//�摜(49)
	
	
	double x,y;		//���W
	double angle;	//�p�x
	double spd;		//�X�s�[�h
}cshot_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�V���b�g�̃I�v�V�������ˌ��{���{��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag;	//�t���O
	int img;	//�摜
	int cnt;	//�J�E���^
	double x,y;	//���W
}option_bb_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�t�F�N�g
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,col,knd,img,eff;
	double x,y,r,ang,spd,mvang,brt;
}effect_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���ŃG�t�F�N�g
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,col;
	double x,y;
}del_effect_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�e�̏��@�����蔻��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�{���̏��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,knd;
	double x,y;
}bom_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//��ʂ̖��邳���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	unsigned char brt;
}bright_set_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�h���I�Ɨh����ʂ̏��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,time,size;
	int x,y;
}dn_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�����I�v�Z���s���ׂ̍\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,set_t;
	double ax,v0x,ay,v0y,vx,vy,prex,prey;
}phy_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���[�U�[�̕����I�v�Z���s���ׂ̍\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int conv_flag;
	double time,base_ang,angle;
	double conv_x,conv_y,conv_base_x,conv_base_y;
}lphy_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�{�X�̏��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A�J�E���^�A��ށA�ҋ@���ԁA��ԁA�e���I���܂ł̃J�E���^�A���̉H�߁A�\���t���O
	int flag,cnt,knd,wtime,state,endtime,hagoromo,graph_flag;
	//HP,�ő�HP
	int hp,hp_max;
	//�o���J�E���^���A�e�e����HP�A�w�i�̎�ށA���{�X-���X�{�X�̒e����(45)
	int appear_count[2],set_hp[DANMAKU_MAX],back_knd[DANMAKU_MAX],danmaku_num[2];
	//���W
	double x,y,dx,dy,ang,spd;
	//�����ړ��̂��߂̕ϐ�
	phy_t phy;
}boss_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���[�U�[�̍\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,knd,col,state;//�t���O�A�J�E���^�A��ށA�F
	double haba,angle,length,hantei;//���A�p�x�A�����A����͈�(�\�����ɑ΂���0~1�Ŏw��)�A��]���x
	pt_t startpt,disppt[4],outpt[4];//���[�U�[�𔭎˂���n�_�A�\�����W�A�����蔻��͈�
	lphy_t lphy;
}lazer_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�e���̔��ˈʒu�ɕ\������G�t�F�N�g
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	int flag,cnt,knd,col,state;
	double x,y,angle,spd,range;
}child_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�Q�[���X�e�[�W�^�C�g��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A�摜�n���h���A�J�E���^�A�P�x�A�o���J�E���g
	int flag,img,cnt,brt,appear_cnt;
}stage_title_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�A�C�e���̍\����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A�J�E���^�A��ށA���
	int flag,cnt,knd,state;
	//���x�A���W�A�傫��
	double v,x,y,r;
}item_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�t���b�V��(42)
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//�t���O�A�J�E���^�A�t���b�V���̎�ށA���J�E���g�ŕ\�����邩
	int flag,cnt,knd,to_cnt;
	//���邳
	double brt;
}flash_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//BGM���(area_t�Ŏg�p
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	//BGM�̍Đ��t���O�A�Đ��n���h���A���Ȃ炷���Đ���ޔԍ��������A���[�v�ʒu
	int flag,handle,knd[3],loop_pos[3];
}bgm_t;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���̃G���A�������Ă�����(48)
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
typedef struct{
	bgm_t bgm;
}area_t;