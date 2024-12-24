//=============================================
//
//���p�I�ȏ������܂Ƃ߂�����[useful.cpp]
//Auther Matsuda Towa?
//
//=============================================

//�w�b�_�[�̃C���N���[�h
#include "useful.h"

//=============================================
//�~�̓����蔻��
//=============================================
bool JudgeBallCollision(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float length)
{
    D3DXVECTOR3 Vector;     //�x�N�g��
    float fDistance = 0.0f; //����
    bool bHit = false;      //�������Ă��邩

    //�Q�_�Ԃ̋������v�Z
    D3DXVec3Subtract(&Vector, &pos2, &pos1);

    // �����x�N�g���̒����i�����j���v�Z
    fDistance = static_cast<float>(D3DXVec3Length(&Vector));

    //�����͈͈̔ȉ��Ȃ瓖�����Ă���
    if (fDistance <= length)
    {
        bHit = true;
    }

    return bHit;
}