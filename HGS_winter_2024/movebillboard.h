//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MOVEBILLBOARD_H_ //‚±‚ê‚ª’è‹`‚³‚ê‚Ä‚È‚¢‚Æ‚«

#define _MOVEBILLBOARD_H_
#include "main.h"
#include "billboard.h"

class CMoveBillboard : public CBillboard
{
public:

	CMoveBillboard(int nPriority);
	~CMoveBillboard() override;
	HRESULT Init() override;
	void Update() override;

	//ˆÚ“®—Ê
	void SetMove(D3DXVECTOR3 move) { m_Move = move; }	//İ’è
	D3DXVECTOR3& GetMove() { return m_Move;}			//æ“¾

private:

	D3DXVECTOR3 m_Move;	//ˆÚ“®—Ê

};
#endif