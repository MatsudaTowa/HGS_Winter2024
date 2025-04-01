//=============================================
//
//3DTemplate[levelupselect.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _LEVELUPSELECT_H_ //これが定義されてないとき
#define _LEVELUPSELECT_H_
#include "main.h"
#include "ui_select.h"

//クラス
class CLevelupSelect
{
public:
	CLevelupSelect() : m_pSelect(), m_nSelect(0), m_End(false) {}		//コンストラクタ
	~CLevelupSelect() {}	//デストラクタ

	void Init() {}	//初期化
	void Uninit();
	void Update(); //更新

	bool GetEnd() { return m_End; }
	int GetSelect() { return m_nSelect; }

	static CLevelupSelect* Create();	//生成

private:

	static const int NUM_SELECT = 3; //選択の数

	std::array<CUi_Select*, NUM_SELECT> m_pSelect;
	int m_nSelect;
	bool m_End;
};
#endif