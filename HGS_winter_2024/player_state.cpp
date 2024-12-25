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

//=============================================
//�ŏ��̈�񂾂�
//=============================================
void CAttackState::Start()
{
	m_pMelee = nullptr;
}

//=============================================
//�U����Ԃ̏���
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
