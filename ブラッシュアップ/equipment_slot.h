//=============================================
//
//������UI�p�w�b�_�[[equipment_slot.h]
//Auther Matsuda Towa
//
//=============================================

//�w�b�_�[�̃C���N���[�h
#include "equipment.h"
#include "object2D.h"
#include "texture.h"

class CEquipMent_Slot :public CObject2D
{
public:
	static const int PRIORITY = 20;  //�`�揇
	static constexpr float SIZE = 30.0f;	//�T�C�Y

	CEquipMent_Slot(int nPriority = PRIORITY);
	~CEquipMent_Slot() override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static CEquipMent_Slot* Create(D3DXVECTOR3 pos);	//����
private:
	static const std::string TEXTURE_NAME;	//�e�N�X�`���̖��O
};