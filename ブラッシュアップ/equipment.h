//=============================================
//
//�����N���X�p�w�b�_�[[equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _EQUIPMENT_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "main.h"

//�����N���X
class CEquipment
{
public:

	//�֐�
	CEquipment() {}				//�R���X�g���N�^
	virtual ~CEquipment() {} 	//�f�X�g���N�^
	virtual void Effect() = 0;	//�����̌��ʏ���(�v���C���[��������)

private:

	//�ϐ�
	int m_nLevel;	//�����̃��x��
};


#endif