#pragma once

union COLLIDER_ID
{
	struct
	{
		UINT Left_id;
		UINT Right_id;
	};
	ULONGLONG ID;
};

class GameCollider;

class GameCollisionMgr
{
	SINGLE(GameCollisionMgr);

private:
	map<ULONGLONG, bool> m_mapColInfo; // �浹ü ���� ���� ������ �浹����
	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // �׷� ���� �浹 üũ ��Ʈ����

	void CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(GameCollider* _pLeftCol, GameCollider* _pRightCol);
public:
	void Update();

	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
};