//=============================================
//
//3DTemplate[equipment_magnum.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_MAGNUM_H_ //これが定義されてないとき
#define _EQUIPMENT_MAGNUM_H_
#include "equipment.h"

//装備クラス
class CEquipment_Magnum : public CEquipment
{
public:

	//定数
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Magnum() : m_Count(0) {}		//コンストラクタ
	~CEquipment_Magnum() override {}		//デストラクタ

	void Init() override {}	//初期化
	void Update() override;	//更新

private:
	int m_Count;
};
#endif