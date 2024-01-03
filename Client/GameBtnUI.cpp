#include "pch.h"
#include "GameBtnUI.h"

GameBtnUI::GameBtnUI()
	: GameUI{ false }
	, m_pSceneFunc{ nullptr }
	, m_pFunc{ nullptr }
	, m_param1{}
	, m_param2{}
	, m_pSceneInst{ nullptr }
{
}

GameBtnUI::~GameBtnUI()
{
}

void GameBtnUI::SetClickedCallBack(GameScene* _pScene, SCENE_MEMFUNC _pSceneFunc)
{
	m_pSceneInst = _pScene;
	m_pSceneFunc = m_pSceneFunc;
}

void GameBtnUI::MouseLbtnClicked()
{
	if (nullptr != m_pFunc)
	{
		m_pFunc(m_param1, m_param2);
	}

	if (m_pSceneInst && m_pSceneFunc)
	{
		// Ŭ���� ����Լ��� �Լ������ͷ� ȣ���մϴ�.
		((*m_pSceneInst).*m_pSceneFunc)();
	}
}