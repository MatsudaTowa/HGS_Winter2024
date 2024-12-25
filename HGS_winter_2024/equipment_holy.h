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
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Holy() : m_nCount(0) {}				//�R���X�g���N�^
	~CEquipment_Holy() override {}		//�f�X�g���N�^

	void Init() override;	//������
	void Update() override;	//�X�V

private:
	int m_nCount;
};
#endif