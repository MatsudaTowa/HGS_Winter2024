//=============================================
//
//3DTemplate[equipment_childattack.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_childattack.h"
#include "object.h"
#include "player.h"
#include "child.h"

//=============================================
//������
//=============================================
void CEquipment_ChildAttack::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_CHILED_ATTACK);
}

//=============================================
//�X�V
//=============================================
void CEquipment_ChildAttack::Update()
{
	m_Count++;

	if (m_Count <= TIME_SHOT)
	{
		return;
	}

	m_Count = 0;

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();
	CChild::Create({ pPlayer->GetPos().x, 30.0f, pPlayer->GetPos().z });
}