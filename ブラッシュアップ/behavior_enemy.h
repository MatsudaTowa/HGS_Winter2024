//=============================================
//
//�G�s���N���X�p�w�b�_�[[behavior_enemy.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _BEHAVIOR_ENEMY_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _BEHAVIOR_ENEMY_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "main.h"
#include "enemy.h"

//�O���錾
class CEnemy;

//�����N���X
class CBehavior_Enemy
{
public:

	//�֐�
	CBehavior_Enemy(CEnemy* /*enemy*/) {}	//�R���X�g���N�^
	virtual ~CBehavior_Enemy() {} 	//�f�X�g���N�^
	virtual void Behavior(CEnemy* /*enemy*/) = 0;	//�s��

private:

};


#endif