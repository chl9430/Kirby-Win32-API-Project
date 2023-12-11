#pragma once
#include "GameState.h"

class GameIdleState :
    public GameState
{
private:

public:
    virtual void Update();
    virtual void Enter();
    virtual void Exit();

    GameIdleState();
    ~GameIdleState();
};