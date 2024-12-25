//=============================================
//
//3DTemplate[equipment_childattack.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_CHILDATTACK_H_ //これが定義されてないとき
#define _EQUIPMENT_CHILDATTACK_H_
#include "equipment.h"

//装備クラス
class CEquipment_ChildAttack : public CEquipment
{
public:

	//定数
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_ChildAttack() : m_Count(0) {}		//コンストラクタ
	~CEquipment_ChildAttack() override {}			//デストラクタ

	void Init() override;	//初期化
	void Update() override;	//更新

private:
	int m_Count;
};
#endif