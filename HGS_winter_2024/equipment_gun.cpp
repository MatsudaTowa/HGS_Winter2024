//=============================================
//
//3DTemplate[equipment_gun.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gun.h"
#include "object.h"
#include "player.h"

//=============================================
//������
//=============================================
void CEquipment_Gun::Init()
{
	//�ϐ��錾
	CPlayer* pPlayer = nullptr;
	bool bHit = false;

	//�v���C���[�̑����Ƀ��[�X�𐶐��\��

	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

			//�v���C���[�������đ��x���グ��
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				pPlayer = dynamic_cast<CPlayer*>(pObj);
				bHit = true;
				break;
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}

		//�v���C���[���������甲����
		if (bHit) { break; }
	}

}

//=============================================
//�X�V
//=============================================
void CEquipment_Gun::Update()
{

}