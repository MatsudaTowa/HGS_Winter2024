//=============================================
//
//3DTemplate[object.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include  "manager.h"

//総数初期化
int CObject::m_nNumAll = 0;

//オブジェクトポインタ初期化
CObject* CObject::m_apObject[CObject::PRI_MAX][CObject::MAX_OBJECT] = {};

//=============================================
//コンストラクタ
//=============================================
CObject::CObject(int nPriority):m_isDraw(true)
{
	m_nPriority = nPriority; //描画優先度設定

	for (int nCnt = INT_ZERO; nCnt < CObject::MAX_OBJECT; nCnt++)
	{
		if (m_apObject[m_nPriority][nCnt] == nullptr)
		{
			m_apObject[m_nPriority][nCnt] = this; //自分自身を代入
			m_nID = nCnt; //ID代入
			m_type = OBJECT_TYPE_NONE;
			m_nNumAll++; //総数増加
			break;
		}
	}
}


//=============================================
//デストラクタ
//=============================================
CObject::~CObject()
{
	m_nNumAll--;
}

//=============================================
//全削除
//=============================================
void CObject::ReleaseAll()
{
	for (int nCntPri = INT_ZERO; nCntPri < CObject::PRI_MAX; nCntPri++)
	{
		for (int nCntObj = INT_ZERO; nCntObj < CObject::MAX_OBJECT; nCntObj++)
		{
			if (m_apObject[nCntPri][nCntObj] == nullptr)
			{
				continue;
			}
			
			if (m_apObject[nCntPri][nCntObj]->m_type != CObject::OBJECT_TYPE::OBJECT_TYPE_FADE)
			{
				//終了処理
				m_apObject[nCntPri][nCntObj]->Uninit();
				m_apObject[nCntPri][nCntObj] = nullptr;
			}
			
		}
	}
}

//=============================================
//全更新
//=============================================
void CObject::UpdateAll()
{
	for (int nCntPri = INT_ZERO; nCntPri < CObject::PRI_MAX; nCntPri++)
	{
		for (int nCntObj = INT_ZERO; nCntObj < CObject::MAX_OBJECT; nCntObj++)
		{
			if (m_apObject[nCntPri][nCntObj] == nullptr)
			{
				continue;
			}

			//更新処理
			m_apObject[nCntPri][nCntObj]->Update();
			
		}
	}
}

//=============================================
//全描画
//=============================================
void CObject::DrawAll()
{
	for (int nCntPri = INT_ZERO; nCntPri < CObject::PRI_MAX; nCntPri++)
	{
		for (int nCntObj = INT_ZERO; nCntObj < CObject::MAX_OBJECT; nCntObj++)
		{
			if (m_apObject[nCntPri][nCntObj] == nullptr)
			{
				continue;
			}

			if (m_apObject[nCntPri][nCntObj]->GetisDraw())
			{//描画するものは
				//描画処理
				m_apObject[nCntPri][nCntObj]->Draw();
			}

			
		}
	}
}


//=============================================
//自分自身の削除
//=============================================
void CObject::Release()
{
	int nID = m_nID;
	int nPri = m_nPriority;
	if (m_apObject[nPri][nID] != nullptr)
	{

		delete m_apObject[nPri][nID];
		m_apObject[nPri][nID] = nullptr;
	}
}

//=============================================
//オブジェクト取得
//=============================================
CObject* CObject::Getobject(int nPri, int nIdx)
{
	return m_apObject[nPri][nIdx];
}