//=============================================
//
//�Q�[���}�l�[�W���[�̏���[gamemanager.cpp]
//Auther Yuuto Shimadu
//
//=============================================

//�w�b�_�[�̃C���N���[�h
#include "gamemanager.h"

//=====================================================
//�R���X�g���N�^
//=====================================================
CGameManager::CGameManager() :
	m_pPlayer(nullptr),			//�v���C���[�̃|�C���^
	m_pEnemyManager(nullptr)	//�G�l�~�[�}�l�[�W���[�̃|�C���^
{
	//�G�l�~�[�}�l�[�W���̐���
	if (m_pEnemyManager == nullptr)
	{
		m_pEnemyManager = new CEnemyManager();	//�������̊m��
		m_pEnemyManager->Init();				//������
	}
}

//=====================================================
//�f�X�g���N�^
//=====================================================
CGameManager::~CGameManager()
{
	//�G�l�~�[�}�l�[�W���̔j��
	if (m_pEnemyManager != nullptr)
	{
		m_pEnemyManager->Uninit();	//�I������
		delete m_pEnemyManager;		//�j��
	}
}