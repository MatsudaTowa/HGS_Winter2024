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
	for (int i = 0; i < 3; i++)
	{
		if (m_pSelect[i] != nullptr)
		{
			m_pSelect[i]->Uninit();
			m_pSelect[i] = nullptr;
		}
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
	}
	else if (pKeyboard->GetTrigger(DIK_DOWN)
		|| pPad->GetTrigger(CInputPad::JOYPAD_DPAD_DOWN))
	{
	
		if (m_nSelect < 2)
		{
			m_nSelect++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (m_nSelect == i)
		{
			m_pSelect[i]->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
		}
		else
		{
			m_pSelect[i]->SetColor({ 0.2f, 0.2f, 0.2f, 1.0f });
		}

		m_pSelect[i]->SetVtx(1.0f);
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
	
	for (int i = 0; i < 3; i++)
	{
		int nRand = (rand() % 9); //�����_��
		pLevelupSelect->m_pSelect[i] = CUi_Select::Create({ SCREEN_WIDTH * 0.5f, 200.0f + 150.0f * i, 0.0f }, nRand);
	}
	
	return pLevelupSelect;
}