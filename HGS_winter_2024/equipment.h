//=============================================
//
//3DTemplate[equipment.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_H_
#include "main.h"

//�����N���X
class CEquipment
{
public:
	CEquipment() {}			//�R���X�g���N�^
	virtual ~CEquipment() {}	//�f�X�g���N�^

	virtual void Init() {}	//������
	virtual void Update() {}//�X�V

	static CEquipment* Create(CEquipment* equipment);	//����
	
};
#endif