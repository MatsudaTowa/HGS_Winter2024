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
#include "equipment_slot.h"

class CPlayerState;

//�v���C���[�N���X
class CPlayer :public CCharacter
{
public:
	static const int MAX_KEY = 20; //�L�[�ő吔
	static const int PLAYER_LIFE = 150; //�̗�
	static const int PLAYER_PRIORITY = 8; //�`�揇
	static const char* MODEL_FILE; //���f���̃t�@�C���p�X
	//static constexpr float LEVEL_WINDOW = 50.0f;

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

	//�N�[���J�E���g�擾
	inline float& GetAttackCoolCnt()
	{
		return m_AttackCoolTime;
	}

	//�N�[���J�E���g�ݒ�
	inline void SetAttackCoolCnt(float Cnt)
	{
		m_AttackCoolTime = Cnt;
	}

private:
	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //�X�|�[���ʒu
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //�X�|�[������
	static const D3DXVECTOR3 SLOT_START_POS; //��ڂ̃X���b�g����
	static const int MAX_EQUIPMENT = 6; //�����̍ő吔
	static constexpr float DEFAULT_COOLTIME = 120.0f;

	std::array<CEquipment*, MAX_EQUIPMENT> m_pEquipMent; //�������

	std::array<CEquipMent_Slot*, MAX_EQUIPMENT> m_pEquipMentSlot; //�����X���b�g

	CPlayerState* m_pPlayerState;

	D3DXVECTOR3 m_SlotPos; //�X���b�g�̈ʒu(���炷���߂ɕϐ���)

	float m_AttackCoolTime;	//�N�[���^�C��

	float m_AttackCoolCnt;  //�A�^�b�N�̃N�[���^�C���J�E���g

	void ReSpawn(); //���X�|�[��

	void DebugPos();

	void Input(); //���͏���
};
#endif