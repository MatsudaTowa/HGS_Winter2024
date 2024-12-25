//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _MOVEBILLBOARD_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _MOVEBILLBOARD_H_
#include "main.h"
#include "billboard.h"

class CMoveBillboard : public CBillboard
{
public:

	CMoveBillboard(int nPriority);
	~CMoveBillboard() override;
	HRESULT Init() override;
	void Update() override;

	//�ړ���
	void SetMove(D3DXVECTOR3 move) { m_Move = move; }	//�ݒ�
	D3DXVECTOR3& GetMove() { return m_Move;}			//�擾

private:

	D3DXVECTOR3 m_Move;	//�ړ���

};
#endif