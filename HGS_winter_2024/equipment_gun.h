//=============================================
//
//3DTemplate[equipment_gun.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_GUN_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_GUN_H_
#include "equipment.h"

//�����N���X
class CEquipment_Gun : public CEquipment
{
public:

	//�萔
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Gun() : m_Count(0){}		//�R���X�g���N�^
	~CEquipment_Gun() override {}		//�f�X�g���N�^

	void Init() override {}	//������
	void Update() override;	//�X�V

private:
	int m_Count;
};
#endif