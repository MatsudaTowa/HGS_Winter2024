//=============================================
//
//3DTemplate[kerosene.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "kerosene.h"
#include "manager.h"

//texパス
const std::string CKerosene::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//コンストラクタ
//=============================================
CKerosene::CKerosene(int nPriority) :CObject3D(nPriority),m_nCount(0)
{
}

//=============================================
//デストラクタ
//=============================================
CKerosene::~CKerosene()
{
}

//=============================================
//初期化
//=============================================
HRESULT CKerosene::Init()
{
	//テクスチャ取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //テクスチャ設定
}

//=============================================
//描画
//=============================================
void CKerosene::Update()
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
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				//CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
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
//生成
//=============================================
CKerosene* CKerosene::Create(D3DXVECTOR3 pos)
{
	CKerosene* pObject = new CKerosene(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS * 2.0f, 0.0f, SIZE_RADIUS * 2.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	return pObject;
}
