//=============================================
//
//�J�����̃X�e�[�g�p�^�[��[camera_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "camera_state.h"
#include "manager.h"

//=============================================
//���R���_
//=============================================
void CCameraState::FreeView(CCamera* camera)
{
}

//=============================================
//�O�l�̂̏��
//=============================================
void CCameraState::ThirdView(CCamera* camera)
{
}

//=============================================
//�E���g�̏��
//=============================================
void CCameraState::Ult(CCamera* camera)
{
}

//=============================================
//���R������
//=============================================
void CFreeView::FreeView(CCamera* camera)
{
	camera->SetLength(FREEVIEW_LENGTH);

	//����
	camera->InputMove();
}