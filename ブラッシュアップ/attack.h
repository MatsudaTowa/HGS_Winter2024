//=============================================
//
//攻撃クラス用ヘッダー[attack.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ATTACK_H_	//これが定義されてないとき
#define _ATTACK_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "main.h"

//攻撃クラス
class CAttack
{
public:

	//関数
	CAttack() : m_nDamage(0) {}							//コンストラクタ
	virtual ~CAttack() {}								//デストラクタ
	virtual void Attack();								//攻撃処理
	virtual void Attack(D3DXVECTOR3 pos, float range);	//位置指定の攻撃処理

	void SetDamage(int damage) { m_nDamage = damage; }	//ダメージの設定

private:

	//変数
	int m_nDamage;	//ダメージ量
};


#endif