//=============================================
//
//3DTemplate[exp.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp.h"
#include "manager.h"
#include "player.h"

//�o���l�̏��
const CExp::ExpInfo CExp::Info[EXP_TYPE_MAX] =
{
	{1, "data\\MODEL\\giftbox.x"},
	{3, "data\\MODEL\\giftbox.x"},
	{5, "data\\MODEL\\giftbox.x"},
};

//=============================================
//�R���X�g���N�^
//=============================================
CExp::CExp(int nPriority) :CObjectX(nPriority),
	m_Info()
{
	//���
	m_type = OBJECT_TYPE_EXP;
}

//=============================================
//�f�X�g���N�^
//=============================================
CExp::~CExp()
{
}

//=============================================
//������
//=============================================
HRESULT CExp::Init()
{
	CModel* pModel = CManager::GetInstance()->GetModel();

	//X�t�@�C���ǂݍ���
	BindXFile(pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pBuffMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).dwNumMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pMesh);
	//�e�N���X�̏�����
	CObjectX::Init();

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CExp::Update()
{
	CObjectX::Update();

	//�G�Ƃ̓����蔻��
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

			//�G�������đ��x���グ��
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}
}

//=============================================
//����
//=============================================
CExp* CExp::Create(D3DXVECTOR3 pos, EXP_TYPE type)
{
	CExp* pObject = new CExp(3);

	pObject->m_Info = Info[type];

	pObject->Init();
	return pObject;
}