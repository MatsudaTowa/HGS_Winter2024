//=============================================
//
//攻撃装備クラス用ヘッダー[attack_equipment.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ATTACK_EQUIPMENT_H_	//これが定義されてないとき
#define _ATTACK_EQUIPMENT_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "equipment.h"

//攻撃装備クラス
class CAttack_Equipment : public CEquipment
{
public:

	//関数
	CAttack_Equipment();									//コンストラクタ
	~CAttack_Equipment() override {} 						//デストラクタ
	void Effect() override {}								//装備の効果処理(プレイヤーを引数に)
	void SetCoolTime(float time) { m_fCoolTime = time; }	//クールタイムの設定

private:

	//関数
	void Attack() {}		//攻撃の処理
	void UpdateCoolTime();	//クールタイムの更新

	//変数
	float m_fCoolTime;		//攻撃発生までのクールタイム
	float m_fCoolTimeCount;	//クールタイムのカウント
	bool m_bCanAttack;		//攻撃が可能か
};


#endif