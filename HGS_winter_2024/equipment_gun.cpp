//=============================================
//
//3DTemplate[equipment_gun.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gun.h"
#include "object.h"
#include "player.h"

//=============================================
//������
//=============================================
void CEquipment_Gun::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_GUN);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Gun::Update()
{
	m_Count++;

	if (m_Count <= TIME_SHOT)
	{
		return;
	}

	m_Count = 0;

	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();

	//�S�C�̒e�𐶐��\��(�����̓v���C���[�A�X�s�[�h��)
	pPlayer->GetRot();
}