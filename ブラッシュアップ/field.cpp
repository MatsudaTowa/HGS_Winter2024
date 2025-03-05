//=============================================
//
//3DTemplate[field.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "field.h"
#include "manager.h"

//texパス
const std::string CField::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//コンストラクタ
//=============================================
CField::CField(int nPriority) : CObject3D(nPriority)
{
}

//=============================================
//デストラクタ
//=============================================
CField::~CField()
{
}

//=============================================
//初期化
//=============================================
HRESULT CField::Init()
{
	//頂点設定
	SetVtx(D3DXVECTOR3(0.0f,1.0f,0.0f));

	return S_OK;
}

//=============================================
//終了
//=============================================
void CField::Uninit()
{
	CObject3D::Uninit();
}

//=============================================
//更新
//=============================================
void CField::Update()
{

}

//=============================================
//描画
//=============================================
void CField::Draw()
{
	// 親クラスの描画
	CObject3D::Draw();
}

//=============================================
//  生成
//=============================================
CField* CField::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CField* pField = new CField;

	// nullならnullを返す
	if (pField == nullptr) { return nullptr; }

	//テクスチャ取得
	CTexture* pTexture = GET_TEXTURE;

	pField->SetPos(pos); //pos設定
	pField->SetSize(size); //サイズ設定
	pField->BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //テクスチャ設定
	pField->SetType(OBJECT_TYPE_FIELD); //タイプ設定
	pField->Init(); //床の初期化処理

	return pField;
}