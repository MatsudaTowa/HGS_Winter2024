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
	CLevelupSelect() : m_pSelect(), m_nSelect(0){}		//�R���X�g���N�^
	~CLevelupSelect() {}	//�f�X�g���N�^

	void Init() {}	//������
	void Update(); //�X�V

	static CLevelupSelect* Create();	//����

private:
	
	CUi_Select* m_pSelect[3];
	int m_nSelect;
};
#endif