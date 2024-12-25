//=============================================
//
//3DTemplate[input.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _INPUT_H_ //��`����ĂȂ�������
#define _INPUT_H_ //�Q��C���N���[�h�h�~
#include "main.h"

//�C���v�b�g�N���X
class CInput
{
public:
	CInput();
	~CInput();
	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;//�[�����Ƃ�
protected:
	static LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
};

//�L�[�{�[�h�N���X
class CInputKeyboard:public CInput
{
public:
	static const int NUM_KEY_MAX = 256; //�L�[�{�[�h�̃L�[��
	CInputKeyboard();
	~CInputKeyboard();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;//�[�����Ƃ�
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
private:
	BYTE m_aKeyStateTrigger[NUM_KEY_MAX]; //�L�[�{�[�h�̃g���K�[���
	BYTE m_aKeyStateRelease[NUM_KEY_MAX]; //�L�[�{�[�h�̃����[�X���
	BYTE m_aKeyState[NUM_KEY_MAX]; //�L�[�{�[�h�̃v���X���
};

//�}�E�X�N���X
class CInputMouse :public CInput
{
public:
	static const int NUM_MOUSE_MAX = 3; //�}�E�X�̃L�[��
	CInputMouse();
	~CInputMouse();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;//�[�����Ƃ�
	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRelease(int nKey);
	D3DXVECTOR3 GetMouseMove(void);
	void Debug();
private:
	DIMOUSESTATE m_KeyStateTrigger; //�}�E�X�̃g���K�[���
	DIMOUSESTATE m_KeyStateRelease; //�}�E�X�̃����[�X���
	DIMOUSESTATE m_KeyState; //�}�E�X�̃v���X���
	DIMOUSESTATE m_zdiMouseMove; //�}�E�X���[�u
	D3DXVECTOR3 m_MousePos;
	D3DXVECTOR3 m_MouseMove;
};

//pad�N���X
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

	bool GetPress(JOYKEY key);		//�L�[�̃v���X���
	bool GetTrigger(JOYKEY key);	//�L�[�̃g���K�[���
	bool GetRelease(JOYKEY key);	//�L�[�̃����[�X���
	bool GetRepeat(JOYKEY key);		//�L�[�̃��s�[�g���

	bool GetJoyStickL(JOYSTICK joystick);						//���X�e�B�b�N�̓��͏��
	bool GetJoyStickR(JOYSTICK joystick);						//�E�X�e�B�b�N�̓��͏��
	bool GetJoyStickTrigger(JOYKEY joykey, JOYSTICK joystick);	//�X�e�B�b�N�̃g���K�[���
	bool GetJoyStickRelease(JOYKEY joykey, JOYSTICK joystick);	//�X�e�B�b�N�̃����[�X���
	bool GetJoyStickRepeat(JOYKEY joykey, JOYSTICK joystick);	//�X�e�B�b�N�̃��s�[�g���

	D3DXVECTOR2 GetJoyStickVecL();
	D3DXVECTOR2 GetJoyStickVecR();

private:

	XINPUT_STATE m_joyKeyState;				//�L�[�̓��͏��
	XINPUT_STATE m_joyKeyOldState;			//�L�[�̉ߋ��̓��͏��
	XINPUT_STATE m_joyKeyStateTrigger;		//�L�[�̃g���K�[������
	XINPUT_STATE m_joyKeyStateRelease;		//�L�[�̃����[�X������
	XINPUT_STATE m_joyKeyStateRepeat;		//�L�[�̃��s�[�g������
};
#endif // _INPUT_H_ //��`����ĂȂ�������