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
CEquipment* CEquipment::Create(CEquipment* equipment)
{
	CEquipment* Equipment = equipment;
	equipment->Init();
	return equipment;
}