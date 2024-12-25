//=============================================
//
//3DTemplate[ui_select.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "ui_select.h"
#include "renderer.h"
#include "manager.h"

//経験値の情報
const std::string CUi_Select::Path[9] =
{
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
};

//定数
const D3DXVECTOR2 CUi_Select::SIZE = { 300.0f, 150.0f};

//=============================================
//コンストラクタ
//=============================================
CUi_Select::CUi_Select(int nPriority) : CObject2D(nPriority), m_nNum(0)
{
	
}

//=============================================
//デストラクタ
//=============================================
CUi_Select::~CUi_Select()
{
}

//=============================================
//初期化
//=============================================
HRESULT CUi_Select::Init()
{
	return S_OK;
}

//=============================================
//終了
//=============================================
void CUi_Select::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
//更新
//=============================================
void CUi_Select::Update()
{
	CObject2D::Update();
}

//=============================================
//生成
//=============================================
CUi_Select* CUi_Select::Create(D3DXVECTOR3 pos, int num)
{
	CUi_Select* p = new CUi_Select();

	//テクスチャ取得
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	p->SetPos(pos);		//pos設定
	p->SetSize(SIZE);	 //サイズ設定
	p->BindTexture(pTexture->GetAddress(pTexture->Regist(&Path[num]))); //テクスチャ設定
	p->SetColor({ 0.2f, 0.2f, 0.2f, 1.0f });
	p->Init();
	p->SetVtx(1.0f);
	p->m_nNum = num;

	return p;
}