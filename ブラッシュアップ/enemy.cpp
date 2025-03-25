//=============================================
//
//�G�l�~�[�̏���[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================

//�C���N���[�h
#include "enemy.h"
#include "gamemanager.h"

//�萔
const std::string CEnemy::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";	//�ǂݍ��ރt�@�C��(�G�̃��f�����Ȃ��̂ŉ��Ńv���C���[���o��)

//=============================================
//�R���X�g���N�^
//=============================================
CEnemy::CEnemy(int nPriority) :CCharacter(nPriority)
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

	//���[�u�l���
	SetMove(move);

	//�p�[�c�ǂݍ���
	Load_Parts(MODEL_FILE.c_str());

	CCharacter::SetLife(LIFE);

	SetMotion(MOTION_NEUTRAL);

	//�v���C���[���g���}�l�[�W���[�ɑ��
	CGameManager::GetInstance()->SetEnemy(this);

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CEnemy::Uninit()
{
	//�e�N���X�̏I���������Ă�
	CCharacter::Uninit();
}

//=============================================
//�X�V
//=============================================
void CEnemy::Update()
{
	//�L�����N�^�[�̍X�V
	CCharacter::Update();	

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