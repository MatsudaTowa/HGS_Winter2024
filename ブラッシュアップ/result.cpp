//=============================================
//
//3DTemplate[result.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "result.h"
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
    CScene::Init();
  
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
        || pPad->GetTrigger(CInputPad::JOYKEY::JOYPAD_A))
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