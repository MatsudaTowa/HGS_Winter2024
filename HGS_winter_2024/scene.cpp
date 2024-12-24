//=============================================
//
//3DTemplate[scene.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "manager.h"

CScene::MODE CScene::m_Mode = CScene::MODE::MODE_TITLE;
//=============================================
//コンストラクタ
//=============================================
CScene::CScene()
{
}

//=============================================
//デストラクタ
//=============================================
CScene::~CScene()
{
}

//=============================================
//初期化
//=============================================
HRESULT CScene::Init()
{
    return S_OK;
}

//=============================================
//終了
//=============================================
void CScene::Uninit()
{
}

//=============================================
//更新
//=============================================
void CScene::Update()
{
}

//=============================================
//描画
//=============================================
void CScene::Draw()
{
}

//=============================================
//生成
//=============================================
CScene* CScene::Create(MODE mode)
{
    // インスタンス生成
    CScene* pScene = nullptr;

    // 条件分岐
    switch (mode)
    {
    case MODE_TITLE: // タイトル

        //delete pScene;
        pScene = new CTitle;
        break;
   
    case MODE_GAME: // ゲーム

        //delete pScene;
        pScene = new CGame;
        break;
    case MODE_RESULT: //リザルト

        //delete pScene;
        pScene = new CResult;
        break;
    default:
    assert(true);
        break;
    }

    if (pScene != nullptr)
    {
        pScene->m_Mode = mode;
    }
    //今のシーンの初期化
    pScene->Init();

    CManager::GetInstance()->GetModel()->Unload();

    return pScene;
}

//=============================================
//シーンの取得
//=============================================
CScene::MODE CScene::GetSceneMode()
{
    return m_Mode;
}

