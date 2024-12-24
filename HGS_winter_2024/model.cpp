//=============================================
//
//3DTemplate[model.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "model.h"
#include "manager.h"

//=============================================
//コンストラクタ
//=============================================
CModel::CModel()
{
	//モデル情報初期化
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		m_ModelInfo[nCnt].pBuffMat = nullptr;
		m_ModelInfo[nCnt].pMesh = nullptr;
		m_ModelInfo[nCnt].dwNumMat = 0;
	}

	m_nNumAll = 0;
}

//=============================================
//デストラクタ
//=============================================
CModel::~CModel()
{
}

//=============================================
//モデル破棄
//=============================================
void CModel::Unload()
{
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		if (m_ModelInfo[nCnt].pBuffMat != nullptr)
		{//マテリアル破棄
			m_ModelInfo[nCnt].pBuffMat->Release();
			m_ModelInfo[nCnt].pBuffMat = nullptr;
			m_ModelInfo[nCnt].dwNumMat = 0;
		}
		if (m_ModelInfo[nCnt].pMesh != nullptr)
		{//メッシュ破棄
			m_ModelInfo[nCnt].pMesh->Release();
			m_ModelInfo[nCnt].pMesh = nullptr;
		}

		if (m_ModelInfo[nCnt].ModelName != nullptr)
		{//モデルネーム破棄
			m_ModelInfo[nCnt].ModelName = nullptr;
		}
	}
	m_nNumAll = 0;
}

//=============================================
//モデル登録
//=============================================
int CModel::Regist(const char* pModel)
{
	int nIdx = 0;
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		if (m_ModelInfo[nCnt].pBuffMat == nullptr
			&& m_ModelInfo[nCnt].pMesh == nullptr)
		{
			LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

			//Xファイルの読み込み
			D3DXLoadMeshFromX(pModel,
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&m_ModelInfo[nCnt].pBuffMat,
				NULL,
				&m_ModelInfo[nCnt].dwNumMat,
				&m_ModelInfo[nCnt].pMesh);

			//引数のファイルパスを保存
			m_ModelInfo[nCnt].ModelName = pModel;
			nIdx = nCnt;	//番号の保存
			m_nNumAll++;	//総数のカウントアップ
			break;
		}
		if (strcmp(m_ModelInfo[nCnt].ModelName, pModel) == 0)
		{//引数のモデルが存在するなら
		
			//番号を代入してbreak
			nIdx = nCnt;
			break;
		}
	}
	return nIdx;
}

//=============================================
//モデル情報取得
//=============================================
CModel::MODEL_INFO CModel::GetModelInfo(int nIdx)
{
	return m_ModelInfo[nIdx];
}

