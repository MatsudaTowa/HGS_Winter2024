//=============================================
//
//�G�̏���[weak_enemy.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _WEAK_ENEMY_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _WEAK_ENEMY_H_
#include "main.h"
#include "manager.h"
#include "model_parts.h"
#include "enemy.h"

//�G�l�~�[�N���X
class CWeakEnemy :public CEnemy
{
public:
	static const int MAX_KEY = 20; //�L�[�ő吔
	static const int ENEMY_PRIORITY = 8; //�`�揇
	static const int DEFAULT_LIFE = 5; //���C�t

	//���[�V�����̎�ނ̗�
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_MAX,
	};

	CWeakEnemy(int nPriority = ENEMY_PRIORITY);
	~CWeakEnemy() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

private:

	static constexpr float THRESHOLD = 10.0f; //�ړ���臒l

	void Move();
	void MovetoPlayer(float distance, D3DXVECTOR3& Vector);

	Motion_Type m_Motion; //���[�V�����̎��
};

#endif