//=============================================
//
//3DTemplate[result_Screen.h]
//Auther Matsuda Towa
//
//=============================================
#include "UI_player_life.h"
#include "manager.h"

namespace UI_Info
{
	std::string TexName = { "data\\Texture\\playerlife" };
	D3DXVECTOR2 Poly_Size = {
		300.0f,
		60.0f
	};
	D3DXCOLOR LifeCol = {1.0f,0.0f,0.0f,1.0f};
};

//=============================================
//������
//=============================================
HRESULT UI_PlayerLife::Init()
{
	//�e�N���X�̏��������Ă�
	CObject2D::Init();

	//�������g�̃T�C�Y�擾
	D3DXVECTOR2 size = GetSize();

	size = UI_Info::Poly_Size;

	//�e�N�X�`�����W�ݒ�
	SetTexPos(D3DXVECTOR2(1.0f, 1.0f));

	//�T�C�Y����
	SetSize(size);

	//�J���[�擾
	D3DXCOLOR col = GetColor();

	col = UI_Info::LifeCol;

	//�J���[����
	SetColor(col);

	SetMaxGauge(m_Life);

	//���_�ݒ�
	SetVtx(1.0f);
	return S_OK;
}

//=============================================
//�I��
//=============================================
void UI_PlayerLife::Uninit()
{
	SetGaugeVtx(1.0f);
	//�e�N���X�̏I�����Ă�
	CObject2D::Uninit();

}

//=============================================
//�X�V
//=============================================
void UI_PlayerLife::Update()
{
	SetGauge(m_Life);		//�Q�[�W�l�Z�b�g
	CObject2D::UpdateGauge();//�Q�[�W�X�V
	//�e�N���X�̍X�V
	CObject2D::Update();
}

//=============================================
//�`��
//=============================================
void UI_PlayerLife::Draw()
{
	//�e�N���X�̕`��
	CObject2D::Draw();
}

//=============================================
//����
//=============================================
UI_PlayerLife* UI_PlayerLife::Create(D3DXVECTOR3 pos,int MaxLife)
{
	using namespace UI_Info;
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	UI_PlayerLife* pUI = new UI_PlayerLife;

	//null�Ȃ�null��Ԃ�
	if (pUI == nullptr) { return nullptr; }

	pUI->SetPos(pos); //pos�ݒ�

	pUI->SetType(OBJECT_TYPE_RESULT); //�^�C�v�ݒ�

	pUI->BindTexture(pTexture->GetAddress(pTexture->Regist(&TexName)));

	pUI->SetLife(MaxLife);

	pUI->Init();

	return pUI;
}
