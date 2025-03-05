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
	virtual void FreeView(CCamera* camera);
	virtual void ThirdView(CCamera* camera);
	virtual void Ult(CCamera* camera);
};

//=============================================
//自由なカメラ
//=============================================
class CFreeView : public CCameraState
{
public:
	virtual void FreeView(CCamera* camera)override;
private:
	static constexpr float FREEVIEW_LENGTH = 200.0f; //自由視点時の距離
};
#endif // !_CAMERA_STATE_H
