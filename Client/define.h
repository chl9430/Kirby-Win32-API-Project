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

enum class SCENE_TYPE
{
	TITLE,
	/*SELECT_STAGE,
	STAGE_01,*/
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