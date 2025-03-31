//=============================================
//
//�Q�[�W����[hpgauge.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "hp_gauge.h"

namespace LifeGauge_Info
{
	//std::string TexName = { "data\\Texture\\playerlife" };
	D3DXVECTOR2 Poly_Size = {
		400.0f,
		20.0f
	};
	D3DXCOLOR LifeCol = { 0.0f,1.0f,0.0f,1.0f };
};

//=============================================
// �f�X�g���N�^
//=============================================
CHpGauge::~CHpGauge()
{
}

//=============================================
// ������
//=============================================
HRESULT CHpGauge::Init()
{
	//�e�N�X�`�����W�ݒ�
	//SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	SetSize(LifeGauge_Info::Poly_Size);
	SetColor(LifeGauge_Info::LifeCol);

	CGauge_2D::Init();

	return S_OK;
}

//=============================================
// �I��
//=============================================
void CHpGauge::Uninit()
{
	CGauge_2D::Uninit();
}

//=============================================
// �X�V
//=============================================
void CHpGauge::Update()
{
	CGauge_2D::Update();
}

//=============================================
// �`��
//=============================================
void CHpGauge::Draw()
{
	CGauge_2D::Draw();
}
