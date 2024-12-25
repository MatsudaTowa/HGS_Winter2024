//=============================================
//
//�v���C���[�̃X�e�[�g�p�^�[��[player_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_

#include "character.h"
#include"melee.h"

//=============================================
//�O���錾
//=============================================
class CPlayer;

//=============================================
//�L�����N�^�[�̃X�e�[�g�N���X
//=============================================
class CPlayerState
{
public:
	virtual void Start();
	virtual void Move(CPlayer* player);
	virtual void Attack(CPlayer* player);
};

//=============================================
//�L�����N�^�[�̒ʏ���
//=============================================
class CMoveState : public CPlayerState
{
public:
	virtual void Move(CPlayer* player)override;
};

//=============================================
//�L�����N�^�[�̍U�����
//=============================================
class CAttackState : public CPlayerState
{
public:
	void Start()override;
	virtual void Attack(CPlayer* player) override;
private:
	CMelee* m_pMelee;
};

#endif // !_PLAYER_STATE_H
