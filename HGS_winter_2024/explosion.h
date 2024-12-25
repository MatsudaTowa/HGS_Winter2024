//=============================================
//
//3DTemplate[explosion.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXPLOSION_H_ //���ꂪ��`����ĂȂ��Ƃ�

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

	//����
	static CExplosion* Create(D3DXVECTOR3 pos);

private:

	int m_nLife;
};
#endif