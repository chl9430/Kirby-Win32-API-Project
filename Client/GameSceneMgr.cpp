#include "pch.h"
#include "GameSceneMgr.h"

#include "GameScene_Title.h"
#include "GameScene_Tool.h"

GameSceneMgr::GameSceneMgr()
	: m_arrScene{}
	, m_pCurScene{ nullptr }
{

}

GameSceneMgr::~GameSceneMgr()
{
	// ��� �� �Ҵ� ����
	for (size_t i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (m_arrScene[i] != nullptr)
		{
			delete m_arrScene[i];
		}
	}
}

void GameSceneMgr::Init()
{
	// �� ����
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new GameScene_Title;
	m_arrScene[(UINT)SCENE_TYPE::TITLE]->SetName(L"Title Scene");

	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new GameScene_Tool;
	m_arrScene[(UINT)SCENE_TYPE::TOOL]->SetName(L"Tool Scene");

	// ���� �� ����
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TITLE];
	m_pCurScene->Enter();
}