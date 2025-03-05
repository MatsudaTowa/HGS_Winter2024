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
	inline void SetColor(D3DXCOLOR col)
	{
		m_col = col;
	}

	//posの代入
	inline void SetPos(D3DXVECTOR3 pos)
	{
		m_pos = pos;
	}

	//rotの代入
	inline void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	}

	//サイズの代入
	inline void SetSize(D3DXVECTOR3 size)
	{
		m_size = size;
	}

	//テクスチャ座標の代入
	inline void SetTexPos(D3DXVECTOR2 tex)
	{
		m_tex_pos = tex;
	}

	//ワールドマトリックスの代入
	inline void SetMtxWorld(D3DXMATRIX mtxWorld)
	{
		m_mtxWorld = mtxWorld;
	}

	//頂点情報の代入
	inline void SetVtxBuff(LPDIRECT3DVERTEXBUFFER9 vtxBuff)
	{
		m_pVtxBuff = vtxBuff;
	}

	//アニメーションフレーム代入
	inline void SetAnimFrame(int nAnimFrame)
	{
		m_nAnimFrame = nAnimFrame;
	}

	//テクスチャ移動量の代入
	inline void SetTexMove(D3DXVECTOR2 tex_move)
	{
		m_tex_move = tex_move;
	}


	//頂点座標の代入
	void SetVtx(D3DXVECTOR3 nor);

	//頂点座標の代入
	void SetVtx(D3DXVECTOR3 nor,float fAngle, float fLength);

	//頂点座標の代入
	void SetVtxAnim(D3DXVECTOR3 nor,D3DXVECTOR2 tex_pos, D3DXVECTOR2 tex_move);
	void SetGaugeVtx(D3DXVECTOR3 ReferencePos,D3DXVECTOR3 nor);
	void SetVtx_FootPos(D3DXVECTOR3 nor);

	//色の取得
	inline D3DXCOLOR& GetColor()
	{
		return m_col;
	}

	//posの取得
	inline D3DXVECTOR3& GetPos()
	{
		return m_pos;
	}

	//rotの取得
	inline D3DXVECTOR3& GetRot()
	{
		return m_rot;
	}

	//サイズの取得
	inline D3DXVECTOR3& GetSize()
	{
		return m_size;
	}

	//テクスチャ座標の取得
	inline D3DXVECTOR2& GetTexPos()
	{
		return m_tex_pos;
	}

	//頂点情報取得
	inline LPDIRECT3DVERTEXBUFFER9& GetVtxBuff()
	{
		return m_pVtxBuff;
	}

	//テクスチャ情報取得
	inline LPDIRECT3DTEXTURE9& GetTexture()
	{
		return m_pTexture;
	}

	//ワールドマトリックス取得
	inline D3DXMATRIX& GetMtxWorld()
	{
		return m_mtxWorld;
	}

	//アニメーションフレーム取得
	inline int GetAnimFrame()
	{
		return m_nAnimFrame;
	}

	//テクスチャ移動量取得
	inline D3DXVECTOR2& GetTexMove()
	{
		return m_tex_move;
	}

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