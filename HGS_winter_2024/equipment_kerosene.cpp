//=============================================
//
//3DTemplate[equipment_kerosene.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_kerosene.h"
#include "object.h"
#include "player.h"

//=============================================
//初期化
//=============================================
void CEquipment_Kerosene::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_KEROSENE);
}

//=============================================
//更新
//=============================================
void CEquipment_Kerosene::Update()
{
	//変数宣言
	CPlayer* pPlayer = GetPlayer();
}