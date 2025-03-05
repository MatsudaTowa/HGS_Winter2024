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
	virtual void FreeView(CCamera* camera);
	virtual void ThirdView(CCamera* camera);
	virtual void Ult(CCamera* camera);
};

//=============================================
//���R�ȃJ����
//=============================================
class CFreeView : public CCameraState
{
public:
	virtual void FreeView(CCamera* camera)override;
private:
	static constexpr float FREEVIEW_LENGTH = 200.0f; //���R���_���̋���
};
#endif // !_CAMERA_STATE_H
