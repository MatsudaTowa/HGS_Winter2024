//=============================================
//
//エネミーの処理[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================

//インクルード
#include "enemy.h"
#include "gamemanager.h"
#include "behavior_enemy_chase.h"

//定数
const std::string CEnemy::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";	//読み込むファイル(敵のモデルがないので仮でプレイヤーを出す)

//=============================================
//コンストラクタ
//=============================================
CEnemy::CEnemy(int nPriority) :CCharacter(nPriority),
	m_Behavior(nullptr)
{

}

//=============================================
//デストラクタ
//=============================================
CEnemy::~CEnemy()
{
	
}

//=============================================
//初期化
//=============================================
HRESULT CEnemy::Init()
{
	CCharacter::Init();

	//移動量初期化
	D3DXVECTOR3 move = VEC3_RESET_ZERO;

	//カメラ情報取得
	CCamera* pCamera = GET_CAMERA;

	//カメラの方向設定
	pCamera->SetRot(VEC3_RESET_ZERO);

	SetPos({50.0f, 1.0f, 50.0f});

	//ムーブ値代入
	SetMove(move);

	//パーツ読み込み
	Load_Parts(MODEL_FILE.c_str());

	CCharacter::SetLife(LIFE);

	SetMotion(MOTION_NEUTRAL);

	//自身をマネージャーに代入
	CGameManager::GetInstance()->GetEnemyManager()->Regist(this);

	//行動の代入
	SetBehavior(new CBehavior_Enemy_Chase(this));

	return S_OK;
}

//=============================================
//終了
//=============================================
void CEnemy::Uninit()
{
	//親クラスの終了処理を呼ぶ
	CCharacter::Uninit();

	delete m_Behavior;
}

//=============================================
//更新
//=============================================
void CEnemy::Update()
{
	//キャラクターの更新
	CCharacter::Update();	

	//行動の更新
	m_Behavior->Behavior(this);

	//プレイヤーとのヒット確認
	if (CheckHitPlayer())
	{
		HitPlayer();	//ヒット処理
	}

	//モーション処理
	Motion();				
}

//=============================================
//描画
//=============================================
void CEnemy::Draw()
{
	//親クラスのモーション用の描画を呼ぶ
	MotionDraw();
}

//=============================================
//生成
//=============================================
CEnemy* CEnemy::Create()
{
	CEnemy* pEnemy = new CEnemy;

	// nullならnullを返す
	if (pEnemy == nullptr) { return nullptr; }

	pEnemy->SetType(OBJECT_TYPE_ENEMY); //タイプ設定

	pEnemy->Init(); //初期化処理

	return pEnemy;
}

//=============================================
//行動の設定
//=============================================
void CEnemy::SetBehavior(CBehavior_Enemy* behavior)
{
	//中身の破棄
	if (m_Behavior != nullptr)
	{
		delete m_Behavior;
		m_Behavior = nullptr;
	}

	//代入
	m_Behavior = behavior;
}

//=============================================
//プレイヤーとのヒット確認
//=============================================
bool CEnemy::CheckHitPlayer()
{
	//プレイヤーの取得
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//プレイヤーの距離を算出
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();		//プレイヤーの位置を取得
	D3DXVECTOR3 Pos = GetPos();						//自分の位置を取得

	//距離計算
	float fDistance = sqrtf((PlayerPos.x - Pos.x) * (PlayerPos.x - Pos.x) + (PlayerPos.z - Pos.z) * (PlayerPos.z - Pos.z));	//計算

	//次の移行半径内なら真
	if (fDistance > CCharacter::GetHitSize() * 2) return false;
}

//=============================================
//プレイヤーとのヒット処理
//=============================================
void CEnemy::HitPlayer()
{
	//プレイヤーの取得
	CPlayer* pPlayer = CGameManager::GetInstance()->GetPlayer();

	//体力を減らす
	pPlayer->SetLife(pPlayer->GetLife() - 1);
}