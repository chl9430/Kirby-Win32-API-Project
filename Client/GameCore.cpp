#include "pch.h"
#include "GameCore.h"

GameCore::GameCore() 
	: m_hWnd{ 0 }
	, m_ptResolution{}
	, m_hDC{ 0 }
{
}

GameCore::~GameCore()
{
}

GameCore* GameCore::GetInst()
{
	static GameCore mgr;
	return &mgr;
}

int GameCore::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	ChangeWindowSize(Vec2{ (float)m_ptResolution.x, (float)m_ptResolution.y }, false);

	return S_OK;
}

void GameCore::ChangeWindowSize(Vec2 _vResolution, bool _bMenu)
{
	RECT rt = { 0, 0, (long)_vResolution.x, (long)_vResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu); // �޴��ٸ� ������ ���¿��� â�� �ػ󵵸� ����� (false : �޴��ٸ� ������ ȭ���� �ȼ��� ������ ������ ����)
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // ������ �ػ� ����
}
