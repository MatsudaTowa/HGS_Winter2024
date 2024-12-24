//=============================================
//
//スコア処理「scorer.h」
// Author松田永久
//
//=============================================
#ifndef _SCORE_H_ //これが定義されてないとき
#define _SCORE_H_
#include "main.h"
#include "object2D.h"
#include "number.h"

//=============================================
//スコアクラス
//=============================================
class CScore
{
public:
	CScore();
	virtual ~CScore();
	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();
	void AddScore(int nValue);
	void ExportScore(const std::string* pFileName); //スコア書き出し
	void Reset();

	int m_nScore; //スコアの値
	void SetScore(int nScore);

	void SetPos(D3DXVECTOR3 pos)
	{
		m_pos = pos;
	}

	void SetSize(D3DXVECTOR2 size)
	{
		m_size = size;
	}

	void SetDigitShift(float shift)
	{
		m_DigitShift = shift;
	}

	D3DXVECTOR3& GetPos();
	D3DXVECTOR2& GetSize();
	float& GetDigitShift();
private:
	static const int NUM_DIGIT = 6;  //桁数

	static const D3DXVECTOR3 NUM_POS; //数字の位置
	static const D3DXVECTOR2 NUM_SIZE; //数字のサイズ

	D3DXVECTOR3 m_pos;
	D3DXVECTOR2 m_size;
	CNumber_2D* m_pNumber[NUM_DIGIT];

	float m_DigitShift;
};
#endif // DEBUG