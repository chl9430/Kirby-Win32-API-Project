#pragma once

class GameAnimation;
class GameObject;

class GameAnimator
{
private:
	map<wstring, GameAnimation*> m_mapAnim;
	GameObject* m_pOwner;
	GameAnimation* m_pCurAnim;
	bool m_bRepeat;

public:
	void Play(const wstring& _strName, bool _bRepeat);

	void CreateAnimation(const wstring& _strName
		, GameTexture* _pTex // �̹��� �ؽ�ó
		, Vec2 _vLT // �ڸ� �̹����� �»�� ��ġ
		, Vec2 _vSliceSize // �ڸ� �̹����� ������
		, Vec2 _vStep // ������ �ڸ� �̹��������� �Ÿ�
		, float _fDuration
		, UINT _iFrameCount // �̹����� ������ ��
	);
	GameAnimation* FindAnimation(const wstring& _strName);
	void LoadAnimation(const wstring& _strRelativePath);

	GameAnimator();
	~GameAnimator();

	friend class GameObject;
};