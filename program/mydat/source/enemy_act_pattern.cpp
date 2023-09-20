#include "../include/GV.h"


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�n���ꂽ-ang�`ang�܂ł̃����_���Ȋp�x��Ԃ�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
double rang(double ang){
    return ( -ang + ang*2 * GetRand(10000)/10000.0 );
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��0
//�������Ă��Ē�؂��ďオ���Ă���
void enemy_pattern0(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if(t==0){
        enemy[i].vy=3;
    }

    //�~�܂�
    if(t==40){
        enemy[i].vy=0;
    }

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==40+enemy[i].wait){
        enemy[i].vy=-3;//�オ���Ă���
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��1
//�������Ă��Ē�؂��č����ɍs��
void enemy_pattern1(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if(t==0){
        enemy[i].vy=3;
    }

    //�~�܂�
    if(t==40){
        enemy[i].vy=0;
    }

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==40+enemy[i].wait){
        enemy[i].vx=-1; //�~�܂�
        enemy[i].vy=2;  //�オ���Ă���
        enemy[i].muki=0;//�������Z�b�g
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��2
//�������Ă��Ē�؂��ĉE���ɍs��
void enemy_pattern2(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if (t == 0) {
        enemy[i].vy = 3;
    }

    //�~�܂�
    if (t == 40) {
        enemy[i].vy = 0;
    }

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==40+enemy[i].wait){
        enemy[i].vx=1;  //�オ���Ă���
        enemy[i].vy=2;  //�~�܂�
        enemy[i].muki=2;//�E�����Z�b�g
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�s���p�^�[��3
//���΂₭�~��Ă��č���
void enemy_pattern3(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if(t==0){
        enemy[i].vy=5;
    }

    //�r���ō�������
    if(t==30){
        enemy[i].muki=0;
    }

    //�������Ɉړ�
    if(t<100){
        enemy[i].vx-=5/100.0;//����������
        enemy[i].vy-=5/100.0;//����
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�s���p�^�[��4
//���΂₭�~��Ă��ĉE��
void enemy_pattern4(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if(t==0){
        enemy[i].vy=5;
    }

    //�r���ŉE������
    if(t==30){
        enemy[i].muki=2;
    }

    //�E�����Ɉړ�
    if(t<100){
        enemy[i].vx+=5/100.0;//�E��������
        enemy[i].vy-=5/100.0;//����
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�s���p�^�[��5
//�΂ߍ�����
void enemy_pattern5(int i){
    int t=enemy[i].cnt;

    //�΂ߍ����ֈړ�
    if(t==0){
        enemy[i].vx-=1; //���ֈړ�
        enemy[i].vy=2;  //���ֈړ�
        enemy[i].muki=0;//�摜����������
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�s���p�^�[��6
//�΂߉E����
void enemy_pattern6(int i){
    int t=enemy[i].cnt;

    //�΂߉E���Ɉړ�
    if(t==0){
        enemy[i].vx+=1; //�E�ֈړ�
        enemy[i].vy=2;  //���ֈړ�
        enemy[i].muki=2;//�摜�̌������E������
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��7
//��؂��Ă��̂܂܍����
void enemy_pattern7(int i){
    int t=enemy[i].cnt;

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==enemy[i].wait){
        enemy[i].vx=-0.7;   //����
        enemy[i].vy=-0.3;   //�オ���Ă���
        enemy[i].muki=0;    //������
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��8
//��؂��Ă��̂܂܉E���
void enemy_pattern8(int i){
    int t=enemy[i].cnt;

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==enemy[i].wait){
        enemy[i].vx=+0.7;   //�E��
        enemy[i].vy=-0.3;   //�オ���Ă���
        enemy[i].muki=2;    //�E����
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��9
//��؂��Ă��̂܂܏��
void enemy_pattern9(int i){
    int t=enemy[i].cnt;

    //�o�^���ꂽ��؎��Ԃ�������
    if(t==enemy[i].wait){
        enemy[i].vy=-1;//�オ���Ă���
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�ړ��p�^�[��10
//�������Ă��ăE���E�����ďオ���Ă���
void enemy_pattern10(int i){
    int t=enemy[i].cnt;

    //�������Ă���
    if (t == 0) {
        enemy[i].vy = 4;
    }

    //��~
    if(t==40){
        enemy[i].vy=0;//�~�܂�
    }

    //���낤�낵�ď㏸����
    if(t>=40){
        if(t%60==00){
            int r=cos(enemy[i].ang)< 0 ? 0 : 1;
            enemy[i].sp=6+rang(2);
            enemy[i].ang=rang(PI/4)+PI*r;
            enemy[i].muki=2-2*r;
        }
        enemy[i].sp*=0.95;
    }
    if(t>=40+enemy[i].wait){
        enemy[i].vy-=0.05;
    }
}