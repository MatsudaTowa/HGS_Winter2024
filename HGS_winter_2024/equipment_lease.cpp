//=============================================
//
//3DTemplate[equipment_lease.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_lease.h"
#include "object.h"
#include "player.h"

//=============================================
//������
//=============================================
void CEquipment_Lease::Init()
{

}

//=============================================
//�X�V
//=============================================
void CEquipment_Lease::Update()
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