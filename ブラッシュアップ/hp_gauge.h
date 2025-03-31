//=============================================
//
//�Q�[�W����[hpgauge.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _HP_GAUGE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _HP_GAUGE_H_
#include "main.h"
#include "gauge.h"

//2D�I�u�W�F�N�g�N���X
class CHpGauge : public CGauge_2D
{
public:
	enum GAUGE_TYPE
	{
		GAUGE_LIFE = 0,
		GAUGE_EXP,
		GAUGE_MAX,
	};

	CHpGauge(int nPriority = 25) :CGauge_2D(nPriority) {};
	~CHpGauge()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
};
#endif