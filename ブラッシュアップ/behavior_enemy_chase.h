//=============================================
//
//�G�s���N���X�p�w�b�_�[[behavior_enemy_chasse.h]
//Auther Yuuto Shimadu
//
//=============================================

#ifndef _BEHAVIOR_ENEMY_CHASE_H_	//���ꂪ��`����ĂȂ��Ƃ�
#define _BEHAVIOR_ENEMY_CHASE_H_	//��d�}�N���h�~

//�w�b�_�[�̃C���N���[�h
#include "behavior_enemy.h"

//�����N���X
class CBehavior_Enemy_Chase : public CBehavior_Enemy
{
public:

	//�萔
	static constexpr float VALUE_MOVE{ 3.0f };				//�ړ���

	//�֐�
	CBehavior_Enemy_Chase(CEnemy* enemy);			//�R���X�g���N�^
	~CBehavior_Enemy_Chase() override;				//�f�X�g���N�^
	void Behavior(CEnemy* /*enemy*/) override;		//�s��

private:

};


#endif