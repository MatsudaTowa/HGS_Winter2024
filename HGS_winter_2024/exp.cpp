//=============================================
//
//3DTemplate[exp.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp.h"
#include "manager.h"
#include "player.h"

//経験値の情報
const CExp::ExpInfo CExp::Info[EXP_TYPE_MAX] =
{
	{1, "data\\MODEL\\giftbox.x"},
	{3, "data\\MODEL\\giftbox.x"},
	{5, "data\\MODEL\\giftbox.x"},
};

//=============================================
//コンストラクタ
//=============================================
CExp::CExp(int nPriority) :CObjectX(nPriority),
	m_Info()
{
	//種類
	m_type = OBJECT_TYPE_EXP;
}

//=============================================
//デストラクタ
//=============================================
CExp::~CExp()
{
}

//=============================================
//初期化
//=============================================
HRESULT CExp::Init()
{
	CModel* pModel = CManager::GetInstance()->GetModel();

	//Xファイル読み込み
	BindXFile(pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pBuffMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).dwNumMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pMesh);
	//親クラスの初期化
	CObjectX::Init();

	return S_OK;
}

//=============================================
//更新
//=============================================
void CExp::Update()
{
	CObjectX::Update();

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
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			}

			pObj = pNext;							//ポインタを進める
		}
	}
}

//=============================================
//生成
//=============================================
CExp* CExp::Create(D3DXVECTOR3 pos, EXP_TYPE type)
{
	CExp* pObject = new CExp(3);

	pObject->m_Info = Info[type];

	pObject->Init();
	return pObject;
}