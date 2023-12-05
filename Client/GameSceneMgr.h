#pragma once

class GameScene;

class GameSceneMgr
{
	SINGLE(GameSceneMgr);

private:
	GameScene* m_arrScene[(UINT)SCENE_TYPE::END]; // ��� �� ���
	GameScene* m_pCurScene;

	void ChangeScene(SCENE_TYPE _eNext); // GameEventMgr Ŭ������ ȣ�� ����

public:
	void Init();
	void Update();
	void Render(HDC _dc);

	GameScene* GetCurScene()
	{
		return m_pCurScene;
	}

	friend class GameEventMgr;
};