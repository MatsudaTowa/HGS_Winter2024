//=============================================
//
//ゲージ処理[hpgauge.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp_gauge.h"

namespace ExpGauge_Info
{
	//std::string TexName = { "data\\Texture\\playerlife" };
	D3DXVECTOR2 Poly_Size = {
		SCREEN_WIDTH,
		20.0f
	};
	D3DXCOLOR Col = { 0.0f,1.0f,1.0f,1.0f };
};

//=============================================
// デストラクタ
//=============================================
CExpGauge::~CExpGauge()
{
}

//=============================================
// 初期化
//=============================================
HRESULT CExpGauge::Init()
{
	//テクスチャ座標設定
	//SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	SetSize(ExpGauge_Info::Poly_Size);
	SetColor(ExpGauge_Info::Col);

	CGauge_2D::Init();

	return S_OK;
}

//=============================================
// 終了
//=============================================
void CExpGauge::Uninit()
{
	CGauge_2D::Uninit();
}

//=============================================
// 更新
//=============================================
void CExpGauge::Update()
{
	CGauge_2D::Update();
}

//=============================================
// 描画
//=============================================
void CExpGauge::Draw()
{
	CGauge_2D::Draw();
}
