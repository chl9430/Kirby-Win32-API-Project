#include "pch.h"
#include "GameScene.h"

#include "GameObject.h"

GameScene::GameScene()
	: m_strName{}
	, m_arrObj{}
	, m_pPlayer{ nullptr }
{
}

GameScene::~GameScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
		}
	}
}

void GameScene::Start()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->Start();
		}
	}
}

void GameScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			if (!m_arrObj[i][j]->IsDead()) // ������Ʈ�� ����������� �ƴ϶��
			{
				m_arrObj[i][j]->Update();
			}
		}
	}
}

void GameScene::FinalUpdate()
{
}

void GameScene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		/*if ((UINT)GROUP_TYPE::TILE == i)
		{
			Render_Tile(_dc);
			continue;
		}*/

		vector<GameObject*>::iterator iter = m_arrObj[i].begin();

		for ( ; iter != m_arrObj[i].end(); )
		{
			if (!(*iter)->IsDead()) // ������Ʈ�� ���� �ʾҴٸ�
			{
				(*iter)->Render(_dc);
				++iter;
			}
			else // ������Ʈ�� ���� �ʾҴٸ�
			{
				iter = m_arrObj[i].erase(iter); // �ش��ϴ� ���� ���Ϳ��� �����, ���� ������ iter���� ��ȯ
			}
		}
	}
}

void GameScene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		Safe_Delete_Vec<GameObject*>(m_arrObj[i]);
	}
}