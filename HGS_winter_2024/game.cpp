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

//���̃T�C�Y
const D3DXVECTOR3 CGame::FIELD_SIZE = { 100.0f,0.0f,100.0f };

//=============================================
//�R���X�g���N�^
//=============================================
CGame::CGame():m_nResultDelay(0), m_pLevelupSelect(0)
{//�C�j�V�����C�U�[�Ńv���C�I���e�B�ݒ�A�G�f�B�b�g���ĂȂ���ԂɕύX
}

//=============================================
//�f�X�g���N�^
//=============================================
CGame::~CGame()
{
}

//=============================================
//������
//=============================================
HRESULT CGame::Init()
{
    CField::Create(VEC3_RESET_ZERO, FIELD_SIZE);

    CPlayer::Create();

    CEnemy::Create({ 5.0f,0.5f,100.0f }, VEC3_RESET_ZERO, CEnemy::ENEMY_TYPE_WEAK);

    CManager::GetInstance()->GetSound()->PlaySound(CSound::SOUND_LABEL_BGM_GAME);
    return S_OK;
}

//=============================================
//�I��
//=============================================
void CGame::Uninit()
{
    CManager::GetInstance()->GetSound()->StopSound(CSound::SOUND_LABEL_BGM_GAME);
	CObject::ReleaseAll();
}

//=============================================
//�X�V
//=============================================
void CGame::Update()
{
    //�e�C���v�b�g�擾
    CInputKeyboard* pKeyboard = CManager::GetInstance()->GetKeyboard();
    CInputPad* pPad = CManager::GetInstance()->GetPad();
    CInputMouse* pMouse = CManager::GetInstance()->GetMouse();

    if (pKeyboard->GetTrigger(DIK_RETURN)
        || pMouse->GetTrigger(0)
        || pPad->GetTrigger(CInputPad::JOYKEY::JOYKEY_A))
    {
        //�^�C�g���ɖ߂�
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
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

    if (m_pLevelupSelect != nullptr)
    {
        m_pLevelupSelect->Update();
    }
}


//=============================================
//�`��
//=============================================
void CGame::Draw()
{
}
