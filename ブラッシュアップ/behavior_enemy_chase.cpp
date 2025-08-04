//=============================================
//
//エネミーの処理[behavior_enemy_chase.cpp]
//Auther Matsuda Towa
//
//=============================================

//インクルード
#include "behavior_enemy_chase.h"
#include "gamemanager.h"

//=============================================
//コンストラクタ
//=============================================
CBehavior_Enemy_Chase::CBehavior_Enemy_Chase(CEnemy* enemy) :CBehavior_Enemy(enemy)
{

}

//=============================================
//デストラクタ
//=============================================
CBehavior_Enemy_Chase::~CBehavior_Enemy_Chase()
{

}

//=============================================
//行動
//=============================================
void CBehavior_Enemy_Chase::Behavior(CEnemy* enemy)
{
	//プレイヤーの追跡
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//プレイヤーの方を向く
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();						//プレイヤーの位置を取得
	D3DXVECTOR3 Pos = enemy->GetPos();								//自分の位置を取得

	//プレイヤーとの角度を算出
	float fAngle = atan2f(PlayerPos.x - Pos.x, PlayerPos.z - Pos.z);

	//角度を設定
	enemy->SetRot({ enemy->GetRot().x, fAngle + D3DX_PI, enemy->GetRot().z });

	//移動量を設定
	enemy->SetMove({ sinf(fAngle) * VALUE_MOVE, enemy->GetMove().y, cosf(fAngle) * VALUE_MOVE });

	//移動量を減衰
	D3DXVECTOR3 move = enemy->GetMove();
	move.x += -move.x * 0.1f;
	move.z += -move.z * 0.1f;
	enemy->SetMove(move);
}