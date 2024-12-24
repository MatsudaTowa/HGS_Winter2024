//=============================================
//
//カメラのステートパターン[camera_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_STATE_H_
#define _CAMERA_STATE_H_

#include "camera.h"

//=============================================
//前方宣言
//=============================================
class CCamera;

//=============================================
//キャラクターのステートクラス
//=============================================
class CCameraState
{
public:
	virtual void FreeView(CCamera* camera); //自由旋回
	virtual void LockView(CCamera* camera); //視点ロック(配置はこっちで)
};

//=============================================
//自由旋回カメラ
//=============================================
class CFreeView : public CCameraState
{
public:
	virtual void FreeView(CCamera* camera)override;
private:
	static const float FREEVIEW_LENGTH; //サードパーソンビュー時の距離
};

//=============================================
//視点ロックカメラ
//=============================================
class CLockView : public CCameraState
{
public:
	CLockView();
	~CLockView();
	virtual void LockView(CCamera* camera)override;
private:
};

#endif // !_PLAYER_STATE_H
