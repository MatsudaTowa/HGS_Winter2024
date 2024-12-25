//=============================================
//
//3DTemplate[child.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _CHILD_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _CHILD_H_
#include "main.h"
#include "objectX.h"

//�q���N���X
class CChild : public CObjectX
{
public:

	CChild(int nPriority = 3);
	~CChild()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	//�v���C���[�쐬
	static CChild* Create(D3DXVECTOR3 pos);
};
#endif