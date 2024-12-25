//=============================================
//
//3DTemplate[movebillboard.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "movebillboard.h"
#include "manager.h"

//=============================================
//コンストラクタ
//=============================================
CMoveBillboard::CMoveBillboard(int priority) : CBillboard(priority)
{
}

//=============================================
//デストラクタ
//=============================================
CMoveBillboard::~CMoveBillboard()
{
}

//=============================================
//初期化
//=============================================
HRESULT CMoveBillboard::Init()
{
	//初期化
	CBillboard::Init();
	m_Move = VEC3_RESET_ZERO;

	return S_OK;
}

//=============================================
//更新
//=============================================
void CMoveBillboard::Update()
{
	//移動量を追加
	D3DXVECTOR3 Pos = GetPos();
	Pos += m_Move;
	SetPos(Pos);
}