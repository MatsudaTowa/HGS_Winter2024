//=============================================
//
//���p�I�ȏ������܂Ƃ߂�����[useful.h]
//Auther Matsuda Towa?
//
//=============================================

//�Q�d�C���N���[�h�h�~
#ifndef _USEFUL_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _USEFUL_H_

#include "main.h"

//�����蔻��n
bool JudgeBallCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length);	//�~�̓����蔻��(�ʒu�A�ʒu�A���肷�钷��)

//�v�Z�n


//�����J��
template<class T>
constexpr void SafeDelete(T& p)
{
	if (p == nullptr) { return; }
	delete p;
	p = nullptr;
}

#endif