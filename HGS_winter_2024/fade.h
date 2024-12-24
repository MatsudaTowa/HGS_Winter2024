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
	typedef enum
	{
		FADE_NONE = 0, //何もしていない状態
		FADE_IN, //フェードイン
		FADE_OUT, //フェードアウト
		FADE_MAX,
	}FADE;

	//static const std::string TEXTURE_NAME;	//テクスチャの名前
	static const int FADE_PRIORITY = 98;  //描画順
	static const float FADE_VALUE;  //アルファ値減衰量

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
	//static LPDIRECT3DTEXTURE9 m_pTexture;
	FADE m_fade;
	CScene::MODE m_fademode;
	float m_colorFade;
};
#endif