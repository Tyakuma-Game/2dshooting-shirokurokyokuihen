#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define BRANGE 40.0//�{�X�̓����蔻��

#define ABSORPTION_SCORE 200   //�e���z���̃X�R�A�ǉ��l
#define ABSORPTION_POWER 1     //�e���z���̃p���[�ǉ��l

#define DECREASE_LIFE 1         //��e�������@�c�@
#define DECREASE_SCORE 10000    //��e�������@�X�R�A
#define DECREASE_POWER 200      //��e�������@�p���[

#define EMY_HIT_SCORE 20       //�G�ɍU�����Ă��@�����X�R�A
#define BOSS_HIT_SCORE 100     //�{�X�ɍU�����Ă��@�����X�R�A


extern int out_lazer();


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�G�̓����蔻��͈�
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���@�V���b�g�̓����蔻��͈�
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int cshot_range[CSHOT_RANGE_MAX]={6,};


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�����蔻��
//�V���b�g�̍��W:1  ������𔻒肷�镨��:2
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;

    //�G�Ǝ��@�V���b�g�Ƃ̋���
    double x=x1-x2;
    double y=y1-y2;

    //�G�̓����蔻��Ǝ��@�V���b�g�̓����蔻��͈̔�
    double r=range1+range2;

    //���Ԃ��v�Z����K�v�������
    if(spd1>r){
        //�P�t���[���O�ɂ����ʒu���i�[����
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;

        //�i�񂾕��������蔻�蕪���[�v
        for(j=0;j<spd1/r;j++){
            px=pre_x-x2;
            py=pre_y-y2;

            //�����蔻����Ȃ�
            if(px*px+py*py<r*r){
                return 1;//������
            }

            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }

    //�����蔻����Ȃ�
    if(x*x+y*y<r*r){
        return 1;//������
    }

    return 0;//�O��
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�G�Ǝ��@�V���b�g�������������ǂ����𔻒肷��
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int out_judge_cshot(int i,int s){

    //�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
    if(cshot[i].cnt>0){
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;//��������
        }
    }

    return 0;//������Ȃ�����
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�{�X�Ǝ��@�V���b�g�������������𔻒�
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int out_judge_cshot_boss(int i){
    //�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
    if(cshot[i].cnt>0){
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;//��������
        }
    }

    return 0;//������Ȃ�����
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���@�ƓG�V���b�g�������������𔻒�
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int out_judge_enemyshot(int s,int n,double size){
    //�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
    if(shot[s].bullet[n].cnt>0){
        if(out_judge(
            shot[s].bullet[n].x,shot[s].bullet[n].y,ch.x,ch.y,
            bullet_info[shot[s].bullet[n].knd].range, size,
            shot[s].bullet[n].spd,shot[s].bullet[n].angle
            )){
                return 1;//��������
        }
    }

    return 0;//������Ȃ�����
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���@�ƃ{�X�V���b�g����������������
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
int out_judge_bossshot(int n,double siza){
    //�V���b�g�̋O�����P�x�ł��v�Z����Ă�����
    if(boss_shot.bullet[n].cnt>0){
        if(out_judge(
            boss_shot.bullet[n].x,boss_shot.bullet[n].y,ch.x,ch.y,
            bullet_info[boss_shot.bullet[n].knd].range,siza,
            boss_shot.bullet[n].spd,boss_shot.bullet[n].angle
            )){
                return 1;//��������
        }
    }

    return 0;//������Ȃ�����
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �A�C�e���̋󂫔ԍ���Ԃ�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
int serch_item(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].flag==0){//�󂫂���������
			return i;       //���̔ԍ���Ԃ�
        }
    }
	return -1;//�󂫂���������
}

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�A�C�e���o�^
//�A�C�e���@0:���p���[ 1:���_ 2:�e�_ 3:���� 4:��p���[ 5:���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enter_item(double x, double y, int item_n[], int num){//x,y,�A�C�e���̎��,��
	int k;
	double r[6]={0.6,0.6,1.0,0.6,1.0,1.0};//dat/img/item�̉摜�̊g�嗦

    //1�̓G����o��A�C�e���̍ő吔��6��
	for(int i=0;i<num;i++){
		if(item_n[i]!=-1){//�G�N�Z���Ŏw�肵���A�C�e����-1(�Ȃ�)�Ȃ�I��

            //�o�^�o����ԍ���������
			if((k=serch_item())!=-1){

                //�o�^����
				item[k].flag=1;
				item[k].v    =-3.5;	//����
				item[k].cnt  =0;
				item[k].state=0;
				item[k].x    =x;
				item[k].y    =y;

                //�����Ȃ�K���ɂ���΂点��
				if(i>0){
					item[k].x+=rang(40);
					item[k].y+=rang(40);
				}

                //�w�肵���A�C�e�����o��������
				item[k].knd =item_n[i];
				item[k].r   =r[item[k].knd];
			}
		}
	}
}

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G����o��A�C�e��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enter_enemy_item(int s){
	enter_item(enemy[s].x,enemy[s].y,enemy[s].item_n, sizeof(enemy[s].item_n)/sizeof(int));//x,y,�A�C�e���̎��,��
}

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�v���C���[����o��A�C�e��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enter_char_item(){
	int item_n[4]={4,4,4,4};
	enter_item(ch.x, ch.y, item_n, 4);//x,y,�A�C�e���̎��,��
}

extern void enter_del_effect(int);


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�����ʂ��ǂ����̌���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//�G�ɓ���������

    //�G��HP���O�����ɂȂ�����
    if(enemy[s].hp<0){
        ch.kill_count++;    //�G�̓������J�E���g
        enemy[s].flag=0;    //�G�����ł�����
        se_flag[1]=1;       //�G�̃s�`������

        enter_del_effect(s);//�G�̏��ŃG�t�F�N�g���o��
		enter_enemy_item(s);//�G�̃A�C�e�����o��������(39��)
        
        //�G������
        for(i=0;i<SHOT_MAX;i++){
            if(shot[i].flag!=0){    //�o�^����Ă���e���f�[�^�������
                if(s==shot[i].num){ //���̓G���o�^�����e���������
                    shot[i].flag=2; //����ȏ�e���𑱂��Ȃ��t���O�𗧂Ă�
                    break;
                }
            }
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//s�̓G��power�H��킷
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void hit_enemy(int s,int power){
    enemy[s].hp-=power;     //�e�̎��p���[��HP�����炷
    enemy_death_judge(s);   //�G�����ʂ��ǂ��������߂�
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�{�X��power�H��킷
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void hit_boss(int power){
    boss.hp-=power;//�e�̎��p���[��HP�����炷
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���@�V���b�g�ƓG�Ƃ̏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//���@�V���b�g����
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//�G����
                if(enemy[s].flag>0){

                    //���@�V���b�g�ƓG���������Ă����
                    if(out_judge_cshot(i,s)){
                        ch.score += EMY_HIT_SCORE;  //�X�R�A�����Z����
                        cshot[i].flag=0;            //���̎��@�V���b�g������
                        hit_enemy(s,cshot[i].power);//�_���[�W����
                        CreateParticle(cshot[i].x, cshot[i].y);//�p�[�e�B�N���o�^
                        break;
                    }
                }
            }

            //�{�X���o�����Ă��āA�`�悵�Ȃ��t���O���I�t�ŁA�V���b�g���Ȃ�
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    ch.score += BOSS_HIT_SCORE; //�X�R�A�����Z
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                    CreateParticle(cshot[i].x, cshot[i].y);//�p�[�e�B�N���o�^
                }
            }
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�V���b�g�Ǝ��@�Ƃ̏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enemyshot_and_ch(){
    int s,n;
	if(ch.flag==0 && ch.mutekicnt==0 && out_lazer()==1){
        ch.cnt=0;
        ch.flag=1;
        se_flag[3]=1;
	}

    //�|�|�|�|�|�|�|�|�|�|/
    //�G���G�̃V���b�g
    //�|�|�|�|�|�|�|�|�|�|/
    for(s=0;s<SHOT_MAX;s++){//�G�V���b�g����

        //���̃V���b�g���o�^����Ă�����
        if(shot[s].flag>0){
            for(n=0;n<SHOT_BULLET_MAX;n++){//�e����

                //�e���o�^����Ă�����
                if(shot[s].bullet[n].flag==1){
					if(bom.flag!=0){
						shot[s].bullet[n].flag=0;
						continue;
					}

                    //�|�|�|�|�|�|�|�|�|�|/
                    //�F�̓����蔻��
                    //�|�|�|�|�|�|�|�|�|�|/
                    if (out_judge_enemyshot(s, n,CRANGE_COLOR) == 1 && shot[s].bullet[n].col == ch.color) {//�F����͈͓̔��ɒe�����������@���@�����F�̒e���Ȃ�
                        shot[s].bullet[n].flag = 0;   //�e���I�t
                        ch.score += ABSORPTION_SCORE; //�X�R�A���z��
                        ch.power += ABSORPTION_POWER; //�p���[���z��
                        if (ch.power >= POWER_MAX) ch.power = POWER_MAX;//����C��
                        CreateParticle(shot[s].bullet[n].x, shot[s].bullet[n].y);//�p�[�e�B�N���o�^
                    }

                    //�|�|�|�|�|�|�|�|�|�|/
                    //���@�̓����蔻��
                    //�|�|�|�|�|�|�|�|�|�|/
                    if(out_judge_enemyshot(s,n,CRANGE)==1){//���@�͈͓̔��ɒe����������
                        shot[s].bullet[n].flag=0;//�e���I�t

                        //���G��Ԃ���Ȃ��Ȃ�
                        if (ch.flag == 0 && ch.mutekicnt == 0) {//��e
                            ch.cnt = 0;     //���G��Ԃ�
                            ch.flag = 1;    //���G��Ԃ�
                            se_flag[3] = 1; //�s�`������

                            //�p���[�����炷
                            ch.power -= DECREASE_POWER;
                            if (ch.power < POWER_MIN) ch.power = POWER_MIN;//�����C��

                            //�~�X�񐔂𑝂₷
                            ch.miss++;

                            switch (game_mode) {//game_mode / = 0 �c�@���[�h / = 1 �X�R�A���[�h
                            case 0: ch.life -= DECREASE_LIFE;   break;
                            case 1: ch.score -= DECREASE_SCORE; if (ch.score < SCORE_MIN)ch.score = SCORE_MIN; break;
                            }
                        }
                    }
                }
            }
        }
    }

    //�|�|�|�|�|�|�|�|�|�|/
    //�{�X�̃V���b�g
    //�|�|�|�|�|�|�|�|�|�|/
    if(boss_shot.flag>0){//���̃V���b�g���o�^����Ă�����
        for(n=0;n<BOSS_BULLET_MAX;n++){//�e����

            //�e���o�^����Ă�����
            if(boss_shot.bullet[n].flag==1){
				if(bom.flag!=0){
					boss_shot.bullet[n].flag=0;
					continue;
				}

                //�|�|�|�|�|�|�|�|�|�|/
                //�F�̓����蔻��
                //�|�|�|�|�|�|�|�|�|�|/
                if (out_judge_bossshot(n,CRANGE_COLOR) == 1 && boss_shot.bullet[n].col == ch.color) {//�F����͈͓̔��ɒe�����������@���@�����F�̒e���Ȃ�
                    boss_shot.bullet[n].flag = 0; //�e���I�t
                    ch.score += ABSORPTION_SCORE; //�G�l���M�[���z��
                    ch.power += ABSORPTION_POWER; //�p���[���z��
                    if (ch.power >= POWER_MAX) ch.power = POWER_MAX;//����C��
                    CreateParticle(boss_shot.bullet[n].x, boss_shot.bullet[n].y);//�p�[�e�B�N���o�^
                }

                //�|�|�|�|�|�|�|�|�|�|/
                //���@�̓����蔻��
                //�|�|�|�|�|�|�|�|�|�|/
                if(out_judge_bossshot(n,CRANGE)==1){//���@�͈͓̔��ɒe����������
                    boss_shot.bullet[n].flag=0;//�e���I�t

                    //���G��Ԃ���Ȃ��Ȃ�
                    if(ch.flag==0 && ch.mutekicnt==0){
                        ch.cnt = 0;     //���G��Ԃ�
                        ch.flag=1;      //���G��Ԃ�
                        se_flag[3]=1;   //�s�`������

                        //�p���[�����炷
                        ch.power -= DECREASE_POWER;
                        if (ch.power < POWER_MIN) ch.power = POWER_MIN;//�����C��

                        //�~�X�񐔂𑝂₷
                        ch.miss++;
                        
                        switch (game_mode) {//game_mode / = 0 �c�@���[�h / = 1 �X�R�A���[�h
                        case 0: ch.life -= DECREASE_LIFE;   break;
                        case 1: ch.score -= DECREASE_SCORE; if (ch.score < SCORE_MIN)ch.score = SCORE_MIN; break;
                        }
                    }
                }
            }
        }
    }
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�{���̃_���[�W��G�ɋ��킷
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void cbom_and_enemy(){
    int s;
    if (bom.flag != 1) {//�{���𔭎˂��Ă��Ȃ��Ȃ�
        return;//�I��
    }

    //�G����
    for(s=0;s<ENEMY_MAX;s++){
        if(enemy[s].flag>0){//���̓G�������
            hit_enemy(s,ch.power/20);//�G�Ƀ_���[�W��^����
        }
    }

    //�{�X�����āA�`�悵�Ȃ��t���O���I�t�ŁA�V���b�g���Ȃ�
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
        hit_boss(ch.power/20);//�{�X�Ƀ_���[�W��^����
    }
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�A�C�e���Ƃ̐ڐG
//�A�C�e���@0:���p���[ 1:���_ 2:�e�_ 3:���� 4:��p���[ 5:���
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void ch_and_item(){
	for(int i=0;i<ITEM_MAX;i++){

        //�A�C�e��������Ȃ�
		if(item[i].flag>0){
			double x=item[i].x-ch.x,y=item[i].y-ch.y;

            //��������������
			if(x*x+y*y<ITEM_HIT_BOX*ITEM_HIT_BOX){
				switch(item[i].knd){//���������Ȃ�ǂ̃A�C�e��
					case 0:	ch.power+=5; break;
					case 1:	ch.point+=5; break;
					case 2:	ch.graze+=5; break;
					case 3:	ch.money+=5; break;
					case 4:	ch.power+=50;break;
					case 5:	ch.money+=10;break;
				}

                //�|�|�|�|�|�|�|�|�|�|/
                //����l�C��
                //�|�|�|�|�|�|�|�|�|�|/
				if(ch.power>POWER_MAX)ch.power=POWER_MAX;
				if(ch.point>OTHER_MAX)ch.point=OTHER_MAX;
				if(ch.money>OTHER_MAX)ch.money=OTHER_MAX;
				if(ch.graze>OTHER_MAX)ch.graze=OTHER_MAX;
				

                //�|�|�|�|�|�|�|�|�|�|/
                // �A�C�e����n��
                //�|�|�|�|�|�|�|�|�|�|/
                item[i].flag=0; //�A�C�e��������
				se_flag[34]=1;  //�������炷
			}
		}
	}
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�����蔻�胁�C��
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void out_main(){
    cbom_and_enemy();   //�G�Ƀ{�������킹��
    cshot_and_enemy();  //���@�V���b�g�ƓG�Ƃ̏���
    enemyshot_and_ch(); //�G�V���b�g�Ǝ��@�Ƃ̏���
	ch_and_item();      //�A�C�e���ڐG����
}