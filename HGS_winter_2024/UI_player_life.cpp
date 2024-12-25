//=============================================
//
//3DTemplate[result_Screen.h]
//Auther Matsuda Towa
//
//=============================================
#include "UI_player_life.h"
#include "manager.h"

namespace UI_Info
{
	std::string TexName = { "data\\Texture\\playerlife" };
	D3DXVECTOR2 Poly_Size = {
		300.0f,
		60.0f
	};
	D3DXCOLOR LifeCol = {1.0f,0.0f,0.0f,1.0f};
};

//=============================================
//初期化
//=============================================
HRESULT UI_PlayerLife::Init()
{
	//親クラスの初期化を呼ぶ
	CObject2D::Init();

	//自分自身のサイズ取得
	D3DXVECTOR2 size = GetSize();

	size = UI_Info::Poly_Size;

	//テクスチャ座標設定
	SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	//サイズを代入
	SetSize(size);

	//カラー取得
	D3DXCOLOR col = GetColor();

	col = UI_Info::LifeCol;

	//カラーを代入
	SetColor(col);

	SetMaxGauge(m_Life);

	//頂点設定
	SetVtx(1.0f);
	return S_OK;
}

//=============================================
//終了
//=============================================
void UI_PlayerLife::Uninit()
{
	SetGaugeVtx(1.0f);
	//親クラスの終了を呼ぶ
	CObject2D::Uninit();

}

//=============================================
//更新
//=============================================
void UI_PlayerLife::Update()
{
	SetGauge(m_Life);		//ゲージ値セット
	CObject2D::UpdateGauge();//ゲージ更新
	//親クラスの更新
	CObject2D::Update();
}

//=============================================
//描画
//=============================================
void UI_PlayerLife::Draw()
{
	//親クラスの描画
	CObject2D::Draw();
}

//=============================================
//生成
//=============================================
UI_PlayerLife* UI_PlayerLife::Create(D3DXVECTOR3 pos,int MaxLife)
{
	using namespace UI_Info;
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	UI_PlayerLife* pUI = new UI_PlayerLife;

	//nullならnullを返す
	if (pUI == nullptr) { return nullptr; }

	pUI->SetPos(pos); //pos設定

	pUI->SetType(OBJECT_TYPE_RESULT); //タイプ設定

	pUI->BindTexture(pTexture->GetAddress(pTexture->Regist(&TexName)));

	pUI->SetLife(MaxLife);

	pUI->Init();

	return pUI;
}
