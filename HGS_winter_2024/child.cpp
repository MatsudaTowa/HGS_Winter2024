//=============================================
//
//3DTemplate[child.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "child.h"
#include"manager.h"
#include "enemy.h"

//=============================================
//コンストラクタ
//=============================================
CChild::CChild(int nPriority) :
	CObjectX(nPriority)
{//イニシャライザーでプライオリティ設定、各メンバ変数初期化
}

//=============================================
//デストラクタ
//=============================================
CChild::~CChild()
{
	
}

//=============================================
//初期化
//=============================================
HRESULT CChild::Init()
{
	CModel* pModel = CManager::GetInstance()->GetModel();

	//Xファイル読み込み
	BindXFile(pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).pBuffMat,
		pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).dwNumMat,
		pModel->GetModelInfo(pModel->Regist("data\\MODEL\\ChildBullet.x")).pMesh);

	//親クラスの初期化
	CObjectX::Init();
	return S_OK;
}

//=============================================
//終了
//=============================================
void CChild::Uninit()
{
	CObjectX::Uninit();
}

//=============================================
//更新
//=============================================
void CChild::Update()
{
	GetRot().x -= 0.1f;

	CObjectX::Update();
}

//=============================================
//描画
//=============================================
void CChild::Draw()
{
	CObjectX::Draw();
}

//=============================================
//生成
//=============================================
CChild* CChild::Create(D3DXVECTOR3 pos)
{
	CChild* pObject = new CChild(3);
	pObject->SetPos(pos);
	float fDistance = 99999.0f;
	float fAngle = 0.0f;

	//敵との当たり判定
	for (int i = 0; i < MAX_PRIORITY; i++)
	{
		CObject* pObj = CObject::Getobject(i);	//先頭取得

		//最大数が不明なのでwhileを使用
		while (pObj != nullptr)
		{
			CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

			//敵を見つけて速度を上げる
			if (pObj->GetType() == CObject::OBJECT_TYPE_ENEMY)
			{
				CEnemy* pEnemy = dynamic_cast<CEnemy*>(pObj);
				D3DXVECTOR3 Vector;

				//２点間の距離を計算
				D3DXVec3Subtract(&Vector, &pos, &pEnemy->GetPos());

				// 差分ベクトルの長さ（距離）を計算
				float fVextor= static_cast<float>(D3DXVec3Length(&Vector));
				float A = fVextor;
				if (fVextor < 0.0f) { A *= -1.0f; }

				if (fDistance > A)
				{
					fAngle = atan2f(Vector.x, Vector.z);
				}
			}

			pObj = pNext;							//ポインタを進める
		}
	}

	pObject->SetMove({ sinf(fAngle + D3DX_PI) * 10.0f, 0.0f, cosf(fAngle + D3DX_PI) * 10.0f });
	pObject->Init();
	return pObject;
}