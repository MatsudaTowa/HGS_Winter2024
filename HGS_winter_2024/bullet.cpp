//=============================================
//
//3DTemplate[bullet.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "bullet.h"
#include "manager.h"
#include "enemy.h"

//tex�p�X
const std::string CBullet::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//�R���X�g���N�^
//=============================================
CBullet::CBullet(int nPriority) :CMoveBillboard(nPriority), m_nLife(0)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CBullet::~CBullet()
{
}

//=============================================
//������
//=============================================
HRESULT CBullet::Init()
{
	//�e�N�X�`���擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //�e�N�X�`���ݒ�

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CBullet::Update()
{
	CMoveBillboard::Update();

	m_nLife++;

	//�G�Ƃ̓����蔻��
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

			//�G�������đ��x���グ��
			if (pObj->GetType() == CObject::OBJECT_TYPE_ENEMY)
			{
				CEnemy* pEnemy = dynamic_cast<CEnemy*>(pObj);

				//�~�̒��ɓ�������_���[�W
				if (JudgeBallCollision(GetPos(), pEnemy->GetPos(), SIZE_RADIUS * 2.0f))
				{
					pEnemy->Damage(1);
					Uninit();
				}

			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}

	if (m_nLife > LIFE)
	{
		Uninit();
	}
}

//=============================================
//����
//=============================================
CBullet* CBullet::Create(D3DXVECTOR3 pos, float angle)
{
	CBullet* pObject = new CBullet(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS, SIZE_RADIUS,0.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	pObject->SetMove(D3DXVECTOR3(sinf(angle) * SPEED, 0.0f, cosf(angle) * SPEED));
	return pObject;
}
