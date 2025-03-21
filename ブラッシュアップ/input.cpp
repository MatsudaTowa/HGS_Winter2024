//=============================================
//
//3DTemplate[input.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "input.h"
#include "manager.h"

//静的メンバ初期化
LPDIRECTINPUT8 CInput::m_pInput = nullptr;

//=============================================
//コンストラクタ
//=============================================
CInput::CInput()
{
	m_pDevice = nullptr;
}

//=============================================
//デストラクタ
//=============================================
CInput::~CInput()
{
}

//=============================================
//初期化
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
//終了
//=============================================
void CInput::Uninit()
{
	//入力デバイスの破棄
	if (m_pDevice != nullptr)
	{
		m_pDevice->Unacquire();
		m_pDevice = nullptr;
	}

	//DirectInputオブジェクトの破棄
	if (m_pInput != nullptr)
	{
		m_pInput->Release();
		m_pInput = nullptr;
	}
}

//↓からキーボード

//=============================================
//コンストラクタ
//=============================================
CInputKeyboard::CInputKeyboard()
{
}

//=============================================
//デストラクタ
//=============================================
CInputKeyboard::~CInputKeyboard()
{
}


//=============================================
//初期化
//=============================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);
	//入力デバイスの生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}
	//協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	//キーボードのアクセス権を獲得
	m_pDevice->Acquire();
	return S_OK;
}

//=============================================
//終了
//=============================================
void CInputKeyboard::Uninit()
{
	CInput::Uninit();
}

//=============================================
//更新
//=============================================
void CInputKeyboard::Update()
{
	BYTE aKeyState[NUM_KEY_MAX]; //入力情報
	int nCntKey;
	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & ~aKeyState[nCntKey]; //リリース
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyState[nCntKey] = aKeyState[nCntKey]; //キーボードのプレス情報を保存
		}
	}
	else
	{
		m_pDevice->Acquire(); //キーボードのアクセス権を獲得
	}
}

//=============================================
//キーボードの情報を取得
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

//↓からマウス

//=============================================
//コンストラクタ
//=============================================
CInputMouse::CInputMouse()
{
}

//=============================================
//デストラクタ
//=============================================
CInputMouse::~CInputMouse()
{
}

//=============================================
//初期化
//=============================================
HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	//入力デバイスの生成
	if (FAILED(m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}
	//データフォーマットを設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIMouse)))
	{
		return E_FAIL;
	}
	//協調モードを設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}
	// デバイスの設定
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
		// デバイスの設定に失敗
		return E_FAIL;
	}

	//マウスのアクセス権を獲得
	m_pDevice->Acquire();
	return S_OK;
}

//=============================================
//終了
//=============================================
void CInputMouse::Uninit()
{
	CInput::Uninit();
}

//=============================================
//更新
//=============================================
void CInputMouse::Update()
{

	DIMOUSESTATE zdiMouseState;
	int nCntMouse;

	//入力デバイスからデータを取得
	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(zdiMouseState), &zdiMouseState)))
	{
		for (nCntMouse = 0; nCntMouse < NUM_MOUSE_MAX; nCntMouse++)
		{
			m_KeyStateRelease.rgbButtons[nCntMouse] = (m_KeyState.rgbButtons[nCntMouse] ^ zdiMouseState.rgbButtons[nCntMouse]) & ~zdiMouseState.rgbButtons[nCntMouse];
			m_KeyStateTrigger.rgbButtons[nCntMouse] = (m_KeyState.rgbButtons[nCntMouse] ^ zdiMouseState.rgbButtons[nCntMouse]) & zdiMouseState.rgbButtons[nCntMouse];
			m_KeyState.rgbButtons[nCntMouse] = zdiMouseState.rgbButtons[nCntMouse]; //キーボードのプレス情報を保存
		}

		m_MouseMove.x = (float)zdiMouseState.lX;
		m_MouseMove.y = (float)zdiMouseState.lY;
	}
	else
	{
		m_pDevice->Acquire(); //キーボードのアクセス権を獲得
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
//マウスの情報を取得
//=============================================
bool CInputMouse::GetPress(int nKey)
{
	return(m_KeyState.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//マウスのトリガー取得
//=============================================
bool CInputMouse::GetTrigger(int nKey)
{
	return(m_KeyStateTrigger.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//マウスのリリース取得
//=============================================
bool CInputMouse::GetRelease(int nKey)
{
	return(m_KeyStateRelease.rgbButtons[nKey] & 0x80) != 0;
}
//=============================================
//マウスのムーブ値取得
//=============================================
D3DXVECTOR3 CInputMouse::GetMouseMove(void)
{
	return(m_MouseMove);
}

//=============================================
//マウスのデバッグ表示
//=============================================
void CInputMouse::Debug()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n\n\n\n\n\n\n\n\n\n\n[mouse]\nmove:%.1f,%.1f,%.1f"
		, m_MouseMove.x, m_MouseMove.y, m_MouseMove.z);
	//テキストの描画
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG


}

//↓からpad

//==========================================================================================
//コンストラクタ
//==========================================================================================
CInputPad::CInputPad()
{

}

//==========================================================================================
//デストラクタ
//==========================================================================================
CInputPad::~CInputPad()
{

}

//==========================================================================================
//コントローラーの初期化
//==========================================================================================
HRESULT CInputPad::Init(HINSTANCE hInstace, HWND hWnd)
{
	//メモリのクリア
	memset(&m_joyKeyState, 0, sizeof(XINPUT_STATE));

	//XInputEnableのステートを設定(有効にする)
	XInputEnable(true);

	return S_OK;
}

//==========================================================================================
//コントローラーの終了処理
//==========================================================================================
void CInputPad::Uninit()
{
	//XInputEnableのステートを設定(無効にする)
	XInputEnable(false);
}

//==========================================================================================
//コントローラーの更新処理
//==========================================================================================
void CInputPad::Update()
{
	XINPUT_STATE JoykeyState;
	//ジョイパッドの状態を取得
	if (XInputGetState(0, &JoykeyState) == ERROR_SUCCESS)
	{
		WORD Button = JoykeyState.Gamepad.wButtons;
		BYTE LeftTrigger = JoykeyState.Gamepad.bLeftTrigger;    // 左トリガーアナログコントロール
		BYTE RightTrigger = JoykeyState.Gamepad.bRightTrigger;   // 右トリガーアナログコントロール
		SHORT ThumbLX = JoykeyState.Gamepad.sThumbLX;       // 左スティックの X 軸
		SHORT ThumbLY = JoykeyState.Gamepad.sThumbLY;       // 左スティックの Y 軸
		SHORT ThumbRX = JoykeyState.Gamepad.sThumbRX;       // 右スティックの X 軸
		SHORT ThumbRY = JoykeyState.Gamepad.sThumbRY;       // 右スティックの Y 軸

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
		// 各スティックの入力値がデッドゾーン以下なら入力値を0にする
		if ((JoykeyState.Gamepad.sThumbLX <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
			JoykeyState.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
			(JoykeyState.Gamepad.sThumbLY <  XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
				JoykeyState.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
		{//左スティックがデッドゾーン内なので数値を無効
			JoykeyState.Gamepad.sThumbLX = 0;
			JoykeyState.Gamepad.sThumbLY = 0;
		}

		if ((JoykeyState.Gamepad.sThumbRX <  XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
			JoykeyState.Gamepad.sThumbRX >  -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
			(JoykeyState.Gamepad.sThumbRY <  XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
				JoykeyState.Gamepad.sThumbRY >  -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
		{//右スティックがデッドゾーン内なので数値を無効
			JoykeyState.Gamepad.sThumbRX = 0;
			JoykeyState.Gamepad.sThumbRY = 0;
		}
		m_joyKeyState = JoykeyState;

	}
}

//==========================================================================================
//コントローラーのプレス情報
//==========================================================================================
bool CInputPad::GetPress(JOYKEY key)
{
	//もし入力されたボタンがLT・RTならボタン入力に変換する
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
//コントローラーのトリガー情報
//==========================================================================================
bool CInputPad::GetTrigger(JOYKEY key)
{
	//もし入力されたボタンがLT・RTならボタン入力に変換する
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
//コントローラーのリリース(離した時)情報
//==========================================================================================
bool CInputPad::GetRelease(JOYKEY key)
{
	//もし入力されたボタンがLT・RTならボタン入力に変換する
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
//コントローラーのリピート(押され続けている)情報
//==========================================================================================
bool CInputPad::GetRepeat(JOYKEY key)
{

	//もし入力されたボタンがLT・RTならボタン入力に変換する
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
//左スティックの取得
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
//右スティックの取得
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
//左スティックの方向ベクトルを取得
//==========================================================================================
D3DXVECTOR2 CInputPad::GetJoyStickVecL()
{
	// 各スティックの入力値がデッドゾーン以下なら入力値を0にする
	if ((m_joyKeyState.Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		m_joyKeyState.Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ||
		(m_joyKeyState.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
			m_joyKeyState.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{//左スティック
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
//右スティックの方向ベクトルを取得
//==========================================================================================
D3DXVECTOR2 CInputPad::GetJoyStickVecR()
{
	// 各スティックの入力値がデッドゾーン以下なら入力値を0にする
	if ((m_joyKeyState.Gamepad.sThumbRX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		m_joyKeyState.Gamepad.sThumbRX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ||
		(m_joyKeyState.Gamepad.sThumbRY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
			m_joyKeyState.Gamepad.sThumbRY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{//左スティック
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
//スティックのトリガー判定の取得
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
//スティックのリリース判定の取得
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
//スティックのリピート判定の取得
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