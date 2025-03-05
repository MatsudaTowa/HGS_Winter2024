//=============================================
//
//3DTemplate[billboard.h]
//Auther Matsuda Towa
//
//=============================================
#include "billboard.h"

//=============================================
//コンストラクタ
//=============================================
CBillboard::CBillboard(int nPriority) :CObject3D(nPriority)
{
}

//=============================================
//デストラクタ
//=============================================
CBillboard::~CBillboard()
{
}

//=============================================
//描画
//=============================================
void CBillboard::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE; //デバイス取得

	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス

	D3DXMATRIX mtxView; //描画マトリックス

	D3DXMATRIX mtxWorld = GetMtxWorld(); //描画マトリックス

	D3DXVECTOR3 pos = GetPos();	//場所取得

	D3DXVECTOR3 rot = GetRot();	//方向取得

	LPDIRECT3DVERTEXBUFFER9 pVtxBuff = GetVtxBuff(); //頂点座標取得

	LPDIRECT3DTEXTURE9 pTexture = GetTexture(); //テクスチャ情報取得

	//マトリックスの初期化
	D3DXMatrixIdentity(&mtxWorld);

	//ビューマトリックスを取得
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	//ポリゴンの正面をカメラに向ける
	D3DXMatrixInverse(&mtxWorld, NULL, &mtxView);

	mtxWorld._41 = 0.0f;
	mtxWorld._42 = 0.0f;
	mtxWorld._43 = 0.0f;

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, pVtxBuff, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, pTexture);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	SetMtxWorld(mtxWorld);
}
