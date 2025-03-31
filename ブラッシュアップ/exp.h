//=============================================
//
//�o���l[exp.h]
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
	enum EXP_TYPE
	{
		EXP_TYPE_LOW = 0,
		EXP_TYPE_NORMAL,
		EXP_TYPE_HIGH,
		EXP_TYPE_MAX,
	};

	//�o���l�̏��
	struct ExpInfo
	{
		int Value;
		std::string Path;
	};

	static const int PRI = 3;

	CExp(int nPriority = PRI);
	~CExp() override;
	HRESULT Init() override;
	void Update() override;
	static CExp* Create(D3DXVECTOR3 pos, EXP_TYPE type);

	//�ړ���
	inline void SetExp(int exp) { m_Info.Value = exp; }	//�ݒ�
	inline int& GetExp() { return m_Info.Value; }		//�擾

private:
	static const char* MODEL_NAME;	//���f���̖��O
	static const ExpInfo Info[EXP_TYPE_MAX];

	//�o���l
	ExpInfo m_Info;
};
#endif