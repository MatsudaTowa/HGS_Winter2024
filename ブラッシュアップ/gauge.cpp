//=============================================
//
//ゲージ処理[gauge.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "gauge.h"
#include "hp_gauge.h"
#include "exp_gauge.h"

//=============================================
//デストラクタ
//=============================================
CGauge_2D::~CGauge_2D()
{
}

//=============================================
//初期化
//=============================================
HRESULT CGauge_2D::Init()
{
	CObject2D::Init();
	return S_OK;
}

//=============================================
//終了
//=============================================
void CGauge_2D::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
//更新
//=============================================
void CGauge_2D::Update()
{
	SetGaugeVtx();

	CObject2D::Update();
}

//=============================================
//頂点生成
//=============================================
void CGauge_2D::SetGaugeVtx()
{
	D3DXVECTOR2 size = GetSize();
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXCOLOR col = GetColor();

	float fWidth = (size.x / m_MaxGauge) * m_GaugeValue;
	//対角線の長さを算出
	float fLength = sqrtf(fWidth * fWidth + size.y * size.y) / 2.0f;
	//対角線の角度を算出
	float fAngle = atan2f(fWidth, size.y);

	//テクスチャの端を算出
	float fGaugeTex = ((1.0f / m_MaxGauge) * m_GaugeValue);
	float TexPos = pos.x + (fWidth * 0.5f) - size.x * 0.5f;

	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();

	LPDIRECT3DVERTEXBUFFER9 pVtxBuff = GetVtxBuff();

	if (pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &pVtxBuff, NULL);
	}

	VERTEX_2D* pVtx;

	//頂点バッファをロックし頂点情報へのポインタを取得
	pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標の設定

	//頂点座標の設定
	pVtx[0].pos.x = TexPos + sinf(rot.z - (D3DX_PI - fAngle)) * (fLength);
	pVtx[0].pos.y = pos.y + cosf(rot.z - (D3DX_PI - fAngle)) * (fLength);
	pVtx[0].pos.z = 0.0f;
	pVtx[1].pos.x = TexPos + sinf(rot.z + (D3DX_PI - fAngle)) * (fLength);
	pVtx[1].pos.y = pos.y + cosf(rot.z + (D3DX_PI - fAngle)) * (fLength);
	pVtx[1].pos.z = 0.0f;
	pVtx[2].pos.x = TexPos + sinf(rot.z - fAngle) * (fLength);
	pVtx[2].pos.y = pos.y + cosf(rot.z - fAngle) * (fLength);
	pVtx[2].pos.z = 0.0f;
	pVtx[3].pos.x = TexPos + sinf(rot.z + fAngle) * (fLength);
	pVtx[3].pos.y = pos.y + cosf(rot.z + fAngle) * (fLength);
	pVtx[3].pos.z = 0.0f;

	//rhwの設定
	pVtx[0].rhw =
	pVtx[1].rhw =
	pVtx[2].rhw =
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = col;

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	//頂点バッファのアンロック
	pVtxBuff->Unlock();

	SetVtxBuff(pVtxBuff);

	SetSize(size);
	SetPos(pos);
	SetRot(rot);
	SetColor(col);
}

//=============================================
//描画
//=============================================
void CGauge_2D::Draw()
{
	CObject2D::Draw();
}

//=============================================
//生成
//=============================================
CGauge_2D* CGauge_2D::Create(D3DXVECTOR3 pos, int Max, GAUGE_TYPE type)
{
	CGauge_2D* pGauge2D = nullptr;

	switch (type)
	{
	case CGauge_2D::GAUGE_LIFE:
		pGauge2D = new CHpGauge;
		break;
	case CGauge_2D::GAUGE_EXP:
		pGauge2D = new CExpGauge;
		break;
	default:
		assert("範囲外のゲージタイプです");
		break;
	}

	if (pGauge2D == nullptr) { return nullptr; }

	pGauge2D->SetPos(pos);
	pGauge2D->m_MaxGauge = Max;

	pGauge2D->Init();

	return pGauge2D;
}
