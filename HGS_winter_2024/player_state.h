//=============================================
//
//プレイヤーのステートパターン[player_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_

#include "character.h"
#include"melee.h"

//=============================================
//前方宣言
//=============================================
class CPlayer;

//=============================================
//キャラクターのステートクラス
//=============================================
class CPlayerState
{
public:
	virtual void Start();
	virtual void Move(CPlayer* player);
	virtual void Attack(CPlayer* player);
};

//=============================================
//キャラクターの通常状態
//=============================================
class CMoveState : public CPlayerState
{
public:
	virtual void Move(CPlayer* player)override;
};

//=============================================
//キャラクターの攻撃状態
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
