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
//初期化
//=============================================
void CEquipment_Gloves::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_GLOVES);

	//変数宣言
	CPlayer* pPlayer = GetPlayer();

	float f = pPlayer->GetAttackCoolTime();

	f -= 30.0f;

	pPlayer->SetAttackCoolTime(f);
}

//=============================================
//更新
//=============================================
void CEquipment_Gloves::Update()
{

}