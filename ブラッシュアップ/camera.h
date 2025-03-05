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
class CCamera
{
public:
	//カメラタイプ宣言 TODO:ステートパターンで
	enum CANERA_TYPE
	{
		TYPE_DEBUG,
		TYPE_MAX,
	};

	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void SetCamera();
	void ResetCamera();

	void InputMove();

	void ChangeCameraState(CCameraState* state);

	//方向取得
	inline void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	}
	//視点取得
	inline void SetPosV(D3DXVECTOR3 posV)
	{
		m_posV = posV;
	}
	//注視点取得
	inline void SetPosR(D3DXVECTOR3 posR)
	{
		m_posR = posR;
	}

	inline void SetLength(float length)
	{
		m_fLength = length;
	}

	//方向取得
	inline D3DXVECTOR3 GetRot()
	{
		return m_rot;
	}

	//視点取得
	inline D3DXVECTOR3 GetPosV()
	{
		return m_posV;
	}
	//注視点取得
	inline D3DXVECTOR3 GetPosR()
	{
		return m_posR;
	}

	inline float& GetLength()
	{
		return m_fLength;
	}

	//カメラのデバック表示
	void DebugCameraDraw();

	CCameraState* m_pCameraState;
private:
	static constexpr float DEFAULT_MOVE = 1.0f; //通常時の移動
	static constexpr float DAMPING_COEFFICIENT = 0.2f; //移動抵抗

	static constexpr float DEFAULT_LENGTH_Y = 200.0f; //通常状態のYの距離
	static constexpr float DEFAULT_LENGTH_Z = 500.0f; //通常状態のZの距離

	static constexpr float BIRDVIEW_LENGTH_Y = 300.0f; //バードビュー時のYの距離

	static constexpr float SIDEVIEW_LENGTH_X = 20.0f; //サイドビュー時のXの距離
	static constexpr float SIDEVIEW_LENGTH_Y = 50.0f; //サイドビュー時のYの距離
	static constexpr float SIDEVIEW_LENGTH_Z = 200.0f; //サイドビュー時のZの距離

	static constexpr float THIRDVIEW_CORRECT_X = 20.0f; //サードパーソンビュー時の補正値X
	static constexpr float THIRDVIEW_CORRECT_Y = 105.0f; //サードパーソンビュー時の補正値Y
	static constexpr float THIRDVIEW_CORRECT_Z = 20.0f; //サードパーソンビュー時の補正値Z

	static constexpr float MOUSE_SENS = 0.001f; //デフォルトのマウス感度

	static constexpr float MAX_TURN_X = 0.5f; //サードパーソンビュー時のXの最大可動域
	static constexpr float MIN_TURN_X = -0.15f; //サードパーソンビュー時のXの最小可動域

	void CameraTurn(); //カメラ回転処理

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
