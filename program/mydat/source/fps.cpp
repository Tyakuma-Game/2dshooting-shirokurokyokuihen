#include "../include/GV.h"

//�t���[����
#define FLAME 60

//fps�̃J�E���^�A60�t���[����1���ƂȂ鎞�����L�^����ϐ�
int fps_count,count0t;

//���ς��v�Z���邽��60���1�����Ԃ��L�^
int f[FLAME];

//����fps
double ave;


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �t���[���v�Z
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void fps_wait(){
    int term,i,gnt;
    static int t=0;

    //60�t���[����1��ڂȂ�
    if(fps_count==0){
        if(t==0){//���S�ɍŏ��Ȃ�܂��Ȃ�
            term=0;
        }
        else{   //�O��L�^�������Ԃ����Ɍv�Z
            term=count0t+1000-GetNowCount();
        }
    }
    else{       //�҂ׂ�����=���݂���ׂ�����-���݂̎���
        term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
    }

    //�҂ׂ����Ԃ����҂�
    if(term>0){
        Sleep(term);
    }

    gnt=GetNowCount();

    //60�t���[����1�x������
    if(fps_count==0){
        count0t=gnt;
    }
    
    //�P���������Ԃ��L�^
    f[fps_count]=gnt-t;
    t=gnt;
    
    //���όv�Z
    if(fps_count==FLAME-1){
        ave=0;
        for(i=0;i<FLAME;i++){
            ave+=f[i];
        }
        ave/=FLAME;
    }
    fps_count = (++fps_count)%FLAME ;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �t���[������\������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void draw_fps(int x, int y){
    if(ave!=0){
        DrawFormatString(x, y,color[0],"[%.1f]",1000/ave);
    }
    return;
}