//=============================================
//
//�Q�[�W����[hpgauge.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_GAUGE_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _EXP_GAUGE_H_
#include "main.h"
#include "gauge.h"

//2D�I�u�W�F�N�g�N���X
class CExpGauge : public CGauge_2D
{
public:
	CExpGauge(int nPriority = 25) :CGauge_2D(nPriority) {};
	~CExpGauge()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
private:
};
#endif