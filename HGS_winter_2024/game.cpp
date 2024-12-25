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
#include "exp.h"
#include "player.h"
#include "enemy.h"

//床のサイズ
const D3DXVECTOR3 CGame::FIELD_SIZE = { 100.0f,0.0f,100.0f };

//=============================================
//コンストラクタ
//=============================================
CGame::CGame():m_nResultDelay(0), m_pLevelupSelect(0)
{//イニシャライザーでプライオリティ設定、エディットしてない状態に変更
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
    CField::Create(VEC3_RESET_ZERO, FIELD_SIZE);

    CPlayer::Create();

    CEnemy::Create({ 5.0f,0.5f,100.0f }, VEC3_RESET_ZERO, CEnemy::ENEMY_TYPE_WEAK);

    CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_GAME);
    return S_OK;
}

//=============================================
//終了
//=============================================
void CGame::Uninit()
{
    CManager::GetInstance()->GetSound()->StopSound(CSound::SOUND_LABEL_BGM_GAME);
	CObject::ReleaseAll();
}

//=============================================
//更新
//=============================================
void CGame::Update()
{
    //各インプット取得
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN)
        || pMouse->GetTrigger(0)
        || pPad->GetTrigger(CInputPad::JOYKEY::JOYKEY_A))
    {
        //タイトルに戻る
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
    }
	//if (m_bEdit == false)
	//{
	//CObject::UpdateAll();

    if (pKeyboard->GetTrigger(DIK_K))
    {
        if (m_pLevelupSelect == nullptr)
        {
            m_pLevelupSelect = CLevelupSelect::Create();
        }
    }

    if (m_pLevelupSelect != nullptr)
    {
        m_pLevelupSelect->Update();

        if (m_pLevelupSelect->GetEnd())
        {
            m_pLevelupSelect->Uninit();
            delete m_pLevelupSelect;
            m_pLevelupSelect = nullptr;
        }
    }
}


//=============================================
//描画
//=============================================
void CGame::Draw()
{
}
