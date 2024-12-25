//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EXP_H_
#include "main.h"
#include "movebillboard.h"

//�o���l�N���X
class CExp : public CMoveBillboard
{
public:

	CExp(int nPriority);
	~CExp() override;
	HRESULT Init() override;
	void Update() override;

	//�ړ���
	void SetExp(int exp) { m_Exp = m_Exp; }	//�ݒ�
	int& GetExp() { return m_Exp; }			//�擾

private:

	//�o���l
	int m_Exp;

};
#endif