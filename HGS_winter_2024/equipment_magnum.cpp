//=============================================
//
//3DTemplate[equipment_magnum.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_magnum.h"
#include "object.h"
#include "player.h"

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
	//変数宣言
	CPlayer* pPlayer = GetPlayer();

	//鉄砲の弾を生成予定(向きはプレイヤー、スピードも)
	pPlayer->GetRot();
}