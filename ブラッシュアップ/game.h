//=============================================
//
//3DTemplate[game.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _GAME_H_ //これが定義されてないとき

#define _GAME_H_
#include "main.h"
#include "scene.h"

class CGame:public CScene
{
public:

	static const int DELAY_CNT = 30; //リザルトに飛ぶまでのディレイ
	static const int BLOCK_TXT_MAX = 2048; //敵を読み込む際の読み込める最大文字数
	CGame();
	~CGame() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void UpdateObjectDecision(bool bStop); //オブジェクトの更新を行うか決定
	void Draw() override;

	inline bool GetPause() { return m_bPause; }
	inline void SetPause() { m_bPause = m_bPause ? false : true; }
private:
	static const D3DXVECTOR3 FIELD_SIZE; //フィールドサイズ
	bool m_bPause;	//ポーズ中か
};
#endif