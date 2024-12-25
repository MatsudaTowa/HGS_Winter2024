//=============================================
//
//3DTemplate[equipment_childattack.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_childattack.h"
#include "object.h"
#include "player.h"

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

	//鉄砲の弾を生成予定(向きはプレイヤー、スピードも)
	pPlayer->GetRot();
}