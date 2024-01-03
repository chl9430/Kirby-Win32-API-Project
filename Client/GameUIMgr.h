#pragma once

class GameUI;

class GameUIMgr
{
	SINGLE(GameUIMgr);

private:
	GameUI* m_pFocusedUI;

	GameUI* GetFocusedUI();
	GameUI* GetTargetedUI(GameUI* _pParentUI); // �θ� UI ������ ������ Ÿ���� �� UI�� ã�Ƽ� ��ȯ�Ѵ�.

public:
	void Update();

	void SetFocusedUI(GameUI* _pUI);
};