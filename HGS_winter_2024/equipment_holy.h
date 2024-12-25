//=============================================
//
//3DTemplate[equipment_holy.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_HOLY_H_ //これが定義されてないとき
#define _EQUIPMENT_HOLY_H_
#include "equipment.h"

//装備クラス
class CEquipment_Holy : public CEquipment
{
public:
	CEquipment_Holy() {}				//コンストラクタ
	~CEquipment_Holy() override {}		//デストラクタ

	void Init() override;	//初期化
	void Update() override;	//更新
};
#endif