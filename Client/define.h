#pragma once

// �̱��� ��ũ��
#define SINGLE(type)	public:\
							static type* GetInst()\
							{\
								static type mgr;\
								return &mgr;\
							}\
						private:\
							type();\
							~type();

#define fDT GameTimeMgr::GetInst()->GetfDT()
#define DT GameTimeMgr::GetInst()->GetfDT()

#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)

#define KEY_CHECK(key, state) GameKeyMgr::GetInst()->GetKeyState(key) == state

enum class GROUP_TYPE // ��ȣ�� ���� ���� ���߿� ����
{
	DEFAULT,
	TILE,
	GROUND,
	MONSTER,
	PLAYER,
	PROJ_PLAYER,
	PROJ_MONSTER,

	UI = 31,
	END = 32
};

enum class SCENE_TYPE
{
	TITLE,
	// SELECT_STAGE,
	STAGE_01,
	TOOL,
	END
};

enum class BRUSH_TYPE
{
	HOLLOW, // ä��� ������ ���� �귯�� Ÿ��
	BLACK,
	END
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};