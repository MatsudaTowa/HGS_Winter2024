//=============================================
//
//ゲージ処理[hpgauge.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _HP_GAUGE_H_ //これが定義されてないとき

#define _HP_GAUGE_H_
#include "main.h"
#include "gauge.h"

//2Dオブジェクトクラス
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