#pragma once

class GameTimeMgr
{
	SINGLE(GameTimeMgr);

private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;

	double m_dDT; // ������ ������ �ð���
	double m_dAcc; // 1�� üũ�� ���� �����ð�
	UINT m_iCallCount;
	UINT m_iFPS; // ���� FPS

public:
	void Init();
	void Update();
	void Render();

	double GetDT()
	{
		return m_dDT;
	}

	float GetfDT()
	{
		return (float)m_dDT;
	}
};