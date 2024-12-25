//=============================================
//
//3DTemplate[movebillboard.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EXP_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EXP_H_
#include "main.h"
#include "objectX.h"

//�o���l�N���X
class CExp : public CObjectX
{
public:

	//�o���l�̎��
	typedef enum
	{
		EXP_TYPE_LOW = 0,
		EXP_TYPE_NORMAL,
		EXP_TYPE_HIGH,
		EXP_TYPE_MAX,
	}EXP_TYPE;

	//�o���l�̏��
	typedef struct
	{
		int Value;
		std::string Path;
	}ExpInfo;

	CExp(int nPriority);
	~CExp() override;
	HRESULT Init() override;
	void Update() override;
	static CExp* Create(D3DXVECTOR3 pos, EXP_TYPE type);

	//�ړ���
	void SetExp(int exp) { m_Info.Value = exp; }	//�ݒ�
	int& GetExp() { return m_Info.Value; }			//�擾

private:

	static const ExpInfo Info[EXP_TYPE_MAX];

	//�o���l
	ExpInfo m_Info;

};
#endif