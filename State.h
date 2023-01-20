#pragma once

#include "FiniteStateMachine.h"
class State
{
public:
    virtual void onStart()=0;
    virtual void onEnter()=0;
    virtual void onUpdate()=0;
    virtual void onExit()=0;
};
