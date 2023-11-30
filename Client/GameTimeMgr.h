#pragma once

class GameTimeMgr
{
	SINGLE(GameTimeMgr);

private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;

	double m_dDT; // ������ ������ �ð���

public:
	void Init();
	void Update();
};