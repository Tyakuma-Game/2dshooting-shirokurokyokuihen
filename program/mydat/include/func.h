
extern void boss_shot_bulletH000();//�~�`����
extern void boss_shot_bulletH001();//�T�C�����g�Z���i
extern void boss_shot_bulletH002();//�p�[�t�F�N�g�t���[�Y
extern void boss_shot_bulletH003();//���̖��H
extern void boss_shot_bulletH004();//�P�������J���ɂ�������
extern void boss_shot_bulletH005();//���e��
extern void boss_shot_bulletH006();//���肩�璆����
extern void boss_shot_bulletH007();//���肩�璼��
extern void boss_shot_bulletH008();//������
extern void boss_shot_bulletH015();//�~�`���˂ƃT�C�����g�Z���i
extern void boss_shot_bulletH016();//�����ɍ��킹�ĂQ�����Ă���
extern void boss_shot_bulletH017();//�p�[�t�F�N�g�t���[�Y�Ǝ��肩�璼��
extern void boss_shot_bulletH018();//�������Ɖ~�`����
extern void boss_shot_bulletH019();//�����ɍ��킹�ĂQ�����Ă��� �~�`����


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ��Փx�m�[�}���̃{�X�e��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void (*boss_shot_bullet_normal[DANMAKU_MAX])() = {

//���{�X�i�Q�e���j
    boss_shot_bulletH000,//�~�`����
    boss_shot_bulletH006,//���肩�璆����

//���X�{�X�i�R�e���j
    boss_shot_bulletH007,//���肩�璼��
    boss_shot_bulletH002,//�p�[�t�F�N�g�t���[�Y
    boss_shot_bulletH001,//�T�C�����g�Z���i

//�I��
    boss_shot_bulletH000,//�ʂ�ۉ��p(���̒e���͏o�Ă��Ȃ�)
};


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ��Փx�n�[�h�̃{�X�e��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void (*boss_shot_bullet_hard[DANMAKU_MAX])() = {

//���{�X�i�Q�e���j
    boss_shot_bulletH005,//���^�e��
    boss_shot_bulletH001,//�T�C�����g�Z���i

//���X�{�X�i�R�e���j
    boss_shot_bulletH016,//�����ɍ��킹�ĂQ�����Ă���
    boss_shot_bulletH004,//�P�������J���ɂ�������
    boss_shot_bulletH015,//�~�`���˂ƃT�C�����g�Z���i

//�I��
    boss_shot_bulletH000,//�ʂ�ۉ��p(���̒e���͏o�Ă��Ȃ�)
};


//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
// ��Փx���i�e�B�b�N�̃{�X�e��
//�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|/
void (*boss_shot_bullet_lunatic[DANMAKU_MAX])() = {

//���{�X�i�Q�e���j
    boss_shot_bulletH015,//�~�`���˂ƃT�C�����g�Z���i
    boss_shot_bulletH017,//�p�[�t�F�N�g�t���[�Y�Ǝ��肩�璼��

//���X�{�X�i�R�e���j
    boss_shot_bulletH003,//���̖��H
    boss_shot_bulletH019,//�����ɍ��킹�ĂQ�����Ă��� �~�`����
    boss_shot_bulletH018,//�������Ɖ~�`����

//�I��
    boss_shot_bulletH000,//�ʂ�ۉ��p(���̒e���͏o�Ă��Ȃ�)
};
