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
	Equipment->Init();
	Equipment->m_pPlayer = player;
	return equipment;
}