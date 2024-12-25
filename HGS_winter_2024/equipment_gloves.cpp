//=============================================
//
//3DTemplate[equipment_gloves.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gloves.h"
#include "object.h"
#include "player.h"

//=============================================
//èâä˙âª
//=============================================
void CEquipment_Gloves::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_GLOVES);

	//ïœêîêÈåæ
	CPlayer* pPlayer = GetPlayer();

	float f = pPlayer->GetAttackCoolTime();

	f -= 30.0f;

	pPlayer->SetAttackCoolTime(f);
}

//=============================================
//çXêV
//=============================================
void CEquipment_Gloves::Update()
{

}