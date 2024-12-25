//=============================================
//
//3DTemplate[explosion.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "explosion.h"
#include "manager.h"
#include "enemy.h"

//=============================================
//�R���X�g���N�^
//=============================================
CExplosion::CExplosion(int priority) : CBillboard(priority)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CExplosion::~CExplosion()
{
}

//=============================================
//������
//=============================================
HRESULT CExplosion::Init()
{
	//������
	CBillboard::Init();

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CExplosion::Update()
{
	CBillboard::Update();

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
CExplosion* CExplosion::Create(D3DXVECTOR3 pos)
{
	CExplosion* pObject = new CExplosion(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS, SIZE_RADIUS,0.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	
	return pObject;
}