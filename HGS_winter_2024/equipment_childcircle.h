//=============================================
//
//3DTemplate[equipment_childcircle.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_CHILDCIRCLE_H_ //これが定義されてないとき
#define _EQUIPMENT_CHILDCIRCLE_H_
#include "equipment.h"

//装備クラス
class CEquipment_ChildCircle : public CEquipment
{
public:
	CEquipment_ChildCircle() {}				//コンストラクタ
	~CEquipment_ChildCircle() override {}		//デストラクタ

	void Init() override;	//初期化
	void Update() override;	//更新
};
#endif