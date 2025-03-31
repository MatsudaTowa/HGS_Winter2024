//=============================================
//
//�G�l�~�[�}�l�[�W���[�̏���[enemymanager.cpp]
//Auther Matsuda Towa
//
//=============================================

//�C���N���[�h
#include "enemymanager.h"

//=============================================
//�R���X�g���N�^
//=============================================
CEnemyManager::CEnemyManager() :
	m_EnemyList()
{
	//���X�g�̃N���A
	m_EnemyList.clear();
}

//=============================================
//�f�X�g���N�^
//=============================================
CEnemyManager::~CEnemyManager()
{

}

//=============================================
//������
//=============================================
HRESULT CEnemyManager::Init()
{
	//���X�g�̃N���A
	m_EnemyList.clear();

	return S_OK;
}

//=============================================
//�I��
//=============================================
void CEnemyManager::Uninit()
{
	//���X�g�̃N���A
	m_EnemyList.clear();
}

//=============================================
//�o�^
//=============================================
void CEnemyManager::Regist(CEnemy* enemy)
{
	//�o�^�ς݂�
	bool bRegisted = false;

	//�������̂����������m�F
	for (auto itr : m_EnemyList)
	{
		if (itr == enemy)
		{
			bRegisted = true;
			break;
		}
	}

	//�o�^����Ă���Ȃ甲����
	if (bRegisted)
	{
		return;
	}

	//�G�̏���o�^
	m_EnemyList.push_back(enemy);
}

//=============================================
//�폜
//=============================================
void CEnemyManager::Delete(CEnemy* enemy)
{
	//�T�C�Y��0�Ȃ甲����
	if (m_EnemyList.size() == 0)
	{
		return;
	}

	//�o�^�ς݂�
	bool bRegisted = false;

	//�������̂����������m�F
	for (auto itr : m_EnemyList)
	{
		if (itr == enemy)
		{
			bRegisted = true;
			break;
		}
	}

	//�o�^����Ă��Ȃ��Ȃ甲����
	if (!bRegisted)
	{
		return;
	}

	//�G�l�~�[�̏����폜
	m_EnemyList.remove(enemy);
}