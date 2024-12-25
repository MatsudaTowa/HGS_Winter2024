//=============================================
//
//3DTemplate[object.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "object.h"
#include "object2D.h"
#include "object3D.h"

//����������
int CObject::m_nNumAll = 0;

//�I�u�W�F�N�g�|�C���^������
CObject* CObject::m_apObject[MAX_PRIORITY][CObject::MAX_OBJECT] = {};
CObject* CObject::m_pCur[MAX_PRIORITY] = { nullptr };			//�Ō���̃|�C���^�̏�����
CObject* CObject::m_pTop[MAX_PRIORITY] = { nullptr };			//�ŏ��̃|�C���^�̏�����

//=============================================
//�R���X�g���N�^
//=============================================
CObject::CObject(int nPriority) :
	m_bDeath(false)
{
	m_nPriority = nPriority; //�`��D��x�ݒ�

	//for (int nCnt = 0; nCnt < CObject::MAX_OBJECT; nCnt++)
	//{
	//	if (m_apObject[m_nPriority][nCnt] == nullptr)
	//	{
	//		m_apObject[m_nPriority][nCnt] = this; //�������g����
	//		m_nID = nCnt; //ID���
	//		m_type = OBJECT_TYPE_NONE;
	//		m_nNumAll++; //��������
	//		break;
	//	}
	//}

	CObject* pObj = this;				//���g�̃|�C���^���擾
	m_nNumAll++;						//�������J�E���g

	pObj->m_pPrev = m_pCur[nPriority];	//�����̑O�̃I�u�W�F�N�g�|�C���^���擾

	//���߂ẴI�u�W�F�N�g�Ȃ�ÓI�����o�ɑ��
	if (m_pTop[nPriority] == nullptr)
	{
		m_pTop[nPriority] = pObj;	//�ŏ��̃I�u�W�F�N�g�̃|�C���^
		m_pCur[nPriority] = pObj;	//�Ō���̃I�u�W�F�N�g�̃|�C���^
		m_pCur[nPriority]->m_pNext = nullptr;	//���̃|�C���^��������
	}
	else
	{
		m_pCur[nPriority]->m_pNext = pObj;	//���݂̍Ō���Ɏ��̃|�C���^��ݒ�
	}

	pObj->m_pNext = nullptr;			//���̃|�C���^��������
	m_pCur[nPriority] = pObj;			//�Ō�����X�V
	m_bDeath = false;					//���S�t���O�̏�����
}

//=============================================
//�f�X�g���N�^
//=============================================
CObject::~CObject()
{
	m_nNumAll--;
}

//=============================================
//�S�폜
//=============================================
void CObject::ReleaseAll()
{
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{

	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			if (m_apObject[nCntPri][nCntObj]->m_type != CObject::OBJECT_TYPE::OBJECT_TYPE_FADE)
	//			{
	//				//�I������
	//				m_apObject[nCntPri][nCntObj]->Uninit();
	//				m_apObject[nCntPri][nCntObj] = nullptr;
	//			}
	//		}
	//	}
	//}

	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = m_pTop[i];	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//���̃|�C���^���擾

			if (pObj->m_type != CObject::OBJECT_TYPE::OBJECT_TYPE_FADE)
			{
				pObj->Release();				//�J������
			}
			
			pObj = pNext;					//�|�C���^��i�߂�
		}

		//�ÓI�|�C���^�ϐ��̏�����
		m_pTop[i] = nullptr;
		m_pCur[i] = nullptr;
	}
}

//=============================================
//�S�X�V
//=============================================
void CObject::UpdateAll()
{
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{
	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			//�X�V����
	//			m_apObject[nCntPri][nCntObj]->Update();
	//		}
	//	}
	//}

	//�ϐ��̐錾
	CObject* pObj = nullptr;

	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		pObj = m_pTop[i];	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//���̃|�C���^���擾

			pObj->Update();					//�X�V����

			pObj = pNext;					//�|�C���^��i�߂�
		}
	}

	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		pObj = m_pTop[i];	//�擪�擾

	//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//���̃|�C���^���擾

			//���S�t���O�������Ă�����Release
			if (pObj->m_bDeath)
			{
				pObj->Release();
			}

			pObj = pNext;	//�|�C���^��i�߂�
		}
	}
}

//=============================================
//�S�`��
//=============================================
void CObject::DrawAll()
{
	//for (int nCntPri = 0; nCntPri < MAX_PRIORITY; nCntPri++)
	//{
	//	for (int nCntObj = 0; nCntObj < CObject::MAX_OBJECT; nCntObj++)
	//	{
	//		if (m_apObject[nCntPri][nCntObj] != nullptr)
	//		{
	//			//�I������
	//			m_apObject[nCntPri][nCntObj]->Draw();
	//		}
	//	}
	//}

	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = m_pTop[i];	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->m_pNext;	//���̃|�C���^���擾
			pObj->Draw();					//�X�V����
			pObj = pNext;					//�|�C���^��i�߂�
		}
	}
}


//=============================================
//�������g�̍폜
//=============================================
void CObject::Release()
{
	/*int nID = m_nID;
	int nPri = m_nPriority;
	if (m_apObject[nPri][nID] != nullptr)
	{
		delete m_apObject[nPri][nID];
		m_apObject[nPri][nID] = nullptr;
	}*/

	//�ϐ��ɑ��
	int nPriority = m_nPriority;

	//null�`�F�b�N
	if (this != nullptr)
	{
		CObject* pObj = this;					//���g�̃|�C���^���擾

		if (pObj->m_pPrev != nullptr)
		{
			pObj->m_pPrev->m_pNext = pObj->m_pNext;	//���g�̑O����q��
		}

		if (pObj->m_pNext != nullptr)
		{
			pObj->m_pNext->m_pPrev = pObj->m_pPrev;	//���g�̑O����q��
		}

		//�Ō�������݂̃|�C���^�Ȃ�O�̃|�C���^�ɍX�V
		if (pObj == m_pCur[nPriority])
		{
			m_pCur[nPriority] = pObj->m_pPrev;	//�|�C���^�̕ύX
		}

		//�ŏ������݂̃|�C���^�Ȃ玟�̃|�C���^�ɍX�V
		if (pObj == m_pTop[nPriority])
		{
			m_pTop[nPriority] = pObj->m_pNext;	//�|�C���^�̕ύX
		}

		//���X�g����폜
		delete pObj;
		pObj = nullptr;
		//m_nNumAll--;
	}
}

//=============================================
//�I�u�W�F�N�g�擾
//=============================================
CObject* CObject::Getobject(int nPri, int nIdx)
{
	return m_apObject[nPri][nIdx];
}

//=============================================
//�I�u�W�F�N�g�擾
//=============================================
CObject* CObject::Getobject(int nPri)
{
	return m_pTop[nPri];
}

//=============================================
//�^�C�v�擾
//=============================================
CObject::OBJECT_TYPE CObject::GetType()
{
	return m_type;
}

//=============================================
//�^�C�v�ݒ�
//=============================================
void CObject::SetType(OBJECT_TYPE type)
{
	m_type = type;
}

