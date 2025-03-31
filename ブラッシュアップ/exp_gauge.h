//=============================================
//
//ゲージ処理[hpgauge.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_GAUGE_H_ //これが定義されてないとき

#define _EXP_GAUGE_H_
#include "main.h"
#include "gauge.h"

//2Dオブジェクトクラス
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