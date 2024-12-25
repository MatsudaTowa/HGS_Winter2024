//=============================================
//
//3DTemplate[bullet001.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "bullet001.h"
#include "manager.h"
#include "enemy.h"
#include "explosion.h"

//tex�p�X
const std::string CBullet001::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//�R���X�g���N�^
//=============================================
CBullet001::CBullet001(int nPriority) :CMoveBillboard(nPriority), m_nLife(0), m_fGravity(0.0f)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CBullet001::~CBullet001()
{
}

//=============================================
//������
//=============================================
HRESULT CBullet001::Init()
{
	//�e�N�X�`���擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //�e�N�X�`���ݒ�

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CBullet001::Update()
{
	m_fGravity += GRAVITY;;
	GetPos().y -= m_fGravity;
	CMoveBillboard::Update();

	m_nLife++;

	if (m_nLife > LIFE)
	{
		Uninit();
	}

	//�����蔻��̐���
	if (GetPos().y <= 0.0f)
	{
		CExplosion::Create(GetPos());
		Uninit();
	}
}

//=============================================
//����
//=============================================
CBullet001* CBullet001::Create(D3DXVECTOR3 pos, float angle)
{
	CBullet001* pObject = new CBullet001(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS, SIZE_RADIUS,0.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	pObject->SetMove(D3DXVECTOR3(sinf(angle) * SPEED, 0.0f, cosf(angle) * SPEED));
	return pObject;
}
