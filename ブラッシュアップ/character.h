//=============================================
//
//3DTemplate[character.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CHARACTER_H_ //これが定義されてないとき

#define _CHARACTER_H_
#include "main.h"
#include "objectX.h"
#include "model_parts.h"
#include "shadow.h"
#include "manager.h"

//プレイヤークラス
class CCharacter : public CObjectX
{
public:
	static const int MAX_KEY = 20; //キー最大数
	static const int CHARACTER_PRIORITY = 8;
	static const int MAX_MOTION = 100;
	static const int MAX_PARTS = 64; //最大パーツ数

	struct RayHitInfo
	{
		float distance;
		BOOL hit;
	};

	struct ColisionBlockInfo
	{
		bool bColision_X; //X軸に当たっている
		bool bColision_Y; //Y軸に当たっている
		bool bColision_Z; //Z軸に当たっている
		float radius;
	};

	enum CHARACTER_STATE
	{
		CHARACTER_NORMAL = 0, //通常状態
		CHARACTER_DAMAGE, //ダメージ状態
		CHARACTER_STATE_MAX,
	};

	CCharacter(int nPriority = CHARACTER_PRIORITY);
	~CCharacter()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	void MotionDraw();

	void Load_Parts(const char* FileName);
	void Motion(); //モーション処理
	void SetMotion(int Motion); //引数で指定したモーションに切り替える
	void Gravity(); //重力処理
	void Jump(); //ジャンプ処理

	void ConversionMtxWorld();

	//移動量代入
	inline void SetMove(D3DXVECTOR3 move)
	{
		m_move = move;
	}

	//oldpos代入
	inline void SetOldPos(D3DXVECTOR3 oldpos)
	{
		m_oldpos = oldpos;
	}

	//着地してるかどうかを代入
	inline void SetLanding(bool bLanding)
	{
		m_bLanding = bLanding;
	}

	//体力代入
	inline void SetLife(int nLife)
	{
		m_nLife = nLife;
	}

	//状態代入
	inline void SetState(CHARACTER_STATE state)
	{
		m_State = state;
	}

	//ステートカウント代入
	inline void SetStateCnt(int nStateCnt)
	{
		m_nStateCnt = nStateCnt;
	}

	//ジャンプ数代入
	inline void SetJumpCnt(int nJumpCnt)
	{
		m_nJumpCnt = nJumpCnt;
	}

	//終わった判定に
	inline void SetFinish(bool bFinish)
	{
		m_bLoopFinish = bFinish;
	}

	//影のサイズ設定
	inline void SetShadowSize(D3DXVECTOR3 shadow_size)
	{
		m_ShadowSize = shadow_size;
	}
	//移動量取得
	inline D3DXVECTOR3& GetMove()
	{
		return m_move;
	}

	//過去の位置取得
	inline D3DXVECTOR3& GetOldPos()
	{
		return m_oldpos;
	}

	//影のサイズ取得
	inline D3DXVECTOR3& GetShadowSize()
	{
		return m_ShadowSize;
	}

	//着地してるかどうか取得
	inline bool& GetLaunding()
	{
		return m_bLanding;
	}

	//終わってるか取得
	inline bool& GetFinish()
	{
		return m_bLoopFinish;
	}

	//体力取得
	inline int& GetLife()
	{
		return m_nLife;
	}

	//パーツ数取得
	inline int& GetNumParts()
	{
		return m_PartsCnt;
	}

	inline float& GetSpeed()
	{
		return m_Speed;
	}

	//状態取得
	inline CHARACTER_STATE& GetState()
	{
		return m_State;
	}

	//ステートカウント取得
	inline int& GetStateCnt()
	{
		return m_nStateCnt;
	}

	//ジャンプ回数取得
	inline int& GetJumpCnt()
	{
		return m_nJumpCnt;
	}

	//パーツ
	CModel_Parts* m_apModel[MAX_PARTS];

private:

	static constexpr float GRAVITY_MOVE = 2.0f; //重力値
	static constexpr float GRAVITY_MAX = 100.0f; //重力最大値
	static constexpr float SHADOW_POS_Y = 0.5f; //影のY座標(地面から少し浮かす)
	static constexpr float MOVE_FRICTION = 0.3f; //移動抵抗

	D3DXVECTOR3 m_move; //速度
	D3DXVECTOR3 m_oldpos; //過去の位置
	bool m_bLanding; //着地してるかどうか
	bool m_bLoopFinish; //ループモーションが終わったか
	int m_nLife; //体力
	int m_nStateCnt; //ステート切り替え計測カウント
	int m_PartsCnt; //パーツ数
	int m_nMotionFrameCnt; //切り替えフレームカウント
	int m_nKeySetCnt; //キー切り替えカウント
	int m_nJumpCnt; //ジャンプカウント
	int m_Motion; //モーション(各オブジェクトから列挙を受け取る)
	float m_Speed; //スピード
	float m_Jump; //ジャンプ
	CHARACTER_STATE m_State; //プレイヤー状態
	D3DXCOLOR m_col; //カラー
	D3DXVECTOR3 m_ShadowSize; //影のサイズ

	CShadow* m_pShadow; //影

	//キー情報構造体
	struct Key
	{
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
		D3DXVECTOR3 Trot;
	};

	//キー設定構造体
	struct KeySet
	{
		int nFrame; //フレーム数
		Key key[MAX_KEY];
	};

	//モーション設定構造体
	struct MotionSet
	{
		int nLoop; //ループするかどうか
		int nNumKey; //キー数
		KeySet keySet[MAX_PARTS];
	};

	MotionSet m_MotionSet[MAX_MOTION]; //モーション設定
};
#endif