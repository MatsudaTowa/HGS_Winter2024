//=============================================
//
//3DTemplate[bullet.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "bullet.h"
#include "manager.h"
#include "enemy.h"

//texパス
const std::string CBullet::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//コンストラクタ
//=============================================
CBullet::CBullet(int nPriority) :CMoveBillboard(nPriority), m_nLife(0)
{
}

//=============================================
//デストラクタ
//=============================================
CBullet::~CBullet()
{
}

//=============================================
//初期化
//=============================================
HRESULT CBullet::Init()
{
	//テクスチャ取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //テクスチャ設定

	return S_OK;
}

//=============================================
//更新
//=============================================
void CBullet::Update()
{
	CMoveBillboard::Update();

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
					Uninit();
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
CBullet* CBullet::Create(D3DXVECTOR3 pos, float angle)
{
	CBullet* pObject = new CBullet(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS, SIZE_RADIUS,0.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	pObject->SetMove(D3DXVECTOR3(sinf(angle) * SPEED, 0.0f, cosf(angle) * SPEED));
	return pObject;
}
