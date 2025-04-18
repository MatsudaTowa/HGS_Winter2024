//=============================================
//
//3DTemplate[equipment_shoes.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_shoes.h"
#include "object.h"
#include "player.h"

//=============================================
//初期化
//=============================================
void CEquipment_Shoes::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_SHOES);

	//変数宣言
	CPlayer* pPlayer = GetPlayer();

	float speed = pPlayer->GetSpeed();

	speed += 0.25f;

	pPlayer->SetSpeed(speed);
}

//=============================================
//更新
//=============================================
void CEquipment_Shoes::Update()
{
}