//=============================================
//
//�G�l�~�[�̏���[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================

//�C���N���[�h
#include "enemy.h"
#include "gamemanager.h"
#include "behavior_enemy_chase.h"

//�萔
const std::string CEnemy::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";	//�ǂݍ��ރt�@�C��(�G�̃��f�����Ȃ��̂ŉ��Ńv���C���[���o��)

//=============================================
//�R���X�g���N�^
//=============================================
CEnemy::CEnemy(int nPriority) :CCharacter(nPriority),
	m_Behavior(nullptr)
{

}

//=============================================
//�f�X�g���N�^
//=============================================
CEnemy::~CEnemy()
{
	
}

//=============================================
//������
//=============================================
HRESULT CEnemy::Init()
{
	CCharacter::Init();

	//�ړ��ʏ�����
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//�J�������擾
	CCamera* pCamera = GET_CAMERA;

	//�J�����̕����ݒ�
	pCamera->SetRot(VEC3_RESET_ZERO);

	SetPos({50.0f, 1.0f, 50.0f});

	//���[�u�l���
	SetMove(move);

	//�p�[�c�ǂݍ���
	Load_Parts(MODEL_FILE.c_str());

	CCharacter::SetLife(LIFE);

	SetMotion(MOTION_NEUTRAL);

	//���g���}�l�[�W���[�ɑ��
	CGameManager::GetInstance()->GetEnemyManager()->Regist(this);

	//�s���̑��
	SetBehavior(new CBehavior_Enemy_Chase(this));

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CEnemy::Uninit()
{
	//�e�N���X�̏I���������Ă�
	CCharacter::Uninit();

	delete m_Behavior;
}

//=============================================
//�X�V
//=============================================
void CEnemy::Update()
{
	//�L�����N�^�[�̍X�V
	CCharacter::Update();	

	//�s���̍X�V
	m_Behavior->Behavior(this);

	//�v���C���[�Ƃ̃q�b�g�m�F
	if (CheckHitPlayer())
	{
		HitPlayer();	//�q�b�g����
	}

	//���[�V��������
	Motion();				
}

//=============================================
//�`��
//=============================================
void CEnemy::Draw()
{
	//�e�N���X�̃��[�V�����p�̕`����Ă�
	MotionDraw();
}

//=============================================
//����
//=============================================
CEnemy* CEnemy::Create()
{
	CEnemy* pEnemy = new CEnemy;

	// null�Ȃ�null��Ԃ�
	if (pEnemy == nullptr) { return nullptr; }

	pEnemy->SetType(OBJECT_TYPE_ENEMY); //�^�C�v�ݒ�

	pEnemy->Init(); //����������

	return pEnemy;
}

//=============================================
//�s���̐ݒ�
//=============================================
void CEnemy::SetBehavior(CBehavior_Enemy* behavior)
{
	//���g�̔j��
	if (m_Behavior != nullptr)
	{
		delete m_Behavior;
		m_Behavior = nullptr;
	}

	//���
	m_Behavior = behavior;
}

//=============================================
//�v���C���[�Ƃ̃q�b�g�m�F
//=============================================
bool CEnemy::CheckHitPlayer()
{
	//�v���C���[�̎擾
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//�v���C���[�̋������Z�o
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();		//�v���C���[�̈ʒu���擾
	D3DXVECTOR3 Pos = GetPos();						//�����̈ʒu���擾

	//�����v�Z
	float fDistance = sqrtf((PlayerPos.x - Pos.x) * (PlayerPos.x - Pos.x) + (PlayerPos.z - Pos.z) * (PlayerPos.z - Pos.z));	//�v�Z

	//���̈ڍs���a���Ȃ�^
	if (fDistance > CCharacter::GetHitSize() * 2) return false;
}

//=============================================
//�v���C���[�Ƃ̃q�b�g����
//=============================================
void CEnemy::HitPlayer()
{
	//�v���C���[�̎擾
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//�̗͂����炷
	pPlayer->SetLife(pPlayer->GetLife() - 1);
}