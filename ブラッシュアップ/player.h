//=============================================
//
//プレイヤー[player_test.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _PLAYER_TEST_H_ //これが定義されてないとき

#define _PLAYER_TEST_H_
#include "main.h"
#include "model_parts.h"
#include "character.h"
#include "equipment.h"
#include "equipment_slot.h"
#include "hp_gauge.h"

class CPlayerState;

//プレイヤークラス
class CPlayer :public CCharacter
{
public:
	static const int MAX_KEY = 20; //キー最大数
	static const int PLAYER_LIFE = 150; //体力
	static const int PLAYER_PRIORITY = 8; //描画順
	static const char* MODEL_FILE; //モデルのファイルパス
	static constexpr float ITEM_UI_UNLOCK_EXP = 50.0f;	//アイテム選択画面に遷移するまでに必要な経験値の量

	//モーションの種類の列挙
	enum Motion_Type
	{
		MOTION_NEUTRAL = 0,
		MOTION_MOVE,
		MOTION_ATTACK,
		MOTION_MAX,
	};

	CPlayer(int nPriority = PLAYER_PRIORITY);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	//プレイヤー作成
	static CPlayer* Create();

	void ChangePlayerState(CPlayerState* state);

	//クールカウント取得
	inline float& GetAttackCoolCnt()
	{
		return m_AttackCoolTime;
	}

	//クールカウント設定
	inline void SetAttackCoolCnt(float Cnt)
	{
		m_AttackCoolTime = Cnt;
	}

	//経験値取得
	inline float& GetExp()
	{
		return m_fExp;
	}

	//経験値追加
	inline void AddExp(float exp)
	{
		if (m_fExp < ITEM_UI_UNLOCK_EXP)
		{
			m_fExp += exp;
		}
	}

	//経験値リセット
	inline void ResetExp()
	{
		m_fExp = 0.0f;
	}

private:
	static const D3DXVECTOR3 PLAYER_SPAWN_POS; //スポーン位置
	static const D3DXVECTOR3 PLAYER_SPAWN_ROT; //スポーン方向
	static const D3DXVECTOR3 SLOT_START_POS; //一個目のスロット生成
	static const int MAX_EQUIPMENT = 6; //装備の最大数
	static constexpr float DEFAULT_COOLTIME = 120.0f;
	static constexpr float LEVEL_EXP = 1.05f;

	std::array<CEquipment*, MAX_EQUIPMENT> m_pEquipMent; //装備情報

	std::array<CEquipMent_Slot*, MAX_EQUIPMENT> m_pEquipMentSlot; //装備スロット

	CPlayerState* m_pPlayerState;

	CGauge_2D* m_pHpGauge;	//体力ゲージ
	CGauge_2D* m_pExpGauge;	//経験値ゲージ

	D3DXVECTOR3 m_SlotPos; //スロットの位置(ずらすために変数化)

	float m_AttackCoolTime;	//クールタイム

	float m_AttackCoolCnt;  //アタックのクールタイムカウント

	float m_fExp; //経験値

	void ReSpawn(); //リスポーン

	void DebugPos();

	void Input(); //入力処理
};
#endif