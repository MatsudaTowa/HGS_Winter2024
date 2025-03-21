//=============================================
//
//�Q�[���}�l�[�W���[�̃w�b�_�[[gamemaneger.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _GAMEMANAGER_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _GAMEMANAGER_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "player.h"

//�Q�[���}�l�[�W���[�N���X
class CGameManager
{
private:

	//�����o�֐�
	CGameManager();		//�R���X�g���N�^

public:

	//�֐�
	~CGameManager();	//�f�X�g���N�^

	static CGameManager* GetInstance()	//�C���X�^���X�̐���
	{
		//�ÓI�C���X�^���X
		static CGameManager instance;	
		return &instance;
	}

	void SetPlayer(CPlayer* player) { m_pPlayer = player; }	//�v���C���[�̐ݒ�
	CPlayer* GetPlayer() { return m_pPlayer; }				//�v���C���[�̎擾

private:

	//�ϐ�
	CPlayer* m_pPlayer;
};

#endif