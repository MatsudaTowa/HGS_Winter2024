//=============================================
//
//�U�������N���X�p�w�b�_�[[attack_equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ATTACK_EQUIPMENT_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _ATTACK_EQUIPMENT_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "equipment.h"

//�U�������N���X
class CAttack_Equipment : public CEquipment
{
public:

	//�֐�
	CAttack_Equipment();									//�R���X�g���N�^
	~CAttack_Equipment() override {} 						//�f�X�g���N�^
	void Effect() override {}								//�����̌��ʏ���(�v���C���[��������)
	void SetCoolTime(float time) { m_fCoolTime = time; }	//�N�[���^�C���̐ݒ�

private:

	//�֐�
	void Attack() {}		//�U���̏���
	void UpdateCoolTime();	//�N�[���^�C���̍X�V

	//�ϐ�
	float m_fCoolTime;		//�U�������܂ł̃N�[���^�C��
	float m_fCoolTimeCount;	//�N�[���^�C���̃J�E���g
	bool m_bCanAttack;		//�U�����\��
};


#endif