//=============================================
//
//3DTemplate[object2D.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _UI_SELECT_H_ //これが定義されてないとき

#define _UI_SELECT_H_
#include "object2D.h"

//2Dオブジェクトクラス
class CUi_Select : public CObject2D
{
public:
	CUi_Select(int nPriority = 97);
	~CUi_Select()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	//void Draw()override;

	static CUi_Select* Create(D3DXVECTOR3 pos, int num);

	int GetNum() { return m_nNum; }

private:

	static const std::string Path[9];
	static const D3DXVECTOR2 SIZE;

	int m_nNum;

};
#endif