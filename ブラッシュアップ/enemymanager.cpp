//=============================================
//
//エネミーマネージャーの処理[enemymanager.cpp]
//Auther Matsuda Towa
//
//=============================================

//インクルード
#include "enemymanager.h"

//=============================================
//コンストラクタ
//=============================================
CEnemyManager::CEnemyManager() :
	m_EnemyList()
{
	//リストのクリア
	m_EnemyList.clear();
}

//=============================================
//デストラクタ
//=============================================
CEnemyManager::~CEnemyManager()
{

}

//=============================================
//初期化
//=============================================
HRESULT CEnemyManager::Init()
{
	//リストのクリア
	m_EnemyList.clear();

	return S_OK;
}

//=============================================
//終了
//=============================================
void CEnemyManager::Uninit()
{
	//リストのクリア
	m_EnemyList.clear();
}

//=============================================
//登録
//=============================================
void CEnemyManager::Regist(CEnemy* enemy)
{
	//登録済みか
	bool bRegisted = false;

	//同じものが無いかを確認
	for (auto itr : m_EnemyList)
	{
		if (itr == enemy)
		{
			bRegisted = true;
			break;
		}
	}

	//登録されているなら抜ける
	if (bRegisted)
	{
		return;
	}

	//敵の情報を登録
	m_EnemyList.push_back(enemy);
}

//=============================================
//削除
//=============================================
void CEnemyManager::Delete(CEnemy* enemy)
{
	//サイズが0なら抜ける
	if (m_EnemyList.size() == 0)
	{
		return;
	}

	//登録済みか
	bool bRegisted = false;

	//同じものが無いかを確認
	for (auto itr : m_EnemyList)
	{
		if (itr == enemy)
		{
			bRegisted = true;
			break;
		}
	}

	//登録されていないなら抜ける
	if (!bRegisted)
	{
		return;
	}

	//エネミーの情報を削除
	m_EnemyList.remove(enemy);
}