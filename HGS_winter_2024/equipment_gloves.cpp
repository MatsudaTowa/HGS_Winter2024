//=============================================
//
//3DTemplate[equipment_gloves.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gloves.h"
#include "object.h"
#include "player.h"

//=============================================
//更新
//=============================================
void CEquipment_Gloves::Update()
{
	//プレイヤーの攻撃のクールタイムを減少予定
	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			//プレイヤーを見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			}

			pObj = pNext;							//ポインタを進める
		}
	}
}