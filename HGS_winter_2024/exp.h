//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_H_ //これが定義されてないとき
#define _EXP_H_
#include "main.h"
#include "movebillboard.h"

//経験値クラス
class CExp : public CMoveBillboard
{
public:

	CExp(int nPriority);
	~CExp() override;
	HRESULT Init() override;
	void Update() override;

	//移動量
	void SetExp(int exp) { m_Exp = m_Exp; }	//設定
	int& GetExp() { return m_Exp; }			//取得

private:

	//経験値
	int m_Exp;

};
#endif