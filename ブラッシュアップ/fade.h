//=============================================
//
//フェード処理[fade.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _FADE_H_ //これが定義されてないとき

#define _FADE_H_
#include "main.h"
#include "scene.h"
#include "object2D.h"

//fadeクラス
class CFade : public CObject2D
{
public:
	//フェードの状態
	enum FADE
	{
		FADE_NONE = 0, //何もしていない状態
		FADE_IN, //フェードイン
		FADE_OUT, //フェードアウト
		FADE_MAX,
	};

	static const int FADE_PRIORITY = 29;  //描画順

	CFade(int nPriority = FADE_PRIORITY);
	~CFade()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	void SetFade(CScene::MODE modeNext);

	//static FADE GetFade(void);
	float FadeColor(void);
	static CFade* Create(D3DXVECTOR3 pos);
private:
	static constexpr float FADE_VALUE = 0.05f;  //アルファ値減衰量
	FADE m_fade;
	CScene::MODE m_fademode;
	float m_colorFade;
};
#endif