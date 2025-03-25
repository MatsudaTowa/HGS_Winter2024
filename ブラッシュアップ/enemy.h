//=============================================
//
//�G�l�~�[�p�w�b�_�[[enemy.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ENEMY_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _ENEMY_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "model_parts.h"
#include "character.h"

//�G�l�~�[�N���X
class CEnemy :public CCharacter
{
public:

	//�萔
	static constexpr int MAX_KEY{20};	//�L�[�ő吔
	static constexpr int LIFE{150};		//�̗�
	static constexpr int PRIORITY{8};	//�`�揇
	static const std::string MODEL_FILE;//���f���̃t�@�C���p�X

	//���[�V�����̎�ނ̗�
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	//�֐�
	CEnemy(int nPriority = PRIORITY);	//�R���X�g���N�^
	~CEnemy();							//�f�X�g���N�^
	HRESULT Init();						//������
	void Uninit();						//�I������
	void Update();						//�X�V����
	void Draw();						//�`�揈��

	//�G�l�~�[�̍쐬
	static CEnemy* Create();
};
#endif