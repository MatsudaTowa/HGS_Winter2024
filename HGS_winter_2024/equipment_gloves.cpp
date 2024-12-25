//=============================================
//
//3DTemplate[equipment_gloves.cpp]
//Auther Matsuda Towa
//
//=============================================

#include "equipment_gloves.h"
#include "object.h"
#include "player.h"

//=============================================
//�X�V
//=============================================
void CEquipment_Gloves::Update()
{
	//�v���C���[�̍U���̃N�[���^�C���������\��
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
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
			}

			pObj = pNext;							//�|�C���^��i�߂�
		}
	}
}