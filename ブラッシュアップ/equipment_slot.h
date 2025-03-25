//=============================================
//
//装備のUI用ヘッダー[equipment_slot.h]
//Auther Matsuda Towa
//
//=============================================

//ヘッダーのインクルード
#include "equipment.h"
#include "object2D.h"
#include "texture.h"

class CEquipMent_Slot :public CObject2D
{
public:
	static const int PRIORITY = 20;  //描画順
	static constexpr float SIZE = 30.0f;	//サイズ

	CEquipMent_Slot(int nPriority = PRIORITY);
	~CEquipMent_Slot() override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static CEquipMent_Slot* Create(D3DXVECTOR3 pos);	//生成
private:
	static const std::string TEXTURE_NAME;	//テクスチャの名前
};