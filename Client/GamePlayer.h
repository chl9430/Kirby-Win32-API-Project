#pragma once
#include "GameObject.h"

enum class PLAYER_STATE
{
    IDLE,
    WALK,
    RUN,
    DOWN,
    INHALE,
    JUMP,
    FLOAT,
    EXHALE
};

class GamePlayer :
    public GameObject
{
private:
    PLAYER_STATE m_eCurState;
    PLAYER_STATE m_ePrevState;
    int m_iDir; // �÷��̾��� ��������
    int m_iPrevDir;

public:
    virtual void Update();
    virtual void Render(HDC _dc);

    void UpdateState();
    void UpdateMove();
    void UpdateAnimation();

    GamePlayer();
    virtual ~GamePlayer();
};