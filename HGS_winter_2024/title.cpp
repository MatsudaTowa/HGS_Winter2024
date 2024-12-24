//=============================================
//
//3DTemplate[title.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "title.h"
#include "title_screen.h"
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include "objectX.h"
#include "field.h"
#include "manager.h"
#include "sound.h"

const std::string CTitle::BLOCK_FILE = "data\\FILE\\block.txt";


//=============================================
//�R���X�g���N�^
//=============================================
CTitle::CTitle()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CTitle::~CTitle()
{
}

//=============================================
//������
//=============================================
HRESULT CTitle::Init()
{
    //�n�ʐ���
    CField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1000.0f, 0.0f, 1000.0f));

	//�u���b�N����
	//LoadBlock(&CTitle::BLOCK_FILE);

	//�v���C���[����
	//CPlayer* pPlayer_test = CPlayer_test::Create(D3DXVECTOR3(0.0f, 0.5f, -300.0f), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 100);

    m_pTitleScreen[0] = CTitle_Screen::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f,200.0f,0.0f),D3DXVECTOR2(400.0f,200.0f),CTitle_Screen::TITLE_UI::UI_TITLE_ROGO);

    m_pTitleScreen[1]=CTitle_Screen::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, 600.0f, 0.0f), D3DXVECTOR2(200.0f, 50.0f), CTitle_Screen::TITLE_UI::UI_TITLE_PRESS_BUTTON);

    return S_OK;
}

//=============================================
//�I��
//=============================================
void CTitle::Uninit()
{
    CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CTitle::Update()
{
    CObject::UpdateAll();
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN) || pPad->GetTrigger(CInputPad::JOYKEY::JOYKEY_A) || pMouse->GetTrigger(0))
    {
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_GAME);
    }
}

//=============================================
//�`��
//=============================================
void CTitle::Draw()
{
}

