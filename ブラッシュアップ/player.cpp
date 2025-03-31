//=============================================
//
//�v���C���[[player.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player.h"
#include "player_state.h"
#include "gamemanager.h"

//�X�|�[���ʒu
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_POS = { 0.0f, 0.5f, 0.0f };

//�X�|�[������
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 0.0f, 0.0f };

//�X���b�g�̊J�n�ʒu
const D3DXVECTOR3 CPlayer::SLOT_START_POS = { 490.0f, 690.0f,0.0f };

//���f���t�@�C��
const char* CPlayer::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";

//=============================================
//�R���X�g���N�^
//=============================================
CPlayer::CPlayer(int nPriority) :CCharacter(nPriority),
m_pPlayerState(nullptr),				//�v���C���[�̏�ԏ���
m_pHpGauge(nullptr),					//�v���C���[�̗̑�UI
m_pExpGauge(nullptr),					//�v���C���[�̌o���lUI
m_SlotPos(VEC3_RESET_ZERO),				//�X���b�g�̈ʒu
m_AttackCoolTime(FLOAT_ZERO),			//�U���N�[���^�C��
m_AttackCoolCnt(FLOAT_ZERO)				//�U���N�[���^�C���J�E���g
{
	//������nullptr���
	m_pEquipMent.fill(nullptr);

	//UI�̘g��nullptr���
	m_pEquipMentSlot.fill(nullptr);
}

//=============================================
//�f�X�g���N�^
//=============================================
CPlayer::~CPlayer()
{
	//�����֘A�폜
	for (int nCnt = 0; nCnt < MAX_EQUIPMENT; ++nCnt)
	{
		//�����폜
		if (m_pEquipMent[nCnt] != nullptr)
		{
			delete m_pEquipMent[nCnt];
			m_pEquipMent[nCnt] = nullptr;
		}

		//�����̃X���b�g�I��
		if (m_pEquipMentSlot[nCnt] != nullptr)
		{
			m_pEquipMentSlot[nCnt]->Uninit();
			m_pEquipMentSlot[nCnt] = nullptr;
		}
	}

	if (m_pHpGauge != nullptr)
	{
		m_pHpGauge->Uninit();
		m_pHpGauge = nullptr;
	}

	if (m_pExpGauge != nullptr)
	{
		m_pExpGauge->Uninit();
		m_pExpGauge = nullptr;
	}

	//�X�e�[�g�폜
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
		m_pPlayerState = nullptr;
	}
}

//=============================================
//������
//=============================================
HRESULT CPlayer::Init()
{
	CCharacter::Init();

	//�X���b�g�̍ŏ��Ɉʒu�ݒ�
	m_SlotPos = SLOT_START_POS;

	for (int nCnt = 0; nCnt < MAX_EQUIPMENT; ++nCnt)
	{
		//�����̃X���b�g����
		if (m_pEquipMentSlot[nCnt] == nullptr)
		{
			m_pEquipMentSlot[nCnt] = CEquipMent_Slot::Create(m_SlotPos);
		}

		m_SlotPos.x += CEquipMent_Slot::SIZE * 2;
	}

	if (m_pPlayerState == nullptr)
	{
		m_pPlayerState = new CMoveState;
	}

	//�ʏ�̃N�[���^�C���ݒ�
	m_AttackCoolTime = DEFAULT_COOLTIME;

	//�ړ��ʏ�����
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//�J�������擾
	CCamera* pCamera = GET_CAMERA;

	//���[�u�l���
	SetMove(move);

	//�ʒu�ݒ�
	SetPos(PLAYER_SPAWN_POS);

	//�����ݒ�
	SetRot(PLAYER_SPAWN_ROT);

	//�p�[�c�ǂݍ���
	Load_Parts(MODEL_FILE);

	CCharacter::SetLife(PLAYER_LIFE);

	if (m_pHpGauge == nullptr)
	{
		m_pHpGauge = CGauge_2D::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT - 80.0f,0.0f }, PLAYER_LIFE, CGauge_2D::GAUGE_LIFE);
	}

	if (m_pExpGauge == nullptr)
	{
		m_pExpGauge = CGauge_2D::Create({ SCREEN_WIDTH * 0.5f,10.0f,0.0f }, (float)ITEM_UI_UNLOCK_EXP, CGauge_2D::GAUGE_EXP);
	}

	SetMotion(MOTION_NEUTRAL);

	//�v���C���[���g���}�l�[�W���[�ɑ��
	CGameManager::GetInstance()->SetPlayer(this);

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CPlayer::Uninit()
{
	//�e�N���X�̏I���������Ă�
	CCharacter::Uninit();
}

//=============================================
//�X�V
//=============================================
void CPlayer::Update()
{
	Increment(m_AttackCoolCnt);

	if (m_AttackCoolCnt > m_AttackCoolTime)
	{
		m_AttackCoolCnt = 0;
	}

	if (m_pHpGauge != nullptr)
	{
		m_pHpGauge->SetValue(GetLife());
	}

	if (m_pExpGauge != nullptr)
	{
		m_pExpGauge->SetValue(m_fExp);
	}

	CCharacter::Update();

	Input();

	if (m_pPlayerState != nullptr)
	{
		m_pPlayerState->Move(this);
		m_pPlayerState->Attack(this);
	}

	Motion(); //���[�V��������
}

//=============================================
//�`��
//=============================================
void CPlayer::Draw()
{
	//�e�N���X�̃��[�V�����p�̕`����Ă�
	MotionDraw();
	//�v���C���[�̃f�o�b�O�\��
	DebugPos();
}

//=============================================
//����
//=============================================
CPlayer* CPlayer::Create()
{
	CPlayer* pPlayer = new CPlayer;

	// null�Ȃ�null��Ԃ�
	if (pPlayer == nullptr) { return nullptr; }

	pPlayer->SetType(OBJECT_TYPE_PLAYER); //�^�C�v�ݒ�

	pPlayer->Init(); //����������

	return pPlayer;
}

//=============================================
//��ԕύX
//=============================================
void CPlayer::ChangePlayerState(CPlayerState* state)
{
	//���̃X�e�[�g�����������̃X�e�[�g�ɐ؂�ւ���
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
		m_pPlayerState = state;
	}
}

//=============================================
//���X�|�[��
//=============================================
void CPlayer::ReSpawn()
{
	//�������g��pos�擾
	D3DXVECTOR3 PlayerPos = GetPos();

	//�X�|�[�����̐ݒ�ɂ��ǂ�
	SetPos(CPlayer::PLAYER_SPAWN_POS);
	SetRot(CPlayer::PLAYER_SPAWN_ROT);
	SetLife(CPlayer::PLAYER_LIFE);
}

//=============================================
//�ʒu���
//=============================================
void CPlayer::DebugPos()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n[player]\npos:%.1f,%.1f,%.1f\nrot:%.1f,%.1f,%.1f\nmove:%.1f,%.1f,%.1f\n�̗�:%d"
		, GetPos().x, GetPos().y, GetPos().z, GetRot().x, GetRot().y, GetRot().z, GetMove().x, GetMove().y, GetMove().z, GetLife());
	//�e�L�X�g�̕`��
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG
}

//=============================================
//���͏��
//=============================================
void CPlayer::Input()
{
	CInputMouse* pMouse = GET_INPUT_MOUSE;

	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;

	CCamera* pCamera = GET_CAMERA;

	CInputPad* pInput = GET_INPUT_PAD;

	//�ړ��̕����̒P�ʃx�N�g���ϐ�
	D3DXVECTOR3 vecDirection(VEC3_RESET_ZERO);

	vecDirection = { pInput->GetJoyStickVecL().x,0.0f, pInput->GetJoyStickVecL().y };

	float rotMoveY = CManager::GetInstance()->GetCamera()->GetRot().y + atan2f(vecDirection.x, vecDirection.z);

	//�ړ���
	D3DXVECTOR3 move = GetMove();

	if (vecDirection.x == 0.0f && vecDirection.z == 0.0f)
	{ // �����ĂȂ��B
		move.x = 0.0f;
		move.z = 0.0f;
	}
	else
	{
		move.x += sinf(rotMoveY) * GetSpeed();
		move.z += cosf(rotMoveY) * GetSpeed();
	}
	//�e�N���X����rot���擾
	D3DXVECTOR3 rot = GetRot();
	rot.y = rotMoveY + D3DX_PI;
	//rot����
	SetRot(rot);
	//�ړ��ʑ��
	SetMove(move);

#ifdef _DEBUG
	if (pKeyboard->GetTrigger(DIK_0))
	{
		int nLife = GetLife();
		nLife -= 10;
		SetLife(nLife);
	}
#endif // _DEBUG

}
