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
//������
//=============================================
void CEquipment_ChildCircle::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_CHILED_CIRCLE);
}

//=============================================
//�X�V
//=============================================
void CEquipment_ChildCircle::Update()
{
	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();
}