//=============================================
//
//3DTemplate[equipment_gloves.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_GLOVES_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_GLOVES_H_
#include "equipment.h"

//�����N���X
class CEquipment_Gloves : public CEquipment
{
public:
	CEquipment_Gloves() {}				//�R���X�g���N�^
	~CEquipment_Gloves() override {}		//�f�X�g���N�^

	void Init() override;//������
	void Update() override;	//�X�V
};
#endif