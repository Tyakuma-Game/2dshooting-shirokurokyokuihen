#include "../include/GV.h"

//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �͖��\������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_stage_title(){

	//�����\���J�n���Ȃ�
	if(stage_title.appear_cnt==stage_count){
		stage_title.flag=1;//�t���O��\������ɕύX

		//�Ή������摜��ǂݍ���
		stage_title.img = LoadGraph("../dat/img/board/subject1.png");
	}

	//�t���O�������ĂȂ��Ȃ炱���ŏI��
	if (stage_title.flag == 0) {
		return;//�����I��
	}

	//�ŏ���128�̊Ԓi�X���邭
	if (stage_title.cnt < 128) {
		stage_title.brt += 2;
	}
	
	//�i�X�Â�
	if(stage_title.cnt>128+128){
		stage_title.brt-=2;
	}

	//�I��
	if(stage_title.cnt>128+128+128){
		stage_title.cnt=0;	//�o�ߎ��Ԃ��O��
		stage_title.brt=0;	//���邳�����l���O��
		stage_title.flag=0;	//�t���O�𗧂��ĂȂ���Ԃ�
		DeleteGraph(stage_title.img);//�摜���

		return;//�����I��
	}

	stage_title.cnt++;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�A�C�e���̋z������
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_item_indraw(int i){
	double v = item[i].state ? 8 : 3;					//state1�Ȃ�X�s�[�h8�A�Ⴄ�Ȃ�2
	double angle=atan2(ch.y-item[i].y,ch.x-item[i].x);	//���@�ւ̊p�x���v�Z����
	item[i].x += cos(angle)*v;
	item[i].y += sin(angle)*v;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�A�C�e���ړ��Ȃǌv�Z
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_item(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].flag>0){
			if(item[i].state==0){
				//�z����ԂȂ�
				if(ch.y<ITEM_GET_BORDER_LINE){
					item[i].state=1;
				}
			}

			//���ʂ̏�ԂȂ�
			if(item[i].state==0){
				double x=ch.x-item[i].x,y=ch.y-item[i].y;

				//�ᑬ��ԂŎ��@�t�߂Ȃ�
				if(CheckStatePad(configpad.slow)>0 &&
						x*x+y*y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE){
					calc_item_indraw(i);//�z��
				}
				else{
					if(item[i].v<2.5){//���x�A�b�v
						item[i].v+=0.06;
					}
					item[i].y+=item[i].v;//�ړ�
				}
			}
			else{//�z����ԂȂ�
				calc_item_indraw(i);
			}

			item[i].cnt++;

			if(item[i].y>FMY+50){
				item[i].flag=0;
			}
		}
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
//�t���b�V��(42)
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_flash(){
	if(flash.flag>0){
		if(flash.knd==0){

			if (flash.cnt == 0) {
				flash.brt = 0;
			}

			if(flash.cnt<flash.to_cnt){
				flash.brt+=255.0/flash.to_cnt;
			}
			else{
				flash.brt-=255.0/flash.to_cnt;
			}
		}
		if(flash.knd==1){
			if (flash.cnt == 0) {
				flash.brt = 255;
			}
			flash.brt-=255.0/flash.to_cnt;
		}

		flash.cnt++;

		if(flash.knd==0){
			if(flash.cnt>flash.to_cnt*2){
				flash.flag=0;
			}
		}
		if(flash.knd==1){
			if(flash.cnt>flash.to_cnt){
				flash.flag=0;
			}
		}
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �Q�[�����̏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_game_ply() {
	//�֐�����p�ϐ�
	if (boss.flag == 0) {
		stage_count++;
	}

	//���U���g��ʂ�\�����邩����
	if (stage_count > 2900) {
		func_state = result;//��ʂ����U���g��ʂɕύX
	}

	//�Q�[���I�[�o�[����
	if (game_mode == 0 && ch.life == 0) {//�c�@���[�h���c�@���O�ɂȂ���
		func_state = game_over;//��ʂ��Q�[���I�[�o�[��
	}

	count++;
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ���U���g��ʂ̏���
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_result() {

	//����Ȃ�
	if (result_flg == 0) {
		
		//����
		end = clock();											//�v���I��
		elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;	//�o�ߎ��Ԍv�Z

		//���[�h�ݒ�
		mode_tmp ^= 1;					//���[�h���]
		if (mode_tmp == 1)mode_tmp++;	//�c�@���[�h�Ńv���C���Ă����Ȃ�

		//�{�[�i�X�{�����v�Z
		bonus = mode_tmp + level_tmp + 3 - ch.retry;
		if (bonus < 1)bonus = 1;//�{�[�i�X�ŏ��␳

		//���v�_���v�Z
		sum_score = ch.score_max + ch.power * POWER_BONUS_SCORE + ch.kill_count * KILL_BONUS_SCORE +
			ch.money * MONEY_BONUS_SCORE + ch.graze * GRAZE_BONUS_SCORE + ch.point * POINT_BONUS_SCORE;

		//�{�[�i�X�v�Z�Ə���C��
		final_score = sum_score * bonus;
		if (final_score > SCORE_MAX) final_score = SCORE_MAX;

		//�����N�t��
		if (final_score <= RANKING_BORDER_BRONZE) {
			result_rank = bronze;
		}
		else if (final_score <= RANKING_BORDER_SILVER) {
			result_rank = silver;
		}
		else if (final_score <= RANKING_BORDER_GOLD) {
			result_rank = gold;
		}
		else if (final_score <= RANKING_BORDER_PLATINUM) {
			result_rank = platinum;
		}
		else {
			result_rank = diamond;
		}

		//�t���O�����s�ς݂ɕς���
		result_flg = 1;
	}
}


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// �ꌳ�Ǘ�
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void calc_main(){
	calc_stage_title();	//�͖���\������
	calc_item();		//�A�C�e���v�Z
	calc_flash();		//�t���b�V��(42)
}