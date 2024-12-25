//=============================================
//
//3DTemplate[input.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _INPUT_H_ //定義されてなかったら
#define _INPUT_H_ //２種インクルード防止
#include "main.h"

//インプットクラス
class CInput
{
public:
	CInput();
	~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;//端末ごとに
protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};

//キーボードクラス
class CInputKeyboard:public CInput
{
public:
	static const int NUM_KEY_MAX = 256; //キーボードのキー数
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;//端末ごとに
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
private:
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX]; //キーボードのトリガー情報
	BYTE m_aKeyStateRelease[NUM_KEY_MAX]; //キーボードのリリース情報
	BYTE m_aKeyState[NUM_KEY_MAX]; //キーボードのプレス情報
};

//マウスクラス
class CInputMouse :public CInput
{
public:
	static const int NUM_MOUSE_MAX = 3; //マウスのキー数
	CInputMouse();
	~CInputMouse();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;//端末ごとに
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
	D3DXVECTOR3 GetMouseMove(void);
	void Debug();
private:
	DIMOUSESTATE m_KeyStateTrigger; //マウスのトリガー情報
	DIMOUSESTATE m_KeyStateRelease; //マウスのリリース情報
	DIMOUSESTATE m_KeyState; //マウスのプレス情報
	DIMOUSESTATE m_zdiMouseMove; //マウスムーブ
	D3DXVECTOR3 m_MousePos;
	D3DXVECTOR3 m_MouseMove;
};

//padクラス
class CInputPad :public CInput
{
public:
	typedef enum
	{
		JOYPAD_DPAD_UP = 0,
		JOYPAD_DPAD_DOWN,
		JOYPAD_DPAD_LEFT,
		JOYPAD_DPAD_RIGHT,
		JOYPAD_START,
		JOYPAD_BACK,
		JOYPAD_LEFT_THUMB,
		JOYPAD_RIGHT_THUMB,
		JOYPAD_LEFT_SHOULDER,
		JOYPAD_RIGHT_SHOULDER,
		JOYPAD_RIGHT_TRIGGER,
		JOYPAD_LEFT_TRIGGER,
		JOYPAD_A,
		JOYPAD_B,
		JOYPAD_X,
		JOYPAD_Y,
		JOYPAD_MAX
	}JOYKEY;

	typedef enum
	{
		JOYSTICK_DLEFT = 0,
		JOYSTICK_DRIGHT,
		JOYSTICK_DUP,
		JOYSTICK_DDOWN
	}JOYSTICK;

	CInputPad();
	~CInputPad();
	HRESULT Init(HINSTANCE hInstace, HWND hWnd)override;

	void Uninit()override;
	void Update()override;

	bool GetPress(JOYKEY key);		//キーのプレス情報
	bool GetTrigger(JOYKEY key);	//キーのトリガー情報
	bool GetRelease(JOYKEY key);	//キーのリリース情報
	bool GetRepeat(JOYKEY key);		//キーのリピート情報

	bool GetJoyStickL(JOYSTICK joystick);						//左スティックの入力情報
	bool GetJoyStickR(JOYSTICK joystick);						//右スティックの入力情報
	bool GetJoyStickTrigger(JOYKEY joykey, JOYSTICK joystick);	//スティックのトリガー情報
	bool GetJoyStickRelease(JOYKEY joykey, JOYSTICK joystick);	//スティックのリリース情報
	bool GetJoyStickRepeat(JOYKEY joykey, JOYSTICK joystick);	//スティックのリピート情報

	D3DXVECTOR2 GetJoyStickVecL();
	D3DXVECTOR2 GetJoyStickVecR();

private:

	XINPUT_STATE m_joyKeyState;				//キーの入力情報
	XINPUT_STATE m_joyKeyOldState;			//キーの過去の入力情報
	XINPUT_STATE m_joyKeyStateTrigger;		//キーのトリガー判定情報
	XINPUT_STATE m_joyKeyStateRelease;		//キーのリリース判定情報
	XINPUT_STATE m_joyKeyStateRepeat;		//キーのリピート判定情報
};
#endif // _INPUT_H_ //定義されてなかったら