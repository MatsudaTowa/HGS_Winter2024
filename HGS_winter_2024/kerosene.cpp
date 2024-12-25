//=============================================
//
//3DTemplate[kerosene.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "kerosene.h"
#include "manager.h"

//tex�p�X
const std::string CKerosene::TEXTURE_NAME = "data\\TEXTURE\\field.jpg";

//=============================================
//�R���X�g���N�^
//=============================================
CKerosene::CKerosene(int nPriority) :CObject3D(nPriority),m_nCount(0)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CKerosene::~CKerosene()
{
}

//=============================================
//������
//=============================================
HRESULT CKerosene::Init()
{
	//�e�N�X�`���擾
	CTexture* pTexture = CManager::GetInstance()->GetTexture();
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME))); //�e�N�X�`���ݒ�
}

//=============================================
//�`��
//=============================================
void CKerosene::Update()
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
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				//CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
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
//����
//=============================================
CKerosene* CKerosene::Create(D3DXVECTOR3 pos)
{
	CKerosene* pObject = new CKerosene(3);
	pObject->SetPos(pos);
	pObject->SetSize({ SIZE_RADIUS * 2.0f, 0.0f, SIZE_RADIUS * 2.0f });
	pObject->SetVtx(D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	pObject->Init();
	return pObject;
}
