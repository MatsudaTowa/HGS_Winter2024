//=============================================
//
//数字管理「number.h」
// Author松田永久
//
//=============================================
#ifndef _NUMBER_H_ //これが定義されてないとき
#define _NUMBER_H_
#include "main.h"
#include "object2D.h"
#include "billboard.h"

//=============================================
//ナンバークラス2D
//=============================================
class CNumber_2D:public CObject2D
{
public:
	static const int NUMBER_PRIORITY = 21;  //描画順
	CNumber_2D(int nPriority = NUMBER_PRIORITY);
	~CNumber_2D()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	//数字のポリゴン生成処理
	static CNumber_2D* Create(D3DXVECTOR3 pos ,D3DXVECTOR2 size);

	void SetNumber(float fNumPos1,float fNumPos2,D3DXCOLOR col);

	void NumberVtx();

private:
	static const std::string TEXTURE_NAME;	//テクスチャの名前

	D3DXVECTOR2 m_mintex; //テクスチャの最小座標
	D3DXVECTOR2 m_maxtex; //テクスチャの最大座標
	D3DXCOLOR m_col; //カラー
};

//=============================================
//ナンバークラス3D
//=============================================
class CNumber_3D :public CBillboard
{
public:
	static const int NUMBER_PRIORITY = 20;  //描画順
	CNumber_3D(int nPriority = NUMBER_PRIORITY);
	~CNumber_3D()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	//数字のポリゴン生成処理
	static CNumber_3D* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetNumber(float fNumPos1, float fNumPos2, D3DXCOLOR col);

	void NumberVtx();

private:
	static const std::string TEXTURE_NAME;	//テクスチャの名前

	D3DXVECTOR2 m_mintex; //テクスチャの最小座標
	D3DXVECTOR2 m_maxtex; //テクスチャの最大座標
	D3DXCOLOR m_col; //カラー
};

#endif // DEBUG