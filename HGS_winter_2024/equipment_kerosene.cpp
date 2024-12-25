//=============================================
//
//3DTemplate[equipment_kerosene.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_kerosene.h"
#include "object.h"
#include "player.h"
#include "kerosene.h"

//=============================================
//������
//=============================================
void CEquipment_Kerosene::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_KEROSENE);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Kerosene::Update()
{
	m_nCount++;

	if (m_nCount <= TIME_SHOT)
	{
		return;
	}

	m_nCount = 0;

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();
	CKerosene::Create(pPlayer->GetPos());
}