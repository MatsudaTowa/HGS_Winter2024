//=============================================
// 
//親子関係のパーツ[model.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MODEL_PARTS_H_ //これが定義されてないとき

#define _MODEL_PARTS_H_
#include "main.h"
#include "objectX.h"

class CModel_Parts
{
public:
	static const int MAX_MODEL = 256; //モデルの数

	//モデル情報構造体定義
	typedef struct
	{
		LPD3DXMESH pMesh; //メッシュ情報
		LPD3DXBUFFER pBuffMat; //マテリアル情報
		DWORD dwNumMat; //マテリアル数;
		char* ModelName; //モデルネーム保存用
	}MODEL_INFO;

	CModel_Parts();
	~CModel_Parts();
	void Unload(); //モデル破棄
	void BindXFile(LPD3DXBUFFER pBuffMat, DWORD dwNumMat, LPD3DXMESH pMesh);
	void Draw();
	void Draw(D3DXCOLOR col);

	//パーツ生成
	static CModel_Parts*Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot,char* pModel_Path);

	//ワールドマトリックスの代入
	void SetMtxWorld(D3DXMATRIX mtxWorld)
	{
		m_mtxWorld = mtxWorld;
	}

	void SetPos(D3DXVECTOR3 pos)
	{
		m_pos = pos;
	};

	void SetOldPos(D3DXVECTOR3 oldpos)
	{
		m_oldpos = oldpos;
	};

	void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	};

	D3DXVECTOR3 GetPos()
	{
		return m_pos;
	};

	D3DXVECTOR3 GetOldPos()
	{
		return m_oldpos;
	};

	D3DXVECTOR3 GetRot()
	{
		return m_rot;
	};

	D3DXVECTOR3 GetMin()
	{
		return m_minpos;
	}

	D3DXVECTOR3 GetMax()
	{
		return m_maxpos;
	}
	void SetParent(CModel_Parts*pParent);

	//ワールドマトリックス取得
	D3DXMATRIX& GetMtxWorld();

	MODEL_INFO GetModelInfo(int nIdx); //モデル情報取得

	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_Tpos;
	D3DXVECTOR3 m_Trot;
	int m_nIdx; //何番目のパーツか
	int m_nIdxModelParent; //親のインデックス
private:
	LPDIRECT3DTEXTURE9 m_pTexture[256]; //テクスチャへのポインタ
	D3DXMATRIX m_mtxWorld; //ワールドマトリックス
	MODEL_INFO m_ModelInfo[MAX_MODEL]; //モデル情報

	D3DXVECTOR3 m_minpos; //pos最小値
	D3DXVECTOR3 m_maxpos; //pos最大値
	D3DXVECTOR3 m_oldpos;
	int m_nNumAll; //モデル総数

	CModel_Parts*m_pParent; //親パーツへのポインタ
};
#endif