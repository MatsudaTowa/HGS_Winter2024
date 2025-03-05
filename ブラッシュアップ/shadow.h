//=============================================
//
//影「shadow.h」
// Author松田永久
//
//=============================================
#ifndef _SHADOW_H_ //これが定義されてないとき

#define _SHADOW_H_
#include "main.h"
#include "object3D.h"

//レンダラークラス
class CShadow : public CObject3D
{
public:
	static const int SHADOW_PRIORITY = 9; //描画順

	CShadow(int nPriority = SHADOW_PRIORITY);
	~CShadow()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CShadow* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);
private:
	static const std::string TEXTURE_NAME;	//テクスチャの名前
};
#endif