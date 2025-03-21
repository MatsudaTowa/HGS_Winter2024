//=============================================
//
//攻撃装備の処理[attack_equipment.cpp]
//Auther Yuuto Shimadu
//
//=============================================

//ヘッダーのインクルード
#include "attack_eqipment.h"

//=====================================================
//コンストラクタ
//=====================================================
CAttack_Equipment::CAttack_Equipment() :
	m_fCoolTime(0.0f),		//クールタイム
	m_fCoolTimeCount(0.0f),	//クールタイムのカウント
	m_bCanAttack(false)		//攻撃可能か
{

}

//=====================================================
//クールタイムの更新
//=====================================================
void CAttack_Equipment::UpdateCoolTime()
{
	m_fCoolTimeCount++;	//カウントアップ

	//クールタイムを終えたら
	if (m_fCoolTimeCount <= m_fCoolTime) return;

	//攻撃準備
	m_bCanAttack = true;		//フラグを立てる
	m_fCoolTimeCount = 0.0f;	//カウントを初期化

	//攻撃処理
	Attack();
}