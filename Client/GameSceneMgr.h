#pragma once

class GameScene;

class GameSceneMgr
{
	SINGLE(GameSceneMgr);

private:
	GameScene* m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	GameScene* m_pCurScene;

public:
	void Init();
};