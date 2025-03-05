//=============================================
//
//マスク処理[mask.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MASK_H_ //これが定義されてないとき

#define _MASK_H_
#include "main.h"
#include "scene.h"
#include "object2D.h"

//マスククラス
class CMask : public CObject2D
{
public:
	static const int MASK_PRIORITY = 12;  //描画順

	CMask(int nPriority = MASK_PRIORITY);
	~CMask()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static CMask* Create();
private:
};
#endif