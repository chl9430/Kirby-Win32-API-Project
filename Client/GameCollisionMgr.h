#pragma once

class GameCollisionMgr
{
	SINGLE(GameCollisionMgr);

private:
	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // �׷� ���� �浹 üũ ��Ʈ����

public:
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
};