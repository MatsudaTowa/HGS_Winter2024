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

class CPlayer;
//装備クラス
class CEquipment
{
public:
	enum EQUIPMENT_TYPE
	{
		EQUIPMENT_TYPE_CHILED_ATTACK = 0,
		EQUIPMENT_TYPE_CHILED_CIRCLE,
		EQUIPMENT_TYPE_GLOVES,
		EQUIPMENT_TYPE_GUN,
		EQUIPMENT_TYPE_HOLY,
		EQUIPMENT_TYPE_KEROSENE,
		EQUIPMENT_TYPE_LEASE,
		EQUIPMENT_TYPE_MAGNUM,
		EQUIPMENT_TYPE_SHOES,
		EQUIPMENT_TYPE_CHILED_,
	};
	CEquipment() : m_pPlayer(nullptr) {}		//コンストラクタ
	virtual ~CEquipment() {}					//デストラクタ

	virtual void Init() {}	//初期化
	virtual void Update() {}//更新

	static CEquipment* Create(CEquipment* equipment, CPlayer* player);	//生成

	//プレイヤー
	CPlayer* GetPlayer() { return m_pPlayer; }

	void SetType(EQUIPMENT_TYPE type)
	{
		m_type = type;
	}

	EQUIPMENT_TYPE GetType()
	{
		return m_type;
	}

private:
	CPlayer* m_pPlayer;
	EQUIPMENT_TYPE m_type;
	
};
#endif