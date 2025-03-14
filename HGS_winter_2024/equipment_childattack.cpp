//=============================================
//
//3DTemplate[equipment_childattack.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_childattack.h"
#include "object.h"
#include "player.h"
#include "child.h"

//=============================================
//初期化
//=============================================
void CEquipment_ChildAttack::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_CHILED_ATTACK);
}

//=============================================
//更新
//=============================================
void CEquipment_ChildAttack::Update()
{
	m_Count++;

	if (m_Count <= TIME_SHOT)
	{
		return;
	}

	m_Count = 0;

	//変数宣言
	CPlayer* pPlayer = GetPlayer();
	CChild::Create({ pPlayer->GetPos().x, 30.0f, pPlayer->GetPos().z });
}