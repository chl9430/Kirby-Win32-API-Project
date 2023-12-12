#include "pch.h"
#include "GameGround.h"

#include "GameCollider.h"
#include "GameGravity.h"

GameGround::GameGround()
{
	CreateCollider();
}

GameGround::~GameGround()
{
}

void GameGround::Start()
{
	GetCollider()->SetScale(Vec2{ GetScale() });
}

void GameGround::Update()
{
}

void GameGround::OnCollisionEnter(GameCollider* _pOther)
{
	GameObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player" || pOtherObj->GetName() == L"Monster")
	{
		pOtherObj->GetGravity()->SetGround(true);

		Vec2 vObjPos = _pOther->GetFinalPos();
		Vec2 vObjScale = _pOther->GetScale();

		Vec2 vPos = GetCollider()->GetFinalPos();
		Vec2 vScale = GetCollider()->GetScale();

		float fLen = abs(vObjPos.y - vPos.y);
		float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

		// �浹�� ���� ���·� �����ϱ� ���� �Ϻη� 1�ȼ� �÷��ش�.
		vObjPos = pOtherObj->GetPos();
		vObjPos.y -= (fValue);

		pOtherObj->SetPos(vObjPos);
	}
}

void GameGround::OnCollision(GameCollider* _pOther)
{
	GameObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player" || pOtherObj->GetName() == L"Monster")
	{
		pOtherObj->GetGravity()->SetGround(true);

		Vec2 vObjPos = _pOther->GetFinalPos();
		Vec2 vObjScale = _pOther->GetScale();

		Vec2 vPos = GetCollider()->GetFinalPos();
		Vec2 vScale = GetCollider()->GetScale();

		float fLen = abs(vObjPos.y - vPos.y);
		float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

		// �浹�� ���� ���·� �����ϱ� ���� �Ϻη� 1�ȼ� �÷��ش�.
		vObjPos = pOtherObj->GetPos();
		vObjPos.y -= (fValue);

		pOtherObj->SetPos(vObjPos);
	}
}

void GameGround::OnCollisionExit(GameCollider* _pOther)
{
	GameObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player" || pOtherObj->GetName() == L"Monster")
	{
		pOtherObj->GetGravity()->SetGround(false);
	}
}