//=============================================
//
//3DTemplate[game.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _GAME_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _GAME_H_
#include "main.h"
#include "scene.h"
#include "score.h"
#include "levelupselect.h"
#include "timer.h"

class CGame:public CScene
{
public:
	static const int DELAY_CNT = 30; //���U���g�ɔ�Ԃ܂ł̃f�B���C
	CGame();
	~CGame() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:
	static const D3DXVECTOR3 FIELD_SIZE; //�t�B�[���h�T�C�Y
	int m_nResultDelay; //���U���g�ւ̃f�B���C
	void LoadBlock(const std::string* pFileName);

	CTimer* m_pTimer;
	CLevelupSelect* m_pLevelupSelect;
};
#endif