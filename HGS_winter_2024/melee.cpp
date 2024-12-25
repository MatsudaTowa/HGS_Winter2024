//=============================================
//
//3DTemplate[melee.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "melee.h"
#include "manager.h"
#include "enemy.h"
//=============================================
// �R���X�g���N�^
//=============================================
CMelee::CMelee(int nPriority):CObject3D(nPriority), m_fRadius(FLOAT_ZERO)
{
}

//=============================================
// �f�X�g���N�^
//=============================================
CMelee::~CMelee()
{
}

//=============================================
// ������
//=============================================
HRESULT CMelee::Init()
{
	CObject3D::Init();
	//���_���W
	SetVtx(D3DXVECTOR3(0.0f, 0.0f, -1.0f));
	return S_OK;
}

//=============================================
// �I��
//=============================================
void CMelee::Uninit()
{
	CObject3D::Uninit();
}

//=============================================
// �X�V
//=============================================
void CMelee::Update()
{
	CObject3D::Update();
	//���_���W
	SetVtx(D3DXVECTOR3(0.0f, 0.0f, -1.0f));
	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //���̃|�C���^���擾

			if (pObj->GetType() == CObject::OBJECT_TYPE_ENEMY)
			{
				CEnemy* pEnemy = dynamic_cast<CEnemy*>(pObj);

				bool bHit = JudgeBallCollision(GetPos(), pEnemy->GetPos(), m_fRadius + pEnemy->GetRadius());

				if (bHit)
				{
					pEnemy->Damage(100);
				}
				
			}

			pObj = pNext;  //�|�C���^��i�߂�
		}
	}

}

//=============================================
// �`��
//=============================================
void CMelee::Draw()
{
	//CObject3D::Draw();
}

//=============================================
// ����
//=============================================
CMelee* CMelee::Create(D3DXVECTOR3 pos, float fRadius)
{
	CMelee* pMelee = new CMelee;
	if (pMelee == nullptr) { return nullptr; }

	pMelee->SetPos(pos);
	pMelee->SetSize({fRadius, fRadius,0.0f});
	pMelee->m_fRadius = fRadius;

	pMelee->Init();

	return pMelee;
}