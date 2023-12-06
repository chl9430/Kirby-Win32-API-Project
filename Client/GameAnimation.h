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

	void SetName(const wstring& _strName)
	{
		m_strName = _strName;
	}

public:
	void Save(const wstring& _strRelativePath);
	void Load(const wstring& _strRelativePath);
	void Create(GameTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);

	const wstring& GetName()
	{
		return m_strName;
	}

	GameAnimation();
	~GameAnimation();

	friend class GameAnimator;
};