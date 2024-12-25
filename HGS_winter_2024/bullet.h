//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _BULLET_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _BULLET_H_
#include "main.h"
#include "movebillboard.h"

class CBullet : public CMoveBillboard
{
public:

	static constexpr float SIZE_RADIUS{ 10.0f };
	static constexpr int LIFE{ 300 };
	static constexpr float SPEED{ 10.0f };

	CBullet(int nPriority);
	~CBullet() override;
	HRESULT Init() override;
	void Update() override;

	//����
	static CBullet* Create(D3DXVECTOR3 pos, float angle);

private:

	static const std::string TEXTURE_NAME;	//�e�N�X�`���̖��O

	int m_nLife;
};
#endif