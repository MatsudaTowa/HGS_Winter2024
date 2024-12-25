//=============================================
//
//3DTemplate[equipment_gun.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gun.h"
#include "object.h"
#include "player.h"

//=============================================
//初期化
//=============================================
void CEquipment_Gun::Init()
{
	//変数宣言
	CPlayer* pPlayer = nullptr;
	bool bHit = false;

	//プレイヤーの足元にリースを生成予定

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
				pPlayer = dynamic_cast<CPlayer*>(pObj);
				bHit = true;
				break;
			}

			pObj = pNext;							//ポインタを進める
		}

		//プレイヤーを見つけたら抜ける
		if (bHit) { break; }
	}

}

//=============================================
//更新
//=============================================
void CEquipment_Gun::Update()
{

}