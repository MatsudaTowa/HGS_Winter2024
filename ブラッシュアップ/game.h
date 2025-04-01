//=============================================
//
//3DTemplate[game.h]
//Auther Matsuda Towa
//
//=============================================
#ifndef _GAME_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _GAME_H_
#include "main.h"
#include "scene.h"

class CGame:public CScene
{
public:

	static const int DELAY_CNT = 30; //���U���g�ɔ�Ԃ܂ł̃f�B���C
	static const int BLOCK_TXT_MAX = 2048; //�G��ǂݍ��ލۂ̓ǂݍ��߂�ő啶����
	CGame();
	~CGame() override;
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void UpdateObjectDecision(bool bStop); //�I�u�W�F�N�g�̍X�V���s��������
	void Draw() override;

	inline bool GetPause() { return m_bPause; }
	inline void SetPause() { m_bPause = m_bPause ? false : true; }
private:
	static const D3DXVECTOR3 FIELD_SIZE; //�t�B�[���h�T�C�Y
	bool m_bPause;	//�|�[�Y����
};
#endif