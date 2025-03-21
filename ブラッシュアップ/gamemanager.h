//=============================================
//
//ゲームマネージャーのヘッダー[gamemaneger.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _GAMEMANAGER_H_	//これが定義されてないとき
#define _GAMEMANAGER_H_	//二重マクロ防止

//ヘッダーのインクルード
#include "player.h"

//ゲームマネージャークラス
class CGameManager
{
private:

	//メンバ関数
	CGameManager();		//コンストラクタ

public:

	//関数
	~CGameManager();	//デストラクタ

	static CGameManager* GetInstance()	//インスタンスの生成
	{
		//静的インスタンス
		static CGameManager instance;	
		return &instance;
	}

	void SetPlayer(CPlayer* player) { m_pPlayer = player; }	//プレイヤーの設定
	CPlayer* GetPlayer() { return m_pPlayer; }				//プレイヤーの取得

private:

	//変数
	CPlayer* m_pPlayer;
};

#endif