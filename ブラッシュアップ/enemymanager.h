//=============================================
//
//エネミーマネージャー用ヘッダー[enemymanager.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ENEMYMANAGER_H_	//これが定義されてないとき
#define _ENEMYMANAGER_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "enemy.h"

//エネミーマネージャークラス
class CEnemyManager
{
public:

	//関数
	CEnemyManager();					//コンストラクタ
	~CEnemyManager();					//デストラクタ
	HRESULT Init();						//初期化
	void Uninit();						//終了処理
	void Regist(CEnemy* enemy);			//登録
	void Delete(CEnemy* enemy);			//削除

private:

	//変数
	std::list<CEnemy*> m_EnemyList;	//敵のリスト

};
#endif