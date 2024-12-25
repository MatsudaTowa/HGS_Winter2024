//=============================================
//
//タイマー処理「timer.h」
// Author松田永久
//
//=============================================
#ifndef _TIMER_H_ //これが定義されてないとき
#define _TIMER_H_
#include "main.h"
#include "object2D.h"
#include "number.h"

//=============================================
//タイマークラス
//=============================================
class CTimer
{
public:
	static const int LIMIT_TIME = 120;  //制限時間
	static const int NUM_DIGIT = 3;  //桁数
	static const float DIGIT_SHIFT;  //桁ごとに座標をずらす

	CTimer();
	~CTimer();
	HRESULT Init();
	void Uninit();
	void Update();

private:
	void SetTimer();
	int m_nFrameCnt; //何フレーム経ったかカウントする変数
	int m_nCurrentTime; //今の時間
	D3DXVECTOR3 m_pos;
	CNumber_2D* m_pNumber[NUM_DIGIT];
};

#endif // DEBUG