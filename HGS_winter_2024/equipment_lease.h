//=============================================
//
//3DTemplate[equipment_lease.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_LEASE_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_LEASE_H_
#include "equipment.h"

//�����N���X
class CEquipment_Lease : public CEquipment
{
public:

	//�萔
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Lease() : m_Count(0){}	//�R���X�g���N�^
	~CEquipment_Lease() override {}		//�f�X�g���N�^

	void Init() override;	//������
	void Update() override;	//�X�V

private:
	int m_Count;
};
#endif