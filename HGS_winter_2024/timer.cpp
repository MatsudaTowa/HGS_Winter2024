//=============================================
//
//タイマー処理「timer.cpp」
// Author松田永久
//
//=============================================
#include "timer.h"
#include "manager.h"

//桁ごとにずらす
const float CTimer::DIGIT_SHIFT = 50.0f;

//=============================================
//コンストラクタ
//=============================================
CTimer::CTimer() :m_nFrameCnt(0), m_nCurrentTime(0), m_pos(D3DXVECTOR3(0.0f, 0.0f, 0.0f))
{//イニシャライザーでカウンターと,今の時間pos初期化

	//タイマー
	m_nCurrentTime = CTimer::LIMIT_TIME;
	//初期位置代入
	m_pos = D3DXVECTOR3(660.0f, 50.0f, 0.0f);

	//最初からセットするため
	//m_nFrameCnt = 60;

	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		m_pNumber[nCnt] = nullptr;
	}
}

//=============================================
//デストラクタ
//=============================================
CTimer::~CTimer()
{
}

//=============================================
//初期化
//=============================================
HRESULT CTimer::Init()
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//ナンバー生成
		/*if (m_pNumber[nCnt] == nullptr)
		{
			m_pNumber[nCnt] = new CNumber();
		}*/

		if (m_pNumber[nCnt] == nullptr)
		{
			m_pNumber[nCnt] = CNumber_2D::Create(m_pos, D3DXVECTOR2(30.0f, 50.0f));
		}

		//座標をずらす
		m_pos.x -= DIGIT_SHIFT;
	}

	return S_OK;
}

//=============================================
//終了
//=============================================
void CTimer::Uninit()
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		if (m_pNumber[nCnt] != nullptr)
		{
			m_pNumber[nCnt]->Uninit();
			//delete m_pNumber[nCnt];
			m_pNumber[nCnt] = nullptr;
		}
	}
}

//=============================================
//更新
//=============================================
void CTimer::Update()
{
	SetTimer();

	m_nFrameCnt++;

	if (m_nFrameCnt >= 60)
	{
		m_nCurrentTime--;
		m_nFrameCnt = 0;
	}

	if (m_nCurrentTime <= 0)
	{
		m_nCurrentTime = 0;
		CManager::GetInstance()->SetMode(CScene::MODE::MODE_RESULT);
	}
	////頂点設定
	//SetTimerVtx();
}


//=============================================
//タイマー用の頂点生成
//=============================================
void CTimer::SetTimer()
{
	//テクスチャ座標設定
	int a_PosTexU[NUM_DIGIT];

	//現在計算してる桁
	int nDigit = 1;
	int nCnt;
	for (nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//今の時間から計算
		a_PosTexU[nCnt] = m_nCurrentTime / nDigit % 10;

		//桁を進める
		nDigit *= 10;
	}

	for (nCnt = NUM_DIGIT - 1; nCnt >= 0; nCnt--)
	{
		//テクスチャの座標計算用変数
		float fMinTexU, fMaxTexU;

		fMinTexU = a_PosTexU[nCnt] * 0.1f;
		fMaxTexU = fMinTexU + 0.1f;

		m_pNumber[nCnt]->SetNumber(fMinTexU, fMaxTexU, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	}
}