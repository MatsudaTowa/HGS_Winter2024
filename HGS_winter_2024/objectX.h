//=============================================
//
//3DTemplate[objectX.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _OBJECTX_H_ //これが定義されてないとき

#define _OBJECTX_H_
#include "main.h"
#include "object.h"

//2Dオブジェクトクラス
class CObjectX : public CObject
{
public:
	static const int MAX_TEX = 256; //テクスチャの数

	CObjectX(int nPriority);
	~CObjectX()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void BindTexture(LPDIRECT3DTEXTURE9 pTex,int Idx);

	void BindXFile(LPD3DXBUFFER pBuffMat, DWORD dwNumMat, LPD3DXMESH pMesh);

	//scaleの代入
	void SetScale(D3DXVECTOR3 scale)
	{
		m_scale = scale;
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

	//最小値代入
	void SetMinPos(D3DXVECTOR3 MinPos)
	{
		m_minpos = MinPos;
	}

	//最大値代入
	void SetMaxPos(D3DXVECTOR3 MaxPos)
	{
		m_maxpos = MaxPos;
	}

	//ワールドマトリックスの代入
	void SetMtxWorld(D3DXMATRIX mtxWorld)
	{
		m_mtxWorld = mtxWorld;
	}

	//カラーの代入
	void SetColor(D3DXCOLOR col)
	{
		m_col = col;
	}
	//scaleの取得
	D3DXVECTOR3& GetScale();

	//posの取得
	D3DXVECTOR3& GetPos();

	//rotの取得
	D3DXVECTOR3& GetRot();

	//最小値取得
	D3DXVECTOR3& GetMinPos();

	//最大値取得
	D3DXVECTOR3& GetMaxPos();

	//メッシュ情報取得
	LPD3DXMESH& GetpMesh();

	//マテリアル情報取得
	LPD3DXBUFFER& GetpBuffMat();

	//マテリアル数取得
	DWORD& GetNumMat();

	//ワールドマトリックス取得
	D3DXMATRIX& GetMtxWorld();

	//カラー取得
	D3DXCOLOR& GetCol();

private:

	LPDIRECT3DTEXTURE9 m_pTexture[MAX_TEX]; //テクスチャへのポインタ

	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_minpos; //pos最小値
	D3DXVECTOR3 m_maxpos; //pos最大値

	D3DXMATRIX m_mtxWorld; //ワールドマトリックス
	
	LPD3DXMESH m_pMesh; //メッシュ情報
	LPD3DXBUFFER m_pBuffMat; //マテリアル情報
	DWORD m_dwNumMat; //マテリアル数

	D3DXCOLOR m_col; //カラーの値
};
#endif