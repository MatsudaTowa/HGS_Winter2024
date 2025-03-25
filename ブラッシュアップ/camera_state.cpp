
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
void CCameraState::PlayerView(CCamera* camera)
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

//�v���C���[�r���[���̕␳�l
const float CPlayerView::PLAYERVIEW_CORRECT_X = 20.0f;
const float CPlayerView::PLAYERVIEW_CORRECT_Y = 155.0f;
const float CPlayerView::PLAYERVIEW_CORRECT_Z = 20.0f;

//����
const float CPlayerView::PLAYERVIEW_LENGTH = 280.0f;

const D3DXVECTOR3 CPlayerView::START_ROT = { 0.7f,0.0f,0.0f };

//=============================================
//�R���X�g���N�^
//=============================================
CPlayerView::CPlayerView()
{
	m_rot = START_ROT;
}

//=============================================
//�f�X�g���N�^
//=============================================
CPlayerView::~CPlayerView()
{
}

//=============================================
//�v���C���[�J��������
//=============================================
void CPlayerView::PlayerView(CCamera* camera)
{
	camera->SetLength(PLAYERVIEW_LENGTH);
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

				posR.x = pPlayer->GetPos().x;
				posR.y = pPlayer->GetPos().y + PLAYERVIEW_CORRECT_Y;
				posR.z = pPlayer->GetPos().z;

				posV = posR + D3DXVECTOR3(camera->GetLength() * cosf(m_rot.x) * sinf(m_rot.y),
					camera->GetLength() * sinf(m_rot.x),
					camera->GetLength() * cosf(m_rot.x) * cosf(m_rot.y));

				//�������
				camera->SetRot(m_rot);
				//�����_���
				camera->SetPosR(posR);
				//���_���
				camera->SetPosV(posV);
			}

			pObj = pNext;  //�|�C���^��i�߂�
		}
	}
}
