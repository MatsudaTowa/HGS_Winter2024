////=============================================
////
////プレイヤー[player_test.h]
////Auther Matsuda Towa
////
////=============================================
//#ifndef _PLAYER_TEST_H_ //これが定義されてないとき
//
//#define _PLAYER_TEST_H_
//#include "main.h"
//#include "model_parts.h"
//#include "character.h"
//
////class CPlayerState;
//
////プレイヤークラス
//class CPlayer :public CCharacter
//{
//public:
//	static const int MAX_KEY = 20; //キー最大数
//	static const int PLAYER_LIFE = 150; //体力
//	static const int PLAYER_PRIORITY = 8; //描画順
//	static const char* MODEL_FAIL; //モデルのファイルパス
//	static constexpr float LEVEL_WINDOW = 50.0f;
//
//
//	//モーションの種類の列挙
//	enum Motion_Type
//	{
//		MOTION_NEUTRAL = 0,
//		MOTION_MOVE,
//		MOTION_ATTACK,
//		MOTION_MAX,
//	};
//
//	CPlayer(int nPriority = PLAYER_PRIORITY);
//	~CPlayer();
//	HRESULT Init();
//	void Uninit();
//	void Update();
//	void Draw();
//
//	//プレイヤー作成
//	static CPlayer* Create();
//
//	//void ChangePlayerState(CPlayerState* state);
//
//private:
//
//	//プレイヤーの移動関連
//	static const float DAMPING_COEFFICIENT; //移動抵抗
//	static const int MAX_JUMPCNT; //ジャンプ回数
//	static const int NUM_SLOT = 6;
//	static const int IGNORE_COLLISION_FRAME; //当たり判定無視フレーム
//	static const int SMOKE_RECAST_FRAME; //スモーク復活フレーム
//	static const float DEADZONE_Y; //これを過ぎたらプレイヤー破棄
//	static const float DEFAULT_COOLTIME; //デフォルトのクールタイム
//	static constexpr float LEVEL_EXP = 1.05f;
//
//	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //スポーン位置
//	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //スポーン方向
//
//	void ReSpawn(); //リスポーン
//
//	void DebugPos();
//
//	void Input(); //入力処理
//};
//#endif