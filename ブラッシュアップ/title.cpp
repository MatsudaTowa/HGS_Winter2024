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
//コンストラクタ
//=============================================
CTitle::CTitle()
{
}

//=============================================
//デストラクタ
//=============================================
CTitle::~CTitle()
{
}

//=============================================
//初期化
//=============================================
HRESULT CTitle::Init()
{
	//CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL::SOUND_LABEL_BGM_TITLE);

    return S_OK;
}

//=============================================
//終了
//=============================================
void CTitle::Uninit()
{
	CManager::GetInstance()->GetSound()->StopSound();
    CObject::ReleaseAll();
}

//=============================================
//更新
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
//描画
//=============================================
void CTitle::Draw()
{
}