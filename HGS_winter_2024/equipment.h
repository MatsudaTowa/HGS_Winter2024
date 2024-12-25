//=============================================
//
//3DTemplate[equipment.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _EQUIPMENT_H_ //���ꂪ��`����ĂȂ��Ƃ�
#define _EQUIPMENT_H_
#include "main.h"
#include "player.h"

//�����N���X
class CEquipment
{
public:
	CEquipment() : m_pPlayer(nullptr) {}		//�R���X�g���N�^
	virtual ~CEquipment() {}					//�f�X�g���N�^

	virtual void Init() {}	//������
	virtual void Update() {}//�X�V

	static CEquipment* Create(CEquipment* equipment, CPlayer* player);	//����

	//�v���C���[
	CPlayer* GetPlayer() { return m_pPlayer; }

private:
	CPlayer* m_pPlayer;
	
};
#endif