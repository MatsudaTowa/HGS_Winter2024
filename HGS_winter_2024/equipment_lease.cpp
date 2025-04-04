//=============================================
//
//3DTemplate[equipment_lease.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_lease.h"
#include "object.h"
#include "player.h"
#include "kerosene.h"

//=============================================
//初期化
//=============================================
void CEquipment_Lease::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_LEASE);
}

//=============================================
//更新
//=============================================
void CEquipment_Lease::Update()
{
	m_Count++;

	if (m_Count <= TIME_SHOT)
	{
		return;
	}

	m_Count = 0;

	//変数宣言
	CPlayer* pPlayer = GetPlayer();

	//鉄砲の弾を生成予定(向きはプレイヤー、スピードも)
	CKerosene::Create(pPlayer->GetPos());
}