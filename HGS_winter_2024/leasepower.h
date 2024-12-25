//=============================================
//
//3DTemplate[leasepower.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _LEASEPOWER_H_ //これが定義されてないとき

#define _LEASEPOWER_H_
#include "main.h"
#include "object3D.h"

class CLeasepower : public CObject3D
{
public:

	//定数
	static constexpr int TIME_END{ 60 };
	static constexpr float SIZE_RADIUS{ 100.0f };

	CLeasepower(int nPriority);
	~CLeasepower()override;
	HRESULT Init() override;
	void Update() override;
	void Draw() override;

	static CLeasepower* Create(D3DXVECTOR3 pos);

private:

	static const std::string TEXTURE_NAME;	//テクスチャの名前

	int m_nCount;
};


#endif