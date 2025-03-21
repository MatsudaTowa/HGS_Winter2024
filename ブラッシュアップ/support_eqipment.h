//=============================================
//
//補助装備クラス用ヘッダー[support_equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _SUPPORT_EQUIPMENT_H_	//これが定義されてないとき
#define _SUPPORT_EQUIPMENT_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "equipment.h"

//補助装備クラス
class CSupport_Equipment : public CEquipment
{
public:

	//関数
	CSupport_Equipment() : m_bActivate(false) {}	//コンストラクタ
	~CSupport_Equipment() override {} 				//デストラクタ
	void Effect() override;							//装備の効果処理(プレイヤーを引数に)

private:

	//関数
	void Support() {}		//補助の処理

	//変数
	bool m_bActivate;		//発動したか
};


#endif