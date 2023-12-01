#pragma once

class GameTexture;
class GameObject;

class GameCamera
{
	SINGLE(GameCamera);

private:
	GameTexture* m_pVeilTex; // ī�޶� ������ �ؽ�ó(������), GameResMgr���� �޸� �Ҵ� ����
	GameObject* m_pTargetObj;
	Vec2 m_vLookAt;

public:
	void Init();
	void Update();
};