//=============================================
//
//3DTemplate[field.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _FIELD_H_ //これが定義されてないとき

#define _FIELD_H_
#include "main.h"
#include "object3D.h"

//レンダラークラス
class CField : public CObject3D
{
public:

	static const int FIELD_PRIORITY = 3; //描画順

	CField(int nPriority = FIELD_PRIORITY);
	~CField()override;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	static CField* Create(D3DXVECTOR3 pos,D3DXVECTOR3 size);
private:
	static const std::string TEXTURE_NAME;	//テクスチャの名前
};
#endif