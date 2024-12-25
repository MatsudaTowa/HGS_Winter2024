//=============================================
//
//3DTemplate[object.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "object.h"
#include "object2D.h"
#include "object3D.h"

//総数初期化
int CObject::m_nNumAll = 0;

//オブジェクトポインタ初期化
CObject* CObject::m_apObject[MAX_PRIORITY][CObject::MAX_OBJECT] = {};
CObject* CObject::m_pCur[MAX_PRIORITY] = { nullptr };			//最後尾のポインタの初期化
CObject* CObject::m_pTop[MAX_PRIORITY] = { nullptr };			//最初のポインタの初期化

//=============================================
//コンストラクタ
//=============================================
CObject::CObject(int nPriority) :
	m_bDeath(false)
{
	m_nPriority = nPriority; //描画優先度設定

	//for (int nCnt = 0; nCnt < CObject::MAX_OBJECT; nCnt++)
	//{
	//	if (m_apObject[m_nPriority][nCnt] == nullptr)
	//	{
	//		m_apObject[m_nPriority][nCnt] = this; //自分自身を代入
	//		m_nID = nCnt; //ID代入
	//		m_type = OBJECT_TYPE_NONE;
	//		m_nNumAll++; //総数増加
	//		break;
	//	}
	//}

	CObject* pObj = this;				//自身のポインタを取得
	m_nNumAll++;						//総数をカウント

	pObj->m_pPrev = m_pCur[nPriority];	//自分の前のオブジェクトポインタを取得

	//初めてのオブジェクトなら静的メンバに代入
	if (m_pTop[nPriority] == nullptr)
	{
		m_pTop[nPriority] = pObj;	//最初のオブジェクトのポインタ
		m_pCur[nPriority] = pObj;	//最後尾のオブジェクトのポインタ
		m_pCur[nPriority]->m_pNext = nullptr;	//次のポインタを初期化
	}
	else
	{
		m_pCur[nPriority]->m_pNext = pObj;	//現在の最後尾に次のポインタを設定
	}

	pObj->m_pNext = nullptr;			//次のポインタを初期化
	m_pCur[nPriority] = pObj;			//最後尾を更新
	m_bDeath = false;					//死亡フラグの初期化
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
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{

	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			if (m_apObject[nCntPri][nCntObj]->m_type != CObject::OBJECT_TYPE::OBJECT_TYPE_FADE)
	//			{
	//				//終了処理
	//				m_apObject[nCntPri][nCntObj]->Uninit();
	//				m_apObject[nCntPri][nCntObj] = nullptr;
	//			}
	//		}
	//	}
	//}

	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = m_pTop[i];	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//次のポインタを取得

			if (pObj->m_type != CObject::OBJECT_TYPE::OBJECT_TYPE_FADE)
			{
				pObj->Release();				//開放処理
			}
			
			pObj = pNext;					//ポインタを進める
		}

		//静的ポインタ変数の初期化
		m_pTop[i] = nullptr;
		m_pCur[i] = nullptr;
	}
}

//=============================================
//全更新
//=============================================
void CObject::UpdateAll()
{
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{
	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			//更新処理
	//			m_apObject[nCntPri][nCntObj]->Update();
	//		}
	//	}
	//}

	//変数の宣言
	CObject* pObj = nullptr;

	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		pObj = m_pTop[i];	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//次のポインタを取得

			pObj->Update();					//更新処理

			pObj = pNext;					//ポインタを進める
		}
	}

	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		pObj = m_pTop[i];	//先頭取得

	//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//次のポインタを取得

			//死亡フラグが立っていたらRelease
			if (pObj->m_bDeath)
			{
				pObj->Release();
			}

			pObj = pNext;	//ポインタを進める
		}
	}
}

//=============================================
//全描画
//=============================================
void CObject::DrawAll()
{
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{
	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			//終了処理
	//			m_apObject[nCntPri][nCntObj]->Draw();
	//		}
	//	}
	//}

	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = m_pTop[i];	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//次のポインタを取得
			pObj->Draw();					//更新処理
			pObj = pNext;					//ポインタを進める
		}
	}
}


//=============================================
//自分自身の削除
//=============================================
void CObject::Release()
{
	/*int nID = m_nID;
	int nPri = m_nPriority;
	if (m_apObject[nPri][nID] != nullptr)
	{
		delete m_apObject[nPri][nID];
		m_apObject[nPri][nID] = nullptr;
	}*/

	//変数に代入
	int nPriority = m_nPriority;

	//nullチェック
	if (this != nullptr)
	{
		CObject* pObj = this;					//自身のポインタを取得

		if (pObj->m_pPrev != nullptr)
		{
			pObj->m_pPrev->m_pNext = pObj->m_pNext;	//自身の前後を繋ぐ
		}

		if (pObj->m_pNext != nullptr)
		{
			pObj->m_pNext->m_pPrev = pObj->m_pPrev;	//自身の前後を繋ぐ
		}

		//最後尾が現在のポインタなら前のポインタに更新
		if (pObj == m_pCur[nPriority])
		{
			m_pCur[nPriority] = pObj->m_pPrev;	//ポインタの変更
		}

		//最初が現在のポインタなら次のポインタに更新
		if (pObj == m_pTop[nPriority])
		{
			m_pTop[nPriority] = pObj->m_pNext;	//ポインタの変更
		}

		//リストから削除
		delete pObj;
		pObj = nullptr;
		//m_nNumAll--;
	}
}

//=============================================
//オブジェクト取得
//=============================================
CObject* CObject::Getobject(int nPri, int nIdx)
{
	return m_apObject[nPri][nIdx];
}

//=============================================
//オブジェクト取得
//=============================================
CObject* CObject::Getobject(int nPri)
{
	return m_pTop[nPri];
}

//=============================================
//タイプ取得
//=============================================
CObject::OBJECT_TYPE CObject::GetType()
{
	return m_type;
}

//=============================================
//タイプ設定
//=============================================
void CObject::SetType(OBJECT_TYPE type)
{
	m_type = type;
}

