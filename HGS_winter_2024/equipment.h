//=============================================
//
//3DTemplate[equipment.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_H_ //これが定義されてないとき
#define _EQUIPMENT_H_
#include "main.h"
#include "player.h"

//装備クラス
class CEquipment
{
public:
	CEquipment() : m_pPlayer(nullptr) {}		//コンストラクタ
	virtual ~CEquipment() {}					//デストラクタ

	virtual void Init() {}	//初期化
	virtual void Update() {}//更新

	static CEquipment* Create(CEquipment* equipment, CPlayer* player);	//生成

	//プレイヤー
	CPlayer* GetPlayer() { return m_pPlayer; }

private:
	CPlayer* m_pPlayer;
	
};
#endif