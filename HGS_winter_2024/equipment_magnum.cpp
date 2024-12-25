//=============================================
//
//3DTemplate[equipment_magnum.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_magnum.h"
#include "object.h"
#include "player.h"
#include "bullet001.h"

//=============================================
//初期化
//=============================================
void CEquipment_Magnum::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_MAGNUM);
}

//=============================================
//更新
//=============================================
void CEquipment_Magnum::Update()
{
	m_Count++;

	if (m_Count > TIME_SHOT)
	{
		m_Count = 0;

		//変数宣言
		CPlayer* pPlayer = GetPlayer();

		//鉄砲の弾を生成予定(向きはプレイヤー、スピードも)
		CBullet001::Create({ pPlayer->GetPos().x, 30.0f, pPlayer->GetPos().z }, pPlayer->GetRot().y + D3DX_PI);
	}
}