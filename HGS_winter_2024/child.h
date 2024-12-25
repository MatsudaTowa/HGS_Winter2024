//=============================================
//
//3DTemplate[child.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CHILD_H_ //これが定義されてないとき

#define _CHILD_H_
#include "main.h"
#include "objectX.h"

//子供クラス
class CChild : public CObjectX
{
public:

	CChild(int nPriority = 3);
	~CChild()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	//プレイヤー作成
	static CChild* Create(D3DXVECTOR3 pos);
};
#endif