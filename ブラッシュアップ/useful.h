//=============================================
//
//���p�I�ȏ������܂Ƃ߂�����[useful.h]
//Auther Matsuda Towa
//
//============================================= 

//�Q�d�C���N���[�h�h�~
#ifndef _USEFUL_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _USEFUL_H_

#include "main.h"
#include "manager.h"

//0�������p
#define INT_ZERO (0)
#define FLOAT_ZERO (0.0f)
#define INT_ONE (1)
#define FLOAT_ONE (1.0f)

//����
#define HALF	(0.5f)

//�J���[������
#define COLOR_NONE (D3DXCOLOR(0.0f,0.0f,0.0f,0.0f))
#define COLOR_BLACK (D3DXCOLOR(0.0f,0.0f,0.0f,1.0f))
#define COLOR_WHITE (D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))
#define COLOR_RED (D3DXCOLOR(1.0f,0.0f,0.0f,1.0f))
#define COLOR_GREEN (D3DXCOLOR(0.0f,1.0f,0.0f,1.0f))
#define COLOR_BLUE (D3DXCOLOR(0.0f,0.0f,1.0f,1.0f))

//���_3D������
#define VEC3_RESET_ZERO (D3DXVECTOR3(0.0f,0.0f,0.0f))
#define VEC3_RESET_ONE (D3DXVECTOR3(1.0f,1.0f,1.0f))

//���_2D������
#define VEC2_RESET_ZERO (D3DXVECTOR2(0.0f,0.0f))
#define VEC2_RESET_ONE (D3DXVECTOR2(1.0f,1.0f))

//���~
#define HALF_PI	(D3DX_PI * HALF)
//1/4�~
#define QRTR_PI	(D3DX_PI * (HALF * HALF))

//�������ő吔
#define MAX_TXT (256)

//���ˏ�Ƀ����_��
#define CICRLE_RAND  ((float)(rand() % 629 - 314) / 100.0f)

// �}�l�[�W���[�֌W
#define GET_MANAGER			(CManager::GetInstance())												// �}�l�[�W���[�C���X�^���X�擾
#define GET_SCENE			(CManager::GetInstance()->GetScene())									// �V�[���擾
#define GET_CAMERA			(CManager::GetInstance()->GetCamera())									// �J�����擾
#define GET_LIGHT			(CManager::GetInstance()->GetLight())									// ���C�g�擾
#define GET_MODEL			(CManager::GetInstance()->GetModel())									// ���f���擾
#define GET_TEXTURE			(CManager::GetInstance()->GetTexture())									// �e�N�X�`���擾
#define GET_FADE			(CManager::GetInstance()->GetFade())									// �t�F�[�h�擾
#define GET_INPUT_KEYBOARD	(CManager::GetInstance()->GetKeyboard())								// �L�[�{�[�h���擾
#define GET_INPUT_MOUSE		(CManager::GetInstance()->GetMouse())									// �}�E�X���擾
#define GET_INPUT_PAD		(CManager::GetInstance()->GetPad())										// �p�b�h���擾
#define GET_RENDERER		(CManager::GetInstance()->GetRenderer())								// �����_���[���擾
#define GET_FONT			(CManager::GetInstance()->GetFont())									// �t�H���g�擾
#define GET_DEVICE			(CManager::GetInstance()->GetRenderer()->GetDevice())					// �f�o�C�X���擾
#define GET_SOUND			(CManager::GetInstance()->GetSound())									// �T�E���h�擾

//�C���N�������g�֐�
template <std::floating_point T>  // float, double �ȂǕ��������_�^�̂�
void increment(T& value) 
{
    value += 1.0;
}
#endif