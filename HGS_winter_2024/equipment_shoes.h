//=============================================
//
//3DTemplate[equipment_shoes.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_SHOES_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_SHOES_H_
#include "equipment.h"

//�����N���X
class CEquipment_Shoes : public CEquipment
{
public:
	CEquipment_Shoes() {}				//�R���X�g���N�^
	~CEquipment_Shoes() override {}		//�f�X�g���N�^

	void Init() override; //������
	void Update() override;	//�X�V
};
#endif