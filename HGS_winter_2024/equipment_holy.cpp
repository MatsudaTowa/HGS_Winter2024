//=============================================
//
//3DTemplate[equipment_holy.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_holy.h"
#include "object.h"
#include "player.h"
#include "leasepower.h"

//=============================================
//������
//=============================================
void CEquipment_Holy::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_HOLY);

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();

}

//=============================================
//�X�V
//=============================================
void CEquipment_Holy::Update()
{
	m_nCount++;

	if (m_nCount <= TIME_SHOT)
	{
		return;
	}

	m_nCount = 0;

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();
	CLeasepower::Create(pPlayer->GetPos());
}