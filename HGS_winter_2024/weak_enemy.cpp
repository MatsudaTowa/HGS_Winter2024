//=============================================
//
//�G�̏���[weak_enemy.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "weak_enemy.h"
#include "player.h"

//=============================================
//�R���X�g���N�^
//=============================================
CWeakEnemy::CWeakEnemy(int nPriority):CEnemy(nPriority)
{
}

//=============================================
//�f�X�g���N�^
//=============================================
CWeakEnemy::~CWeakEnemy()
{
}

//=============================================
//������
//=============================================
HRESULT CWeakEnemy::Init()
{
	Load_Parts("data\\motion_enemy000.txt");
	SetLife(DEFAULT_LIFE);
	//�e�N���X�̏��������Ă�
	CEnemy::Init();
	return S_OK;
}

//=============================================
//�I��
//=============================================
void CWeakEnemy::Uninit()
{
	//�e�N���X�̏I���������Ă�
	CEnemy::Uninit();
}

//=============================================
//�X�V
//=============================================
void CWeakEnemy::Update()
{
	CEnemy::Update();
	Move();

	Motion(GetNumParts()); //���[�V��������
}

//=============================================
//�`��
//=============================================
void CWeakEnemy::Draw()
{
	CEnemy::Draw();

}

//=============================================
//�ړ�
//=============================================
void CWeakEnemy::Move()
{
	//�v���C�I���e�B�̐���������
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);    //�擪�擾

		//�ő吔���s���Ȃ̂�while���g�p
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();    //���̃|�C���^���擾

			//�v���C���[�������đ��x���グ��
			if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
			{
				CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
				//�v���C���[�̈ʒu�ւ̕������
				D3DXVECTOR3 Vector = pPlayer->GetPos() - GetPos();
				// �ړI�n�Ƃ̋������v�Z
				float distance = sqrtf(Vector.x * Vector.x + Vector.z * Vector.z);

				//�v���C���[�Ɍ������ē�����
				MovetoPlayer(distance, Vector);
			}
			pObj = pNext;  //�|�C���^��i�߂�

		}
	}
}

//=============================================
//�v���C���[�Ɍ������ē�����
//=============================================
void CWeakEnemy::MovetoPlayer(float distance, D3DXVECTOR3& Vector)
{
	// �܂��ړI�n�ɓ��B���Ă��Ȃ��ꍇ�݈̂ړ��������s��
	if (distance > THRESHOLD)
	{
		//�Ώە��Ƃ̊p�x�v�Z
		float angle = atan2f(Vector.x, Vector.z);

		D3DXVECTOR3 move = GetMove();

		move.x += sinf(angle) * GetSpeed();
		move.z += cosf(angle) * GetSpeed();
		//�e�N���X����rot���擾
		D3DXVECTOR3 rot = GetRot();
		rot.y = angle + D3DX_PI;
		//rot����
		SetRot(rot);
		//�ړ��ʑ��
		SetMove(move);
		SetMotion(CWeakEnemy::Motion_Type::MOTION_MOVE);
	}
	else
	{
		D3DXVECTOR3 move = { 0.0f,0.0f,0.0f };
		SetMotion(CWeakEnemy::Motion_Type::MOTION_NEUTRAL);

		//�ړ��ʑ��
		SetMove(move);
	}
}
