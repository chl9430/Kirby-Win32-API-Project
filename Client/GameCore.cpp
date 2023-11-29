#include "pch.h"
#include "GameCore.h"

#include "GameResMgr.h"

GameCore::GameCore() 
	: m_hWnd{ 0 }
	, m_ptResolution{}
	, m_hDC{ 0 }
	, m_pMemTex{ nullptr }
	, m_hMenu{}
{
}

GameCore::~GameCore()
{
}

int GameCore::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	ChangeWindowSize(Vec2{ (float)_ptResolution.x, (float)_ptResolution.y }, false);

	m_hMenu = LoadMenu(nullptr, MAKEINTRESOURCEW(IDC_CLIENT));

	m_hDC = GetDC(m_hWnd);

	// ���� ���۸��� �ؽ�ó ������ �����.
	// m_pMemTex = GameResMgr::GetInst()->CreateTexture(L"BackBuffer", (UINT)m_ptResolution.x, (UINT)m_ptResolution.y);
	m_pMemTex = GameResMgr::GetInst()->CreateTexture(L"BackBuffer", (UINT)m_ptResolution.x, (UINT)m_ptResolution.y);

	return S_OK;
}

void GameCore::ChangeWindowSize(Vec2 _vResolution, bool _bMenu)
{
	RECT rt = { 0, 0, (long)_vResolution.x, (long)_vResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu); // false�� �� : �޴��ٸ� ������ ���¿��� â�� �ػ󵵸� �����
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); // ������ �ػ� ����
}
