//=============================================
//
//3DTemplate[equipment.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment.h"

//=============================================
//¶¬
//=============================================
CEquipment* CEquipment::Create(CEquipment* equipment, CPlayer* player)
{
	CEquipment* Equipment = equipment;
	Equipment->m_pPlayer = player;

	Equipment->Init();
	return equipment;
}