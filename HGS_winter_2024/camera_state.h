//=============================================
//
//�J�����̃X�e�[�g�p�^�[��[camera_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_STATE_H_
#define _CAMERA_STATE_H_

class CCamera;

//=============================================
//�J�����̃X�e�[�g�N���X
//=============================================
class CCameraState
{
public:
	virtual void FreeView(CCamera* camera); //���R����
	virtual void LockView(CCamera* camera); //���_���b�N(�z�u�͂�������)
	virtual void ThirdPersonView(CCamera* camera); //3�l�̎��_
};

//=============================================
//���R����J����
//=============================================
class CFreeView : public CCameraState
{
public:
	virtual void FreeView(CCamera* camera)override;
private:
	static const float FREEVIEW_LENGTH; //�T�[�h�p�[�\���r���[���̋���
};

//=============================================
//���_���b�N�J����
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
//�O�l�̃J����
//=============================================
class CThirdView : public CCameraState
{
public:
	CThirdView();
	~CThirdView();
	virtual void ThirdPersonView(CCamera* camera)override;
private:
	static const float THIRDVIEW_CORRECT_X; //�T�[�h�p�[�\���r���[���̕␳�lX
	static const float THIRDVIEW_CORRECT_Y; //�T�[�h�p�[�\���r���[���̕␳�lY
	static const float THIRDVIEW_CORRECT_Z; //�T�[�h�p�[�\���r���[���̕␳�lZ

	static const float THIRDVIEW_LENGTH;	//�T�[�h�r���[���̋���

	static const float MAX_TURN_X; //�T�[�h�p�[�\���r���[����X�̍ő����
	static const float MIN_TURN_X; //�T�[�h�p�[�\���r���[����X�̍ŏ�����
};

#endif // !_PLAYER_STATE_H
