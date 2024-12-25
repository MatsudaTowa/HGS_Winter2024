//=============================================
//
//プレイヤーのステートパターン[player_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player_state.h"
#include"player.h"
#include "manager.h"

//=============================================
//最初の一回だけ
//=============================================
void CPlayerState::Start()
{
}

//=============================================
//通常状態の処理
//=============================================
void CPlayerState::Move(CPlayer* player)
{
}

//=============================================
//攻撃状態の処理
//=============================================
void CPlayerState::Attack(CPlayer* player)
{
}

//=============================================
//通常状態の処理
//=============================================
void CMoveState::Move(CPlayer* player)
{
	//移動量
	D3DXVECTOR3 move = player->GetMove();

	if (move.x == 0.0f && move.z == 0.0f)
	{ // 動いてない。
		player->SetMotion(CPlayer::MOTION_NEUTRAL);
	}
	else
	{
		player->SetMotion(CPlayer::MOTION_MOVE);
	}
}

//=============================================
//最初の一回だけ
//=============================================
void CAttackState::Start()
{
	m_pMelee = nullptr;
}

//=============================================
//攻撃状態の処理
//=============================================
void CAttackState::Attack(CPlayer* player)
{
	if (player->GetKeyCnt() == 2)
	{
		if (m_pMelee == nullptr)
		{
			m_pMelee = CMelee::Create({ player->m_apModel[7]->GetMtxWorld()._41,
				player->m_apModel[7]->GetMtxWorld()._42,
				player->m_apModel[7]->GetMtxWorld()._43 },
				50.0f);
		}
	}
	

	player->SetMotion(CPlayer::MOTION_ATTACK);

	if (m_pMelee != nullptr)
	{
		m_pMelee->SetPos({ player->m_apModel[7]->GetMtxWorld()._41,
			player->m_apModel[7]->GetMtxWorld()._42,
			player->m_apModel[7]->GetMtxWorld()._43 });
	}

	if (player->GetMotionFinish())
	{
		if (m_pMelee != nullptr)
		{
			m_pMelee->Uninit();
			m_pMelee = nullptr;
		}
		player->ChangePlayerState(new CMoveState);
	}
}
