//=============================================
//
//3DTemplate[equipment_childcircle.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_CHILDCIRCLE_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_CHILDCIRCLE_H_
#include "equipment.h"

//�����N���X
class CEquipment_ChildCircle : public CEquipment
{
public:
	CEquipment_ChildCircle() {}				//�R���X�g���N�^
	~CEquipment_ChildCircle() override {}		//�f�X�g���N�^

	void Init() override;	//������
	void Update() override;	//�X�V
};
#endif