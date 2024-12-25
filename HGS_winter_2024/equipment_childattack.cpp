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
//èâä˙âª
//=============================================
void CEquipment_ChildAttack::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_CHILED_ATTACK);
}

//=============================================
//çXêV
//=============================================
void CEquipment_ChildAttack::Update()
{
	m_Count++;

	if (m_Count <= TIME_SHOT)
	{
		return;
	}

	m_Count = 0;

	//ïœêîêÈåæ
	CPlayer* pPlayer = GetPlayer();
	CChild::Create({ pPlayer->GetPos().x, 30.0f, pPlayer->GetPos().z });
}