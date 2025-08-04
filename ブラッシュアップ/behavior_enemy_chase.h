//=============================================
//
//敵行動クラス用ヘッダー[behavior_enemy_chasse.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _BEHAVIOR_ENEMY_CHASE_H_	//これが定義されてないとき
#define _BEHAVIOR_ENEMY_CHASE_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "behavior_enemy.h"

//装備クラス
class CBehavior_Enemy_Chase : public CBehavior_Enemy
{
public:

	//定数
	static constexpr float VALUE_MOVE{ 3.0f };				//移動量

	//関数
	CBehavior_Enemy_Chase(CEnemy* enemy);			//コンストラクタ
	~CBehavior_Enemy_Chase() override;				//デストラクタ
	void Behavior(CEnemy* /*enemy*/) override;		//行動

private:

};


#endif