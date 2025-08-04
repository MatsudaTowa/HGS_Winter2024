//=============================================
//
//敵行動クラス用ヘッダー[behavior_enemy.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _BEHAVIOR_ENEMY_H_	//これが定義されてないとき
#define _BEHAVIOR_ENEMY_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "main.h"
#include "enemy.h"

//前方宣言
class CEnemy;

//装備クラス
class CBehavior_Enemy
{
public:

	//関数
	CBehavior_Enemy(CEnemy* /*enemy*/) {}	//コンストラクタ
	virtual ~CBehavior_Enemy() {} 	//デストラクタ
	virtual void Behavior(CEnemy* /*enemy*/) = 0;	//行動

private:

};


#endif