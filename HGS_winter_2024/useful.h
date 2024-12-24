//=============================================
//
//実用的な処理をまとめたもの[useful.h]
//Auther Matsuda Towa?
//
//=============================================

//２重インクルード防止
#ifndef _USEFUL_H_ //これが定義されてないとき
#define _USEFUL_H_

#include "main.h"

//当たり判定系
bool JudgeBallCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length);	//円の当たり判定(位置、位置、判定する長さ)

//計算系


//自動開放
template<class T>
constexpr void SafeDelete(T& p)
{
	if (p == nullptr) { return; }
	delete p;
	p = nullptr;
}

#endif