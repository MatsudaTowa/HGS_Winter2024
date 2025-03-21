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

//�J�����̐ݒ�p���O���
namespace CameraInfo
{
	const float DEFAULT_MOVE = 1.0f;				// �ʏ펞�̈ړ�
	const float DAMPING_COEFFICIENT = 0.2f;			// �ړ���R

	const float DEFAULT_LENGTH_Y = 200.0f;			//�ʏ��Ԃ�Y�̋���
	const float DEFAULT_LENGTH_Z = 500.0f;			//�ʏ��Ԃ�Z�̋���

	const float BIRDVIEW_LENGTH_Y = 300.0f;			//�o�[�h�r���[����Y�̋���

	const float MAX_TURN_X = 0.5f;					//�T�[�h�p�[�\���r���[����X�̍ő����
	const float MIN_TURN_X = -0.15f;				//�T�[�h�p�[�\���r���[����X�̍ŏ�����
}

//=============================================
//�R���X�g���N�^
//=============================================
CCamera::CCamera() :
	m_fAngle(FLOAT_ZERO),
	m_fLength(FLOAT_ZERO),
	m_moveR({ VEC3_RESET_ZERO }),
	m_moveV({ VEC3_RESET_ZERO }),
	m_mtxProjection(),
	m_mtxView(),
	m_pFreeView(),
	m_pCameraState(),
	m_posR({ VEC3_RESET_ZERO }),
	m_posV({ VEC3_RESET_ZERO }),
	m_rot({ VEC3_RESET_ZERO }),
	m_rotmove({ VEC3_RESET_ZERO }),
	m_vecU({ VEC3_RESET_ZERO })
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CCamera::~CCamera()
{
}

//=============================================
//������
//=============================================
HRESULT CCamera::Init()
{
	if (m_pCameraState == nullptr)
	{
		m_pCameraState = new CThirdView;
	}
	m_posV = D3DXVECTOR3(0.0f, 200.0f, -180.0f); //���_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //����

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f); //������x�N�g��

	m_moveV = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //���_�ړ���
	m_moveR = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�����_�ړ���

	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�p�x
	m_rotmove = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //��]��

	D3DXVECTOR3 vecCamera = m_posR - m_posV;
	m_fLength = sqrtf(vecCamera.y * vecCamera.y + vecCamera.z * vecCamera.z);

	//�Ίp���̊p�x���Z�o����
	m_fAngle = atan2f(vecCamera.y, vecCamera.z);
	return S_OK;
}

//=============================================
//�I��
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
//�X�V
//=============================================
void CCamera::Update()
{
	using namespace CameraInfo;	//���O��Ԃ̎g�p�錾

	if (m_pCameraState != nullptr)
	{
		m_pCameraState->FreeView(this);
		m_pCameraState->LockView(this);
		m_pCameraState->ThirdPersonView(this);
	}

	//�}�E�X���擾
	CInputMouse* pMouse = CManager::GetInstance()->GetMouse();
	m_rot.y += pMouse->GetMouseMove().x * 0.001f;
	m_rot.x += pMouse->GetMouseMove().y * 0.001f;

	if (m_rot.y > D3DX_PI)
	{
		m_rot.y = -D3DX_PI;
	}

	if (m_rot.y < -D3DX_PI)
	{
		m_rot.y = D3DX_PI;
	}

	if (m_rot.x > D3DX_PI)
	{
		m_rot.x = -D3DX_PI;
	}

	if (m_rot.x < -D3DX_PI)
	{
		m_rot.x = D3DX_PI;
	}

	m_posV = m_posR + D3DXVECTOR3(-m_fLength * cosf(m_rot.x) * sinf(m_rot.y),
		m_fLength * sinf(m_rot.x),
		-m_fLength * cosf(m_rot.x) * cosf(m_rot.y));

	m_posV += m_moveV;
	m_posR += m_moveR;

	//�ړ��ʂ��X�V(�����j
	m_moveV.x += (0.0f - m_moveV.x) * DAMPING_COEFFICIENT;
	m_moveV.y += (0.0f - m_moveV.y) * DAMPING_COEFFICIENT;
	m_moveV.z += (0.0f - m_moveV.z) * DAMPING_COEFFICIENT;

	m_moveR.x += (0.0f - m_moveR.x) * DAMPING_COEFFICIENT;
	m_moveR.y += (0.0f - m_moveR.y) * DAMPING_COEFFICIENT;
	m_moveR.z += (0.0f - m_moveR.z) * DAMPING_COEFFICIENT;

}

//=============================================
//���͏���
//=============================================
void CCamera::InputMove()
{
	using namespace CameraInfo;	//���O��Ԃ̎g�p�錾

	//�L�[�{�[�h���擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();

	if (pKeyboard->GetPress(DIK_A) == true)
	{
		m_moveV.x -= sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x -= sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z -= cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z -= cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_D) == true)
	{
		m_moveV.x += sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x += sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z += cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z += cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_W) == true)
	{
		m_moveV.x -= sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x -= sinf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z -= cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z -= cosf(D3DX_PI + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_S) == true)
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
//�J�����ݒ�
//=============================================
void CCamera::SetCamera()
{
	CRenderer* pRender = CManager::GetInstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		3000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	D3DXVECTOR3 posV = m_posV;
	D3DXVECTOR3 posR = m_posR;

	posV.y += -15.0f;
	posR.y += -15.0f;

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&posV,
		&posR,
		&m_vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//======================================
//�J�������Z�b�g
//======================================
void CCamera::ResetCamera()
{
	m_posV = D3DXVECTOR3(0.0f, 30.0f, -180.0f); //���_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //����

	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f); //������x�N�g��

	m_moveV = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //���_�ړ���
	m_moveR = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�����_�ړ���

	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�p�x
	m_rotmove = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //��]��

	D3DXVECTOR3 vecCamera = m_posR - m_posV;
	m_fLength = sqrtf(vecCamera.y * vecCamera.y + vecCamera.z * vecCamera.z);

	//�Ίp���̊p�x���Z�o����
	m_fAngle = atan2f(vecCamera.y, vecCamera.z);

}

//=============================================
//�J�����̏�ԕύX
//=============================================
void CCamera::ChangeCameraState(CCameraState* state)
{
	//���̃X�e�[�g�����������̃X�e�[�g�ɐ؂�ւ���
	if (m_pCameraState != nullptr)
	{
		delete m_pCameraState;
		m_pCameraState = state;
	}
}

//=============================================
//�J�����ړ���
//=============================================
void CCamera::CameraMove()
{
	using namespace CameraInfo;	//���O��Ԃ̎g�p�錾

	//�L�[�{�[�h���擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	D3DXVECTOR3 vecDirection(0.0f, 0.0f, 0.0f);

	if (pKeyboard->GetPress(DIK_J) == true)
	{
		m_moveV.x -= sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x -= sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z -= cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z -= cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

	}

	if (pKeyboard->GetPress(DIK_L) == true)
	{
		m_moveV.x += sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.x += sinf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

		m_moveV.z += cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;
		m_moveR.z += cosf(D3DX_PI / 2 + m_rot.y) * DEFAULT_MOVE;

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

}

//=============================================
//�J������]��
//=============================================
void CCamera::CameraTurn()
{
	//�L�[�{�[�h���擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
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
//�J�����̕����擾
//=============================================
D3DXVECTOR3 CCamera::GetRot()
{
	return m_rot;
}

//=============================================
//�J�����̎��_�擾
//=============================================
D3DXVECTOR3 CCamera::GetPosV()
{
	return m_posV;
}

//=============================================
//�J�����̒����_�擾
//=============================================
D3DXVECTOR3 CCamera::GetPosR()
{
	return m_posR;
}

//=============================================
//�����擾
//=============================================
float& CCamera::GetLength()
{
	return m_fLength;
}

//=============================================
//�J�����̃f�o�b�O�\��
//=============================================
void CCamera::DebugCameraDraw()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n\n\n\n\n\n\n[camera]\nposR:%.1f,%.1f,%.1f\nposV:%.1f,%.1f,%.1f\nrot:%.1f,%.1f,%.1f"
		, m_posR.x, m_posR.y, m_posR.z, m_posV.x, m_posV.y, m_posV.z, m_rot.x, m_rot.y, m_rot.z);
	//�e�L�X�g�̕`��
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG
}