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
#include "equipment.h"

class CPlayerState;
class UI_PlayerLife;
class UI_PlayerExp;
class CEquipment;

//�v���C���[�N���X
class CPlayer :public CCharacter
{
public:
	static const int MAX_KEY = 20; //�L�[�ő吔
	static const int PLAYER_LIFE = 150; //�̗�
	static const int PLAYER_PRIORITY = 8; //�`�揇
	static const char* MODEL_FAIL; //���f���̃t�@�C���p�X
	static constexpr float LEVEL_WINDOW = 50.0f;


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

	float& GetAttackCoolTime()
	{
		return m_fAttackCoolTime;
	}

	float& GetExp()
	{
		return m_fExp;
	}

	void AddExp(float exp)
	{
		m_fExp += exp;
	}

	//�N�[���^�C���ݒ�
	void SetAttackCoolTime(float cooltime)
	{
		m_fAttackCoolTime = cooltime;
	}

	void SetSoubi(int num);

private:

	//�v���C���[�̈ړ��֘A
	static const float DAMPING_COEFFICIENT; //�ړ���R
	static const int MAX_JUMPCNT; //�W�����v��
	static const int NUM_SLOT = 6;
	static const int IGNORE_COLLISION_FRAME; //�����蔻�薳���t���[��
	static const int SMOKE_RECAST_FRAME; //�X���[�N�����t���[��
	static const float DEADZONE_Y; //������߂�����v���C���[�j��
	static const float DEFAULT_COOLTIME; //�f�t�H���g�̃N�[���^�C��
	static constexpr float LEVEL_EXP = 1.05f;

	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //�X�|�[���ʒu
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //�X�|�[������

	void ReSpawn(); //���X�|�[��

	void DebugPos();

	void Input(); //���͏���

	CPlayerState* m_pPlayerState;

	CEquipment* m_pEquipment[NUM_SLOT];

	float m_fExp; //�o���l

	float m_fAttackCoolTime;	//�N�[���^�C��

	UI_PlayerLife* m_LifeUI;
	UI_PlayerExp* m_ExpUI;
	float m_fAttackCoolCnt;	//�N�[���^�C��
};
#endif