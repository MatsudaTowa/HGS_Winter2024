//=============================================
//
//ゲームマネージャーの処理[gamemanager.cpp]
//Auther Yuuto Shimadu
//
//=============================================

//ヘッダーのインクルード
#include "gamemanager.h"

//=====================================================
//コンストラクタ
//=====================================================
CGameManager::CGameManager() :
	m_pPlayer(nullptr),			//プレイヤーのポインタ
	m_pEnemyManager(nullptr)	//エネミーマネージャーのポインタ
{
	//エネミーマネージャの生成
	if (m_pEnemyManager == nullptr)
	{
		m_pEnemyManager = new CEnemyManager();	//メモリの確保
		m_pEnemyManager->Init();				//初期化
	}
}

//=====================================================
//デストラクタ
//=====================================================
CGameManager::~CGameManager()
{
	//エネミーマネージャの破棄
	if (m_pEnemyManager != nullptr)
	{
		m_pEnemyManager->Uninit();	//終了処理
		delete m_pEnemyManager;		//破棄
	}
}