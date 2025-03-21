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
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 3.14f, 0.0f };

const char* CPlayer::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";

//=============================================
//�R���X�g���N�^
//=============================================
CPlayer::CPlayer(int nPriority) :CCharacter(nPriority),
m_pPlayerState(nullptr)
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

	//�ړ��ʏ�����
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//�J�������擾
	CCamera* pCamera = GET_CAMERA;

	//�J�����̕����ݒ�
	pCamera->SetRot(VEC3_RESET_ZERO);

	//���[�u�l���
	SetMove(move);

	SetPos(PLAYER_SPAWN_POS);
	SetRot(PLAYER_SPAWN_ROT);

	//�p�[�c�ǂݍ���
	Load_Parts(MODEL_FILE);

	CCharacter::SetLife(PLAYER_LIFE);

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
}
