//=============================================
//
//フェード処理[fade.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "fade.h"
#include"manager.h"

//=============================================
//コンストラクタ
//=============================================
CFade::CFade(int nPriority):CObject2D(nPriority),m_fademode()
{
}

//=============================================
//デストラクタ
//=============================================
CFade::~CFade()
{
}

//=============================================
//初期化
//=============================================
HRESULT CFade::Init()
{
	//サイズ取得
	D3DXVECTOR2 size = GetSize();

	size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	//サイズを代入
	SetSize(size);

	//カラー取得
	D3DXCOLOR col = GetColor();

	col = D3DXCOLOR(FLOAT_ZERO, FLOAT_ZERO, FLOAT_ZERO, m_colorFade);

	//カラーを代入
	SetColor(col);

	//頂点設定
	SetVtx(1.0f);

	return S_OK;
}

//=============================================
//終了
//=============================================
void CFade::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
//更新
//=============================================
void CFade::Update()
{
	if (m_fade != FADE_NONE)
	{
		if (m_fade == FADE_IN)
		{//フェードイン状態
			m_colorFade -= FADE_VALUE;
			if (m_colorFade <= FLOAT_ZERO)
			{
				m_colorFade = FLOAT_ZERO;
				m_fade = FADE_NONE; //何もしてない状態に
			}
		}
		else if (m_fade == FADE_OUT)
		{//フェードアウト状態
			m_colorFade += FADE_VALUE;
			if (m_colorFade >= FLOAT_ONE)
			{
				m_colorFade = FLOAT_ONE;
				m_fade = FADE_IN; //フェードイン状態に
				CManager::GetInstance()->SetMode(m_fademode);
			}
		}

		//カラー取得
		D3DXCOLOR col = GetColor();

		col = D3DXCOLOR(FLOAT_ZERO, FLOAT_ZERO, FLOAT_ZERO, m_colorFade);

		//カラーを代入
		SetColor(col);

		//頂点カラーの設定
		SetVtx(FLOAT_ONE);
	}

}

//=============================================
//描画
//=============================================
void CFade::Draw()
{
	CObject2D::Draw();
}

//=============================================
//フェードの設定
//=============================================
void CFade::SetFade(CScene::MODE modeNext)
{
    m_fademode = modeNext;
    m_fade = FADE_OUT;
}

////=============================================
////フェードの情報取得
////=============================================
////CFade::FADE CFade::GetFade(void)
////{
////    return m_fade;
////}

//=============================================
//フェードの色取得(主にアルファ値)
//=============================================
float CFade::FadeColor(void)
{
    return m_colorFade;
}

//=============================================
//生成
//=============================================
CFade* CFade::Create(D3DXVECTOR3 pos)
{
	CFade* pFade = new CFade;
	//CObject *pObject = Getobject();
	if (pFade != nullptr)
	{
		pFade->SetPos(pos); //pos設定

		pFade->m_colorFade = FLOAT_ZERO;

		pFade->SetType(OBJECT_TYPE_FADE); //タイプ設定

		//pResult_Screen->BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME)));

		pFade->Init();
	}
	return pFade;
}
