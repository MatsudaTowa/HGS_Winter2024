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
#include "score.h"
#include "levelupselect.h"
#include "timer.h"

class CGame:public CScene
{
public:
	static const int DELAY_CNT = 30; //リザルトに飛ぶまでのディレイ
	CGame();
	~CGame() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:
	static const D3DXVECTOR3 FIELD_SIZE; //フィールドサイズ
	int m_nResultDelay; //リザルトへのディレイ
	void LoadBlock(const std::string* pFileName);

	CTimer* m_pTimer;
	CLevelupSelect* m_pLevelupSelect;
};
#endif