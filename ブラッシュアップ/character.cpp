//=============================================
//
//3DTemplate[character.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "character.h"
#include "field.h"

//=============================================
//コンストラクタ
//=============================================
CCharacter::CCharacter(int nPriority):CObjectX(nPriority),
m_bLanding(false),												//着地しているか
m_move(VEC3_RESET_ZERO),										//移動量
m_nLife(INT_ZERO),												//体力
m_nStateCnt(INT_ZERO),											//ダメージステートを維持するカウント
m_oldpos(VEC3_RESET_ZERO),										//過去の位置
m_State(CCharacter::CHARACTER_STATE::CHARACTER_NORMAL),			 //今の状態
m_PartsCnt(INT_ZERO),											//パーツ数
m_nMotionFrameCnt(INT_ZERO),									//モーションのフレーム数
m_nKeySetCnt(INT_ZERO),											//キーの個数
m_Motion(INT_ZERO),												//モーション情報
m_bLoopFinish(),												//ループが終わったか
m_Speed(),														//スピード
m_Jump(),														//ジャンプ力
m_MotionSet(),													//モーション設定
m_nJumpCnt(INT_ZERO),											//ジャンプ数
m_pShadow(),													//影のポインタ
m_ShadowSize(VEC3_RESET_ZERO)						//影のサイズ
{//イニシャライザーでプライオリティ設定、各メンバ変数初期化
}

//=============================================
//デストラクタ
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
//初期化
//=============================================
HRESULT CCharacter::Init()
{
	if (m_pShadow == nullptr)
	{
		m_pShadow = CShadow::Create({ GetPos().x,SHADOW_POS_Y,GetPos().z }, m_ShadowSize);
	}

	//影のサイズ設定
	m_pShadow->SetSize({ m_ShadowSize });

	//最初どのモーションでもない値を代入
	m_Motion = -1;
	//ループモーション終わってる判定に
	m_bLoopFinish = true;

	//親クラスの初期化
	CObjectX::Init();

	//ワールドマトリックス設定
	ConversionMtxWorld();
    return S_OK;
}

//=============================================
//終了
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
//更新
//=============================================
void CCharacter::Update()
{
	for (int nCnt = 0; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->SetOldPos({ m_apModel[nCnt]->GetMtxWorld()._41,m_apModel[nCnt]->GetMtxWorld()._42,m_apModel[nCnt]->GetMtxWorld()._43 });
	}

	//位置取得
	D3DXVECTOR3 pos = GetPos();

	//if (m_bLanding)
	{
		//移動量を更新(減速）
		m_move *= FLOAT_ONE - MOVE_FRICTION;
	}

	//過去の位置に今の位置を代入
	m_oldpos = pos;

	//移動量追加
	pos += m_move;

	//座標を更新
	SetPos(pos);

	//影のサイズ設定
	m_pShadow->SetSize(m_ShadowSize);

	//影の位置設定
	m_pShadow->SetPos({ GetPos().x,SHADOW_POS_Y,GetPos().z });

	//最大最小値取得
	D3DXVECTOR3 minpos = GetMinPos();
	D3DXVECTOR3 maxpos = GetMaxPos();

	if (m_bLanding)
	{//着地してるなら
		//ジャンプ数リセット
		m_nJumpCnt = INT_ZERO;
	}

	////壁との接触処理
	//HitWall();
}

//=============================================
//描画
//=============================================
void CCharacter::Draw()
{
	CObjectX::Draw();
}

//=============================================
//モーション用の描画
//=============================================
void CCharacter::MotionDraw()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;
	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス
	D3DXMATRIX MtxWorld = GetMtxWorld();

	//マトリックスの初期化
	D3DXMatrixIdentity(&MtxWorld);

	//αテストを有効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &MtxWorld);

	for (int nCnt = INT_ZERO; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->Draw();
	}
}

//=============================================
//パーツのロード
//=============================================
void CCharacter::Load_Parts(const char* FileName)
{
	int nCnt = INT_ZERO;
	int nCntName = INT_ZERO;
	int nCntKey = INT_ZERO; //キーを入れるパーツのカウント数
	int nCntMotion = INT_ZERO; //キー数のカウント
	int nCntMotionSet = INT_ZERO; //モーションの種類のカウント
	char aDataSearch[MAX_TXT];
	char aEqual[MAX_TXT]; //[＝]読み込み用
	char aGets[MAX_TXT]; //モーションのいらないもの読み込み用
	float radius = FLOAT_ZERO;//半径
	float height = FLOAT_ZERO;//高さ

	char Path[MAX_PARTS][MAX_TXT]; //パーツのパス

	//ファイルの読み込み
	FILE* pFile;

	//ファイルの読み込み
	pFile = fopen(FileName, "r");

	if (pFile == NULL)
	{//種類の情報のデータファイルが開けなかった場合
		//処理を終了する
		return;
	}

	//ENDが見つかるまで読み込みを繰り返す
	while (1)
	{
		fscanf(pFile, "%s", aDataSearch); //検索

		if (!strcmp(aDataSearch, "END_SCRIPT"))
		{//読み込みを終了
			fclose(pFile);
			break;
		}
		if (aDataSearch[0] == '#')
		{
			continue;
		}

		if (!strcmp(aDataSearch, "NUM_MODEL"))
		{//モデル数読み込み
			fscanf(pFile, "%s", &aEqual[0]);
			fscanf(pFile, "%d", &m_PartsCnt);
		}
		if (!strcmp(aDataSearch, "MODEL_FILENAME"))
		{//モデルファイル読み込み
			fscanf(pFile, "%s", &aEqual[0]);
			fscanf(pFile, "%s", &Path[nCntName][0]);
			//モデルパーツのクリエイト
			m_apModel[nCntName] = CModel_Parts::Create(VEC3_RESET_ZERO, VEC3_RESET_ZERO, &Path[nCntName][0]);

			nCntName++;
		}

		if (!strcmp(aDataSearch, "CHARACTERSET"))
		{
			//項目ごとのデータを代入
			while (1)
			{
				fscanf(pFile, "%s", aDataSearch); //検索

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
					//項目ごとのデータを代入
					while (1)
					{
						fscanf(pFile, "%s", aDataSearch); //検索

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

							//親を設定
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
					nCnt++; //データ数加算
				}
			}
		}
		if (!strcmp(aDataSearch, "MOTIONSET"))
		{
			//項目ごとのデータを代入
			while (1)
			{
				fscanf(pFile, "%s", aDataSearch); //検索

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

					//項目ごとのデータを代入
					while (1)
					{
						fscanf(pFile, "%s", aDataSearch); //検索

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
							//項目ごとのデータを代入
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
							nCntKey++; //パーツ数加算
						}
					}
					nCntMotion++; //キー数加算
				}
			}
			nCntMotionSet++; //キータイプ数加算
		}
	}
}

//=============================================
//モーション処理
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
		{//キーが終わりループモーションじゃなければ
			//モーションをニュートラルに
			SetMotion(INT_ZERO);
			//終わった判定
			m_bLoopFinish = true;
		}
		
	}
}

//=====================================
//引数で指定したモーションに切り替える
//=====================================
void CCharacter::SetMotion(int Motion)
{
	if (m_Motion != Motion)
	{
		m_Motion = Motion;

		//フレームリセット
		m_nMotionFrameCnt = INT_ZERO;

		//キーカウントリセット
		m_nKeySetCnt = INT_ZERO;

		if (m_MotionSet[m_Motion].nLoop == INT_ZERO)
		{
			//終わった判定
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
//重力処理
//=============================================
void CCharacter::Gravity()
{
    if (m_move.y < GRAVITY_MAX)
    {
        m_move.y -= GRAVITY_MOVE;
    }
}

//=============================================
//ジャンプ処理
//=============================================
void CCharacter::Jump()
{
	m_move.y = m_Jump; //ジャンプ力代入
	m_bLanding = false; //空中状態
}

//=============================================
//ワールドマトリックスの変換
//=============================================
void CCharacter::ConversionMtxWorld()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GET_DEVICE;
	D3DXMATRIX mtxRot, mtxTrans; //計算用マトリックス
	D3DXMATRIX MtxWorld = GetMtxWorld();

	//マトリックスの初期化
	D3DXMatrixIdentity(&MtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, GetRot().y, GetRot().x, GetRot().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);

	D3DXMatrixMultiply(&MtxWorld, &MtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &MtxWorld);

	for (int nCnt = INT_ZERO; nCnt < m_PartsCnt; nCnt++)
	{
		m_apModel[nCnt]->ConversionMtxWorld();
	}
}