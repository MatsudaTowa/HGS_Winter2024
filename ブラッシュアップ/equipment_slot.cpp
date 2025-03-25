//=============================================
//
//������UI�p[equipment_slot.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "equipment_slot.h"

const std::string CEquipMent_Slot::TEXTURE_NAME = "data\\TEXTURE\\UI_SLOT";

//=============================================
// �R���X�g���N�^
//=============================================
CEquipMent_Slot::CEquipMent_Slot(int nPriority) : CObject2D(nPriority)
{
}

//=============================================
// �f�X�g���N�^
//=============================================
CEquipMent_Slot::~CEquipMent_Slot()
{
}

//=============================================
// ������
//=============================================
HRESULT CEquipMent_Slot::Init()
{
	CObject2D::Init();

	//�e�N�X�`�����擾
	CTexture* pTexture = GET_TEXTURE;

	//�e�N�X�`���o�^
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME)));

	//���_�ݒ�
	SetVtx(FLOAT_ONE);

	return S_OK;
}

//=============================================
// �I��
//=============================================
void CEquipMent_Slot::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
// �X�V
//=============================================
void CEquipMent_Slot::Update()
{
	CObject2D::Update();

	//���_�ݒ�
	SetVtx(FLOAT_ONE);
}

//=============================================
// �`��
//=============================================
void CEquipMent_Slot::Draw()
{
	CObject2D::Draw();
}

//=============================================
// ����
//=============================================
CEquipMent_Slot* CEquipMent_Slot::Create(D3DXVECTOR3 pos)
{
	CEquipMent_Slot* pEquipment_slot = new CEquipMent_Slot;

	if (pEquipment_slot == nullptr) { return nullptr; }

	pEquipment_slot->SetPos(pos);	//�ʒu�ݒ�

	return pEquipment_slot;
}
