//=============================================
//
//�v���C���[[player_test.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _PLAYER_TEST_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _PLAYER_TEST_H_
#include "main.h"
#include "model_parts.h"
#include "character.h"

class CPlayerState;
class UI_PlayerLife;

//�v���C���[�N���X
class CPlayer :public CCharacter
{
public:
	static const int MAX_KEY = 20; //�L�[�ő吔
	static const int PLAYER_LIFE = 150; //�̗�
	static const int PLAYER_PRIORITY = 8; //�`�揇
	static const char* MODEL_FAIL; //���f���̃t�@�C���p�X


	//���[�V�����̎�ނ̗�
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	CPlayer(int nPriority = PLAYER_PRIORITY);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	//�v���C���[�쐬
	static CPlayer* Create();

	void ChangePlayerState(CPlayerState* state);

	//�N�[���^�C���ݒ�
	void SetAttackCoolTime(float cooltime)
	{
		m_fAttackCoolTime = cooltime;
	}

private:

	//�v���C���[�̈ړ��֘A
	static const float DAMPING_COEFFICIENT; //�ړ���R
	static const int MAX_JUMPCNT; //�W�����v��
	static const int IGNORE_COLLISION_FRAME; //�����蔻�薳���t���[��
	static const int SMOKE_RECAST_FRAME; //�X���[�N�����t���[��
	static const float DEADZONE_Y; //������߂�����v���C���[�j��
	static const float DEFAULT_COOLTIME; //�f�t�H���g�̃N�[���^�C��

	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //�X�|�[���ʒu
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //�X�|�[������

	void ReSpawn(); //���X�|�[��

	void DebugPos();

	void Input(); //���͏���

	CPlayerState* m_pPlayerState;

	float m_fAttackCoolTime;	//�N�[���^�C��
<<<<<<< HEAD


	UI_PlayerLife* m_LifeUI;
=======
	float m_fAttackCoolCnt;	//�N�[���^�C��
>>>>>>> aca345994a80ef3cda6c7e1ef51159d7e4a59e4d
};
#endif