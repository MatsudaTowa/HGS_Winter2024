//=============================================
//
//装備クラス用ヘッダー[equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _EQUIPMENT_H_	//これが定義されてないとき
#define _EQUIPMENT_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "main.h"

//装備クラス
class CEquipment
{
public:

	//関数
	CEquipment() {}				//コンストラクタ
	virtual ~CEquipment() {} 	//デストラクタ
	virtual void Effect() = 0;	//装備の効果処理(プレイヤーを引数に)

private:

	//変数
	int m_nLevel;	//装備のレベル
};


#endif