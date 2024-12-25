//=============================================
//
//3DTemplate[equipment.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_H_ //これが定義されてないとき
#define _EQUIPMENT_H_
#include "main.h"

//装備クラス
class CEquipment
{
public:
	CEquipment() {}			//コンストラクタ
	virtual ~CEquipment() {}	//デストラクタ

	virtual void Init() {}	//初期化
	virtual void Update() {}//更新

	static CEquipment* Create(CEquipment* equipment);	//生成
	
};
#endif