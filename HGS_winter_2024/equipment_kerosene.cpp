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
//������
//=============================================
void CEquipment_Kerosene::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_KEROSENE);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Kerosene::Update()
{
	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();
}