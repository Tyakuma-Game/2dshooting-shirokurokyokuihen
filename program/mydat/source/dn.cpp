#include "../include/GV.h"


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�@�ǂꂮ�炢��邩�w�肷��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void enter_dn(int size, int time){
	dn.flag=1;
	dn.cnt=0;
	dn.time=time;
	dn.size=size;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�h�K�[���Ƃ����ʂ̏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void dn_calc(){
    if(dn.flag==1){//�����t���O��ON�Ȃ�

        //�h�炷
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;

        //�w�肳�ꂽ���Ԃ����ƏI���
        if(dn.cnt>dn.time){
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}