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
	CLevelupSelect() : m_pSelect(), m_nSelect(0){}		//コンストラクタ
	~CLevelupSelect() {}	//デストラクタ

	void Init() {}	//初期化
	void Update(); //更新

	static CLevelupSelect* Create();	//生成

private:
	
	CUi_Select* m_pSelect[3];
	int m_nSelect;
};
#endif