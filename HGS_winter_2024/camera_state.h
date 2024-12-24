//=============================================
//
//�J�����̃X�e�[�g�p�^�[��[camera_state.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_STATE_H_
#define _CAMERA_STATE_H_

#include "camera.h"

//=============================================
//�O���錾
//=============================================
class CCamera;

//=============================================
//�L�����N�^�[�̃X�e�[�g�N���X
//=============================================
class CCameraState
{
public:
	virtual void FreeView(CCamera* camera); //���R����
	virtual void LockView(CCamera* camera); //���_���b�N(�z�u�͂�������)
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

#endif // !_PLAYER_STATE_H
