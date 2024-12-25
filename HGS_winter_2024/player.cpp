//=============================================
//
//プレイヤー[player.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player.h"
#include "UI_player_life.h"
#include "manager.h"
#include "player_state.h"
#include "equipment_shoes.h"
#include "equipment_gloves.h"
#include "equipment_childattack.h"
#include "equipment_childcircle.h"
#include "equipment_gun.h"
#include "equipment_lease.h"
#include "equipment_magnum.h"
#include "equipment_kerosene.h"
#include "equipment_holy.h"

//スポーン位置
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_POS = { 0.0f, 0.5f, 0.0f };

//スポーン方向
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 3.14f, 0.0f };

//通常のクールタイム
const float CPlayer::DEFAULT_COOLTIME = 120.0f;

//=============================================
//コンストラクタ
//=============================================
CPlayer::CPlayer(int nPriority) :CCharacter(nPriority)
, m_pPlayerState(nullptr)		//ステートポインター初期化
, m_LifeUI(nullptr)
, m_fAttackCoolTime(0.0f)		//クールタイム
, m_fAttackCoolCnt(0.0f)			//クールタイムカウント
, m_pEquipment()
{
}

//=============================================
//デストラクタ
//=============================================
CPlayer::~CPlayer()
{
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
	}
}

//=============================================
//初期化
//=============================================
HRESULT CPlayer::Init()
{
	CCharacter::Init();

	if (m_pPlayerState == nullptr)
	{
		m_pPlayerState = new CMoveState;
	}

	//クールタイム代入
	m_fAttackCoolTime = DEFAULT_COOLTIME;

	//移動量初期化
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//カメラ情報取得
	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	//カメラの方向設定
	pCamera->SetRot(VEC3_RESET_ZERO);

	//ムーブ値代入
	SetMove(move);

	SetPos(PLAYER_SPAWN_POS);
	SetRot(PLAYER_SPAWN_ROT);

	//パーツ読み込み
	Load_Parts("data\\TEXT\\motion_HGSPlayer.txt");

	CCharacter::SetLife(PLAYER_LIFE);

	m_LifeUI = UI_PlayerLife::Create({ 150.0f,SCREEN_HEIGHT - 30.0f,0.0f }, PLAYER_LIFE);

	SetMotion(MOTION_NEUTRAL);
	return S_OK;
}

//=============================================
//終了
//=============================================
void CPlayer::Uninit()
{
	//親クラスの終了処理を呼ぶ
	CCharacter::Uninit();
}

//=============================================
//更新
//=============================================
void CPlayer::Update()
{
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_0) == true)
	{
		int nLife = CCharacter::GetLife();

		nLife -= 30;
		CCharacter::SetLife(nLife);
		m_LifeUI->SetLife(nLife);
	}

	CCharacter::Update();

#ifdef _DEBUG
	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_1) == true)
	{
		for (int nCnt = 0; nCnt < NUM_SLOT; nCnt++)
		{
			if (m_pEquipment[nCnt] == nullptr)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Shoes, this);
			}
		}
	}

	if (CManager::GetInstance()->GetKeyboard()->GetTrigger(DIK_2) == true)
	{
		for (int nCnt = 0; nCnt < NUM_SLOT; nCnt++)
		{
			if (m_pEquipment[nCnt] == nullptr)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Gloves, this);
			}
		}
	}
#endif // _DEBUG



	for (int nCnt = 0; nCnt < NUM_SLOT; nCnt++)
	{
		if (m_pEquipment[nCnt] != nullptr)
		{
			m_pEquipment[nCnt]->Update();
		}
	}

	if (m_pPlayerState != nullptr)
	{
		m_pPlayerState->Move(this);
		m_pPlayerState->Attack(this);
	}

	m_fAttackCoolCnt += 1.0f;

	if (m_fAttackCoolCnt > m_fAttackCoolTime)
	{
		m_fAttackCoolCnt = 0.0f;
		ChangePlayerState(new CAttackState);
	}

	Input();

	Motion(GetNumParts()); //モーション処理

}

//=============================================
//描画
//=============================================
void CPlayer::Draw()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetMouse();
	pMouse->Debug();

	//親クラスのモーション用の描画を呼ぶ
	MotionDraw();
	//プレイヤーのデバッグ表示
	DebugPos();
}

//=============================================
//生成
//=============================================
CPlayer* CPlayer::Create()
{
	CPlayer* pPlayer = new CPlayer;

	// nullならnullを返す
	if (pPlayer == nullptr) { return nullptr; }

	pPlayer->SetType(OBJECT_TYPE_PLAYER); //タイプ設定

	pPlayer->Init(); //初期化処理

	return pPlayer;
}

//=============================================
//装備
//=============================================
void CPlayer::SetSoubi(int num)
{
	for (int nCnt = 0; nCnt < NUM_SLOT; nCnt++)
	{
		if (m_pEquipment[nCnt] == nullptr)
		{
			if (nCnt == 0)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Shoes, this);
			}
			if (nCnt == 1)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Gloves, this);
			}
			if (nCnt == 2)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Kerosene, this);
			}
			if (nCnt == 3)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Holy, this);
			}
			if (nCnt == 4)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Gun, this);
			}
			if (nCnt == 5)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Magnum, this);
			}
			if (nCnt == 6)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_ChildCircle, this);
			}
			if (nCnt == 7)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_Lease, this);
			}
			if (nCnt == 8)
			{
				m_pEquipment[nCnt] = CEquipment::Create(new CEquipment_ChildAttack, this);
			}

			break;
		}
	}
}

//=============================================
//状態変更
//=============================================
void CPlayer::ChangePlayerState(CPlayerState* state)
{
	//今のステートを消し引数のステートに切り替える
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
		m_pPlayerState = state;
	}
}

//=============================================
//リスポーン
//=============================================
void CPlayer::ReSpawn()
{
	//自分自身のpos取得
	D3DXVECTOR3 PlayerPos = GetPos();

	//スポーン時の設定にもどす
	SetPos(CPlayer::PLAYER_SPAWN_POS);
	SetRot(CPlayer::PLAYER_SPAWN_ROT);
	SetLife(CPlayer::PLAYER_LIFE);
}

//=============================================
//位置情報
//=============================================
void CPlayer::DebugPos()
{
#ifdef _DEBUG
	LPD3DXFONT pFont = CManager::GetInstance()->GetRenderer()->GetFont();
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	char aStr[256];

	sprintf(&aStr[0], "\n\n[player]\npos:%.1f,%.1f,%.1f\nrot:%.1f,%.1f,%.1f\nmove:%.1f,%.1f,%.1f\n体力:%d"
		, GetPos().x, GetPos().y, GetPos().z, GetRot().x, GetRot().y, GetRot().z, GetMove().x, GetMove().y, GetMove().z, GetLife());
	//テキストの描画
	pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DCOLOR_RGBA(255, 0, 0, 255));
#endif // _DEBUG
}

//=============================================
//入力処理
//=============================================
void CPlayer::Input()
{
	CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

	CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();

	CCamera* pCamera = CManager::GetInstance()->GetCamera();

	//移動の方向の単位ベクトル変数
	D3DXVECTOR3 vecDirection(0.0f, 0.0f, 0.0f);
	if (pKeyboard->GetPress(DIK_W))
	{
		vecDirection.z += 1.0f;
	}
	if (pKeyboard->GetPress(DIK_S))
	{
		vecDirection.z -= 1.0f;
	}
	if (pKeyboard->GetPress(DIK_A))
	{
		vecDirection.x -= 1.0f;
	}
	if (pKeyboard->GetPress(DIK_D))
	{
		vecDirection.x += 1.0f;
	}

	float rotMoveY = CManager::GetInstance()->GetCamera()->GetRot().y + atan2f(vecDirection.x, vecDirection.z);

	//移動量
	D3DXVECTOR3 move = GetMove();

	if (vecDirection.x == 0.0f && vecDirection.z == 0.0f)
	{ // 動いてない。
		move.x = 0.0f;
		move.z = 0.0f;
	}
	else
	{
		move.x += sinf(rotMoveY) * GetSpeed();
		move.z += cosf(rotMoveY) * GetSpeed();
	}
	//親クラスからrotを取得
	D3DXVECTOR3 rot = GetRot();
	rot.y = rotMoveY + D3DX_PI;
	//rotを代入
	SetRot(rot);
	//移動量代入
	SetMove(move);
}
