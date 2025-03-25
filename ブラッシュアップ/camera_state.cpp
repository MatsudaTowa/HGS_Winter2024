
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
void CCameraState::PlayerView(CCamera* camera)
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

//プレイヤービュー時の補正値
const float CPlayerView::PLAYERVIEW_CORRECT_X = 20.0f;
const float CPlayerView::PLAYERVIEW_CORRECT_Y = 155.0f;
const float CPlayerView::PLAYERVIEW_CORRECT_Z = 20.0f;

//距離
const float CPlayerView::PLAYERVIEW_LENGTH = 280.0f;

const D3DXVECTOR3 CPlayerView::START_ROT = { 0.7f,0.0f,0.0f };

//=============================================
//コンストラクタ
//=============================================
CPlayerView::CPlayerView()
{
	m_rot = START_ROT;
}

//=============================================
//デストラクタ
//=============================================
CPlayerView::~CPlayerView()
{
}

//=============================================
//プレイヤーカメラ処理
//=============================================
void CPlayerView::PlayerView(CCamera* camera)
{
	camera->SetLength(PLAYERVIEW_LENGTH);
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

				posR.x = pPlayer->GetPos().x;
				posR.y = pPlayer->GetPos().y + PLAYERVIEW_CORRECT_Y;
				posR.z = pPlayer->GetPos().z;

				posV = posR + D3DXVECTOR3(camera->GetLength() * cosf(m_rot.x) * sinf(m_rot.y),
					camera->GetLength() * sinf(m_rot.x),
					camera->GetLength() * cosf(m_rot.x) * cosf(m_rot.y));

				//方向代入
				camera->SetRot(m_rot);
				//注視点代入
				camera->SetPosR(posR);
				//視点代入
				camera->SetPosV(posV);
			}

			pObj = pNext;  //ポインタを進める
		}
	}
}
