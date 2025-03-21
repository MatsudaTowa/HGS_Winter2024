
//=============================================
//
//�J�����̃X�e�[�g�p�^�[��[camera_state.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "camera_state.h"
#include "manager.h"
#include "player.h"

//=============================================
//���R������(�e�ł͉������Ȃ�)
//=============================================
void CCameraState::FreeView(CCamera* camera)
{
}

//=============================================
//���E���b�N(�e�ł͉������Ȃ�)
//=============================================
void CCameraState::LockView(CCamera* camera)
{
}

//=============================================
//�O�l�̏���(�e�ł͉������Ȃ�)
//=============================================
void CCameraState::ThirdPersonView(CCamera* camera)
{
}

const float CFreeView::FREEVIEW_LENGTH = 200.0f;

//=============================================
//���R������
//=============================================
void CFreeView::FreeView(CCamera* camera)
{
	camera->SetLength(FREEVIEW_LENGTH);

	//����
	camera->InputMove();

	//�L�[�{�[�h���擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	if (pKeyboard->GetTrigger(DIK_V))
	{
		camera->ChangeCameraState(new CLockView);
	}
}

//=============================================
//�R���X�g���N�^
//=============================================
CLockView::CLockView()
{

}

//=============================================
//�f�X�g���N�^
//=============================================
CLockView::~CLockView()
{

}

//=============================================
//���E���b�N
//=============================================
void CLockView::LockView(CCamera* camera)
{
	//�L�[�{�[�h���擾
	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
	if (pKeyboard->GetTrigger(DIK_C))
	{
		camera->ChangeCameraState(new CFreeView);
	}
}

//�T�[�h�r���[���̕␳�l
const float CThirdView::THIRDVIEW_CORRECT_X = 20.0f;
const float CThirdView::THIRDVIEW_CORRECT_Y = 115.0f;
const float CThirdView::THIRDVIEW_CORRECT_Z = 20.0f;

//����
const float CThirdView::THIRDVIEW_LENGTH = 200.0f;

//�T�[�h�p�[�\���r���[����X�̍ő����
const float CThirdView::MAX_TURN_X = 0.5f;
//�T�[�h�p�[�\���r���[����X�̍ŏ�����
const float CThirdView::MIN_TURN_X = -0.15f;
//=============================================
//�R���X�g���N�^
//=============================================
CThirdView::CThirdView()
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CThirdView::~CThirdView()
{
}

//=============================================
//�O�l�̃J��������
//=============================================
void CThirdView::ThirdPersonView(CCamera* camera)
{
	camera->SetLength(THIRDVIEW_LENGTH);
	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //���̃|�C���^���擾

			//�v���C���[�������đ��x���グ��
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
				//�����_�擾
				D3DXVECTOR3 posR = camera->GetPosR();

				//���_�擾
				D3DXVECTOR3 posV = camera->GetPosV();

				//�����擾
				D3DXVECTOR3 rot = camera->GetRot();

				posR.x = pPlayer->GetPos().x;
				posR.y = pPlayer->GetPos().y + THIRDVIEW_CORRECT_Y;
				posR.z = pPlayer->GetPos().z;

				posV = posR + D3DXVECTOR3(-camera->GetLength() * cosf(rot.x) * sinf(rot.y),
					camera->GetLength() * sinf(rot.x),
					-camera->GetLength() * cosf(rot.x) * cosf(rot.y));

				//�}�E�X���擾
				CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

				rot.y += pMouse->GetMouseMove().x * 0.001f;
				rot.x += pMouse->GetMouseMove().y * 0.001f;

				if (rot.x <= MIN_TURN_X)
				{
					rot.x = MIN_TURN_X;
				}
				if (rot.x >= MAX_TURN_X)
				{
					rot.x = MAX_TURN_X;
				}

				//�������
				camera->SetRot(rot);
				//�����_���
				camera->SetPosR(posR);
				//���_���
				camera->SetPosV(posV);
			}

			pObj = pNext;  //�|�C���^��i�߂�
		}
	}
}
