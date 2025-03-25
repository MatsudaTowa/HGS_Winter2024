//=============================================
//
//エネミーの処理[enemy.cpp]
//Auther Matsuda Towa
//
//=============================================

//インクルード
#include "enemy.h"
#include "gamemanager.h"

//定数
const std::string CEnemy::MODEL_FILE = "data\\TEXT\\motion_HGSPlayer.txt";	//読み込むファイル(敵のモデルがないので仮でプレイヤーを出す)

//=============================================
//コンストラクタ
//=============================================
CEnemy::CEnemy(int nPriority) :CCharacter(nPriority)
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

	//ムーブ値代入
	SetMove(move);

	//パーツ読み込み
	Load_Parts(MODEL_FILE.c_str());

	CCharacter::SetLife(LIFE);

	SetMotion(MOTION_NEUTRAL);

	//プレイヤー自身をマネージャーに代入
	CGameManager::GetInstance()->SetEnemy(this);

	return S_OK;
}

//=============================================
//終了
//=============================================
void CEnemy::Uninit()
{
	//親クラスの終了処理を呼ぶ
	CCharacter::Uninit();
}

//=============================================
//更新
//=============================================
void CEnemy::Update()
{
	//キャラクターの更新
	CCharacter::Update();	

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