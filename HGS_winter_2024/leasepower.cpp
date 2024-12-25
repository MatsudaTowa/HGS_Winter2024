//=============================================
//
//3DTemplate[leasepower.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "leasepower.h"
#include "manager.h"
#include "enemy.h"

//texパス
const std::string CLeasepower::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//コンストラクタ
//=============================================
CLeasepower::CLeasepower(int nPriority) :CObject3D(nPriority), m_nCount(0)
{
}

//=============================================
//デストラクタ
//=============================================
CLeasepower::~CLeasepower()
{
}

//=============================================
//初期化
//=============================================
HRESULT CLeasepower::Init()
{
	//テクスチャ取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //テクスチャ設定

	return S_OK;
}

//=============================================
//更新
//=============================================
void CLeasepower::Update()
{
	m_nCount++;

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

	if (m_nCount > TIME_END)
	{
		Uninit();
	}
}

//=============================================
//描画
//=============================================
void CLeasepower::Draw()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//カリング方法を変更
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	CObject3D::Draw();

	//カリング方法を変更
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

//=============================================
//生成
//=============================================
CLeasepower* CLeasepower::Create(D3DXVECTOR3 pos)
{
	CLeasepower* pObject = new CLeasepower(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS * 2.0f, 0.0f, SIZE_RADIUS * 2.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	return pObject;
}
