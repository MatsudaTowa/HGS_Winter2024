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
//������
//=============================================
void CEquipment_Shoes::Init()
{
	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();

	float speed = pPlayer->GetSpeed();

	speed += 0.5f;

	pPlayer->SetSpeed(speed);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Shoes::Update()
{
}