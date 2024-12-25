//=============================================
//
//�^�C�}�[�����utimer.cpp�v
// Author���c�i�v
//
//=============================================
#include "timer.h"
#include "manager.h"

//�����Ƃɂ��炷
const float CTimer::DIGIT_SHIFT = 50.0f;

//=============================================
//�R���X�g���N�^
//=============================================
CTimer::CTimer() :m_nFrameCnt(0), m_nCurrentTime(0), m_pos(D3DXVECTOR3(0.0f, 0.0f, 0.0f))
{//�C�j�V�����C�U�[�ŃJ�E���^�[��,���̎���pos������

	//�^�C�}�[
	m_nCurrentTime = CTimer::LIMIT_TIME;
	//�����ʒu���
	m_pos = D3DXVECTOR3(660.0f, 50.0f, 0.0f);

	//�ŏ�����Z�b�g���邽��
	//m_nFrameCnt = 60;

	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		m_pNumber[nCnt] = nullptr;
	}
}

//=============================================
//�f�X�g���N�^
//=============================================
CTimer::~CTimer()
{
}

//=============================================
//������
//=============================================
HRESULT CTimer::Init()
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//�i���o�[����
		/*if (m_pNumber[nCnt] == nullptr)
		{
			m_pNumber[nCnt] = new CNumber();
		}*/

		if (m_pNumber[nCnt] == nullptr)
		{
			m_pNumber[nCnt] = CNumber_2D::Create(m_pos, D3DXVECTOR2(30.0f, 50.0f));
		}

		//���W�����炷
		m_pos.x -= DIGIT_SHIFT;
	}

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CTimer::Uninit()
{
	for (int nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		if (m_pNumber[nCnt] != nullptr)
		{
			m_pNumber[nCnt]->Uninit();
			//delete m_pNumber[nCnt];
			m_pNumber[nCnt] = nullptr;
		}
	}
}

//=============================================
//�X�V
//=============================================
void CTimer::Update()
{
	SetTimer();

	m_nFrameCnt++;

	if (m_nFrameCnt >= 60)
	{
		m_nCurrentTime--;
		m_nFrameCnt = 0;
	}

	if (m_nCurrentTime <= 0)
	{
		m_nCurrentTime = 0;
		CManager::GetInstance()->SetMode(CScene::MODE::MODE_RESULT);
	}
	////���_�ݒ�
	//SetTimerVtx();
}


//=============================================
//�^�C�}�[�p�̒��_����
//=============================================
void CTimer::SetTimer()
{
	//�e�N�X�`�����W�ݒ�
	int a_PosTexU[NUM_DIGIT];

	//���݌v�Z���Ă錅
	int nDigit = 1;
	int nCnt;
	for (nCnt = 0; nCnt < NUM_DIGIT; nCnt++)
	{
		//���̎��Ԃ���v�Z
		a_PosTexU[nCnt] = m_nCurrentTime / nDigit % 10;

		//����i�߂�
		nDigit *= 10;
	}

	for (nCnt = NUM_DIGIT - 1; nCnt >= 0; nCnt--)
	{
		//�e�N�X�`���̍��W�v�Z�p�ϐ�
		float fMinTexU, fMaxTexU;

		fMinTexU = a_PosTexU[nCnt] * 0.1f;
		fMaxTexU = fMinTexU + 0.1f;

		m_pNumber[nCnt]->SetNumber(fMinTexU, fMaxTexU, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	}
}