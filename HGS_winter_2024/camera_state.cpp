//=============================================
//
//カメラのステートパターン[camera_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "camera_state.h"
#include "manager.h"
#include "player.h"

//=============================================
//自由旋回状態(親では何もしない)
//=============================================
void CCameraState::FreeView(CCamera* camera)
{
}

//=============================================
//視界ロック(親では何もしない)
//=============================================
void CCameraState::LockView(CCamera* camera)
{
}

//=============================================
//三人称処理(親では何もしない)
//=============================================
void CCameraState::ThirdPersonView(CCamera* camera)
{
}

const float CFreeView::FREEVIEW_LENGTH = 200.0f;

//=============================================
//自由旋回状態
//=============================================
void CFreeView::FreeView(CCamera* camera)
{
	camera->SetLength(FREEVIEW_LENGTH);

	//入力
	camera->InputMove();

	//キーボード情報取得
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	if (pKeyboard->GetTrigger(DIK_V))
	{
		camera->ChangeCameraState(new CLockView);
	}
}

//=============================================
//コンストラクタ
//=============================================
CLockView::CLockView()
{

}

//=============================================
//デストラクタ
//=============================================
CLockView::~CLockView()
{

}

//=============================================
//視界ロック
//=============================================
void CLockView::LockView(CCamera* camera)
{
	//キーボード情報取得
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	if (pKeyboard->GetTrigger(DIK_C))
	{
		camera->ChangeCameraState(new CFreeView);
	}
}

//サードビュー時の補正値
const float CThirdView::THIRDVIEW_CORRECT_X = 20.0f;
const float CThirdView::THIRDVIEW_CORRECT_Y = 115.0f;
const float CThirdView::THIRDVIEW_CORRECT_Z = 20.0f;

//距離
const float CThirdView::THIRDVIEW_LENGTH = 200.0f;

//サードパーソンビュー時のXの最大可動域
const float CThirdView::MAX_TURN_X = 0.5f;
//サードパーソンビュー時のXの最小可動域
const float CThirdView::MIN_TURN_X = -0.15f;
//=============================================
//コンストラクタ
//=============================================
CThirdView::CThirdView()
{
}

//=============================================
//デストラクタ
//=============================================
CThirdView::~CThirdView()
{
}

//=============================================
//三人称カメラ処理
//=============================================
void CThirdView::ThirdPersonView(CCamera* camera)
{
	camera->SetLength(THIRDVIEW_LENGTH);
	//プライオリティの数だけ周回
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //次のポインタを取得

			//プレイヤーを見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
				//注視点取得
				D3DXVECTOR3 posR = camera->GetPosR();

				//視点取得
				D3DXVECTOR3 posV = camera->GetPosV();

				//方向取得
				D3DXVECTOR3 rot = camera->GetRot();

				posR.x = pPlayer->GetPos().x;
				posR.y = pPlayer->GetPos().y + THIRDVIEW_CORRECT_Y;
				posR.z = pPlayer->GetPos().z;

				posV = posR + D3DXVECTOR3(-camera->GetLength() * cosf(rot.x) * sinf(rot.y),
					camera->GetLength() * sinf(rot.x),
					-camera->GetLength() * cosf(rot.x) * cosf(rot.y));

				//マウス情報取得
				CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

				rot.y += pMouse->GetMouseMove().x * 0.001f;
				rot.x += pMouse->GetMouseMove().y * 0.001f;

				if (rot.x <= MIN_TURN_X)
				{
					rot.x = MIN_TURN_X;
				}
				if (rot.x >= MAX_TURN_X)
				{
					rot.x = MAX_TURN_X;
				}

				//方向代入
				camera->SetRot(rot);
				//注視点代入
				camera->SetPosR(posR);
				//視点代入
				camera->SetPosV(posV);
			}

			pObj = pNext;  //ポインタを進める
		}
	}
}
