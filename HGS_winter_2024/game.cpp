//=============================================
//
//3DTemplate[game.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "game.h"
#include "object.h"
#include "object2D.h"
#include "object3D.h"
#include "objectX.h"
#include "field.h"
#include "manager.h"
#include "exp.h"
#include "player.h"
#include "enemy.h"

//床のサイズ
const D3DXVECTOR3 CGame::FIELD_SIZE = { 10000.0f,0.0f,10000.0f };

//=============================================
//コンストラクタ
//=============================================
CGame::CGame() :m_nResultDelay(0), m_pLevelupSelect(0)
{//イニシャライザーでプライオリティ設定、エディットしてない状態に変更
}

//=============================================
//デストラクタ
//=============================================
CGame::~CGame()
{
}

//=============================================
//初期化
//=============================================
HRESULT CGame::Init()
{
    CField::Create(VEC3_RESET_ZERO, FIELD_SIZE);

    CPlayer::Create();

    for (int nCnt = 0; nCnt < 10; nCnt++)
    {
        std::random_device seed;
        std::mt19937 random(seed());
        std::uniform_int_distribution<int> number(0, 150);
        CEnemy::Create({ (float)number(random),0.5f,100.0f }, VEC3_RESET_ZERO, CEnemy::ENEMY_TYPE_WEAK);
    }

    CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_GAME);
    return S_OK;
}

//=============================================
//終了
//=============================================
void CGame::Uninit()
{
    CManager::GetInstance()->GetSound()->StopSound(CSound::SOUND_LABEL_BGM_GAME);
    CObject::ReleaseAll();
}

//=============================================
//更新
//=============================================
void CGame::Update()
{
    //各インプット取得
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN)
        || pMouse->GetTrigger(0))
    {
        //タイトルに戻る
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
    }

    if (CEnemy::m_NumEnemy <= 0)
    {//敵がいなくなったら
        for (int nCnt = 0; nCnt < 10; nCnt++)
        {
            std::random_device seed;
            std::mt19937 random(seed());
            std::uniform_int_distribution<int> number(0, 1150);
            CEnemy::Create({ (float)number(random),0.5f,(float)number(random) }, VEC3_RESET_ZERO, CEnemy::ENEMY_TYPE_WEAK);
        }
    }
    //if (m_bEdit == false)
    //{
    //CObject::UpdateAll();

    if (pKeyboard->GetTrigger(DIK_K))
    {
        if (m_pLevelupSelect == nullptr)
        {
            m_pLevelupSelect = CLevelupSelect::Create();
        }
    }

    //敵との当たり判定
    for (int i = 0; i < MAX_PRIORITY; i++)
    {
        CObject* pObj = CObject::Getobject(i);	//先頭取得

        //最大数が不明なのでwhileを使用
        while (pObj != nullptr)
        {
            CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

            //敵を見つけて速度を上げる
            if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
            {
                CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
                if (pPlayer->GetExp() > pPlayer->LEVEL_WINDOW)
                {
                    pPlayer->AddExp(-pPlayer->GetExp());
                    if (m_pLevelupSelect == nullptr)
                    {
                        m_pLevelupSelect = CLevelupSelect::Create();
                    }
                }
            }

            pObj = pNext;							//ポインタを進める
        }
    }

    if (m_pLevelupSelect != nullptr)
    {
        m_pLevelupSelect->Update();

        if (m_pLevelupSelect->GetEnd())
        {
            //敵との当たり判定
            for (int i = 0; i < MAX_PRIORITY; i++)
            {
                CObject* pObj = CObject::Getobject(i);	//先頭取得

                //最大数が不明なのでwhileを使用
                while (pObj != nullptr)
                {
                    CObject* pNext = pObj->GetNextobject();	//次のポインタを取得

                    //敵を見つけて速度を上げる
                    if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
                    {
                        CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
                        pPlayer->SetSoubi(m_pLevelupSelect->GetSelect());
                    }

                    pObj = pNext;							//ポインタを進める
                }
            }

            m_pLevelupSelect->Uninit();
            delete m_pLevelupSelect;
            m_pLevelupSelect = nullptr;
        }
    }
}

void CGame::Draw()
{

}