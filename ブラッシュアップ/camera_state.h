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
	virtual void PlayerView(CCamera* camera); //3�l�̎��_
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
//�v���C���[�J����
//=============================================
class CPlayerView : public CCameraState
{
public:
	CPlayerView();
	~CPlayerView();
	virtual void PlayerView(CCamera* camera)override;
private:
	static const float PLAYERVIEW_CORRECT_X; //�v���C���[�r���[���̕␳�lX
	static const float PLAYERVIEW_CORRECT_Y; //�v���C���[�r���[���̕␳�lY
	static const float PLAYERVIEW_CORRECT_Z; //�v���C���[�r���[���̕␳�lZ

	static const float PLAYERVIEW_LENGTH;	//�v���C���[�r���[���̋���

	static const D3DXVECTOR3 START_ROT;		//�v���C���[�r���[���̊J�n����

	D3DXVECTOR3 m_rot;		//TODO:�J�����ɂ���̂ɁH
};

#endif // !_PLAYER_STATE_H