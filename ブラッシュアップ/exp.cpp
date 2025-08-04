//=============================================
//
//3DTemplate[exp.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp.h"
#include "player.h"
#include "gamemanager.h"

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


	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();
	if (JudgeBallCollision(GetPos(), pPlayer->GetPos(), 20.0f))
	{
		pPlayer->AddExp(m_Info.Value);
		Uninit();
	}

}

//=============================================
//生成
//=============================================
CExp* CExp::Create(D3DXVECTOR3 pos, EXP_TYPE type)
{
	CExp* pObject = new CExp(3);

	pObject->m_Info = Info[type];
	pObject->SetPos(pos);
	pObject->Init();
	return pObject;
}