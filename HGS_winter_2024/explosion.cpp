//=============================================
//
//3DTemplate[explosion.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "explosion.h"
#include "manager.h"
#include "enemy.h"

//=============================================
//コンストラクタ
//=============================================
CExplosion::CExplosion(int priority) : CBillboard(priority)
{
}

//=============================================
//デストラクタ
//=============================================
CExplosion::~CExplosion()
{
}

//=============================================
//初期化
//=============================================
HRESULT CExplosion::Init()
{
	//初期化
	CBillboard::Init();

	return S_OK;
}

//=============================================
//更新
//=============================================
void CExplosion::Update()
{
	CBillboard::Update();

	m_nLife++;

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

				//円の中に入ったらダメージ
				if (JudgeBallCollision(GetPos(), pEnemy->GetPos(), SIZE_RADIUS * 2.0f))
				{
					pEnemy->Damage(1);
				}

			}

			pObj = pNext;							//ポインタを進める
		}
	}

	if (m_nLife > LIFE)
	{
		Uninit();
	}
}

//=============================================
//生成
//=============================================
CExplosion* CExplosion::Create(D3DXVECTOR3 pos)
{
	CExplosion* pObject = new CExplosion(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS, SIZE_RADIUS,0.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	
	return pObject;
}