//=============================================
//
//3DTemplate[light.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "light.h"
#include "renderer.h"
#include "manager.h"

//=============================================
//コンストラクタ
//=============================================
CLight::CLight()
{
	//ライト情報のクリア
	ZeroMemory(&m_aLight[0], sizeof(D3DLIGHT9));
}

//=============================================
//デストラクタ
//=============================================
CLight::~CLight()
{
}

//=============================================
//初期化
//=============================================
HRESULT CLight::Init()
{
	//CRenderer* pRender = CManager::GetRenderer();
	//LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	D3DXVECTOR3 vecDir; //設定方向ベクトル

	for (int nCnt = 0; nCnt < MAX_LIGHT; nCnt++)
	{
		//ライトの種類を設定
		m_aLight[nCnt].Type = D3DLIGHT_DIRECTIONAL;

		//ライトの拡散光の設定
		m_aLight[nCnt].Diffuse = COLOR_WHITE;

		if (nCnt == 0)
		{
			//ライトの方向を設定
			vecDir = D3DXVECTOR3(0.2f, -0.8f, 0.4f);
		}
		else if (nCnt == 1)
		{
			//ライトの方向を設定
			vecDir = D3DXVECTOR3(0.2f, 0.8f, 0.4f);
		}
		else if (nCnt == 2)
		{
			//ライトの方向を設定
			vecDir = D3DXVECTOR3(-0.7f, -0.8f, -0.4f);
		}



		D3DXVec3Normalize(&vecDir, &vecDir); //正規化

		m_aLight[nCnt].Direction = vecDir;

		//ライトを設定
		pDevice->SetLight(nCnt, &m_aLight[nCnt]);

		//ライトを有効化
		pDevice->LightEnable(nCnt, TRUE);
	}
	return S_OK;
}

//=============================================
//終了
//=============================================
void CLight::Uninit()
{
}

//=============================================
//更新
//=============================================
void CLight::Update()
{
}
