#pragma once
#include "GameObject.h"

class GameUI :
    public GameObject
{
private:
    vector<GameUI*> m_vecChildUI;
    GameUI* m_pParentUI;
    Vec2 m_vFinalPos;

    bool m_bCamAffected; // UI�� ī�޶��� ������ �޴��� ����
    bool m_bMouseOn; // UI ���� ���콺�� �ִ��� ����
    bool m_bLbtnDown; // UI�� ���ʹ�ư�� �������� �ִ��� �칫

    void UpdateChild();
    void FinalUpdateChild();
    void RenderChild(HDC _dc);

    void MouseOnCheck();

public:
    virtual void Update();
    virtual void FinalUpdate();
    virtual void Render(HDC _dc);

    virtual void MouseOn();
    virtual void MouseLbtnDown();
    virtual void MouseLbtnUp();
    virtual void MouseLbtnClicked();

    void AddChild(GameUI* _pUI)
    {
        m_vecChildUI.push_back(_pUI);
        _pUI->m_pParentUI = this;
    }
    GameUI* GetParent()
    {
        return m_pParentUI;
    }
    Vec2 GetFinalPos()
    {
        return m_vFinalPos;
    }
    bool IsLbtnDown()
    {
        return m_bLbtnDown;
    }
    bool IsMouseOn() { 
        return m_bMouseOn;
    }
    const vector<GameUI*>& GetChildUI() 
    { 
        return m_vecChildUI; 
    }

    GameUI(bool _bCamAff);
    ~GameUI();

    friend class GameUIMgr;
};