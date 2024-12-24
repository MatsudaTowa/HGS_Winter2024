//=============================================
//
//3DTemplate[title_Screen.h]
//Auther Matsuda Towa
//
//=============================================
#include "title_screen.h"
#include "manager.h"
#include "object.h"

//texパス
const std::string CTitle_Screen::ROGO_TEXTURE_NAME = "data\\TEXTURE\\TitleLogo.png";
const std::string CTitle_Screen::BUTTON_A_TEXTURE_NAME = "data\\TEXTURE\\title_test.png";
const std::string CTitle_Screen::BUTTON_ENTER_TEXTURE_NAME = "data\\TEXTURE\\press_enter.png";

//=============================================
//コンストラクタ
//=============================================
CTitle_Screen::CTitle_Screen(int nPriority):CObject2D(nPriority),m_UItype(CTitle_Screen::TITLE_UI::UI_NONE)
{
}

//=============================================
//デストラクタ
//=============================================
CTitle_Screen::~CTitle_Screen()
{
}

//=============================================
//初期化
//=============================================
HRESULT CTitle_Screen::Init()
{

	//親クラスの初期化を呼ぶ
	CObject2D::Init();

	//テクスチャ座標設定
	SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

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
void CTitle_Screen::Uninit()
{
	//親クラスの終了呼ぶ
	CObject2D::Uninit();
}

//=============================================
//更新
//=============================================
void CTitle_Screen::Update()
{
	//親クラスの更新呼ぶ
	CObject2D::Update();

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	CInputPad* pPad = CManager::GetInstance()->GetPad();

	switch (m_UItype)
	{
	case CTitle_Screen::TITLE_UI::UI_TITLE_ROGO:
		BindTexture(pTexture->GetAddress(pTexture->Regist(&ROGO_TEXTURE_NAME)));
		break;
	case CTitle_Screen::TITLE_UI::UI_TITLE_PRESS_BUTTON:
		if (pPad->GetConnet())
		{
			BindTexture(pTexture->GetAddress(pTexture->Regist(&BUTTON_A_TEXTURE_NAME)));
		}
		else if (!pPad->GetConnet())
		{
			BindTexture(pTexture->GetAddress(pTexture->Regist(&BUTTON_ENTER_TEXTURE_NAME)));
		}
		break;
	default:
		break;
	}
}

//=============================================
//描画
//=============================================
void CTitle_Screen::Draw()
{
	//親クラスの描画呼ぶ
	CObject2D::Draw();
}

//=============================================
//生成
//=============================================
CTitle_Screen* CTitle_Screen::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, TITLE_UI type)
{
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	CTitle_Screen* pTitle_Screen = new CTitle_Screen;

	//nullならnullを返す
	if (pTitle_Screen == nullptr) {return nullptr;}

	pTitle_Screen->SetPos(pos); //pos設定

	pTitle_Screen->SetSize(size); //size設定

	pTitle_Screen->m_UItype = type;

	CInputPad* pPad = CManager::GetInstance()->GetPad();

	switch (pTitle_Screen->m_UItype)
	{
	case CTitle_Screen::TITLE_UI::UI_TITLE_ROGO:
		pTitle_Screen->BindTexture(pTexture->GetAddress(pTexture->Regist(&ROGO_TEXTURE_NAME)));
		break;
	case CTitle_Screen::TITLE_UI::UI_TITLE_PRESS_BUTTON:
		if (pPad->GetConnet())
		{
			pTitle_Screen->BindTexture(pTexture->GetAddress(pTexture->Regist(&BUTTON_A_TEXTURE_NAME)));
		}
		else if (!pPad->GetConnet())
		{
			pTitle_Screen->BindTexture(pTexture->GetAddress(pTexture->Regist(&BUTTON_ENTER_TEXTURE_NAME)));
		}
		break;
	default:
		break;
	}

	pTitle_Screen->SetType(OBJECT_TYPE_TITLE); //タイプ設定

	pTitle_Screen->Init();

	return pTitle_Screen;
}
