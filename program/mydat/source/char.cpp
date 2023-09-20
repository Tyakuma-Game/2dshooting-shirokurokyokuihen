#include "../include/GV.h"

extern void enter_char_item();//(39��)


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �L�����N�^�[�̏�Ԍv�Z
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_ch(){

    //��炢�{����t��
    if(ch.flag==1){
        bright_set.brt=80;//�Â�

        if(ch.cnt>20){//0.33�b�󂯕t����
            ch.flag   =2;    //1:��炢�{����t���@2:����ŕ����オ�蒆
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }

    //���̏u�Ԏ��񂾂�
    if(ch.cnt==0 && ch.flag==2){
		enter_char_item();//�L�����̃A�C�e���o�^(39��)

        //���W������
        ch.x=FMX/2;
        ch.y=FMY+30;

        //���G��Ԃֈڍs
        ch.mutekicnt++;
    }

    //����ŕ��㒆�Ȃ�
    if(ch.flag==2){
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//�L��������ɏグ��


        //�P�b�ȏォ�A�L������������x��ɂ��āA���������ꂽ��
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//�L�����X�e�[�^�X�����ɖ߂�
        }
    }

    //���G���
    if(ch.mutekicnt>0){//�O����Ȃ�������
        ch.mutekicnt++;

        //150�ȏソ������
        if(ch.mutekicnt>150){
            ch.mutekicnt=0;//���G��Ԃ�����
        }
    }

    //�v���C���[����p
    ch.cnt++;//�L�����N�^�J�E���g�A�b�v

    //�A�j���[�V�����v�Z
    ch.img=(ch.cnt%18)/6;//���݂̉摜����
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �L�����N�^�[�v�Z
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void ch_move(){
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    //��炢�{����t���͓������Ȃ�
    if (ch.flag == 1) {
        return;
    }

    //�|�|�|�|�|�|�|�|�|�|/
    // �ړ��v�Z
    //�|�|�|�|�|�|�|�|�|�|/

    //���E��
    for(i=0;i<2;i++){
        if(inputpad[i]>0){  //���E�ǂ��炩�̓��͂������
            sayu_flag=1;    //���E���̓t���O�𗧂Ă�
        }
    }

    //�㉺��
    for(i=2;i<4;i++){
        if(inputpad[i]>0){  //�㉺�ǂ��炩�̓��͂������
            joge_flag=1;    //�㉺���̓t���O�𗧂Ă�
        }
    }

    //�΂߈ړ�������
    if(sayu_flag==1 && joge_flag==1){//���E�A�㉺�����̓��͂�����Ύ΂�
        naname=sqrt(2.0);//�ړ��X�s�[�h��1/���[�g2��
    }


    //�|�|�|�|�|�|�|�|�|�|/
    //���ۂɌv�Z
    //�|�|�|�|�|�|�|�|�|�|/
    for(int i=0;i<4;i++){//4���������[�v
        if(inputpad[i]>0){//i�����̃L�[�{�[�h�A�p�b�h�ǂ��炩�̓��͂������

            //���̍��W���Ƃ肠����x,y�Ɋi�[
            x=ch.x , y=ch.y;

            //�ړ�����mx,my�ɑ��
            mx=move_x[i];    my=move_y[i];

            //�ᑬ�ړ��Ȃ�
            if(CheckStatePad(configpad.slow)>0){
                mx=move_x[i]/3;    my=move_y[i]/3;//�ړ��X�s�[�h��1/3��
            }

            //���v�Z
            x+=mx/naname , y+=my/naname;//���̍��W�ƈړ����𑫂�

            //���v�Z���ʈړ��\�͈͓��Ȃ�
            if(!(x<10 || x>
                FMX-10 || y<5 || y>FMY-5)){
                ch.x=x , ch.y=y;//���ۂɈړ�
            }
        }
    }
}