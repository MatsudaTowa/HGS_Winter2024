//=============================================
//
//プレイヤー[player.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "player.h"
#include "manager.h"

//スポーン位置
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_POS = { 0.0f, 0.5f, 0.0f };

//スポーン方向
const D3DXVECTOR3 CPlayer::PLAYER_SPAWN_ROT = { 0.0f, 3.14f, 0.0f };

//=============================================
//コンストラクタ
//=============================================
CPlayer::CPlayer(int nPriority):CCharacter(nPriority)
,m_pPlayerState(nullptr)		//ステートポインター初期化
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
		//m_pPlayerState = new CDefaultState;
	}
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
	Load_Parts("data\\motion_soldier.txt");

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
	CCharacter::Update();

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
