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
CGame::CGame() :m_nResultDelay(0), m_pLevelupSelect(0)
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
        || pMouse->GetTrigger(0))
    {
        //�^�C�g���ɖ߂�
        CManager::GetInstance()->GetFade()->SetFade(CScene::MODE::MODE_RESULT);
    }

    if (CEnemy::m_NumEnemy <= 0)
    {//�G�����Ȃ��Ȃ�����
        for (int nCnt = 0; nCnt < 10; nCnt++)
        {
            std::random_device seed;
            std::mt19937 random(seed());
            std::uniform_int_distribution<int> number(0, 150);
            CEnemy::Create({ (float)number(random),0.5f,100.0f }, VEC3_RESET_ZERO, CEnemy::ENEMY_TYPE_WEAK);
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

    //�G�Ƃ̓����蔻��
    for (int i = 0; i < MAX_PRIORITY; i++)
    {
        CObject* pObj = CObject::Getobject(i);	//�擪�擾

        //�ő吔���s���Ȃ̂�while���g�p
        while (pObj != nullptr)
        {
            CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

            //�G�������đ��x���グ��
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

            pObj = pNext;							//�|�C���^��i�߂�
        }
    }

    if (m_pLevelupSelect != nullptr)
    {
        m_pLevelupSelect->Update();

        if (m_pLevelupSelect->GetEnd())
        {
            //�G�Ƃ̓����蔻��
            for (int i = 0; i < MAX_PRIORITY; i++)
            {
                CObject* pObj = CObject::Getobject(i);	//�擪�擾

                //�ő吔���s���Ȃ̂�while���g�p
                while (pObj != nullptr)
                {
                    CObject* pNext = pObj->GetNextobject();	//���̃|�C���^���擾

                    //�G�������đ��x���グ��
                    if (pObj->GetType() == CObject::OBJECT_TYPE_PLAYER)
                    {
                        CPlayer* pPlayer = dynamic_cast<CPlayer*>(pObj);
                        pPlayer->SetSoubi(m_pLevelupSelect->GetSelect());
                    }

                    pObj = pNext;							//�|�C���^��i�߂�
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