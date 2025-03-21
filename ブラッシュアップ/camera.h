
//=============================================
//
//3DTemplate[camera.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CAMERA_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _CAMERA_H_
#include "main.h"
#include "input.h"
#include "camera_state.h"

class CCameraState;
class CFreeView;
class CCamera
{
public:
	//�J�����^�C�v�錾
	enum CANERA_TYPE
	{
		TYPE_FREE = 0,
		TYPE_LOCK,
		TYPE_TPS,
		TYPE_MAX,
	};

	CCamera();
	~CCamera();
	HRESULT Init();
	void Uninit();
	void Update();
	void InputMove();
	void SetCamera();
	void ResetCamera();

	void ChangeCameraState(CCameraState* state);

	//�����擾
	void SetRot(D3DXVECTOR3 rot)
	{
		m_rot = rot;
	}
	//���_�擾
	void SetPosV(D3DXVECTOR3 posV)
	{
		m_posV = posV;
	}
	//�����_�擾
	void SetPosR(D3DXVECTOR3 posR)
	{
		m_posR = posR;
	}

	void SetLength(float length)
	{
		m_fLength = length;
	}

	//�����擾
	D3DXVECTOR3 GetRot();
	//���_�擾
	D3DXVECTOR3 GetPosV();
	//�����_�擾
	D3DXVECTOR3 GetPosR();

	float& GetLength();

	//�J�����̃f�o�b�N�\��
	void DebugCameraDraw();

	CCameraState* m_pCameraState;
private:

	void CameraMove(); //�J�����ړ�����

	void CameraTurn(); //�J������]����

	CFreeView* m_pFreeView;

	D3DXVECTOR3 m_posV; //���_
	D3DXVECTOR3 m_posR; //�����_

	D3DXVECTOR3 m_moveV; //���_�ړ���
	D3DXVECTOR3 m_moveR; //�����_�ړ���

	D3DXVECTOR3 m_vecU; //������x�N�g��

	D3DXVECTOR3 m_rot; //����
	D3DXVECTOR3 m_rotmove; //��]��

	float m_fLength; //�ΏۂƂ̋���
	float m_fAngle; //�ΏۂƂ̑Ίp���̊p�x

	D3DXMATRIX m_mtxProjection; //�v���W�F�N�V����
	D3DXMATRIX m_mtxView; //�r���[�s��
};
#endif
