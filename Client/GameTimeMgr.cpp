#include "pch.h"
#include "GameTimeMgr.h"

GameTimeMgr::GameTimeMgr()
	: m_llCurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDT{ 0 }
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