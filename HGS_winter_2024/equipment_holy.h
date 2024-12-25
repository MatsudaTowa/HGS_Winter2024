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
	static constexpr int TIME_SHOT{ 30 };

	CEquipment_Holy() : m_nCount(0) {}				//コンストラクタ
	~CEquipment_Holy() override {}		//デストラクタ

	void Init() override;	//初期化
	void Update() override;	//更新

private:
	int m_nCount;
};
#endif