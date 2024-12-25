//=============================================
//
//3DTemplate[child.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "child.h"
#include"manager.h"
#include "enemy.h"

//=============================================
//�R���X�g���N�^
//=============================================
CChild::CChild(int nPriority) :
	CObjectX(nPriority)
{//�C�j�V�����C�U�[�Ńv���C�I���e�B�ݒ�A�e�����o�ϐ�������
}

//=============================================
//�f�X�g���N�^
//=============================================
CChild::~CChild()
{
	
}

//=============================================
//������
//=============================================
HRESULT CChild::Init()
{
	CModel* pModel = CManager::GetInstance()->GetModel();

	//X�t�@�C���ǂݍ���
	BindXFile(pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).pBuffMat,
		pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).dwNumMat,
		pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).pMesh);

	//�e�N���X�̏�����
	CObjectX::Init();
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CChild::Uninit()
{
	CObjectX::Uninit();
}

//=============================================
//�X�V
//=============================================
void CChild::Update()
{
	GetRot().x -= 0.1f;

	CObjectX::Update();
}

//=============================================
//�`��
//=============================================
void CChild::Draw()
{
	CObjectX::Draw();
}

//=============================================
//����
//=============================================
CChild* CChild::Create(D3DXVECTOR3 pos)
{
	CChild* pObject = new CChild(3);
	pObject->SetPos(pos);
	float fDistance = 99999.0f;
	float fAngle = 0.0f;

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
				D3DXVECTOR3 Vector;

				//�Q�_�Ԃ̋������v�Z
				D3DXVec3Subtract(&Vector, &pos, &pEnemy->GetPos());

				// �����x�N�g���̒����i�����j���v�Z
				float fVextor= static_cast<float>(D3DXVec3Length(&Vector));
				float A = fVextor;
				if (fVextor < 0.0f) { A *= -1.0f; }

				if (fDistance > A)
				{
					fAngle = atan2f(Vector.x, Vector.z);
				}
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}

	pObject->SetMove({ sinf(fAngle + D3DX_PI) * 10.0f, 0.0f, cosf(fAngle + D3DX_PI) * 10.0f });
	pObject->Init();
	return pObject;
}