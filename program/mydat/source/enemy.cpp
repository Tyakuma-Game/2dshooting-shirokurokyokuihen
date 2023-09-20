#include "../include/GV.h"

extern void enemy_pattern0(int);extern void enemy_pattern1(int);extern void enemy_pattern2(int);
extern void enemy_pattern3(int);extern void enemy_pattern4(int);extern void enemy_pattern5(int);
extern void enemy_pattern6(int);extern void enemy_pattern7(int);extern void enemy_pattern8(int);
extern void enemy_pattern9(int);extern void enemy_pattern10(int);


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �G�̍s���p�^�[���𕪂���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void (*enemy_pattern[ENEMY_PATTERN_MAX])(int) = {
    enemy_pattern0,    enemy_pattern1,    enemy_pattern2,    enemy_pattern3,    enemy_pattern4,
    enemy_pattern5,    enemy_pattern6,    enemy_pattern7,    enemy_pattern8,    enemy_pattern9,
    enemy_pattern10,
};


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�󂢂Ă���G�ԍ�������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
int enemy_num_search(){

    //�t���O�̂����Ė���enemy��T��
    for(int i=0;i<ENEMY_MAX;i++){
        if(enemy[i].flag==0){
            return i;//�g�p�\�ԍ���Ԃ�
        }
    }

    //�S�����܂��Ă�����G���[��Ԃ�
    return -1;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�̍s����o�^�E����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enemy_enter(){
    int i,j,t;

    //�{�X�풆�͏o�������Ȃ�
    if (boss.flag != 0) {
        return;
    }

    //�G�̏o���ő吔�܂ł��
    for(t=0;t<ENEMY_ORDER_MAX;t++){

        //���݂̏u�Ԃ��I�[�_�[�̏u�ԂȂ�
        if(enemy_order[t].cnt==stage_count){
            if((i=enemy_num_search())!=-1){//�G�ɋ󂫂������

                //�|�|�|�|�|�|�|�|�|�|/
                // �o�^
                //�|�|�|�|�|�|�|�|�|�|/

                enemy[i].flag    = 1;//�t���O
                enemy[i].cnt     = 0;//�J�E���^
                enemy[i].pattern = enemy_order[t].pattern;  //�ړ��p�^�[��
                enemy[i].muki    = 1;                       //����
                enemy[i].knd     = enemy_order[t].knd;      //�G�̎��
                enemy[i].x       = enemy_order[t].x;        //���W
                enemy[i].y       = enemy_order[t].y;        //���W
                enemy[i].sp      = enemy_order[t].sp;       //�X�s�[�h
                enemy[i].bltime  = enemy_order[t].bltime;   //�e�̔��ˎ���
                enemy[i].blknd   = enemy_order[t].blknd;    //�U���p�^�[��
                enemy[i].blknd1  = enemy_order[t].blknd1;   //�g�p�e��
                enemy[i].col     = enemy_order[t].col;      //�F
                enemy[i].wait    = enemy_order[t].wait;     //�F
                enemy[i].hp      = enemy_order[t].hp;       //�̗�
                enemy[i].hp_max  = enemy[i].hp;             //�̗͍ő�l
                enemy[i].back_col= GetRand(4);
                enemy[i].vx      = 0;//���������̑��x
                enemy[i].vy      = 0;//���������̑��x
                enemy[i].ang     = 0;//�p�x


                //���Ƃ��A�C�e��
                for(j=0;j<6;j++){
                    enemy[i].item_n[j]=enemy_order[t].item_n[j];
                }
            }
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �G�̒e���o�^����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enter_shot(int i){
	int j;

    //�t���O�̂����Ė���enemy��T��
	for(j=0;j<SHOT_MAX;j++){

        //���g�p�̒e���f�[�^�������
		if(shot[j].flag==0){

            //���������ēo�^
			memset(&shot[j],0,sizeof(shot_t));//�������m��
			shot[j].flag=1;                   //�t���O�����Ă�
			shot[j].knd=enemy[i].blknd;       //�U���p�^�[���o�^
            shot[j].knd1 = enemy[i].blknd1;   //�g�p�e���o�^
			shot[j].num=i;                    //num=�ǂ̓G���甭�˂��ꂽ���̂��B
			shot[j].cnt=0;                    //�e�������������

			return;
		}
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�̍s������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enemy_act(){
    int i;

    //�G�̍ő�o�����܂Ŏ��s
    for(i=0;i<ENEMY_MAX;i++){

        //���̓G�̃t���O���I���ɂȂ��Ă���
        if(enemy[i].flag==1){
            if(0<=enemy[i].pattern && enemy[i].pattern<ENEMY_PATTERN_MAX){//�G���[���Ȃ����`�F�b�N
                //�s���p�^�[����n��
                enemy_pattern[enemy[i].pattern](i);

                //���W�ړ�
                enemy[i].x+=cos(enemy[i].ang)*enemy[i].sp;
                enemy[i].y+=sin(enemy[i].ang)*enemy[i].sp;
                enemy[i].x+=enemy[i].vx;
                enemy[i].y+=enemy[i].vy;

                //����p�J�E���g
                enemy[i].cnt++;

                //�G�̃A�j���[�V����
                enemy[i].img=enemy[i].muki*3+(enemy[i].cnt%18)/6;

                //�G����ʊO�ɊO�ꂽ�����
                if(enemy[i].x<-20 || FMX+20<enemy[i].x || enemy[i].y<-20 || FMY+20<enemy[i].y){
                    enemy[i].flag=0;
                }

                //�e���J�n���ԂɂȂ�����e������
				if(enemy[i].bltime==enemy[i].cnt){
					enter_shot(i);
                }
			}
            else
                printfDx("enemy[i].pattern��%d�l���s���ł��B",enemy[i].pattern);
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�G�������C��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enemy_main(){
    enemy_enter();  //�G����o�^
    enemy_act();    //�G�s���𐧌�
}