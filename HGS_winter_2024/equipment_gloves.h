//=============================================
//
//3DTemplate[equipment_gloves.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_GLOVES_H_ //これが定義されてないとき
#define _EQUIPMENT_GLOVES_H_
#include "equipment.h"

//装備クラス
class CEquipment_Gloves : public CEquipment
{
public:
	CEquipment_Gloves() {}				//コンストラクタ
	~CEquipment_Gloves() override {}		//デストラクタ

	void Init() override;//初期化
	void Update() override;	//更新
};
#endif