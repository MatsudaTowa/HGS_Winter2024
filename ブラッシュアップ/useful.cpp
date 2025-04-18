#include "useful.h"
bool JudgeBallCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length)
{
	D3DXVECTOR3 Vector = { 0.0f, 0.0f, 0.0f };     //ベクトル
	float fDistance = 0.0f; //距離
	bool bHit = false;      //当たっているか
	
	//２点間の距離を計算
	D3DXVec3Subtract(&Vector, &pos2, &pos1);
	
	// 差分ベクトルの長さ（距離）を計算
	fDistance = static_cast<float>(D3DXVec3Length(&Vector));
	
	//引数の範囲以下なら当たっている
	if (fDistance <= length)
	{
		bHit = true;
	}
	
	return bHit;
}