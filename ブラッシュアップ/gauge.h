//=============================================
//
//ゲージ処理[gauge.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _GAUGE_H_ //これが定義されてないとき

#define _GAUGE_H_
#include "main.h"
#include "object2D.h"

//2Dオブジェクトクラス
class CGauge_2D : public CObject2D
{
public:
	enum GAUGE_TYPE
	{
		GAUGE_LIFE = 0,
		GAUGE_EXP,
		GAUGE_MAX,
	};

	CGauge_2D(int nPriority = 25):CObject2D(nPriority) {};
	~CGauge_2D()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static CGauge_2D* Create(D3DXVECTOR3 pos, int Max, GAUGE_TYPE type);

	inline void SetValue(int value) { m_GaugeValue = value; }

	inline int& GetValue() { return m_GaugeValue; }
private:
	int m_GaugeValue, m_MaxGauge;	//ゲージ現在地 / 最大値

	void SetGaugeVtx();

};
#endif