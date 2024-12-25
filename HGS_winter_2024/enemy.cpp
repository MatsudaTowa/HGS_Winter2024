//=============================================
//
//�G�̏���[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "enemy.h"
#include "weak_enemy.h"
#include "exp.h"

//�G�l�~�[����
int CEnemy::m_NumEnemy = 0;

//=============================================
//�R���X�g���N�^
//=============================================
CEnemy::CEnemy(int nPriority):CCharacter(nPriority)
{
	//�����ǉ�
	m_NumEnemy++;
}

//=============================================
//�f�X�g���N�^
//=============================================
CEnemy::~CEnemy()
{
	//��������
	m_NumEnemy--;
}

//=============================================
//������
//=============================================
HRESULT CEnemy::Init()
{
	CCharacter::Init();

	//�ړ��ʏ�����
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//���[�u�l���
	SetMove(move);

	m_Motion = CEnemy::Motion_Type::MOTION_MAX; //�j���[�g�����ɐݒ�

	SetMotion(MOTION_NEUTRAL);

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CEnemy::Uninit()
{
	int nRand = rand() % 3;
	CExp::Create(GetPos(), (CExp::EXP_TYPE)nRand); //�����_��)

	//�e�N���X�̏I���������Ă�
	CCharacter::Uninit();
}

//=============================================
//�X�V
//=============================================
void CEnemy::Update()
{
	CCharacter::Update();
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
CEnemy* CEnemy::Create(const D3DXVECTOR3& pos, const D3DXVECTOR3& rot, const ENEMY_TYPE& type)
{
	CEnemy* pEnemy = nullptr;

	switch (type)
	{
	case ENEMY_TYPE::ENEMY_TYPE_WEAK:
		pEnemy = new CWeakEnemy;
		break;
	//case ENEMY_TYPE::ENEMY_TYPE_BOSS:
	//	pEnemy = new CBossEnemy;
	//	pEnemy->Load_Parts("data\\motion_boss.txt");
	//	break;
	default:
		assert(false);
		break;
	}

	// null�Ȃ�null��Ԃ�
	if (pEnemy == nullptr) { return nullptr; }

	pEnemy->m_type = type;
	pEnemy->SetPos(pos); //pos�ݒ�
	pEnemy->SetRot(rot); //rot�ݒ�
	pEnemy->SetType(OBJECT_TYPE_ENEMY); //�^�C�v�ݒ�

	pEnemy->Init(); //����������

	return pEnemy;
}

//=============================================
//�_���[�W
//=============================================
void CEnemy::Damage(int nDamage)
{
	//�̗͎擾
	int nLife = GetLife();
	//��Ԃ��擾
	CCharacter::CHARACTER_STATE state = GetState();

	if (nLife > 0 && state != CCharacter::CHARACTER_STATE::CHARACTER_DAMAGE)
	{//�_���[�W��ԈȊO��HP���c���Ă���
		nLife -= nDamage;

		//�̗͑��
		SetLife(nLife);
	}
	if (nLife <= 0)
	{//HP��0�ȉ���������
		//�I��
		Uninit();
	}
}
