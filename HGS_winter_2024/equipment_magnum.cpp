//=============================================
//
//3DTemplate[equipment_magnum.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_magnum.h"
#include "object.h"
#include "player.h"

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
	//�ϐ��錾
	CPlayer* pPlayer = GetPlayer();

	//�S�C�̒e�𐶐��\��(�����̓v���C���[�A�X�s�[�h��)
	pPlayer->GetRot();
}