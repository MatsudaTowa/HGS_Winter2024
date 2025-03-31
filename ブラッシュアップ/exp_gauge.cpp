//=============================================
//
//�Q�[�W����[hpgauge.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp_gauge.h"

namespace ExpGauge_Info
{
	//std::string TexName = { "data\\Texture\\playerlife" };
	D3DXVECTOR2 Poly_Size = {
		SCREEN_WIDTH,
		20.0f
	};
	D3DXCOLOR Col = { 0.0f,1.0f,1.0f,1.0f };
};

//=============================================
// �f�X�g���N�^
//=============================================
CExpGauge::~CExpGauge()
{
}

//=============================================
// ������
//=============================================
HRESULT CExpGauge::Init()
{
	//�e�N�X�`�����W�ݒ�
	//SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	SetSize(ExpGauge_Info::Poly_Size);
	SetColor(ExpGauge_Info::Col);

	CGauge_2D::Init();

	return S_OK;
}

//=============================================
// �I��
//=============================================
void CExpGauge::Uninit()
{
	CGauge_2D::Uninit();
}

//=============================================
// �X�V
//=============================================
void CExpGauge::Update()
{
	CGauge_2D::Update();
}

//=============================================
// �`��
//=============================================
void CExpGauge::Draw()
{
	CGauge_2D::Draw();
}
