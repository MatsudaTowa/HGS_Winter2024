//=============================================
//
//3DTemplate[kerosene.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _KEROSENE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _KEROSENE_H_
#include "main.h"
#include "object3D.h"

class CKerosene : public CObject3D
{
public:

	//�萔
	static constexpr int TIME_END{ 60 };
	static constexpr float SIZE_RADIUS{ 50.0f };

	CKerosene(int nPriority);
	~CKerosene()override;
	HRESULT Init() override;
	void Update() override;

	static CKerosene* Create(D3DXVECTOR3 pos);

private:

	static const std::string TEXTURE_NAME;	//�e�N�X�`���̖��O

	int m_nCount;
};


#endif