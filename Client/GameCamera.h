#pragma once

class GameTexture;

class GameCamera
{
	SINGLE(GameCamera);

private:
	GameTexture* m_pVeilTex; // ī�޶� ������ �ؽ�ó(������), GameResMgr���� �޸� �Ҵ� ����

public:
	void Init();
};