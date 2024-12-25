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
//‰Šú‰»
//=============================================
void CEquipment_Shoes::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_SHOES);

	//•Ï”éŒ¾
	CPlayer* pPlayer = GetPlayer();

	float speed = pPlayer->GetSpeed();

	speed += 0.25f;

	pPlayer->SetSpeed(speed);
}

//=============================================
//XV
//=============================================
void CEquipment_Shoes::Update()
{
}