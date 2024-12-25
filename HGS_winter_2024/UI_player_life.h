//=============================================
//
//3DTemplate[object2D.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _UI_PLAYER_H_ //これが定義されてないとき

#define _UI_PLAYER_H_
#include "main.h"
#include "object2D.h"

//2Dオブジェクトクラス
class UI_PlayerLife : public CObject2D
{
public:
	UI_PlayerLife(){};
	~UI_PlayerLife()override = default;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static UI_PlayerLife* Create(D3DXVECTOR3 pos,int MaxLife);
	void SetLife(int value) { m_Life = value; }
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	int m_Life;
};

//2Dオブジェクトクラス
class UI_PlayerExp : public CObject2D
{
public:
	UI_PlayerExp() {};
	~UI_PlayerExp()override = default;
	HRESULT Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	static UI_PlayerExp* Create(D3DXVECTOR3 pos, int MaxExp);
	void SetExp(int value) { m_Exp = value; }
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	int m_Exp;
};
#endif