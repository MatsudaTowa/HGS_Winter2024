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
#include "exp.h"
#include "gamemanager.h"

//床のサイズ
const D3DXVECTOR3 CGame::FIELD_SIZE = { 10000.0f,0.0f,10000.0f };

//=============================================
//コンストラクタ
//=============================================
CGame::CGame():m_bPause(false)
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
	CInputPad* pPad = GET_INPUT_PAD;

	if (pKeyboard->GetTrigger(DIK_RETURN) || pMouse->GetTrigger(0))
	{
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
	}

	if (pKeyboard->GetTrigger(DIK_SPACE))
	{
		CExp::Create(VEC3_RESET_ZERO, CExp::EXP_TYPE_LOW);
	}
	
#endif // _DEBUG

	if (pKeyboard->GetTrigger(DIK_P)|| pPad->GetTrigger(CInputPad::JOYPAD_START))
	{
		SetPause();

		//ポーズ中なら止める、ゲーム中なら止めない
		UpdateObjectDecision(m_bPause);
	}

	if (CGameManager::GetInstance()->GetPlayer()->GetLife() <= 0)
	{
		GET_FADE->SetFade(CScene::MODE::MODE_RESULT);
	}

	SelectItem();
}

//=============================================
//アイテム選択
//=============================================
void CGame::SelectItem()
{
	if (CGameManager::GetInstance()->GetPlayer()->GetExp() >= CPlayer::ITEM_UI_UNLOCK_EXP)
	{
		CGameManager::GetInstance()->GetPlayer()->ResetExp();

		//アイテム選択画面へ
		m_bItemChoice = true;

		//アイテム選択中なら止める、ゲーム中なら止めない
		UpdateObjectDecision(m_bItemChoice);

		if (m_pLevelupSelect == nullptr)
		{
			m_pLevelupSelect = CLevelupSelect::Create();
		}
	}

	if (m_pLevelupSelect != nullptr)
	{
		if (!m_bPause)
		{
			m_pLevelupSelect->Update();
		}

		if (m_pLevelupSelect->GetEnd())
		{
			////敵との当たり判定
			//for (int i = 0; i < MAX_PRIORITY; i++)
			//{
			//	CObject* pObj = CObject::Getobject(i);	//先頭取得

			//	//最大数が不明なのでwhileを使用
			//	while (pObj != nullptr)
			//	{
			//		CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			//		//敵を見つけて速度を上げる
			//		if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			//		{
			//			CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			//			pPlayer->SetSoubi(m_pLevelupSelect->GetSelect());
			//		}

			//		pObj = pNext;							//ポインタを進める
			//	}
			//}

			//アイテム選択画面へ
			m_bItemChoice = false;

			m_pLevelupSelect->Uninit();
			m_pLevelupSelect = nullptr;
		}
		//アイテム選択中なら止める、ゲーム中なら止めない
		UpdateObjectDecision(m_bItemChoice);
	}
}

//=============================================
//オブジェクトの更新を行うか決定
//=============================================
void CGame::UpdateObjectDecision(bool bStop)
{
	//敵との当たり判定
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			if (pObj->GetStop() != bStop)
			{
				pObj->SetStop(bStop);
			}

			pObj = pNext;							//ポインタを進める
		}
	}
}

//=============================================
//描画
//=============================================
void CGame::Draw()
{
}