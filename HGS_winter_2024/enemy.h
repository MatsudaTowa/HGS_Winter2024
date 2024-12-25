//=============================================
//
//敵の処理[enemy.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _ENEMY_H_ //これが定義されてないとき

#define _ENEMY_H_
#include "main.h"
#include "manager.h"
#include "model_parts.h"
#include "character.h"

class CEnemyState;

//エネミークラス
class CEnemy :public CCharacter
{
public:
	static const int MAX_KEY = 20; //キー最大数
	static const int NUM_MOTION = 3;
	static const int ENEMY_PRIORITY = 8; //描画順
	static const int DEFAULT_LIFE = 5; //ライフ

	//エネミーの列挙定義
	enum ENEMY_TYPE
	{
		ENEMY_TYPE_WEAK = 0,
		ENEMY_TYPE_BOSS,
		ENEMY_TYPE_MAX,
	};

	//モーションの種類の列挙
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	CEnemy(int nPriority = ENEMY_PRIORITY);
	~CEnemy() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	//エネミー作成
	static CEnemy* Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const ENEMY_TYPE& type);

	void Damage(int nDamage); //当たり判定

	static int m_NumEnemy; //エネミーの総数
	int m_nCombatChangeCnt; //戦闘状態切り替えカウント

private:

	//プレイヤーの移動関連
	static const float DEFAULT_MOVE; //通常時の移動
	static const float DAMPING_COEFFICIENT; //移動抵抗
	static const float DEFAULT_JUMP; //通常時のジャンプ力
	static const int NUM_MOTION; //モーションの数

	ENEMY_TYPE m_type; //エネミーの種類
	Motion_Type m_Motion; //モーションの種類

};

#endif