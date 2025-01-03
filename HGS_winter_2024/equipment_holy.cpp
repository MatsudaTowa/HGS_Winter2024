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
//初期化
//=============================================
void CEquipment_Holy::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_HOLY);

	//変数宣言
	CPlayer* pPlayer = GetPlayer();

}

//=============================================
//更新
//=============================================
void CEquipment_Holy::Update()
{
	m_nCount++;

	if (m_nCount <= TIME_SHOT)
	{
		return;
	}

	m_nCount = 0;

	//変数宣言
	CPlayer* pPlayer = GetPlayer();
	CLeasepower::Create(pPlayer->GetPos());
}