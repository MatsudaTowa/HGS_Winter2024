//=============================================
//
//敵の処理[weak_enemy.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "weak_enemy.h"
#include "player.h"

//=============================================
//コンストラクタ
//=============================================
CWeakEnemy::CWeakEnemy(int nPriority):CEnemy(nPriority)
{
}

//=============================================
//デストラクタ
//=============================================
CWeakEnemy::~CWeakEnemy()
{
}

//=============================================
//初期化
//=============================================
HRESULT CWeakEnemy::Init()
{
	Load_Parts("data\\motion_enemy000.txt");
	SetLife(DEFAULT_LIFE);
	//親クラスの初期化を呼ぶ
	CEnemy::Init();
	return S_OK;
}

//=============================================
//終了
//=============================================
void CWeakEnemy::Uninit()
{
	//親クラスの終了処理を呼ぶ
	CEnemy::Uninit();
}

//=============================================
//更新
//=============================================
void CWeakEnemy::Update()
{
	CEnemy::Update();
	Move();

	Motion(GetNumParts()); //モーション処理
}

//=============================================
//描画
//=============================================
void CWeakEnemy::Draw()
{
	CEnemy::Draw();

}

//=============================================
//移動
//=============================================
void CWeakEnemy::Move()
{
	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //次のポインタを取得

			//プレイヤーを見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
				//プレイヤーの位置への方向情報
				D3DXVECTOR3 Vector = pPlayer->GetPos() - GetPos();
				// 目的地との距離を計算
				float distance = sqrtf(Vector.x * Vector.x + Vector.z * Vector.z);

				//プレイヤーに向かって動かす
				MovetoPlayer(distance, Vector);
			}
			pObj = pNext;  //ポインタを進める

		}
	}
}

//=============================================
//プレイヤーに向かって動かす
//=============================================
void CWeakEnemy::MovetoPlayer(float distance, D3DXVECTOR3& Vector)
{
	// まだ目的地に到達していない場合のみ移動処理を行う
	if (distance > THRESHOLD)
	{
		//対象物との角度計算
		float angle = atan2f(Vector.x, Vector.z);

		D3DXVECTOR3 move = GetMove();

		move.x += sinf(angle) * GetSpeed();
		move.z += cosf(angle) * GetSpeed();
		//親クラスからrotを取得
		D3DXVECTOR3 rot = GetRot();
		rot.y = angle + D3DX_PI;
		//rotを代入
		SetRot(rot);
		//移動量代入
		SetMove(move);
		SetMotion(CWeakEnemy::Motion_Type::MOTION_MOVE);
	}
	else
	{
		D3DXVECTOR3 move = { 0.0f,0.0f,0.0f };
		SetMotion(CWeakEnemy::Motion_Type::MOTION_NEUTRAL);

		//移動量代入
		SetMove(move);
	}
}
