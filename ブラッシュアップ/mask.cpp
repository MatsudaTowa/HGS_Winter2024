//=============================================
//
//マスク処理[mask.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "mask.h"
#include "manager.h"

//=============================================
// コンストラクタ
//=============================================
CMask::CMask(int nPriority):CObject2D(nPriority)
{
}

//=============================================
// デストラクタ
//=============================================
CMask::~CMask()
{
}

//=============================================
// 初期化
//=============================================
HRESULT CMask::Init()
{
	CObject2D::Init();

	SetPos({ SCREEN_WIDTH * HALF,SCREEN_HEIGHT * HALF,FLOAT_ZERO });

	//サイズ取得
	D3DXVECTOR2 size = GetSize();

	size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

	//サイズを代入
	SetSize(size);

	//カラー取得
	D3DXCOLOR col = GetColor();

	col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.75f);

	//カラーを代入
	SetColor(col);

	SetVtx(1.0f);
	return S_OK;
}

//=============================================
// 終了
//=============================================
void CMask::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
// 更新
//=============================================
void CMask::Update()
{
	CObject2D::Update();
	SetVtx(1.0f);
}

//=============================================
// 描画
//=============================================
void CMask::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;	// デバイスのポインタ
	// ステンシルテストを有効にする
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
	// 比較参照値を設定する
	pDevice->SetRenderState(D3DRS_STENCILREF, 2);
	// ステンシルマスクを指定する
	pDevice->SetRenderState(D3DRS_STENCILMASK, 255);
	// ステンシル比較関数を指定する TODO:以上にするとおかしくなる
	pDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
	// ステンシル結果に対しての反映設定
	pDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);	// Zテスト・ステンシルテスト成功
	pDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);		// Zテスト・ステンシルテスト失敗
	pDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);		// Zテスト失敗・ステンシルテスト成功

	CObject2D::Draw();

	// ステンシルテストを無効にする
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
}

//=============================================
// 生成
//=============================================
CMask* CMask::Create()
{
	CMask* pMask = new CMask;

	if (pMask == nullptr) { return nullptr; }

	pMask->Init();

	return pMask;
}
