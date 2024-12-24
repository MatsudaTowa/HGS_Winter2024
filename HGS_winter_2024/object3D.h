//=============================================
//
//3DTemplate[object3D.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _OBJECT3D_H_ //これが定義されてないとき

#define _OBJECT3D_H_
#include "main.h"
#include "object.h"

//=============================================
//3Dオブジェクトクラス
//=============================================
class CObject3D : public CObject
{
public:
	CObject3D(int nPriority);
	~CObject3D()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void BindTexture(LPDIRECT3DTEXTURE9 pTex);

	//色の取得
	//色の代入
	void SetColor(D3DXCOLOR col)
	{
		m_col = col;
	}

	//posの代入
	void SetPos(D3DXVECTOR3 pos)
	{
		m_pos = pos;
	}

	//rotの代入
	void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	}

	//サイズの代入
	void SetSize(D3DXVECTOR3 size)
	{
		m_size = size;
	}

	//テクスチャ座標の代入
	void SetTexPos(D3DXVECTOR2 tex)
	{
		m_tex_pos = tex;
	}

	//ワールドマトリックスの代入
	void SetMtxWorld(D3DXMATRIX mtxWorld)
	{
		m_mtxWorld = mtxWorld;
	}

	//頂点情報の代入
	void SetVtxBuff(LPDIRECT3DVERTEXBUFFER9 vtxBuff)
	{
		m_pVtxBuff = vtxBuff;
	}

	//アニメーションフレーム代入
	void SetAnimFrame(int nAnimFrame)
	{
		m_nAnimFrame = nAnimFrame;
	}

	//テクスチャ移動量の代入
	void SetTexMove(D3DXVECTOR2 tex_move)
	{
		m_tex_move = tex_move;
	}


	//頂点座標の代入
	void SetVtx(D3DXVECTOR3 nor);

	//頂点座標の代入
	void SetVtx(D3DXVECTOR3 nor,float fAngle, float fLength);

	//頂点座標の代入
	void SetVtxAnim(D3DXVECTOR3 nor,D3DXVECTOR2 tex_pos, D3DXVECTOR2 tex_move);
	void SetVtx_FootPos(D3DXVECTOR3 nor);

	//色の取得
	D3DXCOLOR& GetColor();

	//posの取得
	D3DXVECTOR3& GetPos();

	//rotの取得
	D3DXVECTOR3& GetRot();

	//サイズの取得
	D3DXVECTOR3& GetSize();

	//テクスチャ座標の取得
	D3DXVECTOR2& GetTexPos();

	//頂点情報取得
	LPDIRECT3DVERTEXBUFFER9& GetVtxBuff();

	//テクスチャ情報取得
	LPDIRECT3DTEXTURE9& GetTexture();

	//ワールドマトリックス取得
	D3DXMATRIX& GetMtxWorld();

	//アニメーションフレーム取得
	int GetAnimFrame();

	//テクスチャ移動量取得
	D3DXVECTOR2& GetTexMove();

private:

	LPDIRECT3DTEXTURE9 m_pTexture; //テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff; //頂点バッファへのポインタ

	D3DXCOLOR m_col; //色
	D3DXVECTOR3 m_pos; //位置
	D3DXVECTOR3 m_rot; //方向
	D3DXVECTOR3 m_size; //サイズ
	D3DXVECTOR2 m_tex_pos; //tex座標

	//アニメーション
	int m_nAnimFrame; //アニメーションフレーム
	int m_nAnimCnt; //アニメーションカウント
	D3DXVECTOR2 m_tex_move; //tex移動量

	D3DXMATRIX m_mtxWorld; //ワールドマトリックス
};
#endif