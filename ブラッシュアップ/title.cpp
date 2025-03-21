//=============================================
//
//3DTemplate[title.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "title.h"
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include "objectX.h"
#include "field.h"
#include "manager.h"
#include "sound.h"

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
	//CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL::SOUND_LABEL_BGM_TITLE);

    return S_OK;
}

//=============================================
//�I��
//=============================================
void CTitle::Uninit()
{
	CManager::GetInstance()->GetSound()->StopSound();
    CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CTitle::Update()
{
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN) || pPad->GetTrigger(CInputPad::JOYKEY::JOYPAD_A) || pMouse->GetTrigger(0))
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