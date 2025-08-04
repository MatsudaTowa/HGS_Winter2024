//=============================================
//
//�G�l�~�[�̏���[behavior_enemy_chase.cpp]
//Auther Matsuda Towa
//
//=============================================

//�C���N���[�h
#include "behavior_enemy_chase.h"
#include "gamemanager.h"

//=============================================
//�R���X�g���N�^
//=============================================
CBehavior_Enemy_Chase::CBehavior_Enemy_Chase(CEnemy* enemy) :CBehavior_Enemy(enemy)
{

}

//=============================================
//�f�X�g���N�^
//=============================================
CBehavior_Enemy_Chase::~CBehavior_Enemy_Chase()
{

}

//=============================================
//�s��
//=============================================
void CBehavior_Enemy_Chase::Behavior(CEnemy* enemy)
{
	//�v���C���[�̒ǐ�
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//�v���C���[�̕�������
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();						//�v���C���[�̈ʒu���擾
	D3DXVECTOR3 Pos = enemy->GetPos();								//�����̈ʒu���擾

	//�v���C���[�Ƃ̊p�x���Z�o
	float fAngle = atan2f(PlayerPos.x - Pos.x, PlayerPos.z - Pos.z);

	//�p�x��ݒ�
	enemy->SetRot({ enemy->GetRot().x, fAngle + D3DX_PI, enemy->GetRot().z });

	//�ړ��ʂ�ݒ�
	enemy->SetMove({ sinf(fAngle) * VALUE_MOVE, enemy->GetMove().y, cosf(fAngle) * VALUE_MOVE });

	//�ړ��ʂ�����
	D3DXVECTOR3 move = enemy->GetMove();
	move.x += -move.x * 0.1f;
	move.z += -move.z * 0.1f;
	enemy->SetMove(move);
}