//=============================================
//
//3DTemplate[exp.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "exp.h"
#include "manager.h"

//�o���l�̏��
const CExp::ExpInfo CExp::Info[EXP_TYPE_MAX] =
{
	{1, "data\\MODEL\\c.x"},
	{3, ""},
	{5, ""},
};

//=============================================
//�R���X�g���N�^
//=============================================
CExp::CExp(int nPriority) :CObjectX(nPriority),
	m_Info()
{
	//���
	m_type = OBJECT_TYPE_EXP;
}

//=============================================
//�f�X�g���N�^
//=============================================
CExp::~CExp()
{
}

//=============================================
//������
//=============================================
HRESULT CExp::Init()
{
	CModel* pModel = CManager::GetInstance()->GetModel();

	//X�t�@�C���ǂݍ���
	BindXFile(pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pBuffMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).dwNumMat,
		pModel->GetModelInfo(pModel->Regist(m_Info.Path.c_str())).pMesh);
	//�e�N���X�̏�����
	CObjectX::Init();

	return S_OK;
}

//=============================================
//�X�V
//=============================================
void CExp::Update()
{
	CObjectX::Update();
}

//=============================================
//����
//=============================================
CExp* CExp::Create(D3DXVECTOR3 pos, EXP_TYPE type)
{
	CExp* pObject = new CExp(3);

	pObject->m_Info = Info[type];

	pObject->Init();
	return pObject;
}