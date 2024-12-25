//=============================================
//
//3DTemplate[equipment_shoes.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_SHOES_H_ //これが定義されてないとき
#define _EQUIPMENT_SHOES_H_
#include "equipment.h"

//装備クラス
class CEquipment_Shoes : public CEquipment
{
public:
	CEquipment_Shoes() {}				//コンストラクタ
	~CEquipment_Shoes() override {}		//デストラクタ

	void Init() override; //初期化
	void Update() override;	//更新
};
#endif