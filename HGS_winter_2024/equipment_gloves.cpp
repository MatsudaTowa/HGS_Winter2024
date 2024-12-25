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
//������
//=============================================
void CEquipment_Gloves::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_GLOVES);

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();

	float f = pPlayer->GetAttackCoolTime();

	f -= 30.0f;

	pPlayer->SetAttackCoolTime(f);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Gloves::Update()
{

}