//=============================================
//
//3DTemplate[equipment_holy.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_HOLY_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_HOLY_H_
#include "equipment.h"

//�����N���X
class CEquipment_Holy : public CEquipment
{
public:
	CEquipment_Holy() {}				//�R���X�g���N�^
	~CEquipment_Holy() override {}		//�f�X�g���N�^

	void Init() override;	//������
	void Update() override;	//�X�V
};
#endif