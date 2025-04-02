//=============================================
//
//3DTemplate[levelupselect.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "levelupselect.h"
#include "manager.h"

//=============================================
//�I��
//=============================================
void CLevelupSelect::Uninit()
{
	for (auto& itr : m_pSelect)
	{//�I��UI�̃T�C�Y����(�Q�Ƃɂ��Ă��̒��ō폜)
		if (itr == nullptr) { continue; }

		itr->Uninit();
		itr = nullptr;
	}
}

//=============================================
//�X�V
//=============================================
void CLevelupSelect::Update()
{
	//�e�C���v�b�g�擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	CInputPad* pPad = CManager::GetInstance()->GetPad();

	if (pKeyboard->GetTrigger(DIK_UP)
		|| pPad->GetTrigger(CInputPad::JOYPAD_DPAD_UP))
	{
		if (m_nSelect > 0)
		{
			m_nSelect--;
		}
		else if (m_nSelect <= 0)
		{
			m_nSelect = 2;
		}
	}
	else if (pKeyboard->GetTrigger(DIK_DOWN)
		|| pPad->GetTrigger(CInputPad::JOYPAD_DPAD_DOWN))
	{
	
		if (m_nSelect < 2)
		{
			m_nSelect++;
		}
		else if (m_nSelect >= 2)
		{
			m_nSelect = 0;
		}
	}

	int nCnt = 0;

	for (auto& itr : m_pSelect)
	{//�I��UI�̃T�C�Y����(�Q�Ƃɂ��Ă��̒��ō폜)

		if (m_nSelect == nCnt)
		{
			itr->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
		}
		else
		{
			itr->SetColor({ 0.2f, 0.2f, 0.2f, 1.0f });
		}

		itr->SetVtx(1.0f);

		++nCnt;
	}

	if (pKeyboard->GetTrigger(DIK_M)
		|| pPad->GetTrigger(CInputPad::JOYPAD_A))
	{
		m_End = true;
	}
}

//=============================================
//����
//=============================================
CLevelupSelect* CLevelupSelect::Create()
{
	CLevelupSelect* pLevelupSelect = new CLevelupSelect;

	std::vector<int> selectedNumbers; // �I�΂ꂽ���l��ۑ����郊�X�g
	
	for (int i = 0; i < NUM_SELECT; i++)
	{
		int nRand = 0;

		// �d�����Ȃ������_���l���擾
		do 
		{//��v�����烋�[�v����
			nRand = rand() % 9;
		} while (std::find(selectedNumbers.begin(), selectedNumbers.end(), nRand) != selectedNumbers.end());

		selectedNumbers.push_back(nRand); // �g�p�ς݃��X�g�ɒǉ�

		if (pLevelupSelect->m_pSelect[i] == nullptr)
		{
			pLevelupSelect->m_pSelect[i] = CUi_Select::Create({ SCREEN_WIDTH * 0.5f, 200.0f + 150.0f * i, 0.0f }, nRand);
		}
	}
	
	return pLevelupSelect;
}