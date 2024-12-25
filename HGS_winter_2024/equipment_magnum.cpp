//=============================================
//
//3DTemplate[equipment_magnum.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_magnum.h"
#include "object.h"
#include "player.h"
#include "bullet001.h"

//=============================================
//������
//=============================================
void CEquipment_Magnum::Init()
{
	SetType(CEquipment::EQUIPMENT_TYPE_MAGNUM);
}

//=============================================
//�X�V
//=============================================
void CEquipment_Magnum::Update()
{
	m_Count++;

	if (m_Count > TIME_SHOT)
	{
		m_Count = 0;

		//�ϐ��錾
		CPlayer* pPlayer = GetPlayer();

		//�S�C�̒e�𐶐��\��(�����̓v���C���[�A�X�s�[�h��)
		CBullet001::Create({ pPlayer->GetPos().x, 30.0f, pPlayer->GetPos().z }, pPlayer->GetRot().y + D3DX_PI);
	}
}