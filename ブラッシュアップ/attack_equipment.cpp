//=============================================
//
//�U�������̏���[attack_equipment.cpp]
//Auther Yuuto Shimadu
//
//=============================================

//�w�b�_�[�̃C���N���[�h
#include "attack_eqipment.h"

//=====================================================
//�R���X�g���N�^
//=====================================================
CAttack_Equipment::CAttack_Equipment() :
	m_fCoolTime(0.0f),		//�N�[���^�C��
	m_fCoolTimeCount(0.0f),	//�N�[���^�C���̃J�E���g
	m_bCanAttack(false)		//�U���\��
{

}

//=====================================================
//�N�[���^�C���̍X�V
//=====================================================
void CAttack_Equipment::UpdateCoolTime()
{
	m_fCoolTimeCount++;	//�J�E���g�A�b�v

	//�N�[���^�C�����I������
	if (m_fCoolTimeCount <= m_fCoolTime) return;

	//�U������
	m_bCanAttack = true;		//�t���O�𗧂Ă�
	m_fCoolTimeCount = 0.0f;	//�J�E���g��������

	//�U������
	Attack();
}