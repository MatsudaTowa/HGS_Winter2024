//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MOVEBILLBOARD_H_ //これが定義されてないとき

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

	//移動量
	void SetMove(D3DXVECTOR3 move) { m_Move = move; }	//設定
	D3DXVECTOR3& GetMove() { return m_Move;}			//取得

private:

	D3DXVECTOR3 m_Move;	//移動量

};
#endif