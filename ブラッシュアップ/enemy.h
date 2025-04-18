//=============================================
//
//エネミー用ヘッダー[enemy.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ENEMY_H_	//これが定義されてないとき
#define _ENEMY_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "model_parts.h"
#include "character.h"

//エネミークラス
class CEnemy :public CCharacter
{
public:

	//定数
	static constexpr int MAX_KEY{20};	//キー最大数
	static constexpr int LIFE{150};		//体力
	static constexpr int PRIORITY{8};	//描画順
	static const std::string MODEL_FILE;//モデルのファイルパス

	//モーションの種類の列挙
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	//関数
	CEnemy(int nPriority = PRIORITY);	//コンストラクタ
	~CEnemy();							//デストラクタ
	HRESULT Init();						//初期化
	void Uninit();						//終了処理
	void Update();						//更新処理
	void Draw();						//描画処理

	//エネミーの作成
	static CEnemy* Create();
};
#endif