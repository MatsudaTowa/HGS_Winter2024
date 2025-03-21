//=============================================
//
//3DTemplate[input.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "input.h"
#include "manager.h"

//�ÓI�����o������
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//=============================================
//�R���X�g���N�^
//=============================================
CInput::CInput()
{
	m_pDevice = nullptr;
}

//=============================================
//�f�X�g���N�^
//=============================================
CInput::~CInput()
{
}

//=============================================
//������
//=============================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == nullptr)
	{
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
		{
			return E_FAIL;
		}
	}
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CInput::Uninit()
{
	//���̓f�o�C�X�̔j��
	if (m_pDevice != nullptr)
	{
		m_pDevice->Unacquire();
		m_pDevice = nullptr;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != nullptr)
	{
		m_pInput->Release();
		m_pInput = nullptr;
	}
}

//������L�[�{�[�h

//=============================================
//�R���X�g���N�^
//=============================================
CInputKeyboard::CInputKeyboard()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CInputKeyboard::~CInputKeyboard()
{
}


//=============================================
//������
//=============================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);
	//���̓f�o�C�X�̐���
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	//�L�[�{�[�h�̃A�N�Z�X�����l��
	m_pDevice->Acquire();
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CInputKeyboard::Uninit()
{
	CInput::Uninit();
}

//=============================================
//�X�V
//=============================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[NUM_KEY_MAX]; //���͏��
	int nCntKey;
	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & ~aKeyState[nCntKey]; //�����[�X
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyState[nCntKey] = aKeyState[nCntKey]; //�L�[�{�[�h�̃v���X����ۑ�
		}
	}
	else
	{
		m_pDevice->Acquire(); //�L�[�{�[�h�̃A�N�Z�X�����l��
	}
}

//=============================================
//�L�[�{�[�h�̏����擾
//=============================================
bool CInputKeyboard::GetPress(int nKey)
{
	return(m_aKeyState[nKey] & 0x80) != 0;
}
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) != 0;
}
bool CInputKeyboard::GetRelease(int nKey)
{
	return(m_aKeyStateRelease[nKey] & 0x80) != 0;
}

//������}�E�X

//=============================================
//�R���X�g���N�^
//=============================================
CInputMouse::CInputMouse()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CInputMouse::~CInputMouse()
{
}

//=============================================
//������
//=============================================
HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�̐���
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	//���̓f�o�C�X�̐���
	if (FAILED(m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse)))
	{
		return E_FAIL;
	}
	//�������[�h��ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	// �f�o�C�X�̐ݒ�
	DIPROPDWORD diprop;
	m_MousePos = { 0.0f,0.0f,0.0f };
	m_MouseMove = { 0.0f,0.0f,0.0f };
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;


	if (FAILED(m_pDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
	{
		// �f�o�C�X�̐ݒ�Ɏ��s
		return E_FAIL;
	}

	//�}�E�X�̃A�N�Z�X�����l��
	m_pDevice->Acquire();
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CInputMouse::Uninit()
{
	CInput::Uninit();
}

//=============================================
//�X�V
//=============================================
void CInputMouse::Update()
{

	DIMOUSESTATE zdiMouseState;
	int nCntMouse;

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(zdiMouseState), &zdiMouseState)))
	{
		for (nCntMouse = 0; nCntMouse < NUM_MOUSE_MAX; nCntMouse++)
		{
			m_KeyStateRelease.rgbButtons[nCntMouse] = (m_KeyState.rgbButtons[nCntMouse] ^ zdiMouseState.rgbButtons[nCntMouse]) & ~zdiMouseState.rgbButtons[nCntMouse];
			m_KeyStateTrigger.rgbButtons[nCntMouse] = (m_KeyState.rgbButtons[nCntMouse] ^ zdiMouseState.rgbButtons[nCntMouse]) & zdiMouseState.rgbButtons[nCntMouse];
			m_KeyState.rgbButtons[nCntMouse] = zdiMouseState.rgbButtons[nCntMouse]; //�L�[�{�[�h�̃v���X����ۑ�
		}

		m_MouseMove.x = (float)zdiMouseState.lX;
		m_MouseMove.y = (float)zdiMouseState.lY;
	}
	else
	{
		m_pDevice->Acquire(); //�L�[�{�[�h�̃A�N�Z�X�����l��
	}

	//ZeroMemory(&pMouseMove, sizeof(POINT));

	/*D3DXVECTOR3 OldMousePos = m_MousePos;

	POINT pMouseMove;

	GetCursorPos(&pMouseMove);*/

	/*m_MousePos.x = (float)zdiMouseState.lX;
	m_MousePos.y = (float)zdiMouseState.lY;*/

	//m_MouseMove.z = m_MousePos.z - OldMousePos.z;
}

//=============================================
//�}�E�X�̏����擾
//=============================================
bool CInputMouse::GetPress(int nKey)
{
	return(m_KeyState.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//�}�E�X�̃g���K�[�擾
//=============================================
bool CInputMouse::GetTrigger(int nKey)
{
	return(m_KeyStateTrigger.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//�}�E�X�̃����[�X�擾
//=============================================
bool CInputMouse::GetRelease(int nKey)
{
	return(m_KeyStateRelease.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//�}�E�X�̃��[�u�l�擾
//=============================================
D3DXVECTOR3 CInputMouse::GetMouseMove(void)
{
	return(m_MouseMove);
}

//=============================================
//�}�E�X�̃f�o�b�O�\��
//=============================================
void CInputMouse::Debug()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n\n\n\n\n\n\n\n\n\n\n[mouse]\nmove:%.1f,%.1f,%.1f"
		, m_MouseMove.x, m_MouseMove.y, m_MouseMove.z);
	//�e�L�X�g�̕`��
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG


}

//������pad

//==========================================================================================
//�R���X�g���N�^
//==========================================================================================
CInputPad::CInputPad()
{

}

//==========================================================================================
//�f�X�g���N�^
//==========================================================================================
CInputPad::~CInputPad()
{

}

//==========================================================================================
//�R���g���[���[�̏�����
//==========================================================================================
HRESULT CInputPad::Init(HINSTANCE hInstace, HWND hWnd)
{
	//�������̃N���A
	memset(&m_joyKeyState, 0, sizeof(XINPUT_STATE));

	//XInputEnable�̃X�e�[�g��ݒ�(�L���ɂ���)
	XInputEnable(true);

	return S_OK;
}

//==========================================================================================
//�R���g���[���[�̏I������
//==========================================================================================
void CInputPad::Uninit()
{
	//XInputEnable�̃X�e�[�g��ݒ�(�����ɂ���)
	XInputEnable(false);
}

//==========================================================================================
//�R���g���[���[�̍X�V����
//==========================================================================================
void CInputPad::Update()
{
	XINPUT_STATE JoykeyState;
	//�W���C�p�b�h�̏�Ԃ��擾
	if (XInputGetState(0, &JoykeyState) == ERROR_SUCCESS)
	{
		WORD Button = JoykeyState.Gamepad.wButtons;
		BYTE LeftTrigger = JoykeyState.Gamepad.bLeftTrigger;    // ���g���K�[�A�i���O�R���g���[��
		BYTE RightTrigger = JoykeyState.Gamepad.bRightTrigger;   // �E�g���K�[�A�i���O�R���g���[��
		SHORT ThumbLX = JoykeyState.Gamepad.sThumbLX;       // ���X�e�B�b�N�� X ��
		SHORT ThumbLY = JoykeyState.Gamepad.sThumbLY;       // ���X�e�B�b�N�� Y ��
		SHORT ThumbRX = JoykeyState.Gamepad.sThumbRX;       // �E�X�e�B�b�N�� X ��
		SHORT ThumbRY = JoykeyState.Gamepad.sThumbRY;       // �E�X�e�B�b�N�� Y ��

		WORD OldButton = m_joyKeyState.Gamepad.wButtons;
		WORD OldLeftTrigger = m_joyKeyState.Gamepad.bLeftTrigger;
		WORD OldRightTrigger = m_joyKeyState.Gamepad.bRightTrigger;
		m_joyKeyOldState = m_joyKeyState;


		m_joyKeyStateTrigger.Gamepad.wButtons = ~OldButton & Button;
		m_joyKeyStateTrigger.Gamepad.bLeftTrigger = ~OldLeftTrigger & LeftTrigger;
		m_joyKeyStateTrigger.Gamepad.bRightTrigger = ~OldRightTrigger & RightTrigger;

		m_joyKeyStateRelease.Gamepad.wButtons = OldButton & ~Button;
		m_joyKeyStateRelease.Gamepad.bLeftTrigger = OldLeftTrigger & ~LeftTrigger;
		m_joyKeyStateRelease.Gamepad.bRightTrigger = OldRightTrigger & ~RightTrigger;

		m_joyKeyStateRepeat.Gamepad.wButtons = OldButton & Button;
		m_joyKeyStateRepeat.Gamepad.bLeftTrigger = OldLeftTrigger & LeftTrigger;
		m_joyKeyStateRepeat.Gamepad.bRightTrigger = OldRightTrigger & RightTrigger;


		//XINPUT_STATE state;
		//ZeroMemory(&state, sizeof(XINPUT_STATE));
		// �e�X�e�B�b�N�̓��͒l���f�b�h�]�[���ȉ��Ȃ���͒l��0�ɂ���
		if ((JoykeyState.Gamepad.sThumbLX <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			JoykeyState.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(JoykeyState.Gamepad.sThumbLY <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
				JoykeyState.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
		{//���X�e�B�b�N���f�b�h�]�[�����Ȃ̂Ő��l�𖳌�
			JoykeyState.Gamepad.sThumbLX = 0;
			JoykeyState.Gamepad.sThumbLY = 0;
		}

		if ((JoykeyState.Gamepad.sThumbRX <  XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
			JoykeyState.Gamepad.sThumbRX >  -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
			(JoykeyState.Gamepad.sThumbRY <  XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
				JoykeyState.Gamepad.sThumbRY >  -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
		{//�E�X�e�B�b�N���f�b�h�]�[�����Ȃ̂Ő��l�𖳌�
			JoykeyState.Gamepad.sThumbRX = 0;
			JoykeyState.Gamepad.sThumbRY = 0;
		}
		m_joyKeyState = JoykeyState;

	}
}

//==========================================================================================
//�R���g���[���[�̃v���X���
//==========================================================================================
bool CInputPad::GetPress(JOYKEY key)
{
	//�������͂��ꂽ�{�^����LT�ERT�Ȃ�{�^�����͂ɕϊ�����
	if (key == JOYPAD_LEFT_TRIGGER)
	{
		return (m_joyKeyState.Gamepad.bLeftTrigger & key) ? true : false;
	}
	else if (key == JOYPAD_RIGHT_TRIGGER)
	{
		return (m_joyKeyState.Gamepad.bRightTrigger & key) ? true : false;
	}
	else
	{
		return (m_joyKeyState.Gamepad.wButtons & (0x01 << key)) ? true : false;
	}
}

//==========================================================================================
//�R���g���[���[�̃g���K�[���
//==========================================================================================
bool CInputPad::GetTrigger(JOYKEY key)
{
	//�������͂��ꂽ�{�^����LT�ERT�Ȃ�{�^�����͂ɕϊ�����
	if (key == JOYPAD_LEFT_TRIGGER)
	{
		return (m_joyKeyStateTrigger.Gamepad.bLeftTrigger & key) ? true : false;
	}
	else if (key == JOYPAD_RIGHT_TRIGGER)
	{
		return (m_joyKeyStateTrigger.Gamepad.bRightTrigger & key) ? true : false;
	}
	else
	{
		return (m_joyKeyStateTrigger.Gamepad.wButtons & (0x01 << key)) ? true : false;
	}
}

//==========================================================================================
//�R���g���[���[�̃����[�X(��������)���
//==========================================================================================
bool CInputPad::GetRelease(JOYKEY key)
{
	//�������͂��ꂽ�{�^����LT�ERT�Ȃ�{�^�����͂ɕϊ�����
	if (key == JOYPAD_LEFT_TRIGGER)
	{
		return (m_joyKeyStateRelease.Gamepad.bLeftTrigger & key) ? true : false;
	}
	else if (key == JOYPAD_RIGHT_TRIGGER)
	{
		return (m_joyKeyStateRelease.Gamepad.bRightTrigger & key) ? true : false;
	}
	else
	{
		return (m_joyKeyStateRelease.Gamepad.wButtons & (0x01 << key)) ? true : false;
	}
}

//==========================================================================================
//�R���g���[���[�̃��s�[�g(�����ꑱ���Ă���)���
//==========================================================================================
bool CInputPad::GetRepeat(JOYKEY key)
{

	//�������͂��ꂽ�{�^����LT�ERT�Ȃ�{�^�����͂ɕϊ�����
	if (key == JOYPAD_LEFT_TRIGGER)
	{
		return (m_joyKeyStateRepeat.Gamepad.bLeftTrigger & key) ? true : false;
	}
	else if (key == JOYPAD_RIGHT_TRIGGER)
	{
		return (m_joyKeyStateRepeat.Gamepad.bRightTrigger & key) ? true : false;
	}
	else
	{
		return (m_joyKeyStateRepeat.Gamepad.wButtons & (0x01 << key)) ? true : false;
	}
}

//==========================================================================================
//���X�e�B�b�N�̎擾
//==========================================================================================
bool CInputPad::GetJoyStickL(JOYSTICK joystick)
{
	switch (joystick)
	{
	case JOYSTICK_DLEFT:
		return m_joyKeyState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DRIGHT:
		return m_joyKeyState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DUP:
		return m_joyKeyState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DDOWN:
		return m_joyKeyState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
		break;
	}
}

//==========================================================================================
//�E�X�e�B�b�N�̎擾
//==========================================================================================
bool CInputPad::GetJoyStickR(JOYSTICK joystick)
{
	switch (joystick)
	{
	case JOYSTICK_DLEFT:
		return m_joyKeyState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DRIGHT:
		return m_joyKeyState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DUP:
		return m_joyKeyState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
		break;
	case JOYSTICK_DDOWN:
		return m_joyKeyState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
		break;
	}
}

//==========================================================================================
//���X�e�B�b�N�̕����x�N�g�����擾
//==========================================================================================
D3DXVECTOR2 CInputPad::GetJoyStickVecL()
{
	// �e�X�e�B�b�N�̓��͒l���f�b�h�]�[���ȉ��Ȃ���͒l��0�ɂ���
	if ((m_joyKeyState.Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		m_joyKeyState.Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ||
		(m_joyKeyState.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
			m_joyKeyState.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{//���X�e�B�b�N
		float VecX = sinf(atan2f((float)m_joyKeyState.Gamepad.sThumbLX * 0.01f, (float)m_joyKeyState.Gamepad.sThumbLY * 0.01f));
		float VecY = cosf(atan2f((float)m_joyKeyState.Gamepad.sThumbLX * 0.01f, (float)m_joyKeyState.Gamepad.sThumbLY * 0.01f));
		return { VecX ,VecY };
	}
	else
	{
		return { 0.0f,0.0f };
	}

}
//==========================================================================================
//�E�X�e�B�b�N�̕����x�N�g�����擾
//==========================================================================================
D3DXVECTOR2 CInputPad::GetJoyStickVecR()
{
	// �e�X�e�B�b�N�̓��͒l���f�b�h�]�[���ȉ��Ȃ���͒l��0�ɂ���
	if ((m_joyKeyState.Gamepad.sThumbRX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		m_joyKeyState.Gamepad.sThumbRX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ||
		(m_joyKeyState.Gamepad.sThumbRY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
			m_joyKeyState.Gamepad.sThumbRY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{//���X�e�B�b�N
		float VecX = sinf(atan2f((float)m_joyKeyState.Gamepad.sThumbRX * 0.01f, (float)m_joyKeyState.Gamepad.sThumbRY * 0.01f));
		float VecY = cosf(atan2f((float)m_joyKeyState.Gamepad.sThumbRX * 0.01f, (float)m_joyKeyState.Gamepad.sThumbRY * 0.01f));
		return { VecX ,VecY };
	}
	else
	{
		return { 0.0f,0.0f };
	}

}
//==========================================================================================
//�X�e�B�b�N�̃g���K�[����̎擾
//==========================================================================================
bool CInputPad::GetJoyStickTrigger(JOYKEY joykey, JOYSTICK joystick)
{
	if (joykey == JOYPAD_LEFT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
	else if (joykey == JOYPAD_RIGHT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
}
//==========================================================================================
//�X�e�B�b�N�̃����[�X����̎擾
//==========================================================================================
bool CInputPad::GetJoyStickRelease(JOYKEY joykey, JOYSTICK joystick)
{
	if (joykey == JOYPAD_LEFT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbLX >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbLX <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbLY <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbLY >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
	else if (joykey == JOYPAD_RIGHT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbRX >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbRX <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbRY <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbRY >= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
}
//==========================================================================================
//�X�e�B�b�N�̃��s�[�g����̎擾
//==========================================================================================
bool CInputPad::GetJoyStickRepeat(JOYKEY joykey, JOYSTICK joystick)
{
	if (joykey == JOYPAD_LEFT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
	else if (joykey == JOYPAD_RIGHT_THUMB)
	{
		switch (joystick)
		{
		case JOYSTICK_DLEFT:
			return (m_joyKeyState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DRIGHT:
			return (m_joyKeyState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DUP:
			return (m_joyKeyState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		case JOYSTICK_DDOWN:
			return (m_joyKeyState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && m_joyKeyOldState.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
			break;
		}
	}
}