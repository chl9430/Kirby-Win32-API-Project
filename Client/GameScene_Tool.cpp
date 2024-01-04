#include "pch.h"
#include "GameScene_Tool.h"

#include "GameCore.h"

#include "GameSceneMgr.h"
#include "GameKeyMgr.h"
#include "GameCamera.h"
#include "GamePathMgr.h"
#include "GameResMgr.h"

#include "GameUI.h"
#include "GamePanelUI.h"
#include "GameBtnUI.h"
#include "GameTile.h"

GameScene_Tool::GameScene_Tool()
	: m_eCurMode{ EDIT_MODE::NONE }
{
}

GameScene_Tool::~GameScene_Tool()
{
}

void GameScene_Tool::Enter()
{
	// �� Scene���� ����� �޴��� ���δ�.
	GameCore::GetInst()->DockMenu();

	// Ÿ�� ����
	CreateTile(5, 6);

	Vec2 vResolution = GameCore::GetInst()->GetResolution();
	// GameCamera::GetInst()->SetLookAt(vResolution / 2.f);

	GameUI* pPanelUI = new GamePanelUI{ false };
	pPanelUI->SetName(L"ParentUI");
	pPanelUI->SetScale(Vec2{ 300.f, 150.f });
	pPanelUI->SetPos(Vec2{ vResolution.x - pPanelUI->GetScale().x, 0.f });

	GameBtnUI* pBtnUI = new GameBtnUI{ false };
	pBtnUI->SetName(L"ChildUI");
	pBtnUI->SetScale(Vec2{ 150.f, 50.f });
	pBtnUI->SetPos(Vec2{ 0.f, 0.f });
	pBtnUI->SetClickedCallBack(this, (SCENE_MEMFUNC)&GameScene_Tool::SetCurMode);
	pBtnUI->SetIdleTexture(GameResMgr::GetInst()->LoadTexture(L"TileMapButton", L"texture\\Tile_Map_Button.bmp"));
	pBtnUI->SetMouseDownTexture(GameResMgr::GetInst()->LoadTexture(L"TileMapButtonClicked", L"texture\\Tile_Map_Button_Clicked.bmp"));
	pBtnUI->SetCurrentTexture(GameResMgr::GetInst()->FindTexture(L"TileMapButton"));

	pPanelUI->AddChild(pBtnUI);
	AddObject(pPanelUI, GROUP_TYPE::UI);
}

void GameScene_Tool::Exit()
{
	GameCore::GetInst()->DivideMenu();

	DeleteAll();
}

void GameScene_Tool::Update()
{
	GameScene::Update();

	SetTileIdx();

	if (KEY_TAP(KEY::CTRL))
	{
		LoadTileData();
	}

	if (KEY_TAP(KEY::LSHIFT))
	{
		SaveTileData();
	}
}

void GameScene_Tool::SaveTileData()
{
	OPENFILENAME ofn = {};

	wchar_t szName[256] = {};

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = GameCore::GetInst()->GetMainHwnd();
	ofn.lpstrFile = szName;
	ofn.nMaxFile = sizeof(szName);
	ofn.lpstrFilter = L"All\0*.*\0Tile\0*.tile\0"; // ��� �̸�, ��� Ȯ����
	ofn.nFilterIndex = 0;
	ofn.lpstrFileTitle = nullptr;
	ofn.nMaxFileTitle = 0;

	wstring strTileFolder = GamePathMgr::GetInst()->GetContentPath();
	strTileFolder += L"tile";

	ofn.lpstrInitialDir = strTileFolder.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Modal
	if (GetSaveFileName(&ofn)) // ����� true, ��ҽ� false
	{
		SaveTile(szName);
	}
}

void GameScene_Tool::SaveTile(const wstring& _strFilePath)
{
	// ���ϵ� Ŀ�� ������Ʈ(������ġ�� �츮 ���α׷� ���̿��� ������ ����ִ� ������ ��)
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _strFilePath.c_str(), L"wb"); // 2����Ʈ ����
	// 1���� : ���� ������ �ּ�
	// 2���� : ������ ���
	// 3���� : ��� L"w" -> ����, L"r" -> �б�, b�� ������ ���̳ʸ� ���

	assert(pFile);

	// Ÿ�� ���μ��� ���� ����
	UINT xCount = GetTileX();
	UINT yCount = GetTileY();

	fwrite(&xCount, sizeof(UINT), 1, pFile);
	fwrite(&yCount, sizeof(UINT), 1, pFile);

	// ��� Ÿ�ϵ��� ���������� ������ �����͸� �����ϰ� ��
	const vector<GameObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);

	for (size_t i = 0; i < vecTile.size(); ++i)
	{
		((GameTile*)vecTile[i])->Save(pFile);
	}

	fclose(pFile); // ����(��Ʈ��)�� �ݾ��ش�.
}

void GameScene_Tool::LoadTileData()
{
	OPENFILENAME ofn = {};

	wchar_t szName[256] = {};

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = GameCore::GetInst()->GetMainHwnd();
	ofn.lpstrFile = szName;
	ofn.nMaxFile = sizeof(szName);
	ofn.lpstrFilter = L"All\0*.*\0Tile\0*.tile\0"; // ��� �̸�, ��� Ȯ����
	ofn.nFilterIndex = 0;
	ofn.lpstrFileTitle = nullptr;
	ofn.nMaxFileTitle = 0;

	wstring strTileFolder = GamePathMgr::GetInst()->GetContentPath();
	strTileFolder += L"tile";

	ofn.lpstrInitialDir = strTileFolder.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Modal
	if (GetOpenFileName(&ofn))
	{
		wstring strRelativePath = GamePathMgr::GetInst()->GetRelativePath(szName);
		LoadTile(strRelativePath);
	}
}

void GameScene_Tool::SetTileIdx()
{
	if (KEY_TAP(KEY::LBTN))
	{
		Vec2 vMousePos = MOUSE_POS;
		vMousePos = GameCamera::GetInst()->GetRealPos(vMousePos);

		int iTileX = (int)GetTileX();
		int iTileY = (int)GetTileY();

		int iCol = (int)vMousePos.x / TILE_SIZE;
		int iRow = (int)vMousePos.y / TILE_SIZE;

		if (vMousePos.x < 0.f || iTileX <= iCol
			|| vMousePos.y < 0.f || iTileX <= iRow)
		{
			return;
		}

		UINT iIdx = iRow * iTileX + iCol;

		const vector<GameObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((GameTile*)vecTile[iIdx])->AddImgIdx();
	}
}

INT_PTR CALLBACK TileCountProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) // CALLBACK(__stdcall) : �Լ�ȣ��Ծ�
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			UINT iXCount = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, false); // ���� ���̾�α��� �����͸� �������� �Լ�(����������)
			UINT iYCount = GetDlgItemInt(hDlg, IDC_EDIT2, nullptr, false); // ���� ���̾�α��� �����͸� �������� �Լ�

			GameScene* pCurScene = GameSceneMgr::GetInst()->GetCurScene();

			// ToolScene Ȯ��
			GameScene_Tool* pToolScene = dynamic_cast<GameScene_Tool*>(pCurScene);
			assert(pToolScene); // ĳ���ÿ� �����ϸ�, ������� �� ���̴�.

			pToolScene->DeleteGroup(GROUP_TYPE::TILE);
			pToolScene->CreateTile(iXCount, iYCount);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}