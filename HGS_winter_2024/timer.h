//=============================================
//
//�^�C�}�[�����utimer.h�v
// Author���c�i�v
//
//=============================================
#ifndef _TIMER_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _TIMER_H_
#include "main.h"
#include "object2D.h"
#include "number.h"

//=============================================
//�^�C�}�[�N���X
//=============================================
class CTimer
{
public:
	static const int LIMIT_TIME = 120;  //��������
	static const int NUM_DIGIT = 3;  //����
	static const float DIGIT_SHIFT;  //�����Ƃɍ��W�����炷

	CTimer();
	~CTimer();
	HRESULT Init();
	void Uninit();
	void Update();

private:
	void SetTimer();
	int m_nFrameCnt; //���t���[���o�������J�E���g����ϐ�
	int m_nCurrentTime; //���̎���
	D3DXVECTOR3 m_pos;
	CNumber_2D* m_pNumber[NUM_DIGIT];
};

#endif // DEBUG