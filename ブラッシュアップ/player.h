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

private:
	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //�X�|�[���ʒu
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //�X�|�[������

	CPlayerState* m_pPlayerState;

	void ReSpawn(); //���X�|�[��

	void DebugPos();

	void Input(); //���͏���
};
#endif