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

//床のサイズ
const D3DXVECTOR3 CGame::FIELD_SIZE = { 10000.0f,0.0f,10000.0f };

//=============================================
//コンストラクタ
//=============================================
CGame::CGame()
{
}

//=============================================
//デストラクタ
//=============================================
CGame::~CGame()
{
}

//=============================================
//初期化
//=============================================
HRESULT CGame::Init()
{
	CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_GAME);

	CField::Create(VEC3_RESET_ZERO, FIELD_SIZE);

	CPlayer::Create();

	return S_OK;
}

//=============================================
//終了
//=============================================
void CGame::Uninit()
{
	CManager::GetInstance()->GetSound()->StopSound();

	CObject::ReleaseAll();
}

//=============================================
//更新
//=============================================
void CGame::Update()
{
#ifdef _DEBUG
	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;
	CInputMouse* pMouse = GET_INPUT_MOUSE;

	if (pKeyboard->GetTrigger(DIK_RETURN) || pMouse->GetTrigger(0))
	{
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
	}
	
#endif // _DEBUG

}

//=============================================
//描画
//=============================================
void CGame::Draw()
{
}