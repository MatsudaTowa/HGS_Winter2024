//=============================================
//
//3DTemplate[result_Screen.h]
//Auther Matsuda Towa
//
//=============================================
#include "result_screen.h"
#include "manager.h"

//texパス
const std::string CResult_Screen::TEXTURE_NAME = "data\\TEXTURE\\result.png";

//=============================================
//コンストラクタ
//=============================================
CResult_Screen::CResult_Screen(int nPriority) :CObject2D(nPriority)
{
}

//=============================================
//デストラクタ
//=============================================
CResult_Screen::~CResult_Screen()
{
}

//=============================================
//初期化
//=============================================
HRESULT CResult_Screen::Init()
{
	//親クラスの初期化を呼ぶ
	CObject2D::Init();

	//自分自身のサイズ取得
	D3DXVECTOR2 size = GetSize();

	size = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);

	//テクスチャ座標設定
	SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	//サイズを代入
	SetSize(size);

	//カラー取得
	D3DXCOLOR col = GetColor();

	col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//カラーを代入
	SetColor(col);

	//頂点設定
	SetVtx(1.0f);
	return S_OK;
}

//=============================================
//終了
//=============================================
void CResult_Screen::Uninit()
{
	//親クラスの終了を呼ぶ
	CObject2D::Uninit();

}

//=============================================
//更新
//=============================================
void CResult_Screen::Update()
{
	//親クラスの更新
	CObject2D::Update();
}

//=============================================
//描画
//=============================================
void CResult_Screen::Draw()
{
	//親クラスの描画
	CObject2D::Draw();
}

//=============================================
//生成
//=============================================
CResult_Screen* CResult_Screen::Create(D3DXVECTOR3 pos)
{
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	CResult_Screen* pResult_Screen = new CResult_Screen;

	//nullならnullを返す
	if (pResult_Screen == nullptr) {return nullptr;}

	pResult_Screen->SetPos(pos); //pos設定

	pResult_Screen->SetType(OBJECT_TYPE_RESULT); //タイプ設定

	pResult_Screen->BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME)));

	pResult_Screen->Init();

	return pResult_Screen;
}
