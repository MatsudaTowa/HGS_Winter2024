//=============================================
//
//3DTemplate[equipment_magnum.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_MAGNUM_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_MAGNUM_H_
#include "equipment.h"

//�����N���X
class CEquipment_Magnum : public CEquipment
{
public:

	//�萔
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Magnum() : m_Count(0) {}		//�R���X�g���N�^
	~CEquipment_Magnum() override {}		//�f�X�g���N�^

	void Init() override {}	//������
	void Update() override;	//�X�V

private:
	int m_Count;
};
#endif