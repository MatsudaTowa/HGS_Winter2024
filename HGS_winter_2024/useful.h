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
float Ratio(float value, float max);	//�������Z�o

//�J���[������
#define COLOR_RESET_ZERO (0.0f,0.0f,0.0f,0.0f)
#define COLOR_RESET_ONE (1.0f,1.0f,1.0f,1.0f)

//���_3D������
#define VEC3_RESET_ZERO (0.0f,0.0f,0.0f)
#define VEC3_RESET_ONE (1.0f,1.0f,1.0f)

//���_2D������
#define VEC2_RESET_ZERO (0.0f,0.0f)
#define VEC2_RESET_ONE (1.0f,1.0f)

//���~
#define HALF_PI	(D3DX_PI * 0.5f)
//1/4�~
#define QRTR_PI	(D3DX_PI * 0.25f)

//�����J��
template<class T>
constexpr void SafeDelete(T& p)
{
	if (p == nullptr) { return; }
	delete p;
	p = nullptr;
}

#endif