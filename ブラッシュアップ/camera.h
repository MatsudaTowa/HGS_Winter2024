
//=============================================
//
//3DTemplate[camera.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_H_ //これが定義されてないとき

#define _CAMERA_H_
#include "main.h"
#include "input.h"
#include "camera_state.h"

class CCameraState;
class CFreeView;
class CCamera
{
public:
	//カメラタイプ宣言
	enum CANERA_TYPE
	{
		TYPE_FREE = 0,
		TYPE_LOCK,
		TYPE_TPS,
		TYPE_MAX,
	};

	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void InputMove();
	void SetCamera();
	void ResetCamera();

	void ChangeCameraState(CCameraState* state);

	//方向取得
	void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	}
	//視点取得
	void SetPosV(D3DXVECTOR3 posV)
	{
		m_posV = posV;
	}
	//注視点取得
	void SetPosR(D3DXVECTOR3 posR)
	{
		m_posR = posR;
	}

	void SetLength(float length)
	{
		m_fLength = length;
	}

	//方向取得
	D3DXVECTOR3 GetRot();
	//視点取得
	D3DXVECTOR3 GetPosV();
	//注視点取得
	D3DXVECTOR3 GetPosR();

	float& GetLength();

	//カメラのデバック表示
	void DebugCameraDraw();

	CCameraState* m_pCameraState;
private:

	void CameraMove(); //カメラ移動処理

	void CameraTurn(); //カメラ回転処理

	CFreeView* m_pFreeView;

	D3DXVECTOR3 m_posV; //視点
	D3DXVECTOR3 m_posR; //注視点

	D3DXVECTOR3 m_moveV; //視点移動量
	D3DXVECTOR3 m_moveR; //注視点移動量

	D3DXVECTOR3 m_vecU; //上方向ベクトル

	D3DXVECTOR3 m_rot; //方向
	D3DXVECTOR3 m_rotmove; //回転量

	float m_fLength; //対象との距離
	float m_fAngle; //対象との対角線の角度

	D3DXMATRIX m_mtxProjection; //プロジェクション
	D3DXMATRIX m_mtxView; //ビュー行列
};
#endif
