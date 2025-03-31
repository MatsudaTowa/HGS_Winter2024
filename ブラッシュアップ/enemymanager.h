//=============================================
//
//�G�l�~�[�}�l�[�W���[�p�w�b�_�[[enemymanager.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _ENEMYMANAGER_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _ENEMYMANAGER_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "enemy.h"

//�G�l�~�[�}�l�[�W���[�N���X
class CEnemyManager
{
public:

	//�֐�
	CEnemyManager();					//�R���X�g���N�^
	~CEnemyManager();					//�f�X�g���N�^
	HRESULT Init();						//������
	void Uninit();						//�I������
	void Regist(CEnemy* enemy);			//�o�^
	void Delete(CEnemy* enemy);			//�폜

private:

	//�ϐ�
	std::list<CEnemy*> m_EnemyList;	//�G�̃��X�g

};
#endif