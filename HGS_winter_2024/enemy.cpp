//=============================================
//
//敵の処理[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "enemy.h"
#include "weak_enemy.h"
#include "exp.h"
#include "player.h"

//エネミー総数
int CEnemy::m_NumEnemy = 0;

//=============================================
//コンストラクタ
//=============================================
CEnemy::CEnemy(int nPriority) :CCharacter(nPriority)
{
	//総数追加
	m_NumEnemy++;
}

//=============================================
//デストラクタ
//=============================================
CEnemy::~CEnemy()
{
	//総数減少
	m_NumEnemy--;
}

//=============================================
//初期化
//=============================================
HRESULT CEnemy::Init()
{
	CCharacter::Init();

	//移動量初期化
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//ムーブ値代入
	SetMove(move);

	m_Motion = CEnemy::Motion_Type::MOTION_MAX; //ニュートラルに設定

	SetMotion(MOTION_NEUTRAL);

	return S_OK;
}

//=============================================
//終了
//=============================================
void CEnemy::Uninit()
{
	int nRand = rand() % 3;
	CExp::Create(GetPos(), (CExp::EXP_TYPE)nRand); //ランダム)

	//親クラスの終了処理を呼ぶ
	CCharacter::Uninit();
}

//=============================================
//更新
//=============================================
void CEnemy::Update()
{
	CCharacter::Update();

	//敵との当たり判定
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			//敵を見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_ENEMY)
			{
				CEnemy* pEnemy = dynamic_cast<CEnemy*>(pObj);

				if (pEnemy == this)
				{
					pObj = pNext;	//ポインタを進める
					continue;
				}

				//円の中に入ったらダメージ
				if (JudgeBallCollision(GetPos(), pEnemy->GetPos(), 15.0f * 2.0f))
				{
					SetPos(CObjectX::GetOldPos());
				}

			}

			pObj = pNext;							//ポインタを進める
		}
	}

	//敵との当たり判定
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			//敵を見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pEnemy = dynamic_cast<CPlayer*>(pObj);

				//円の中に入ったらダメージ
				if (JudgeBallCollision(GetPos(), pEnemy->GetPos(), 15.0f * 2.0f))
				{
					//SetPos(CObjectX::GetOldPos());
					pEnemy->GetLife()--;
				}

			}

			pObj = pNext;							//ポインタを進める
		}
	}
}

//=============================================
//描画
//=============================================
void CEnemy::Draw()
{
	//親クラスのモーション用の描画を呼ぶ
	MotionDraw();
}

//=============================================
//生成
//=============================================
CEnemy* CEnemy::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const ENEMY_TYPE& type)
{
	CEnemy* pEnemy = nullptr;

	switch (type)
	{
	case ENEMY_TYPE::ENEMY_TYPE_WEAK:
		pEnemy = new CWeakEnemy;
		break;
		//case ENEMY_TYPE::ENEMY_TYPE_BOSS:
		//	pEnemy = new CBossEnemy;
		//	pEnemy->Load_Parts("data\\motion_boss.txt");
		//	break;
	default:
		assert(false);
		break;
	}

	// nullならnullを返す
	if (pEnemy == nullptr) { return nullptr; }

	pEnemy->m_type = type;
	pEnemy->SetPos(pos); //pos設定
	pEnemy->SetRot(rot); //rot設定
	pEnemy->SetType(OBJECT_TYPE_ENEMY); //タイプ設定

	pEnemy->Init(); //初期化処理

	return pEnemy;
}

//=============================================
//ダメージ
//=============================================
void CEnemy::Damage(int nDamage)
{
	//体力取得
	int nLife = GetLife();
	//状態を取得
	CCharacter::CHARACTER_STATE state = GetState();

	if (nLife > 0 && state != CCharacter::CHARACTER_STATE::CHARACTER_DAMAGE)
	{//ダメージ状態以外でHPが残ってたら
		nLife -= nDamage;

		//体力代入
		SetLife(nLife);
	}
	if (nLife <= 0)
	{//HPが0以下だったら
		//終了
		Uninit();
	}
}
