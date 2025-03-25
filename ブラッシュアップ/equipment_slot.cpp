//=============================================
//
//装備のUI用[equipment_slot.cpp]
//Auther Matsuda Towa
//
//=============================================
#include "equipment_slot.h"

const std::string CEquipMent_Slot::TEXTURE_NAME = "data\\TEXTURE\\UI_SLOT";

//=============================================
// コンストラクタ
//=============================================
CEquipMent_Slot::CEquipMent_Slot(int nPriority) : CObject2D(nPriority)
{
}

//=============================================
// デストラクタ
//=============================================
CEquipMent_Slot::~CEquipMent_Slot()
{
}

//=============================================
// 初期化
//=============================================
HRESULT CEquipMent_Slot::Init()
{
	CObject2D::Init();

	//テクスチャ情報取得
	CTexture* pTexture = GET_TEXTURE;

	//テクスチャ登録
	BindTexture(pTexture->GetAddress(pTexture->Regist(&TEXTURE_NAME)));

	//頂点設定
	SetVtx(FLOAT_ONE);

	return S_OK;
}

//=============================================
// 終了
//=============================================
void CEquipMent_Slot::Uninit()
{
	CObject2D::Uninit();
}

//=============================================
// 更新
//=============================================
void CEquipMent_Slot::Update()
{
	CObject2D::Update();

	//頂点設定
	SetVtx(FLOAT_ONE);
}

//=============================================
// 描画
//=============================================
void CEquipMent_Slot::Draw()
{
	CObject2D::Draw();
}

//=============================================
// 生成
//=============================================
CEquipMent_Slot* CEquipMent_Slot::Create(D3DXVECTOR3 pos)
{
	CEquipMent_Slot* pEquipment_slot = new CEquipMent_Slot;

	if (pEquipment_slot == nullptr) { return nullptr; }

	pEquipment_slot->SetPos(pos);	//位置設定

	return pEquipment_slot;
}
