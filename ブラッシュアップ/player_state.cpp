//=============================================
//
//�v���C���[�̃X�e�[�g�p�^�[��[player_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player_state.h"
#include"player.h"
#include "manager.h"

//=============================================
//�ŏ��̈�񂾂�
//=============================================
void CPlayerState::Start()
{
}

//=============================================
//�ʏ��Ԃ̏���
//=============================================
void CPlayerState::Move(CPlayer* player)
{
}

//=============================================
//�U����Ԃ̏���
//=============================================
void CPlayerState::Attack(CPlayer* player)
{
}

//=============================================
//�ʏ��Ԃ̏���
//=============================================
void CMoveState::Move(CPlayer* player)
{
	//�ړ���
	D3DXVECTOR3 move = player->GetMove();

	if (move.x == 0.0f && move.z == 0.0f)
	{ // �����ĂȂ��B
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
