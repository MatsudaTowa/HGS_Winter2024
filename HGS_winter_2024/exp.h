//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_H_ //これが定義されてないとき
#define _EXP_H_
#include "main.h"
#include "objectX.h"

//経験値クラス
class CExp : public CObjectX
{
public:

	//経験値の種類
	typedef enum
	{
		EXP_TYPE_LOW = 0,
		EXP_TYPE_NORMAL,
		EXP_TYPE_HIGH,
		EXP_TYPE_MAX,
	}EXP_TYPE;

	//経験値の情報
	typedef struct
	{
		int Value;
		std::string Path;
	}ExpInfo;

	CExp(int nPriority);
	~CExp() override;
	HRESULT Init() override;
	void Update() override;
	static CExp* Create(D3DXVECTOR3 pos, EXP_TYPE type);

	//移動量
	void SetExp(int exp) { m_Info.Value = exp; }	//設定
	int& GetExp() { return m_Info.Value; }			//取得

private:

	static const ExpInfo Info[EXP_TYPE_MAX];

	//経験値
	ExpInfo m_Info;

};
#endif