#pragma once

class GameTexture;
class GameAnimator;

struct tAnimFrm
{
	Vec2 vLT; // ������ �ִϸ��̼� �̹����� �»��
	Vec2 vSlice; // ������ �ִϸ��̼� �̹����� ������
	Vec2 vOffset;
	float fDuration;
};

class GameAnimation
{
private:
	GameAnimator* m_pAnimator;
	wstring m_strName;
	GameTexture* m_pTex;
	vector<tAnimFrm> m_vecFrm; // ��� ������ ����

public:
	void Save(const wstring& _strRelativePath);
	void Load(const wstring& _strRelativePath);

	const wstring& GetName()
	{
		return m_strName;
	}

	GameAnimation();
	~GameAnimation();

	friend class GameAnimator;
};