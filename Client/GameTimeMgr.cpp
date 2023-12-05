#include "pch.h"
#include "GameTimeMgr.h"

#include "GameCore.h"

GameTimeMgr::GameTimeMgr()
	: m_llCurCount{ 0 }
	, m_llPrevCount{ 0 }
	, m_llFrequency{ 0 }
	, m_dDT{ 0 }
	, m_iCallCount{ 0 }
	, m_dAcc{ 0 }
	, m_iFPS{ 0 }
{

}

GameTimeMgr::~GameTimeMgr()
{

}

void GameTimeMgr::Init()
{
	QueryPerformanceCounter(&m_llPrevCount); // ���� ī��Ʈ
	QueryPerformanceFrequency(&m_llFrequency); // �ʴ� ī��Ʈ�� �� �ִ� Ƚ��
}

void GameTimeMgr::Update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	m_llPrevCount = m_llCurCount;
}

void GameTimeMgr::Render()
{
	++m_iCallCount;

	m_dAcc += m_dDT;

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", m_iFPS, m_dDT);
		SetWindowText(GameCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}