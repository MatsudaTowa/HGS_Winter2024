//=============================================
//
//3DTemplate[explosion.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXPLOSION_H_ //Ç±ÇÍÇ™íËã`Ç≥ÇÍÇƒÇ»Ç¢Ç∆Ç´

#define _EXPLOSION_H_
#include "main.h"
#include "billboard.h"

class CExplosion : public CBillboard
{
public:

	static constexpr float SIZE_RADIUS{ 10.0f };
	static constexpr int LIFE{ 30 };

	CExplosion(int nPriority);
	~CExplosion() override;
	HRESULT Init() override;
	void Update() override;

	//ê∂ê¨
	static CExplosion* Create(D3DXVECTOR3 pos);

private:

	int m_nLife;
};
#endif