//=============================================
//
//3DTemplate[equipment_kerosene.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_KEROSENE_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_KEROSENE_H_
#include "equipment.h"

//�����N���X
class CEquipment_Kerosene : public CEquipment
{
public:
	CEquipment_Kerosene() {}				//�R���X�g���N�^
	~CEquipment_Kerosene() override {}		//�f�X�g���N�^

	void Init() override {}	//������
	void Update() override;	//�X�V
};
#endif