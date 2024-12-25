//=============================================
//
//3DTemplate[bullet001.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _BULLET001_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _BULLET001_H_
#include "main.h"
#include "movebillboard.h"

class CBullet001 : public CMoveBillboard
{
public:

	static constexpr float SIZE_RADIUS{ 10.0f };
	static constexpr int LIFE{ 300 };
	static constexpr float SPEED{ 10.0f };
	static constexpr float GRAVITY{ 0.1f };

	CBullet001(int nPriority);
	~CBullet001() override;
	HRESULT Init() override;
	void Update() override;

	//����
	static CBullet001* Create(D3DXVECTOR3 pos, float angle);

private:

	static const std::string TEXTURE_NAME;	//�e�N�X�`���̖��O

	int m_nLife;
	float m_fGravity;
};
#endif