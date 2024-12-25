//=============================================
//
//3DTemplate[leasepower.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "leasepower.h"
#include "manager.h"
#include "enemy.h"

//tex�p�X
const std::string CLeasepower::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//�R���X�g���N�^
//=============================================
CLeasepower::CLeasepower(int nPriority) :CObject3D(nPriority), m_nCount(0)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CLeasepower::~CLeasepower()
{
}

//=============================================
//������
//=============================================
HRESULT CLeasepower::Init()
{
	//�e�N�X�`���擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //�e�N�X�`���ݒ�

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CLeasepower::Update()
{
	m_nCount++;

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
				}
				
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}

	if (m_nCount > TIME_END)
	{
		Uninit();
	}
}

//=============================================
//�`��
//=============================================
void CLeasepower::Draw()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//�J�����O���@��ύX
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	CObject3D::Draw();

	//�J�����O���@��ύX
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}

//=============================================
//����
//=============================================
CLeasepower* CLeasepower::Create(D3DXVECTOR3 pos)
{
	CLeasepower* pObject = new CLeasepower(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS * 2.0f, 0.0f, SIZE_RADIUS * 2.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	return pObject;
}
