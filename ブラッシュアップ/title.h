//=============================================
//
//3DTemplate[title.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _TITLE_H_ //‚±‚ê‚ª’è‹`‚³‚ê‚Ä‚È‚¢‚Æ‚«

#define _TITLE_H_
#include "main.h"
#include "scene.h"
class CTitle :public CScene
{
public:
	CTitle();
	~CTitle() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
private:
};
#endif