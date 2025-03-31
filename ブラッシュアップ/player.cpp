//=============================================
//
//プレイヤー[player.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player.h"
#include "player_state.h"
#include "gamemanager.h"

//スポーン位置
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_POS = { 0.0f, 0.5f, 0.0f };

//スポーン方向
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 0.0f, 0.0f };

//スロットの開始位置
const D3DXVECTOR3 CPlayer::SLOT_START_POS = { 490.0f, 690.0f,0.0f };

//モデルファイル
const char* CPlayer::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";

//=============================================
//コンストラクタ
//=============================================
CPlayer::CPlayer(int nPriority) :CCharacter(nPriority),
m_pPlayerState(nullptr),				//プレイヤーの状態処理
m_pHpGauge(nullptr),					//プレイヤーの体力UI
m_pExpGauge(nullptr),					//プレイヤーの経験値UI
m_SlotPos(VEC3_RESET_ZERO),				//スロットの位置
m_AttackCoolTime(FLOAT_ZERO),			//攻撃クールタイム
m_AttackCoolCnt(FLOAT_ZERO)				//攻撃クールタイムカウント
{
	//装備にnullptr代入
	m_pEquipMent.fill(nullptr);

	//UIの枠にnullptr代入
	m_pEquipMentSlot.fill(nullptr);
}

//=============================================
//デストラクタ
//=============================================
CPlayer::~CPlayer()
{
	//装備関連削除
	for (int nCnt = 0; nCnt < MAX_EQUIPMENT; ++nCnt)
	{
		//装備削除
		if (m_pEquipMent[nCnt] != nullptr)
		{
			delete m_pEquipMent[nCnt];
			m_pEquipMent[nCnt] = nullptr;
		}

		//装備のスロット終了
		if (m_pEquipMentSlot[nCnt] != nullptr)
		{
			m_pEquipMentSlot[nCnt]->Uninit();
			m_pEquipMentSlot[nCnt] = nullptr;
		}
	}

	if (m_pHpGauge != nullptr)
	{
		m_pHpGauge->Uninit();
		m_pHpGauge = nullptr;
	}

	if (m_pExpGauge != nullptr)
	{
		m_pExpGauge->Uninit();
		m_pExpGauge = nullptr;
	}

	//ステート削除
	if (m_pPlayerState != nullptr)
	{
		delete m_pPlayerState;
		m_pPlayerState = nullptr;
	}
}

//=============================================
//初期化
//=============================================
HRESULT CPlayer::Init()
{
	CCharacter::Init();

	//スロットの最初に位置設定
	m_SlotPos = SLOT_START_POS;

	for (int nCnt = 0; nCnt < MAX_EQUIPMENT; ++nCnt)
	{
		//装備のスロット生成
		if (m_pEquipMentSlot[nCnt] == nullptr)
		{
			m_pEquipMentSlot[nCnt] = CEquipMent_Slot::Create(m_SlotPos);
		}

		m_SlotPos.x += CEquipMent_Slot::SIZE * 2;
	}

	if (m_pPlayerState == nullptr)
	{
		m_pPlayerState = new CMoveState;
	}

	//通常のクールタイム設定
	m_AttackCoolTime = DEFAULT_COOLTIME;

	//移動量初期化
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//カメラ情報取得
	CCamera* pCamera = GET_CAMERA;

	//ムーブ値代入
	SetMove(move);

	//位置設定
	SetPos(PLAYER_SPAWN_POS);

	//方向設定
	SetRot(PLAYER_SPAWN_ROT);

	//パーツ読み込み
	Load_Parts(MODEL_FILE);

	CCharacter::SetLife(PLAYER_LIFE);

	if (m_pHpGauge == nullptr)
	{
		m_pHpGauge = CGauge_2D::Create({ SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT - 80.0f,0.0f }, PLAYER_LIFE, CGauge_2D::GAUGE_LIFE);
	}

	if (m_pExpGauge == nullptr)
	{
		m_pExpGauge = CGauge_2D::Create({ SCREEN_WIDTH * 0.5f,10.0f,0.0f }, (float)ITEM_UI_UNLOCK_EXP, CGauge_2D::GAUGE_EXP);
	}

	SetMotion(MOTION_NEUTRAL);

	//プレイヤー自身をマネージャーに代入
	CGameManager::GetInstance()->SetPlayer(this);

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
	Increment(m_AttackCoolCnt);

	if (m_AttackCoolCnt > m_AttackCoolTime)
	{
		m_AttackCoolCnt = 0;
	}

	if (m_pHpGauge != nullptr)
	{
		m_pHpGauge->SetValue(GetLife());
	}

	if (m_pExpGauge != nullptr)
	{
		m_pExpGauge->SetValue(m_fExp);
	}

	CCharacter::Update();

	Input();

	if (m_pPlayerState != nullptr)
	{
		m_pPlayerState->Move(this);
		m_pPlayerState->Attack(this);
	}

	Motion(); //モーション処理
}

//=============================================
//描画
//=============================================
void CPlayer::Draw()
{
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
//入力情報
//=============================================
void CPlayer::Input()
{
	CInputMouse* pMouse = GET_INPUT_MOUSE;

	CInputKeyboard* pKeyboard = GET_INPUT_KEYBOARD;

	CCamera* pCamera = GET_CAMERA;

	CInputPad* pInput = GET_INPUT_PAD;

	//移動の方向の単位ベクトル変数
	D3DXVECTOR3 vecDirection(VEC3_RESET_ZERO);

	vecDirection = { pInput->GetJoyStickVecL().x,0.0f, pInput->GetJoyStickVecL().y };

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

#ifdef _DEBUG
	if (pKeyboard->GetTrigger(DIK_0))
	{
		int nLife = GetLife();
		nLife -= 10;
		SetLife(nLife);
	}
#endif // _DEBUG

}
