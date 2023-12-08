#include "pch.h"
#include "GameScene_Stage.h"

#include "GameCore.h"

#include "GameCollisionMgr.h"
#include "GameCamera.h"

#include "GamePlayer.h"

GameScene_Stage::GameScene_Stage()
{
}

GameScene_Stage::~GameScene_Stage()
{
}

void GameScene_Stage::Render(HDC _dc)
{
	GameScene::Render(_dc);
}

void GameScene_Stage::Enter()
{
	GameObject* pObj = new GamePlayer; // �θ� Ŭ�������� ���� ���
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2{ 100.f, 100.f });
	pObj->SetScale(Vec2{ 50.f, 50.f });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	RegisterPlayer(pObj);

	Vec2 vResolution = GameCore::GetInst()->GetResolution();

	GameCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

	//// Camera Look ����
	//GameCamera::GetInst()->SetLookAt(vResolution / 2.f);

	Start();
}

void GameScene_Stage::Exit()
{
	DeleteAll();

	// �ٸ� �������� �ٸ� �׷찣�� �浹 üũ�� �ϰԵ� �� ������ �����Ѵ�.
	// CCollisionMgr::GetInst()->Reset();
}