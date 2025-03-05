//=============================================
//
//カメラのステートパターン[camera_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "camera_state.h"
#include "manager.h"

//=============================================
//自由視点
//=============================================
void CCameraState::FreeView(CCamera* camera)
{
}

//=============================================
//三人称の状態
//=============================================
void CCameraState::ThirdView(CCamera* camera)
{
}

//=============================================
//ウルトの状態
//=============================================
void CCameraState::Ult(CCamera* camera)
{
}

//=============================================
//自由旋回状態
//=============================================
void CFreeView::FreeView(CCamera* camera)
{
	camera->SetLength(FREEVIEW_LENGTH);

	//入力
	camera->InputMove();
}