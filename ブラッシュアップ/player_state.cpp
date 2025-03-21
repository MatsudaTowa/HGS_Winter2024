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

void CAttackState::Start()
{
}

void CAttackState::Attack(CPlayer* player)
{
}
