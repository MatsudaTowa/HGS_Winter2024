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
	virtual void PlayerView(CCamera* camera); //3人称視点
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
//プレイヤーカメラ
//=============================================
class CPlayerView : public CCameraState
{
public:
	CPlayerView();
	~CPlayerView();
	virtual void PlayerView(CCamera* camera)override;
private:
	static const float PLAYERVIEW_CORRECT_X; //プレイヤービュー時の補正値X
	static const float PLAYERVIEW_CORRECT_Y; //プレイヤービュー時の補正値Y
	static const float PLAYERVIEW_CORRECT_Z; //プレイヤービュー時の補正値Z

	static const float PLAYERVIEW_LENGTH;	//プレイヤービュー時の距離

	static const D3DXVECTOR3 START_ROT;		//プレイヤービュー時の開始方向

	D3DXVECTOR3 m_rot;		//TODO:カメラにあるのに？
};

#endif // !_PLAYER_STATE_H