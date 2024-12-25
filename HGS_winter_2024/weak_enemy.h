//=============================================
//
//敵の処理[weak_enemy.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WEAK_ENEMY_H_ //これが定義されてないとき

#define _WEAK_ENEMY_H_
#include "main.h"
#include "manager.h"
#include "model_parts.h"
#include "enemy.h"

//エネミークラス
class CWeakEnemy :public CEnemy
{
public:
	static const int MAX_KEY = 20; //キー最大数
	static const int ENEMY_PRIORITY = 8; //描画順
	static const int DEFAULT_LIFE = 5; //ライフ

	//モーションの種類の列挙
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_MAX,
	};

	CWeakEnemy(int nPriority = ENEMY_PRIORITY);
	~CWeakEnemy() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

	static constexpr float THRESHOLD = 10.0f; //移動の閾値

	void Move();
	void MovetoPlayer(float distance, D3DXVECTOR3& Vector);

	Motion_Type m_Motion; //モーションの種類
};

#endif