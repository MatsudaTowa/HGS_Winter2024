//=============================================
//
//3DTemplate[scene.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _SCENE_H_ //これが定義されてないとき

#define _SCENE_H_
#include "main.h"

//=============================================
//  クラス定義
//=============================================
class CScene
{
public:

	//画面の種類の列挙
	enum MODE
	{
		MODE_TITLE = 0,
		MODE_GAME,
		MODE_RESULT,
		MODE_MAX,
	};

	// メンバ関数
	CScene();
	virtual ~CScene();

	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();

	static CScene* Create(MODE mode);
	static MODE GetSceneMode();
private:

	// メンバ変数
	static MODE m_Mode; //現在のモード
};
#endif