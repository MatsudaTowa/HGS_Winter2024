//=============================================
//
//カメラのステートパターン[camera_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_STATE_H_
#define _CAMERA_STATE_H_

class CCamera;

//=============================================
//カメラのステートクラス
//=============================================
class CCameraState
{
public:
	virtual void FreeView(CCamera* camera); //自由旋回
	virtual void LockView(CCamera* camera); //視点ロック(配置はこっちで)
	virtual void ThirdPersonView(CCamera* camera); //3人称視点
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

//=============================================
//三人称カメラ
//=============================================
class CThirdView : public CCameraState
{
public:
	CThirdView();
	~CThirdView();
	virtual void ThirdPersonView(CCamera* camera)override;
private:
	static const float THIRDVIEW_CORRECT_X; //サードパーソンビュー時の補正値X
	static const float THIRDVIEW_CORRECT_Y; //サードパーソンビュー時の補正値Y
	static const float THIRDVIEW_CORRECT_Z; //サードパーソンビュー時の補正値Z

	static const float THIRDVIEW_LENGTH;	//サードビュー時の距離

	static const float MAX_TURN_X; //サードパーソンビュー時のXの最大可動域
	static const float MIN_TURN_X; //サードパーソンビュー時のXの最小可動域
};

#endif // !_PLAYER_STATE_H
