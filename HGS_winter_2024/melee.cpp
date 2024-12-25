//=============================================
//
//3DTemplate[melee.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "melee.h"
#include "manager.h"
#include "enemy.h"
//=============================================
// コンストラクタ
//=============================================
CMelee::CMelee(int nPriority):CObject3D(nPriority), m_fRadius(FLOAT_ZERO)
{
}

//=============================================
// デストラクタ
//=============================================
CMelee::~CMelee()
{
}

//=============================================
// 初期化
//=============================================
HRESULT CMelee::Init()
{
	CObject3D::Init();
	//頂点座標
	SetVtx(D3DXVECTOR3(0.0f, 0.0f, -1.0f));
	return S_OK;
}

//=============================================
// 終了
//=============================================
void CMelee::Uninit()
{
	CObject3D::Uninit();
}

//=============================================
// 更新
//=============================================
void CMelee::Update()
{
	CObject3D::Update();
	//頂点座標
	SetVtx(D3DXVECTOR3(0.0f, 0.0f, -1.0f));
	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //次のポインタを取得

			if (pObj->GetType() == CObject::OBJECT_TYPE_ENEMY)
			{
				CEnemy* pEnemy = dynamic_cast<CEnemy*>(pObj);

				bool bHit = JudgeBallCollision(GetPos(), pEnemy->GetPos(), m_fRadius + pEnemy->GetRadius());

				if (bHit)
				{
					pEnemy->Damage(100);
				}
				
			}

			pObj = pNext;  //ポインタを進める
		}
	}

}

//=============================================
// 描画
//=============================================
void CMelee::Draw()
{
	//CObject3D::Draw();
}

//=============================================
// 生成
//=============================================
CMelee* CMelee::Create(D3DXVECTOR3 pos, float fRadius)
{
	CMelee* pMelee = new CMelee;
	if (pMelee == nullptr) { return nullptr; }

	pMelee->SetPos(pos);
	pMelee->SetSize({fRadius, fRadius,0.0f});
	pMelee->m_fRadius = fRadius;

	pMelee->Init();

	return pMelee;
}