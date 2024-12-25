//=============================================
//
//3DTemplate[equipment_gun.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gun.h"
#include "object.h"
#include "player.h"

//=============================================
//初期化
//=============================================
void CEquipment_Gun::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_GUN);
}

//=============================================
//更新
//=============================================
void CEquipment_Gun::Update()
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