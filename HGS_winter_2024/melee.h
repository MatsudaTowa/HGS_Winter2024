//=============================================
//
//3DTemplate[melee.h]
//Auther Matsuda Towa
//
//=============================================
#include "main.h"
#include "billboard.h"


#ifndef _MELEE_H_ //これが定義されてないとき

#define _MELEE_H_

class CMelee:public CObject3D
{
public:
	CMelee(int nPriority = 5);
	~CMelee()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	//近接作成
	static CMelee* Create(D3DXVECTOR3 pos, float fRadius);
private:
	float m_fRadius;
};

#endif