//=============================================
//
//3DTemplate[levelupselect.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _LEVELUPSELECT_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _LEVELUPSELECT_H_
#include "main.h"
#include "ui_select.h"

//�N���X
class CLevelupSelect
{
public:
	CLevelupSelect() : m_pSelect(), m_nSelect(0), m_End(false) {}		//�R���X�g���N�^
	~CLevelupSelect() {}	//�f�X�g���N�^

	void Init() {}	//������
	void Uninit();
	void Update(); //�X�V

	bool GetEnd() { return m_End; }
	int GetSelect() { return m_nSelect; }

	static CLevelupSelect* Create();	//����

private:

	CUi_Select* m_pSelect[3];
	int m_nSelect;
	bool m_End;
};
#endif