//=============================================
//
//�⏕�����N���X�p�w�b�_�[[support_equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _SUPPORT_EQUIPMENT_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _SUPPORT_EQUIPMENT_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "equipment.h"

//�⏕�����N���X
class CSupport_Equipment : public CEquipment
{
public:

	//�֐�
	CSupport_Equipment() : m_bActivate(false) {}	//�R���X�g���N�^
	~CSupport_Equipment() override {} 				//�f�X�g���N�^
	void Effect() override;							//�����̌��ʏ���(�v���C���[��������)

private:

	//�֐�
	void Support() {}		//�⏕�̏���

	//�ϐ�
	bool m_bActivate;		//����������
};


#endif