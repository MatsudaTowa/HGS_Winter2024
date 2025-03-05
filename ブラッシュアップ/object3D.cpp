//=============================================
//
//3DTemplate[object3D.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "object3D.h"
#include "renderer.h"
#include "manager.h"

//=============================================
//コンストラクタ
//=============================================
CObject3D::CObject3D(int nPriority):CObject(nPriority),
m_col(COLOR_WHITE),
m_pos(VEC3_RESET_ZERO),
m_rot(VEC3_RESET_ZERO),
m_size(VEC3_RESET_ZERO),
m_tex_pos(VEC2_RESET_ZERO),
m_nAnimFrame(INT_ZERO),
m_nAnimCnt(INT_ZERO),
m_tex_move(VEC2_RESET_ZERO),
m_mtxWorld()
{
	m_pTexture = nullptr;
	m_pVtxBuff = nullptr;
}

//=============================================
//デストラクタ
//=============================================
CObject3D::~CObject3D()
{
}

//=============================================
//初期化
//=============================================
HRESULT CObject3D::Init()
{
	return S_OK;
}

//=============================================
//終了
//=============================================
void CObject3D::Uninit()
{
	if (m_pTexture != nullptr)
	{
		m_pTexture = nullptr;
	}

	//頂点バッファの破棄
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	Release();
}

//=============================================
//更新
//=============================================
void CObject3D::Update()
{
}

//=============================================
//描画
//=============================================
void CObject3D::Draw()
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス

	//マトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//=============================================
//テクスチャ設定
//=============================================
void CObject3D::BindTexture(LPDIRECT3DTEXTURE9 pTex)
{
	m_pTexture = pTex;
}

//=============================================
//頂点の設定
//=============================================
void CObject3D::SetVtx(D3DXVECTOR3 nor)
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();
	if (m_pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);
	}
	VERTEX_3D* pVtx;
	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, reinterpret_cast<void**>(&pVtx), 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(-m_size.x
		, m_size.y
		, m_size.z);
	pVtx[1].pos = D3DXVECTOR3(m_size.x
		, m_size.y
		, m_size.z);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x
		, -m_size.y
		, -m_size.z);
	pVtx[3].pos = D3DXVECTOR3(m_size.x
		, -m_size.y
		, -m_size.z);


	//法線の設定
	pVtx[0].nor =
	pVtx[1].nor =
	pVtx[2].nor =
	pVtx[3].nor = nor;

	//頂点カラーの設定
	pVtx[0].col =
	pVtx[1].col =
	pVtx[2].col =
	pVtx[3].col = m_col;

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//アンロック
	m_pVtxBuff->Unlock();

}


//=============================================
//頂点の設定(拡縮回転)
//=============================================
void CObject3D::SetVtx(D3DXVECTOR3 nor, float fAngle, float fLength)
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();
	if (m_pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);

	}
	VERTEX_3D* pVtx;
	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, reinterpret_cast<void**>(&pVtx), 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(-m_size.x + sinf(m_rot.z - (D3DX_PI - fAngle)) * fLength
		, m_size.y + cosf(m_rot.z - (D3DX_PI - fAngle)) * fLength
		, m_size.z);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + (D3DX_PI - fAngle)) * fLength
		, m_size.y + cosf(m_rot.z + (D3DX_PI - fAngle)) * fLength
		, m_size.z);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z - fAngle) * fLength
		, -m_size.y + cosf(m_rot.z - fAngle) * fLength
		, -m_size.z);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + fAngle) * fLength
		, -m_size.y + cosf(m_rot.z + fAngle) * fLength
		, -m_size.z);

	//法線の設定
	pVtx[0].nor =
	pVtx[1].nor =
	pVtx[2].nor =
	pVtx[3].nor = nor;

	//頂点カラーの設定
	pVtx[0].col =
	pVtx[1].col =
	pVtx[2].col =
	pVtx[3].col = m_col;

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//アンロック
	m_pVtxBuff->Unlock();

}

//=============================================
//アニメーション専用頂点の設定
//=============================================
void CObject3D::SetVtxAnim(D3DXVECTOR3 nor, D3DXVECTOR2 tex_pos, D3DXVECTOR2 tex_move)
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();
	if (m_pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);
	}
	VERTEX_3D* pVtx;
	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, reinterpret_cast<void**>(&pVtx), 0);

	//頂点座標の設定
 	pVtx[0].pos = D3DXVECTOR3(-m_size.x
		, m_size.y
		, m_size.z);
	pVtx[1].pos = D3DXVECTOR3(m_size.x
		, m_size.y
		, m_size.z);
	pVtx[2].pos = D3DXVECTOR3(-m_size.x
		, -m_size.y
		, -m_size.z);
	pVtx[3].pos = D3DXVECTOR3(m_size.x
		, -m_size.y
		, -m_size.z);


	//法線の設定
	pVtx[0].nor =
		pVtx[1].nor =
		pVtx[2].nor =
		pVtx[3].nor = nor;

	//頂点カラーの設定
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = m_col;

	m_nAnimCnt++;

	if (m_nAnimCnt >= m_nAnimFrame)
	{//フレーム数が達したら
		//テクスチャをずらす
 		tex_pos.x += tex_move.x;
		m_tex_move = tex_move;

		m_nAnimCnt = 0;
	}

	//テクスチャの座標指定
	pVtx[0].tex = D3DXVECTOR2(tex_pos.x
		, tex_pos.y);
	pVtx[1].tex = D3DXVECTOR2(tex_pos.x + tex_move.x
		, tex_pos.y);
	pVtx[2].tex = D3DXVECTOR2(tex_pos.x
		, tex_pos.y + tex_move.y);
	pVtx[3].tex = D3DXVECTOR2(tex_pos.x + tex_move.x
		, tex_pos.y + tex_move.y);

	SetTexPos(tex_pos);
	//アンロック
	m_pVtxBuff->Unlock();

}

//=============================================
//頂点の設定(ゲージ)
//=============================================
void CObject3D::SetGaugeVtx(D3DXVECTOR3 ReferencePos,D3DXVECTOR3 nor)
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();

	if (m_pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);
	}
	VERTEX_3D* pVtx;

	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(ReferencePos.x
		, ReferencePos.y + m_size.y
		, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(ReferencePos.x + m_size.x
		, ReferencePos.y + m_size.y
		, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(ReferencePos.x
		, ReferencePos.y
		, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(ReferencePos.x + m_size.x
		, ReferencePos.y

		, 0.0f);

	//法線の設定
	pVtx[0].nor =
		pVtx[1].nor =
		pVtx[2].nor =
		pVtx[3].nor = nor;

	//頂点カラーの設定
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = m_col;

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//アンロック
	m_pVtxBuff->Unlock();
}

//=============================================
//頂点の設定(pos足元)
//=============================================
void CObject3D::SetVtx_FootPos(D3DXVECTOR3 nor)
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();

	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();
	if (m_pVtxBuff == nullptr)
	{
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);
	}

	VERTEX_3D* pVtx;

	//頂点バッファをロックし頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x
		, m_pos.y + m_size.y
		, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x
		, m_pos.y + m_size.y
		, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x
		, m_pos.y
		, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x
		, m_pos.y
		, 0.0f);

	//法線の設定
	pVtx[0].nor =
		pVtx[1].nor =
		pVtx[2].nor =
		pVtx[3].nor = nor;

	//頂点カラーの設定
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = m_col;

	//アンロック
	m_pVtxBuff->Unlock();
}