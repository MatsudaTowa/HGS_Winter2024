//=============================================
//
//�v���C���[[player.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player.h"
#include "manager.h"
#include "player_state.h"

//�X�|�[���ʒu
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_POS = { 0.0f, 0.5f, 0.0f };

//�X�|�[������
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 3.14f, 0.0f };

//�ʏ�̃N�[���^�C��
const float CPlayer::DEFAULT_COOLTIME = 120.0f;

//=============================================
//�R���X�g���N�^
//=============================================
CPlayer::CPlayer(int nPriority):CCharacter(nPriority)
,m_pPlayerState(nullptr)		//�X�e�[�g�|�C���^�[������
,m_fAttackCoolTime(0.0f)		//�N�[���^�C��
,m_fAttackCoolCnt(0.0f)			//�N�[���^�C���J�E���g
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CPlayer::~CPlayer()
{
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
	}
}

//=============================================
//������
//=============================================
HRESULT CPlayer::Init()
{
	CCharacter::Init();

	if (m_pPlayerState == nullptr)
	{
		m_pPlayerState = new CMoveState;
	}

	//�N�[���^�C�����
	m_fAttackCoolTime = DEFAULT_COOLTIME;

	//�ړ��ʏ�����
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//�J�������擾
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	//�J�����̕����ݒ�
	pCamera->SetRot(VEC3_RESET_ZERO);

	//���[�u�l���
	SetMove(move);

	SetPos(PLAYER_SPAWN_POS);
	SetRot(PLAYER_SPAWN_ROT);

	//�p�[�c�ǂݍ���
	Load_Parts("data\\TEXT\\motion_HGSPlayer.txt");

	SetMotion(MOTION_NEUTRAL);
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
	CCharacter::Update();

	if (m_pPlayerState != nullptr)
	{
		m_pPlayerState->Move(this);
		m_pPlayerState->Attack(this);
	}

	m_fAttackCoolCnt += 1.0f;

	if (m_fAttackCoolCnt > m_fAttackCoolTime)
	{
		m_fAttackCoolCnt = 0.0f;
		ChangePlayerState(new CAttackState);
	}

	Input();

	Motion(GetNumParts()); //���[�V��������

}

//=============================================
//�`��
//=============================================
void CPlayer::Draw()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetMouse();
	pMouse->Debug();

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
//���͏���
//=============================================
void CPlayer::Input()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();

	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	//�ړ��̕����̒P�ʃx�N�g���ϐ�
	D3DXVECTOR3 vecDirection(0.0f, 0.0f, 0.0f);
	if (pKeyboard->GetPress(DIK_W))
	{
		vecDirection.z += 1.0f;
	}
	if (pKeyboard->GetPress(DIK_S))
	{
		vecDirection.z -= 1.0f;
	}
	if (pKeyboard->GetPress(DIK_A))
	{
		vecDirection.x -= 1.0f;
	}
	if (pKeyboard->GetPress(DIK_D))
	{
		vecDirection.x += 1.0f;
	}

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
}
