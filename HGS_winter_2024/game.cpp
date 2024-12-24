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

//=============================================
//�R���X�g���N�^
//=============================================
CGame::CGame():m_nResultDelay(0)
{//�C�j�V�����C�U�[�Ńv���C�I���e�B�ݒ�A�G�f�B�b�g���ĂȂ���ԂɕύX
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
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CGame::Uninit()
{
	CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CGame::Update()
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
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
    }
	//if (m_bEdit == false)
	//{
	//CObject::UpdateAll();
}


//=============================================
//�`��
//=============================================
void CGame::Draw()
{
}
