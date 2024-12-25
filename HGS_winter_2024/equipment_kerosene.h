//=============================================
//
//3DTemplate[equipment_kerosene.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_KEROSENE_H_ //これが定義されてないとき
#define _EQUIPMENT_KEROSENE_H_
#include "equipment.h"

//装備クラス
class CEquipment_Kerosene : public CEquipment
{
public:
	CEquipment_Kerosene() {}				//コンストラクタ
	~CEquipment_Kerosene() override {}		//デストラクタ

	void Init() override {}	//初期化
	void Update() override;	//更新
};
#endif