#include "../include/GV.h"

extern int search_boss_shot();
extern int search_lazer();
extern int search_child();
extern double bossatan2();
extern double bossatan3(int k,double x,double y);//�w����W�ƒe�Ƃ̐����p
extern int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t);
extern void input_phy_pos(double x,double y,int t);
extern void input_lphy(lazer_t *laz, int time, double angle);


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�v���g�^�C�v�錾
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH000();//�~�`����
void boss_shot_bulletH001();//�T�C�����g�Z���i
void boss_shot_bulletH002();//�p�[�t�F�N�g�t���[�Y
void boss_shot_bulletH003();//���̖��H
void boss_shot_bulletH004();//�P�������J���ɂ�������
void boss_shot_bulletH005();//���e��
void boss_shot_bulletH006();//���肩�璆���ւ̔���
void boss_shot_bulletH007();//���肩�璼������
void boss_shot_bulletH008();//������
void boss_shot_bulletH015();//�~�`���˂ƃT�C�����g�Z���i
void boss_shot_bulletH016();//�����ɍ��킹�ĂQ�����Ă���
void boss_shot_bulletH017();//�p�[�t�F�N�g�t���[�Y�Ǝ��肩�璼��
void boss_shot_bulletH018();//�������Ɖ~�`����
void boss_shot_bulletH019();//�����ɍ��킹�ĂQ�����Ă��� �~�`����



//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �~�`���˂ƃT�C�����g�Z���i
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH015() {
    boss_shot_bulletH000();//�~�`����
    boss_shot_bulletH001();//�T�C�����g�Z���i
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �����ɍ��킹�ĂQ�����Ă���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH016() {
    boss_shot_bulletH006();//���肩�璆����
    boss_shot_bulletH007();//���肩�璼��
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �p�[�t�F�N�g�t���[�Y�Ǝ��肩�璼��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH017() {
    boss_shot_bulletH002();//�p�[�t�F�N�g�t���[�Y
    boss_shot_bulletH007();//���肩�璼��
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �������Ɖ~�`����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH018() {
    boss_shot_bulletH000();//�~�`����
    boss_shot_bulletH008();//������
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �����ɍ��킹�ĂQ�����Ă��� �~�`����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH019() {
    boss_shot_bulletH006();//���肩�璆����
    boss_shot_bulletH007();//���肩�璼��
    boss_shot_bulletH000();//�~�`����
}




//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�����̉~�`����
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH000(){
#define TM000 120
    int i,k,t=boss_shot.cnt%TM000,t2=boss_shot.cnt;
    double angle;

    //60�J�E���g�ȉ���5�J�E���g��1��
    if(t<60 && t%5==0){//�C��

        //���@�ƃ{�X�Ƃ̐����p
        angle=bossatan2();

        for(i=0;i<30;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 0;      //�e�̐F
                if ((i+1) % 2 == 0) boss_shot.bullet[k].col = 1;//�e�̐F
                boss_shot.bullet[k].x     = boss.x; //���W
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 15;      //�e�̎��
                boss_shot.bullet[k].angle = angle+PI2/30*i;//�p�x
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3;//�X�s�[�h
                se_flag[0]=1;
            }
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�T�C�����g�Z���i
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH001(){
#define TM001 60
    int i,k,t=boss_shot.cnt%TM001,t2=boss_shot.cnt;
    static int cnum;
    double angle;

    //�ŏ��Ȃ�
    if(t2==0){
        cnum=0;
    }

    //1�����̍ŏ��Ȃ�
    if(t==0){
        //��Ɛ���p�x���Z�b�g
        boss_shot.base_angle[0]=bossatan2();

        //4��4��ڂȂ�
        if(cnum%4==3){
            //40������FMX-40�A30��y��120�͈̔͂�60�̋����A60�J�E���g�ňړ�
            move_boss_pos(40,30,FMX-40,120,60, 60);
        }
    }

    //�����̔����Ŋp�x��ς���
    if(t==TM001/2-1){
        boss_shot.base_angle[0]+=PI2/20/2;
    }

    //�~�`
    if(t%(TM001/10)==0){//10�J�E���g��1�񂸂�
        angle=bossatan2();//�{�X�Ǝ��@�Ƃ̐����p

        //PI2/20�x����1��
        for(i=0;i<20;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 1;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 15;
                boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI2/20*i;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;
                se_flag[0]=1;
            }
        }
    }

    //�����_����������
    if(t%4==0){
        if((k=search_boss_shot())!=-1){
            boss_shot.bullet[k].col   = 0;
            boss_shot.bullet[k].x     = GetRand(FMX);
            boss_shot.bullet[k].y     = GetRand(200);
            boss_shot.bullet[k].knd   = 15;
            boss_shot.bullet[k].angle = PI/2;
            boss_shot.bullet[k].flag  = 1;
            boss_shot.bullet[k].cnt   = 0;
            boss_shot.bullet[k].spd   = 1+rang(0.5);
            se_flag[0]=1;
        }
    }
    if(t==TM001-1){
        cnum++;
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�p�[�t�F�N�g�t���[�Y
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH002(){
#define TM002 650
    int i,k,t=boss_shot.cnt%TM002;
    double angle;

    if(t==0 || t==210){
        //40<x<FMX-40  50<y<150�@�͈̔͂�100���ꂽ�ʒu��80�J�E���g�ňړ�����
        move_boss_pos(40,50,FMX-40,150,100, 80);
    }

    //�ŏ��̃����_������
    if(t<180){
        for(i=0;i<2;i++){//1�J�E���g��2�񔭎�
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = rand() % 2;
                boss_shot.bullet[k].x     = boss.x;//���ˏ������W�̓{�X�̈ʒu
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 2;//�e�̎��
                boss_shot.bullet[k].angle = rang(PI2/20)+PI2/10*t;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.2+rang(2.1);
                boss_shot.bullet[k].state = 0;//�e�̃X�e�[�^�X
                boss_shot.bullet[k].kaiten= 1;//�e����]���邩�ǂ����̃t���O
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }

    //���@�ˑ��ɂ��8��������
    if(210<t && t<270 && t%3==0){
        angle=bossatan2();
        for(i=0;i<8;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 0;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 2;
                //���@�ƃ{�X�Ƃ̐����p����ɂW�����ɔ��˂���
                boss_shot.bullet[k].angle = angle-PI/2*0.8+PI*0.8/7*i+rang(PI/180);
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.0+rang(0.3);
                boss_shot.bullet[k].state = 2;
                boss_shot.bullet[k].kaiten= 1;
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){

            //t��190�̎��ɑS�ăX�g�b�v�����A�F�ύX�A�J�E���g���Z�b�g
            if(boss_shot.bullet[i].state==0){
                if(t==190){

                    boss_shot.bullet[i].kaiten=0;//�e�̉�]���~�߂�
                    boss_shot.bullet[i].spd   =0;
                    boss_shot.bullet[i].col   =1;
                    boss_shot.bullet[i].cnt   =0;
                    boss_shot.bullet[i].state =1;
                }
            }

            //�����_���ȕ����Ɉړ����n�߂�
            if(boss_shot.bullet[i].state==1){
                if(boss_shot.bullet[i].cnt==200){
                    boss_shot.bullet[i].angle=rang(PI);
                    boss_shot.bullet[i].kaiten=1;
                }
                if(boss_shot.bullet[i].cnt>200)
                    boss_shot.bullet[i].spd+=0.01;
            }
        }
    }
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//���̖��H
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH003(){
#define TM003 600
#define DF003 20 
    int i,j,k,t=boss_shot.cnt%TM003,t2=boss_shot.cnt;
    static int tcnt,cnt,cnum;
    double angle;

    //�ŏ��Ȃ�
    if(t2==0){
        //40<x<FMX-40  50<y<150�@�͈̔͂�100���ꂽ�ʒu��80�J�E���g�ňړ�����
        input_phy_pos(FMX/2,FMY/2, 50);
        cnum=0;
    }

    //�P�����̍ŏ��Ȃ�
    if(t==0){
        boss_shot.base_angle[0]=bossatan2();//���@�_��
        cnt=0;
        tcnt=2;
    }

    if(t<540 && t%3){
        angle=bossatan2();

        //�����Ȃ������Ȃ猂���Ȃ�
        if(tcnt-2==cnt || tcnt-1==cnt){
            if(tcnt-1==cnt){
                //�x�[�X�ƂȂ�p�x���Z�b�g
                boss_shot.base_angle[1]=boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)-PI2/(DF003*6)*3;
                tcnt+=DF003-2;
            }
        }
        //���ꂶ��Ȃ���΂���
        else{
            for(i=0;i<6;i++){//�P��ɂU��������
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = 1;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 2;
                    boss_shot.bullet[k].angle 
                        = boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)+PI2/(DF003*6)*i*(cnum?-1:1);
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt      = 0;
                    boss_shot.bullet[k].spd      = 2;
                    se_flag[0]=1;
                }
            }
        }
        cnt++;
    }
    //�����傫�Ȓe�ŉ~�`����
    if(40<t&&t<540 && t%30==0){
        for(j=0;j<3;j++){
            angle=boss_shot.base_angle[1]-PI2/36*4;
            for(i=0;i<27;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = rand()%2;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 2;
                    boss_shot.bullet[k].angle = angle;
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 4-1.6/3*j;
                    se_flag[0]=1;
                }
                angle-=PI2/36;
            }
        }
    }
    if(t==TM003-1)
        cnum++;
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//�P������񕗉J�ɂ�������
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void boss_shot_bulletH004(){
#define TM004 200
    int i,n,k,t=boss_shot.cnt%TM004,t2=boss_shot.cnt;
    static int tm;
    double angle;
    if(t==0)
        tm=(int)(190+rang(30));
    //�ォ��ӂ炷�e�𔭎˂����̊p�x���Z�b�g
    angle=PI*1.5+PI/6*sin(PI2/tm*t2);
    //�M���M������e
    if(t2%4==0){
        for(n=0;n<8;n++){//8�����ɂӂ�
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].flag=1;
                boss_shot.bullet[k].state=0;
                boss_shot.bullet[k].cnt=0;
                boss_shot.bullet[k].knd=2;
                boss_shot.bullet[k].col=1;
                boss_shot.bullet[k].angle=0;
                boss_shot.bullet[k].eff_detail=1;//�s�J�s�J���点��
                boss_shot.bullet[k].x=boss.x;
                boss_shot.bullet[k].y=boss.y;
                boss_shot.bullet[k].vx = cos(angle-PI/8*4+PI/8*n+PI/16)*3;
                boss_shot.bullet[k].vy = sin(angle-PI/8*4+PI/8*n+PI/16)*3;
            }
        }
        se_flag[0]=1;
    }
    //��������
    if(t%1==0 && t2>80){
        int num=1;
        if(t%2)
            num=2;
        for(n=0;n<num;n++){
            if((k=search_boss_shot())!=-1){
                angle=PI*1.5-PI/2+PI/12*(t2%13)+rang(PI/15);
                boss_shot.bullet[k].flag=1;
                boss_shot.bullet[k].state=1;
                boss_shot.bullet[k].cnt=0;
                boss_shot.bullet[k].knd=4;
                boss_shot.bullet[k].eff_detail=0;//�s�J�s�J�͌���Ȃ�
                boss_shot.bullet[k].col=0;
                boss_shot.bullet[k].angle=0;
                boss_shot.bullet[k].x=boss.x;
                boss_shot.bullet[k].y=boss.y;
                boss_shot.bullet[k].vx = cos(angle)*1.4*1.2;
                boss_shot.bullet[k].vy = sin(angle)*1.4;
            }
        }
        se_flag[7]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            if(boss_shot.bullet[i].state==0){//�X�e�[�^�X���O�Ȃ�
                if(boss_shot.bullet[i].cnt<150)
                    boss_shot.bullet[i].vy+=0.03;//���������̉������ɉ�������
                boss_shot.bullet[i].x+=boss_shot.bullet[i].vx;
                boss_shot.bullet[i].y+=boss_shot.bullet[i].vy;
            }
            if(boss_shot.bullet[i].state==1){//�X�e�[�^�X���P�Ȃ�
                if(boss_shot.bullet[i].cnt<160)
                    boss_shot.bullet[i].vy+=0.03;//���������̉������ɉ�������
                boss_shot.bullet[i].x+=boss_shot.bullet[i].vx;
                boss_shot.bullet[i].y+=boss_shot.bullet[i].vy;
                boss_shot.bullet[i].angle=atan2(boss_shot.bullet[i].vy,boss_shot.bullet[i].vx);
            }
        }
    }
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���e
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void boss_shot_bulletH005(){
#define TM005 820
#define RANGE005 100.0
#define LEM005 4
    int i,j,k,t=boss_shot.cnt%TM005,t2=boss_shot.cnt;
    static int sst,bnum;
    static double sx,sy,sangle;

    //1�����̍ŏ��Ȃ�
    if(t==0){
        sst=0;
        sx=boss.x;
        sy=boss.y-RANGE005;
        sangle=PI/5/2+PI/2;
        bnum=0;
    }

    //����`��
    if(sst<=4){
        for(i=0;i<2;i++){
            sx+=cos(sangle)*LEM005;//���W���v�Z
            sy+=sin(sangle)*LEM005;

            //�~�ƌ��������
            if((sx-boss.x)*(sx-boss.x)+(sy-boss.y)*(sy-boss.y)>RANGE005*RANGE005){
                sangle-=(PI-PI/5);  //�����]��
                sst++;              //�X�e�[�^�X�ϊ�
                if(sst==5)break;    //5�Ȃ�I���
            }

            //�����T�`��
            for(j=0;j<5;j++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].flag=1;
                    boss_shot.bullet[k].state=j;
                    boss_shot.bullet[k].cnt=0;
                    boss_shot.bullet[k].spd=0;
                    boss_shot.bullet[k].knd=2;
                    boss_shot.bullet[k].col = 0;
                    if ((j + 1) % 2 == 0) {
                        boss_shot.bullet[k].col = 1;
                    }

                    boss_shot.bullet[k].angle=-PI/2+PI2/5*j;
                    boss_shot.bullet[k].x=sx;
                    boss_shot.bullet[k].y=sy;
                    boss_shot.bullet[k].vx = cos(sangle)*1.4*1.2;
                    boss_shot.bullet[k].vy = sin(sangle)*1.4;
                    boss_shot.bullet[k].base_angle[0]=sangle-PI+PI/20*bnum;
                }
            }
            bnum++;
        }
        se_flag[0]=1;
    }

   for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            
            //�X�e�[�^�X��10�����Ȃ�
            if(boss_shot.bullet[i].state<10){
                if(t==150){                         //150�Ȃ琯���T�����ɔ���
                    boss_shot.bullet[i].spd=4;      //�X�s�[�h
                    boss_shot.bullet[i].cnt=0;      //�J�E���^���Z�b�g
                    boss_shot.bullet[i].state+=10;  //�X�e�[�^�X�ԍ��ύX
                }
            }
            else if(boss_shot.bullet[i].state<20){//10~19�Ȃ�
                if(cnt<=80){//����
                    boss_shot.bullet[i].spd-=0.05;
                }
                if(cnt==100){//�Z�b�g������p�x�����Y��ȋȐ���`��
                    boss_shot.bullet[i].angle=boss_shot.bullet[i].base_angle[0];
                }
                if(cnt>=100 && cnt<160){//����
                    boss_shot.bullet[i].spd+=0.015;
                }
            }
        }
    }
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���肩�璆���ւ̔���
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void boss_shot_bulletH006(){
#define TM006 300
//�����ɒu���e�̐�
#define DNUMX006 15
    int i,j,k,t=boss_shot.cnt%TM006,t2=boss_shot.cnt;
    double xlen=FMX/DNUMX006;//��ʂ�DNUM���ׂ�ɂ�xlen�Ԋu�ŕ��ׂ�΂���
    int dnumy=(int)(FMY/xlen);//xlen���Ȃ�ׂ�Ɖ��������ɂ����͂��邩
    int cnum;
    if(dnumy==0){printfDx("boss_shot_bulletH006��0����\n"); return ;}
    double ylen=FMY/dnumy;//ylen�������΂���
    double x,y,angle;
    static int num;
    if(t2==0)num=0;
    if(t==0){
        x=0,y=0,angle=0,cnum=0;
        for(j=0;j<4;j++){
            //���������Ȃ�DNUMX006�A���������Ȃ�dnumy
            int to = j%2 ? dnumy: DNUMX006 ;
            //���������A���������ł͒u�������Ⴄ�̂ŁAto��u��
            for(i=0;i<=to;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].x     = x;//���W
                    boss_shot.bullet[k].y     = y;
                    boss_shot.bullet[k].knd   = 2;//�e�̎��
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    switch(num){
                        case 0://���ˎ�ނP
                    boss_shot.bullet[k].col   = 1;//�e�̐F
                    boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);//�p�x
                    boss_shot.bullet[k].spd   = 1.3;//�X�s�[�h
                    boss_shot.bullet[k].state = 0;//�X�e�[�^�X
                        break;
                        case 1://���ˎ�ނQ
                    boss_shot.bullet[k].col   = 0;//�e�̐F
                    boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);//�p�x
                    boss_shot.bullet[k].spd   = 1.4+ ((j%2 ? -1 : 1) * ((cos(PI2/to*i-PI)+1)/2))*0.4;//�X�s�[�h
                    boss_shot.bullet[k].state = 1;//�X�e�[�^�X
                        break;
                        case 2://���ˎ�ނR
                    boss_shot.bullet[k].col   = 1;//�e�̐F
                    boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);//�p�x
                    boss_shot.bullet[k].spd   = 1.3;//�X�s�[�h
                    boss_shot.bullet[k].state = 2;//�X�e�[�^�X
                    boss_shot.bullet[k].base_angle[0] 
                    = PI/1000 * (j%2 ? -1 : 1) * ((cos(PI2/to*i-PI)+1)/2);//���Z����p�x
                        break;
                    }
                    se_flag[0]=1;
                    cnum++;
                }
                x+=cos(angle)*xlen;
                y+=sin(angle)*ylen;
            }
            angle+=PI/2;
        }
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            switch(boss_shot.bullet[i].state){
                case 2://���ˎ�ނR�Ȃ�
                    //�p�x�����Z
                    boss_shot.bullet[i].angle+=boss_shot.bullet[i].base_angle[0];
                    break;
                default:
                    break;
            }
        }
    }
    if(t==TM006-1)
        num=(++num)%3;
}


//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
//���肩�璼������
//�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[/
void boss_shot_bulletH007(){
#define TM007 300
#define DNUMX 9
    int i,j,k,s,t=boss_shot.cnt%TM007,t2=boss_shot.cnt;
    double xlen=FMX/DNUMX;//��ʂ�DNUM���ׂ�ɂ�xlen�Ԋu�ŕ��ׂ�΂���
    int dnumy=(int)(FMY/xlen);//xlen���Ȃ�ׂ�Ɖ��������ɂ����͂��邩
    int cnum;
    if(dnumy==0){printfDx("boss_shot_bulletH006��0����\n"); return ;}
    double ylen=FMY/dnumy;//ylen�������΂���
    double x,y,angle;
    static int num;
    if(t2==0)num=0;
    if(t==0){
        x=0,y=0,angle=0,cnum=0;
        for(j=0;j<4;j++){
            int to=j%2 ? dnumy: DNUMX ;
            for(i=0;i<=to;i++){
                for(s=0;s<2;s++){
                    if((k=search_boss_shot())!=-1){
                        boss_shot.bullet[k].x     = x;//���W
                        boss_shot.bullet[k].y     = y;
                        boss_shot.bullet[k].knd   = 2;//�e�̎��
                        boss_shot.bullet[k].flag  = 1;
                        boss_shot.bullet[k].cnt   = 0;
                        switch(num){
                            case 0:
                        boss_shot.bullet[k].col   = 0;//�e�̐F
                        boss_shot.bullet[k].angle = angle+PI/2;//�p�x
                        boss_shot.bullet[k].spd   = 1.1+0.5*s;//�X�s�[�h
                        boss_shot.bullet[k].state = 0;//�X�e�[�^�X
                            break;
                            case 1:
                        boss_shot.bullet[k].col   = 1;//�e�̐F
                        boss_shot.bullet[k].angle = angle+PI/2-PI/14+PI/7*s;//�p�x
                        boss_shot.bullet[k].spd   = 1.3;//�X�s�[�h
                        boss_shot.bullet[k].state = 1;//�X�e�[�^�X
                            break;
                        }
                        se_flag[0]=1;
                        cnum++;
                    }
                }
                x+=cos(angle)*xlen;
                y+=sin(angle)*ylen;
            }
            angle+=PI/2;
        }
    }
    if(t==TM006-1)
        num=(++num)%2;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void boss_shot_bulletH008(){
#define TM009 420
#define DIST 60
    int i,j,k,s,t=boss_shot.cnt%TM009,t2=boss_shot.cnt;
    double angle;
    static int num;
    if(t2==0)num=4;
    if(t==0){
        for(j=0;j<2;j++){
            for(i=0;i<num;i++){
                int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�e�̐F
                    lazer[k].knd      = 4;//�e�̎��
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�p�x
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//���W
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 2;//�X�s�[�h
                    lazer[k].state    = j;
                    lazer[k].length   = 310;
                    lazer[k].hantei      = 0;
                    lazer[k].lphy.conv_flag=1;
                    lazer[k].lphy.conv_base_x=boss.x;
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],80,PI/num*plmn);
                }
            }
        }
        se_flag[33]=1;
    }
    //60�J�E���g�ȉ���10�J�E���g��1��
    if(t==50){
        angle=rang(PI);//���@�ƃ{�X�Ƃ̐����p
        for(s=0;s<2;s++){
            for(t=0;t<3;t++){
                for(j=0;j<3;j++){
                    for(i=0;i<30;i++){
                        if((k=search_boss_shot())!=-1){
                            boss_shot.bullet[k].col   = s;//�e�̐F
                            boss_shot.bullet[k].x     = boss.x;//���W
                            boss_shot.bullet[k].y     = boss.y;
                            boss_shot.bullet[k].knd   = 10;//�e�̎��
                            boss_shot.bullet[k].angle = angle+PI2/30*i+PI2/60*s;//�p�x
                            boss_shot.bullet[k].flag  = 1;
                            boss_shot.bullet[k].cnt   = 0;
                            boss_shot.bullet[k].spd   = 1.8-0.2*j+0.1*s;//�X�s�[�h
                            boss_shot.bullet[k].eff   = 0;
                            boss_shot.bullet[k].state   = t;
                        }
                        se_flag[0]=1;
                    }
                }
            }
        }
    }
    if(t>=170 && t<310 && (t-170)%35==0){
        int div=((t-170)%70==0) ? -1 : 1;
        angle=rang(PI);//���@�ƃ{�X�Ƃ̐����p
        for(s=0;s<2;s++){//���x�̈Ⴄ2�̒e������
            for(t=0;t<3;t++){//1�ӏ�����3�ɂ킩���
                for(i=0;i<30;i++){//1��30��
                    if((k=search_boss_shot())!=-1){
                        boss_shot.bullet[k].col   = s;//�e�̐F
                        boss_shot.bullet[k].x     = boss.x;//���W
                        boss_shot.bullet[k].y     = boss.y;
                        boss_shot.bullet[k].knd   = 4;//�e�̎��
                        boss_shot.bullet[k].angle = angle+PI2/30*i;//�p�x
                        boss_shot.bullet[k].flag  = 1;
                        boss_shot.bullet[k].cnt   = 0;
                        boss_shot.bullet[k].spd   = 2-0.3*s;//�X�s�[�h
                        boss_shot.bullet[k].eff   = 0;
                        boss_shot.bullet[k].state = 10+t;
                        boss_shot.bullet[k].base_angle[0] = PI/300*div;
                    }
                }
            }
            se_flag[0]=1;
        }
    }
    if(t==360){
        angle=rang(PI);//���@�ƃ{�X�Ƃ̐����p
        for(t=0;t<3;t++){//1�ӏ�����R�ɕ������
            for(i=0;i<30;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = 1;//�e�̐F
                    boss_shot.bullet[k].x     = boss.x;//���W
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 4;//�e�̎��
                    boss_shot.bullet[k].angle = angle+PI2/30*i;//�p�x
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 1.8;//�X�s�[�h
                    boss_shot.bullet[k].eff   = 1;
                    boss_shot.bullet[k].state = 20+t;
                }
            }
        }
        se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            int state=boss_shot.bullet[i].state;
            if(state%10==0){
                if(cnt>90 && cnt<=100)
                    boss_shot.bullet[i].spd-=boss_shot.bullet[i].spd/220;
            }
            if(state%10==1){
                if(cnt>50)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/45;
            }
            if(state%10==2){
                if(cnt>65)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/90;
            }
            if(10<=state && state<=12){
                if(cnt>15 && cnt<=80)
                    boss_shot.bullet[i].angle+=boss_shot.bullet[i].base_angle[0];
            }
        }
    }
    for(i=0;i<LAZER_MAX;i++){
        if(lazer[i].flag>0){
            int cnt=lazer[i].cnt;
            int state=lazer[i].state;
            if(state==0 || state==1){
                if(cnt==80){
                    lazer[i].haba=10;
                    lazer[i].hantei=0.5;
                }
                if(cnt>=260 && cnt<=320){
                    if(cnt==280)
                        lazer[i].hantei=0;
                    lazer[i].haba=10*(60-(cnt-260))/60.0;
                    if(cnt==320)
                        lazer[i].flag=0;
                }
            }
        }
    }
    if(t==TM009-1)
        num=(++num);
}