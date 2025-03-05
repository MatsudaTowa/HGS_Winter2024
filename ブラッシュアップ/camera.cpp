//=============================================
//
//3DTemplate[camera.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "camera.h"
#include "renderer.h"
#include "manager.h"
#include "object.h"

//=============================================
//コンストラクタ
//=============================================
CCamera::CCamera():
m_fAngle(FLOAT_ZERO),
m_fLength(FLOAT_ZERO),
m_moveR(VEC3_RESET_ZERO),
m_moveV(VEC3_RESET_ZERO),
m_mtxProjection(),
m_mtxView(),
m_pCameraState(),
m_posR(VEC3_RESET_ZERO),
m_posV(VEC3_RESET_ZERO),
m_rot(VEC3_RESET_ZERO),
m_rotmove(VEC3_RESET_ZERO),
m_vecU(VEC3_RESET_ZERO)
{
}

//=============================================
//デストラクタ
//=============================================
CCamera::~CCamera()
{
}

//=============================================
//初期化
//=============================================
HRESULT CCamera::Init()
{
	if (m_pCameraState == nullptr)
	{
		m_pCameraState = new CFreeView;
	}
	m_posV = D3DXVECTOR3(0.0f, 200.0f, -180.0f); //視点
	m_posR = D3DXVECTOR3(VEC3_RESET_ZERO); //注視

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f); //上方向ベクトル

	m_moveV = D3DXVECTOR3(VEC3_RESET_ZERO); //視点移動量
	m_moveR = D3DXVECTOR3(VEC3_RESET_ZERO); //注視点移動量

	m_rot = D3DXVECTOR3(VEC3_RESET_ZERO); //角度
	m_rotmove = D3DXVECTOR3(VEC3_RESET_ZERO); //回転量

	D3DXVECTOR3 vecCamera = m_posR - m_posV;
	m_fLength = sqrtf(vecCamera.y * vecCamera.y + vecCamera.z * vecCamera.z);

	//対角線の角度を算出する
	m_fAngle = atan2f(vecCamera.y, vecCamera.z);
	return S_OK;
}

//=============================================
//終了
//=============================================
void CCamera::Uninit()
{
	if (m_pCameraState != nullptr)
	{
		delete m_pCameraState;
		m_pCameraState = nullptr;
	}
}

//=============================================
//更新
//=============================================
void CCamera::Update()
{
	//キーボード情報取得
	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;

	if (m_pCameraState != nullptr)
	{
		m_pCameraState->ThirdView(this);
		m_pCameraState->FreeView(this);
		m_pCameraState->Ult(this);
	}

	//マウス情報取得
	CInputMouse* pMouse = GET_INPUT_MOUSE;

	m_rot.y += pMouse->GetMouseMove().x * MOUSE_SENS;
	m_rot.x += pMouse->GetMouseMove().y * MOUSE_SENS;

	m_posV = m_posR + D3DXVECTOR3(-m_fLength * cosf(m_rot.x) * sinf(m_rot.y),
		m_fLength * sinf(m_rot.x),
		-m_fLength * cosf(m_rot.x) * cosf(m_rot.y));

	if (m_rot.x <= MIN_TURN_X)
	{
		m_rot.x = MIN_TURN_X;
	}
	if (m_rot.x >= MAX_TURN_X)
	{
		m_rot.x = MAX_TURN_X;
	}

	if (m_rot.y > D3DX_PI)
	{
		m_rot.y = -D3DX_PI;
		//		m_rot.y -= D3DX_PI* 2.0f;
	}

	if (m_rot.y < -D3DX_PI)
	{
		m_rot.y = D3DX_PI;
	}

	if (m_rot.x > D3DX_PI)
	{
		m_rot.x = -D3DX_PI;
		//		m_rot.y -= D3DX_PI* 2.0f;
	}

	if (m_rot.x < -D3DX_PI)
	{
		m_rot.x = D3DX_PI;
	}

	m_posV += m_moveV;
	m_posR += m_moveR;

	//移動量を更新(減速）
	m_moveV.x += (FLOAT_ZERO - m_moveV.x) * DAMPING_COEFFICIENT;
	m_moveV.y += (FLOAT_ZERO - m_moveV.y) * DAMPING_COEFFICIENT;
	m_moveV.z += (FLOAT_ZERO - m_moveV.z) * DAMPING_COEFFICIENT;

	m_moveR.x += (FLOAT_ZERO - m_moveR.x) * DAMPING_COEFFICIENT;
	m_moveR.y += (FLOAT_ZERO - m_moveR.y) * DAMPING_COEFFICIENT;
	m_moveR.z += (FLOAT_ZERO - m_moveR.z) * DAMPING_COEFFICIENT;

}

//=============================================
//カメラ設定
//=============================================
void CCamera::SetCamera()
{
	//デバイス取得
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);

	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		3000.0f);

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	D3DXVECTOR3 posV = m_posV;
	D3DXVECTOR3 posR = m_posR;

	posV.y += -15.0f;
	posR.y += -15.0f;

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&m_mtxView,
		&posV,
		&posR,
		&m_vecU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//======================================
//カメラリセット
//======================================
void CCamera::ResetCamera()
{
	m_posV = D3DXVECTOR3(0.0f, 30.0f, -180.0f); //視点
	m_posR = D3DXVECTOR3(VEC3_RESET_ZERO); //注視

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f); //上方向ベクトル

	m_moveV = D3DXVECTOR3(VEC3_RESET_ZERO); //視点移動量
	m_moveR = D3DXVECTOR3(VEC3_RESET_ZERO); //注視点移動量

	m_rot = D3DXVECTOR3(VEC3_RESET_ZERO); //角度
	m_rotmove = D3DXVECTOR3(VEC3_RESET_ZERO); //回転量

	D3DXVECTOR3 vecCamera = m_posR - m_posV;
	m_fLength = sqrtf(vecCamera.y * vecCamera.y + vecCamera.z * vecCamera.z);

	//対角線の角度を算出する
	m_fAngle = atan2f(vecCamera.y, vecCamera.z);

}

//=============================================
//カメラ移動量
//=============================================
void CCamera::InputMove()
{
	//キーボード情報取得
	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;

	if (pKeyboard->GetPress(DIK_J) == true)
	{
		m_moveV.x -= sinf(HALF_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x -= sinf(HALF_PI + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z -= cosf(HALF_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z -= cosf(HALF_PI + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_L) == true)
	{
		m_moveV.x += sinf(HALF_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x += sinf(HALF_PI + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z += cosf(HALF_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z += cosf(HALF_PI + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_I) == true)
	{
		m_moveV.x -= sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x -= sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z -= cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z -= cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_K) == true)
	{
		m_moveV.x += sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x += sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z += cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z += cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
	}


	if (pKeyboard->GetPress(DIK_SPACE))
	{
		m_moveV.y += 1.0f;
		m_moveR.y += 1.0f;
	}

	if (pKeyboard->GetPress(DIK_LSHIFT))
	{
		m_moveV.y -= 1.0f;
		m_moveR.y -= 1.0f;
	}
}

//=============================================
//カメラの状態変更
//=============================================
void CCamera::ChangeCameraState(CCameraState* state)
{
	//今のステートを消し引数のステートに切り替える
	if (m_pCameraState != nullptr)
	{
		delete m_pCameraState;
		m_pCameraState = state;
	}
}

//=============================================
//カメラ回転量
//=============================================
void CCamera::CameraTurn()
{
	//キーボード情報取得
	CInputKeyboard* pKeyboard =	GET_INPUT_KEYBOARD;
	if (pKeyboard->GetPress(DIK_Q) == true)
	{
		m_rot.y -= 0.02f;

		m_posR.x = m_posV.x + sinf(m_rot.y) * m_fLength;
		m_posR.z = m_posV.z + cosf(m_rot.y) * m_fLength;

	}

	if (pKeyboard->GetPress(DIK_E) == true)
	{
		m_rot.y += 0.02f;
		m_posR.x = m_posV.x + sinf(m_rot.y) * m_fLength;
		m_posR.z = m_posV.z + cosf(m_rot.y) * m_fLength;
	}

	if (pKeyboard->GetPress(DIK_U) == true)
	{
		m_rot.y -= 0.02f;

		m_posV.x = m_posR.x - sinf(m_rot.y) * m_fLength;

		m_posV.z = m_posR.z - cosf(m_rot.y) * m_fLength;
	}

	if (pKeyboard->GetPress(DIK_O) == true)
	{
		m_rot.y += 0.02f;

		m_posV.x = m_posR.x - sinf(m_rot.y) * m_fLength;

		m_posV.z = m_posR.z - cosf(m_rot.y) * m_fLength;
	}
}

//=============================================
//カメラのデバッグ表示
//=============================================
void CCamera::DebugCameraDraw()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n\n\n\n\n\n\n\n\n[camera]\nposR:%.1f,%.1f,%.1f\nposV:%.1f,%.1f,%.1f\nrot:%.1f,%.1f,%.1f"
		, m_posR.x, m_posR.y, m_posR.z, m_posV.x, m_posV.y, m_posV.z, m_rot.x, m_rot.y, m_rot.z);
	//テキストの描画
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG
}
