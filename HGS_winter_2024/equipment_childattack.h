//=============================================
//
//3DTemplate[equipment_childattack.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_CHILDATTACK_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_CHILDATTACK_H_
#include "equipment.h"

//�����N���X
class CEquipment_ChildAttack : public CEquipment
{
public:

	//�萔
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_ChildAttack() : m_Count(0) {}		//�R���X�g���N�^
	~CEquipment_ChildAttack() override {}			//�f�X�g���N�^

	void Init() override;	//������
	void Update() override;	//�X�V

private:
	int m_Count;
};
#endif