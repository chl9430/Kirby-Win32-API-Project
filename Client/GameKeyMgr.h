#pragma once

enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	W,
	A,
	S,
	D,
	LSHIFT,
	SPACE,
	LAST
};

struct tKeyInfo
{
	KEY_STATE eState; // Ű�� ���°�
	bool bPrevPush; // ���� �����ӿ��� ���ȴ��� ����
};

class GameKeyMgr
{
	SINGLE(GameKeyMgr);

private:
	vector<tKeyInfo> m_vecKey;

public:
	void Init();
};