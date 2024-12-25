//=============================================
//
//プレイヤー[player_test.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _PLAYER_TEST_H_ //これが定義されてないとき

#define _PLAYER_TEST_H_
#include "main.h"
#include "model_parts.h"
#include "character.h"

class CPlayerState;
class UI_PlayerLife;

//プレイヤークラス
class CPlayer :public CCharacter
{
public:
	static const int MAX_KEY = 20; //キー最大数
	static const int PLAYER_LIFE = 150; //体力
	static const int PLAYER_PRIORITY = 8; //描画順
	static const char* MODEL_FAIL; //モデルのファイルパス


	//モーションの種類の列挙
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	CPlayer(int nPriority = PLAYER_PRIORITY);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	//プレイヤー作成
	static CPlayer* Create();

	void ChangePlayerState(CPlayerState* state);

	//クールタイム設定
	void SetAttackCoolTime(float cooltime)
	{
		m_fAttackCoolTime = cooltime;
	}

private:

	//プレイヤーの移動関連
	static const float DAMPING_COEFFICIENT; //移動抵抗
	static const int MAX_JUMPCNT; //ジャンプ回数
	static const int IGNORE_COLLISION_FRAME; //当たり判定無視フレーム
	static const int SMOKE_RECAST_FRAME; //スモーク復活フレーム
	static const float DEADZONE_Y; //これを過ぎたらプレイヤー破棄
	static const float DEFAULT_COOLTIME; //デフォルトのクールタイム

	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //スポーン位置
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //スポーン方向

	void ReSpawn(); //リスポーン

	void DebugPos();

	void Input(); //入力処理

	CPlayerState* m_pPlayerState;

	float m_fAttackCoolTime;	//クールタイム
<<<<<<< HEAD


	UI_PlayerLife* m_LifeUI;
=======
	float m_fAttackCoolCnt;	//クールタイム
>>>>>>> aca345994a80ef3cda6c7e1ef51159d7e4a59e4d
};
#endif