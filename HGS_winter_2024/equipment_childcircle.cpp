//=============================================
//
//3DTemplate[equipment_childcircle.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_childcircle.h"
#include "object.h"
#include "player.h"

//=============================================
//初期化
//=============================================
void CEquipment_ChildCircle::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_CHILED_CIRCLE);
}

//=============================================
//更新
//=============================================
void CEquipment_ChildCircle::Update()
{
	//変数宣言
	CPlayer* pPlayer = GetPlayer();
}