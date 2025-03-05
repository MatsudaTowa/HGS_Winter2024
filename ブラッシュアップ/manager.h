//=============================================
//
//3DTemplate[maneger.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MANAGER_H_ //これが定義されてないとき

#define _MANAGER_H_
#include "main.h"
#include "input.h"
#include "camera.h"
#include "light.h"
#include "texture.h"
#include "model.h"
#include "scene.h"
#include "fade.h"
#include "sound.h"
class CManager
{
public:
	static const int NUM_RESULT_FILE = 4;
	static const std::string RESULT_SCORE_FILE[NUM_RESULT_FILE]; //リザルトのファイルネーム

	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow);
	void Uninit();
	void Update();
	void Draw();

	//シーン設定
	void SetMode(CScene::MODE mode);

	static CManager* GetInstance()
	{
		static CManager instance; //静的インスタンス
		return &instance;
	}

	//シーン取得
	CScene* GetScene();
	//レンダラー取得
	CRenderer*GetRenderer();
	//キーボード情報取得
	CInputKeyboard* GetKeyboard();
	//マウス情報取得
	CInputMouse* GetMouse();
	//pad情報取得
	CInputPad* GetPad();
	//カメラ取得
	CCamera* GetCamera();
	//ライト取得
	CLight* GetLight();
	//テクスチャ取得
	CTexture* GetTexture();
	//モデル取得
	CModel* GetModel();
	//サウンド取得
	CSound* GetSound();
	//フェード取得
	CFade* GetFade();
private:

	CScene* m_pScene; //現在のシーン
	//static CFade* m_pFade;
	CRenderer* m_pRenderer;
	CInputKeyboard* m_pKeyboard;
	CInputMouse* m_pMouse;
	CInputPad* m_pPad;
	CCamera* m_pCamera;
	CLight* m_pLight;
	CTexture* m_pTexture;
	CModel* m_pModel;
	CSound* m_pSound;
	CFade* m_pFade;

};

#endif