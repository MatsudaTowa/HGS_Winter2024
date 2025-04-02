//=============================================
//
//3DTemplate[game.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "game.h"
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include "objectX.h"
#include "field.h"
#include "manager.h"
#include "field.h"
#include "player.h"
#include "exp.h"
#include "gamemanager.h"

//���̃T�C�Y
const D3DXVECTOR3 CGame::FIELD_SIZE = { 10000.0f,0.0f,10000.0f };

//=============================================
//�R���X�g���N�^
//=============================================
CGame::CGame():m_bPause(false)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CGame::~CGame()
{
}

//=============================================
//������
//=============================================
HRESULT CGame::Init()
{
	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_GAME);

	CField::Create(VEC3_RESET_ZERO, FIELD_SIZE);

	CPlayer::Create();

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CGame::Uninit()
{
	CManager::GetInstance()->GetSound()->StopSound();

	CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CGame::Update()
{
#ifdef _DEBUG
	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;
	CInputMouse* pMouse = GET_INPUT_MOUSE;
	CInputPad* pPad = GET_INPUT_PAD;

	if (pKeyboard->GetTrigger(DIK_RETURN) || pMouse->GetTrigger(0))
	{
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
	}

	if (pKeyboard->GetTrigger(DIK_SPACE))
	{
		CExp::Create(VEC3_RESET_ZERO, CExp::EXP_TYPE_LOW);
	}
	
#endif // _DEBUG

	if (pKeyboard->GetTrigger(DIK_P)|| pPad->GetTrigger(CInputPad::JOYPAD_START))
	{
		SetPause();

		//�|�[�Y���Ȃ�~�߂�A�Q�[�����Ȃ�~�߂Ȃ�
		UpdateObjectDecision(m_bPause);
	}

	if (CGameManager::GetInstance()->GetPlayer()->GetLife() <= 0)
	{
		GET_FADE->SetFade(CScene::MODE::MODE_RESULT);
	}

	SelectItem();
}

//=============================================
//�A�C�e���I��
//=============================================
void CGame::SelectItem()
{
	if (CGameManager::GetInstance()->GetPlayer()->GetExp() >= CPlayer::ITEM_UI_UNLOCK_EXP)
	{
		CGameManager::GetInstance()->GetPlayer()->ResetExp();

		//�A�C�e���I����ʂ�
		m_bItemChoice = true;

		//�A�C�e���I�𒆂Ȃ�~�߂�A�Q�[�����Ȃ�~�߂Ȃ�
		UpdateObjectDecision(m_bItemChoice);

		if (m_pLevelupSelect == nullptr)
		{
			m_pLevelupSelect = CLevelupSelect::Create();
		}
	}

	if (m_pLevelupSelect != nullptr)
	{
		if (!m_bPause)
		{
			m_pLevelupSelect->Update();
		}

		if (m_pLevelupSelect->GetEnd())
		{
			////�G�Ƃ̓����蔻��
			//for (int i = 0; i < MAX_PRIORITY; i++)
			//{
			//	CObject* pObj = CObject::Getobject(i);	//�擪�擾

			//	//�ő吔���s���Ȃ̂�while���g�p
			//	while (pObj != nullptr)
			//	{
			//		CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

			//		//�G�������đ��x���グ��
			//		if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			//		{
			//			CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			//			pPlayer->SetSoubi(m_pLevelupSelect->GetSelect());
			//		}

			//		pObj = pNext;							//�|�C���^��i�߂�
			//	}
			//}

			//�A�C�e���I����ʂ�
			m_bItemChoice = false;

			m_pLevelupSelect->Uninit();
			m_pLevelupSelect = nullptr;
		}
		//�A�C�e���I�𒆂Ȃ�~�߂�A�Q�[�����Ȃ�~�߂Ȃ�
		UpdateObjectDecision(m_bItemChoice);
	}
}

//=============================================
//�I�u�W�F�N�g�̍X�V���s��������
//=============================================
void CGame::UpdateObjectDecision(bool bStop)
{
	//�G�Ƃ̓����蔻��
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

			if (pObj->GetStop() != bStop)
			{
				pObj->SetStop(bStop);
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}
}

//=============================================
//�`��
//=============================================
void CGame::Draw()
{
}