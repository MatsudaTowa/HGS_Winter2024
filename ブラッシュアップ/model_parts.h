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
	struct MODEL_INFO
	{
		LPD3DXMESH pMesh; //メッシュ情報
		LPD3DXBUFFER pBuffMat; //マテリアル情報
		DWORD dwNumMat; //マテリアル数;
		char* ModelName; //モデルネーム保存用
	};

	CModel_Parts();
	~CModel_Parts();
	void Unload(); //モデル破棄
	void BindXFile(LPD3DXBUFFER pBuffMat, DWORD dwNumMat, LPD3DXMESH pMesh);
	void Draw();
	void Draw(D3DXCOLOR col);

	void ConversionMtxWorld();

	//パーツ生成
	static CModel_Parts*Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot,char* pModel_Path);

	//ワールドマトリックスの代入
	inline void SetMtxWorld(D3DXMATRIX mtxWorld)
	{
		m_mtxWorld = mtxWorld;
	}

	inline void SetPos(D3DXVECTOR3 pos)
	{
		m_pos = pos;
	};

	inline void SetOldPos(D3DXVECTOR3 oldpos)
	{
		m_oldpos = oldpos;
	};

	inline void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	};

	inline D3DXVECTOR3 GetPos()
	{
		return m_pos;
	};

	inline D3DXVECTOR3 GetOldPos()
	{
		return m_oldpos;
	};

	inline D3DXVECTOR3 GetRot()
	{
		return m_rot;
	};

	inline D3DXVECTOR3 GetMin()
	{
		return m_minpos;
	}

	inline D3DXVECTOR3 GetMax()
	{
		return m_maxpos;
	}

	//親パーツの設定
	inline void SetParent(CModel_Parts*pParent)
	{
		m_pParent = pParent;
	}

	//ワールドマトリックス取得
	inline D3DXMATRIX& GetMtxWorld()
	{
		return m_mtxWorld;
	}

	//モデル情報取得
	inline MODEL_INFO GetModelInfo(int nIdx)
	{
		return m_ModelInfo[nIdx];
	}

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