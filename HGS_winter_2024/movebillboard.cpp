//=============================================
//
//3DTemplate[movebillboard.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "movebillboard.h"
#include "manager.h"

//=============================================
//�R���X�g���N�^
//=============================================
CMoveBillboard::CMoveBillboard(int priority) : CBillboard(priority)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CMoveBillboard::~CMoveBillboard()
{
}

//=============================================
//������
//=============================================
HRESULT CMoveBillboard::Init()
{
	//������
	CBillboard::Init();
	m_Move = VEC3_RESET_ZERO;

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CMoveBillboard::Update()
{
	//�ړ��ʂ�ǉ�
	D3DXVECTOR3 Pos = GetPos();
	Pos += m_Move;
	SetPos(Pos);
}