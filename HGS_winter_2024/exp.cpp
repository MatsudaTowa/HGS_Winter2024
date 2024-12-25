//=============================================
//
//3DTemplate[exp.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp.h"
#include "manager.h"

//経験値の情報
const CExp::ExpInfo CExp::Info[EXP_TYPE_MAX] =
{
	{1, ""},
	{3, ""},
	{5, ""},
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
	//親クラスの初期化
	CObjectX::Init();

	return S_OK;
}

//=============================================
//更新
//=============================================
void CExp::Update()
{

}

//=============================================
//生成
//=============================================
CExp* CExp::Create(D3DXVECTOR3 pos, EXP_TYPE type)
{
	CExp* pObject = new CExp(3);

	pObject->m_Info = Info[type];

	return pObject;
}