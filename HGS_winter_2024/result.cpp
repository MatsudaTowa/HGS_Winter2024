//=============================================
//
//3DTemplate[result.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "result.h"
#include "result_screen.h"
#include "game.h"

//=============================================
//�R���X�g���N�^
//=============================================
CResult::CResult()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CResult::~CResult()
{
}

//=============================================
//������
//=============================================
HRESULT CResult::Init()
{
    CResult_Screen::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f, 0.0f));
  
    return S_OK;
}

//=============================================
//�I��
//=============================================
void CResult::Uninit()
{
    CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CResult::Update()
{
    //�e�C���v�b�g�擾
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN) 
        || pMouse->GetTrigger(0)
        || pPad->GetTrigger(CInputPad::JOYKEY::JOYKEY_A))
    {
        //�^�C�g���ɖ߂�
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_TITLE);
    }
}

//=============================================
//�`��
//=============================================
void CResult::Draw()
{
}