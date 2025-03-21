//=============================================
//
//3DTemplate[character.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "character.h"
#include "field.h"

//=============================================
//�R���X�g���N�^
//=============================================
CCharacter::CCharacter(int nPriority):CObjectX(nPriority),
m_bLanding(false),												//���n���Ă��邩
m_move(VEC3_RESET_ZERO),										//�ړ���
m_nLife(INT_ZERO),												//�̗�
m_nStateCnt(INT_ZERO),											//�_���[�W�X�e�[�g���ێ�����J�E���g
m_oldpos(VEC3_RESET_ZERO),										//�ߋ��̈ʒu
m_State(CCharacter::CHARACTER_STATE::CHARACTER_NORMAL),			 //���̏��
m_PartsCnt(INT_ZERO),											//�p�[�c��
m_nMotionFrameCnt(INT_ZERO),									//���[�V�����̃t���[����
m_nKeySetCnt(INT_ZERO),											//�L�[�̌�
m_Motion(INT_ZERO),												//���[�V�������
m_bLoopFinish(),												//���[�v���I�������
m_Speed(),														//�X�s�[�h
m_Jump(),														//�W�����v��
m_MotionSet(),													//���[�V�����ݒ�
m_nJumpCnt(INT_ZERO),											//�W�����v��
m_pShadow(),													//�e�̃|�C���^
m_ShadowSize(VEC3_RESET_ZERO)						//�e�̃T�C�Y
{//�C�j�V�����C�U�[�Ńv���C�I���e�B�ݒ�A�e�����o�ϐ�������
}

//=============================================
//�f�X�g���N�^
//=============================================
CCharacter::~CCharacter()
{
	for (int i = 0; i < 64; i++)
	{
		if (m_apModel[i] != nullptr)
		{
			m_apModel[i]->Unload();
		}
	}
}

//=============================================
//������
//=============================================
HRESULT CCharacter::Init()
{
	if (m_pShadow == nullptr)
	{
		m_pShadow = CShadow::Create({ GetPos().x,SHADOW_POS_Y,GetPos().z }, m_ShadowSize);
	}

	//�e�̃T�C�Y�ݒ�
	m_pShadow->SetSize({ m_ShadowSize });

	//�ŏ��ǂ̃��[�V�����ł��Ȃ��l����
	m_Motion = -1;
	//���[�v���[�V�����I����Ă锻���
	m_bLoopFinish = true;

	//�e�N���X�̏�����
	CObjectX::Init();

	//���[���h�}�g���b�N�X�ݒ�
	ConversionMtxWorld();
    return S_OK;
}

//=============================================
//�I��
//=============================================
void CCharacter::Uninit()
{
	if (m_pShadow != nullptr)
	{
		m_pShadow->Uninit();
		m_pShadow = nullptr;
	}

    CObjectX::Uninit();
}

//=============================================
//�X�V
//=============================================
void CCharacter::Update()
{
	for (int nCnt = 0; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->SetOldPos({ m_apModel[nCnt]->GetMtxWorld()._41,m_apModel[nCnt]->GetMtxWorld()._42,m_apModel[nCnt]->GetMtxWorld()._43 });
	}

	//�ʒu�擾
	D3DXVECTOR3 pos = GetPos();

	//if (m_bLanding)
	{
		//�ړ��ʂ��X�V(�����j
		m_move *= FLOAT_ONE - MOVE_FRICTION;
	}

	//�ߋ��̈ʒu�ɍ��̈ʒu����
	m_oldpos = pos;

	//�ړ��ʒǉ�
	pos += m_move;

	//���W���X�V
	SetPos(pos);

	//�e�̃T�C�Y�ݒ�
	m_pShadow->SetSize(m_ShadowSize);

	//�e�̈ʒu�ݒ�
	m_pShadow->SetPos({ GetPos().x,SHADOW_POS_Y,GetPos().z });

	//�ő�ŏ��l�擾
	D3DXVECTOR3 minpos = GetMinPos();
	D3DXVECTOR3 maxpos = GetMaxPos();

	if (m_bLanding)
	{//���n���Ă�Ȃ�
		//�W�����v�����Z�b�g
		m_nJumpCnt = INT_ZERO;
	}

	////�ǂƂ̐ڐG����
	//HitWall();
}

//=============================================
//�`��
//=============================================
void CCharacter::Draw()
{
	CObjectX::Draw();
}

//=============================================
//���[�V�����p�̕`��
//=============================================
void CCharacter::MotionDraw()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;
	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X
	D3DXMATRIX MtxWorld = GetMtxWorld();

	//�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&MtxWorld);

	//���e�X�g��L��
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &MtxWorld);

	for (int nCnt = INT_ZERO; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->Draw();
	}
}

//=============================================
//�p�[�c�̃��[�h
//=============================================
void CCharacter::Load_Parts(const char* FileName)
{
	int nCnt = INT_ZERO;
	int nCntName = INT_ZERO;
	int nCntKey = INT_ZERO; //�L�[������p�[�c�̃J�E���g��
	int nCntMotion = INT_ZERO; //�L�[���̃J�E���g
	int nCntMotionSet = INT_ZERO; //���[�V�����̎�ނ̃J�E���g
	char aDataSearch[MAX_TXT];
	char aEqual[MAX_TXT]; //[��]�ǂݍ��ݗp
	char aGets[MAX_TXT]; //���[�V�����̂���Ȃ����̓ǂݍ��ݗp
	float radius = FLOAT_ZERO;//���a
	float height = FLOAT_ZERO;//����

	char Path[MAX_PARTS][MAX_TXT]; //�p�[�c�̃p�X

	//�t�@�C���̓ǂݍ���
	FILE* pFile;

	//�t�@�C���̓ǂݍ���
	pFile = fopen(FileName, "r");

	if (pFile == NULL)
	{//��ނ̏��̃f�[�^�t�@�C�����J���Ȃ������ꍇ
		//�������I������
		return;
	}

	//END��������܂œǂݍ��݂��J��Ԃ�
	while (1)
	{
		fscanf(pFile, "%s", aDataSearch); //����

		if (!strcmp(aDataSearch, "END_SCRIPT"))
		{//�ǂݍ��݂��I��
			fclose(pFile);
			break;
		}
		if (aDataSearch[0] == '#')
		{
			continue;
		}

		if (!strcmp(aDataSearch, "NUM_MODEL"))
		{//���f�����ǂݍ���
			fscanf(pFile, "%s", &aEqual[0]);
			fscanf(pFile, "%d", &m_PartsCnt);
		}
		if (!strcmp(aDataSearch, "MODEL_FILENAME"))
		{//���f���t�@�C���ǂݍ���
			fscanf(pFile, "%s", &aEqual[0]);
			fscanf(pFile, "%s", &Path[nCntName][0]);
			//���f���p�[�c�̃N���G�C�g
			m_apModel[nCntName] = CModel_Parts::Create(VEC3_RESET_ZERO, VEC3_RESET_ZERO, &Path[nCntName][0]);

			nCntName++;
		}

		if (!strcmp(aDataSearch, "CHARACTERSET"))
		{
			//���ڂ��Ƃ̃f�[�^����
			while (1)
			{
				fscanf(pFile, "%s", aDataSearch); //����

				if (!strcmp(aDataSearch, "END_CHARACTERSET"))
				{
					break;
				}
				else if (!strcmp(aDataSearch, "MOVE"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%f", &m_Speed);
				}
				else if (!strcmp(aDataSearch, "JUMP"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%f", &m_Jump);
				}
				else if (!strcmp(aDataSearch, "RADIUS"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%f", &radius);
				}
				else if (!strcmp(aDataSearch, "HEIGHT"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%f", &height);
				}
				else if (!strcmp(aDataSearch, "PARTSSET"))
				{
					//���ڂ��Ƃ̃f�[�^����
					while (1)
					{
						fscanf(pFile, "%s", aDataSearch); //����

						if (!strcmp(aDataSearch, "END_PARTSSET"))
						{
							break;
						}
						else if (!strcmp(aDataSearch, "INDEX"))
						{
							fscanf(pFile, "%s", &aEqual[0]);
							fscanf(pFile, "%d", &m_apModel[nCnt]->m_nIdx);
						}
						else if (!strcmp(aDataSearch, "PARENT"))
						{
							fscanf(pFile, "%s", &aEqual[0]);
							fscanf(pFile, "%d", &m_apModel[nCnt]->m_nIdxModelParent);

							//�e��ݒ�
							if (m_apModel[nCnt]->m_nIdxModelParent == -1)
							{
								m_apModel[nCnt]->SetParent(nullptr);
							}
							else
							{
								m_apModel[nCnt]->SetParent(m_apModel[m_apModel[nCnt]->m_nIdxModelParent]);
							}

						}
						else if (!strcmp(aDataSearch, "POS"))
						{
							fscanf(pFile, "%s", &aEqual[0]);
							fscanf(pFile, "%f %f %f",
								&m_apModel[nCnt]->m_pos.x,
								&m_apModel[nCnt]->m_pos.y,
								&m_apModel[nCnt]->m_pos.z);

							m_apModel[nCnt]->SetPos(m_apModel[nCnt]->m_pos);

							m_apModel[nCnt]->m_Tpos = m_apModel[nCnt]->m_pos;
						}
						else if (!strcmp(aDataSearch, "ROT"))
						{
							fscanf(pFile, "%s", &aEqual[0]);
							fscanf(pFile, "%f %f %f",
								&m_apModel[nCnt]->m_rot.x,
								&m_apModel[nCnt]->m_rot.y,
								&m_apModel[nCnt]->m_rot.z);

							m_apModel[nCnt]->SetRot(m_apModel[nCnt]->m_rot);

							m_apModel[nCnt]->m_Trot = m_apModel[nCnt]->m_rot;

						}
					}
					nCnt++; //�f�[�^�����Z
				}
			}
		}
		if (!strcmp(aDataSearch, "MOTIONSET"))
		{
			//���ڂ��Ƃ̃f�[�^����
			while (1)
			{
				fscanf(pFile, "%s", aDataSearch); //����

				if (!strcmp(aDataSearch, "END_MOTIONSET"))
				{
					nCntMotion = 0;
					break;
				}
				else if (!strcmp(aDataSearch, "LOOP"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%d", &m_MotionSet[nCntMotionSet].nLoop);
				}
				else if (!strcmp(aDataSearch, "NUM_KEY"))
				{
					fscanf(pFile, "%s", &aEqual[0]);
					fscanf(pFile, "%d", &m_MotionSet[nCntMotionSet].nNumKey);

				}
				else if (!strcmp(aDataSearch, "KEYSET"))
				{
					fgets(&aGets[0], 39, pFile);

					//���ڂ��Ƃ̃f�[�^����
					while (1)
					{
						fscanf(pFile, "%s", aDataSearch); //����

						if (!strcmp(aDataSearch, "END_KEYSET"))
						{
							nCntKey = 0;
							break;
						}

						else if (!strcmp(aDataSearch, "FRAME"))
						{
							fscanf(pFile, "%s", &aEqual[0]);
							fscanf(pFile, "%d", &m_MotionSet[nCntMotionSet].keySet[nCntMotion].nFrame);
						}
						else if (!strcmp(aDataSearch, "KEY"))
						{
							//���ڂ��Ƃ̃f�[�^����
							while (1)
							{
								fscanf(pFile, "%s", aDataSearch);

								if (!strcmp(aDataSearch, "END_KEY"))
								{
									break;
								}
								else if (!strcmp(aDataSearch, "POS"))
								{
									fscanf(pFile, "%s", &aEqual[0]);
									fscanf(pFile, "%f %f %f", &m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].pos.x,
										&m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].pos.y,
										&m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].pos.z);
								}
								else if (!strcmp(aDataSearch, "ROT"))
								{
									fscanf(pFile, "%s", &aEqual[0]);
									fscanf(pFile, "%f %f %f", &m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].rot.x,
										&m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].rot.y,
										&m_MotionSet[nCntMotionSet].keySet[nCntMotion].key[nCntKey].rot.z);
								}
							}
							nCntKey++; //�p�[�c�����Z
						}
					}
					nCntMotion++; //�L�[�����Z
				}
			}
			nCntMotionSet++; //�L�[�^�C�v�����Z
		}
	}
}

//=============================================
//���[�V��������
//=============================================
void CCharacter::Motion(int NumParts)
{
	D3DXVECTOR3 MovePos[MAX_PARTS];
	D3DXVECTOR3 MoveRot[MAX_PARTS];

	int nNextKey = (m_nKeySetCnt + INT_ONE) % m_MotionSet[m_Motion].nNumKey;

	for (int nMotionCnt = INT_ZERO; nMotionCnt < m_PartsCnt; nMotionCnt++)
	{
		MovePos[nMotionCnt] = (m_MotionSet[m_Motion].keySet[nNextKey].key[nMotionCnt].pos - m_MotionSet[m_Motion].keySet[m_nKeySetCnt].key[nMotionCnt].pos) / (float)m_MotionSet[m_Motion].keySet[m_nKeySetCnt].nFrame;
		MoveRot[nMotionCnt] = (m_MotionSet[m_Motion].keySet[nNextKey].key[nMotionCnt].rot - m_MotionSet[m_Motion].keySet[m_nKeySetCnt].key[nMotionCnt].rot) / (float)m_MotionSet[m_Motion].keySet[m_nKeySetCnt].nFrame;

		m_apModel[nMotionCnt]->m_pos += MovePos[nMotionCnt];
		m_apModel[nMotionCnt]->m_rot += MoveRot[nMotionCnt];
		//Pos.x += MovePos[nMotionCnt].x;
		//SetPos(Pos);
	}

	m_nMotionFrameCnt++;

	if (m_nMotionFrameCnt > m_MotionSet[m_Motion].keySet[m_nKeySetCnt].nFrame)
	{

		m_nMotionFrameCnt = INT_ZERO;
		m_nKeySetCnt = (m_nKeySetCnt + INT_ONE) % m_MotionSet[m_Motion].nNumKey;
		if (m_nKeySetCnt == INT_ZERO && m_MotionSet[m_Motion].nLoop == INT_ZERO)
		{//�L�[���I��胋�[�v���[�V��������Ȃ����
			//���[�V�������j���[�g������
			SetMotion(INT_ZERO);
			//�I���������
			m_bLoopFinish = true;
		}
		
	}
}

//=====================================
//�����Ŏw�肵�����[�V�����ɐ؂�ւ���
//=====================================
void CCharacter::SetMotion(int Motion)
{
	if (m_Motion != Motion)
	{
		m_Motion = Motion;

		//�t���[�����Z�b�g
		m_nMotionFrameCnt = INT_ZERO;

		//�L�[�J�E���g���Z�b�g
		m_nKeySetCnt = INT_ZERO;

		if (m_MotionSet[m_Motion].nLoop == INT_ZERO)
		{
			//�I���������
			m_bLoopFinish = false;
		}

		for (int nCntParts = INT_ZERO; nCntParts < m_PartsCnt; nCntParts++)
		{
			m_apModel[nCntParts]->m_pos = m_apModel[nCntParts]->m_Tpos;
			m_apModel[nCntParts]->m_rot = m_apModel[nCntParts]->m_Trot;
			m_apModel[nCntParts]->m_rot = m_MotionSet[Motion].keySet[0].key[nCntParts].rot;
		}
	}
}


//=============================================
//�d�͏���
//=============================================
void CCharacter::Gravity()
{
    if (m_move.y < GRAVITY_MAX)
    {
        m_move.y -= GRAVITY_MOVE;
    }
}

//=============================================
//�W�����v����
//=============================================
void CCharacter::Jump()
{
	m_move.y = m_Jump; //�W�����v�͑��
	m_bLanding = false; //�󒆏��
}

//=============================================
//���[���h�}�g���b�N�X�̕ϊ�
//=============================================
void CCharacter::ConversionMtxWorld()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;
	D3DXMATRIX mtxRot, mtxTrans; //�v�Z�p�}�g���b�N�X
	D3DXMATRIX MtxWorld = GetMtxWorld();

	//�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&MtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &MtxWorld);

	for (int nCnt = INT_ZERO; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->ConversionMtxWorld();
	}
}