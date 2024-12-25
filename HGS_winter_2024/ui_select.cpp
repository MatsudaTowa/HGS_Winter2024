//=============================================
//
//3DTemplate[ui_select.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "ui_select.h"
#include "renderer.h"
#include "manager.h"

//�o���l�̏��
const std::string CUi_Select::Path[9] =
{
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
	{"data\\TEXTURE\\field.jpg"},
};

//�萔
const D3DXVECTOR2 CUi_Select::SIZE = { 300.0f, 150.0f};

//=============================================
//�R���X�g���N�^
//=============================================
CUi_Select::CUi_Select(int nPriority) : CObject2D(nPriority), m_nNum(0)
{
	
}

//=============================================
//�f�X�g���N�^
//=============================================
CUi_Select::~CUi_Select()
{
}

//=============================================
//������
//=============================================
HRESULT CUi_Select::Init()
{
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CUi_Select::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
//�X�V
//=============================================
void CUi_Select::Update()
{
	CObject2D::Update();
}

//=============================================
//����
//=============================================
CUi_Select* CUi_Select::Create(D3DXVECTOR3 pos, int num)
{
	CUi_Select* p = new CUi_Select();

	//�e�N�X�`���擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	p->SetPos(pos);		//pos�ݒ�
	p->SetSize(SIZE);	 //�T�C�Y�ݒ�
	p->BindTexture(pTexture->GetAddress(pTexture->Regist(&Path[num]))); //�e�N�X�`���ݒ�
	p->SetColor({ 0.2f, 0.2f, 0.2f, 1.0f });
	p->Init();
	p->SetVtx(1.0f);
	p->m_nNum = num;

	return p;
}