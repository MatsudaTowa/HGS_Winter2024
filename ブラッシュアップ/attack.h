//=============================================
//
//�U���N���X�p�w�b�_�[[attack.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ATTACK_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _ATTACK_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "main.h"

//�U���N���X
class CAttack
{
public:

	//�֐�
	CAttack() : m_nDamage(0) {}							//�R���X�g���N�^
	virtual ~CAttack() {}								//�f�X�g���N�^
	virtual void Attack();								//�U������
	virtual void Attack(D3DXVECTOR3 pos, float range);	//�ʒu�w��̍U������

	void SetDamage(int damage) { m_nDamage = damage; }	//�_���[�W�̐ݒ�

private:

	//�ϐ�
	int m_nDamage;	//�_���[�W��
};


#endif