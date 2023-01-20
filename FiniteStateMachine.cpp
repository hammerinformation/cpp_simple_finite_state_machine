#include "FiniteStateMachine.h"
#include <algorithm>
#include <iostream>
#include "State.h"
#include <tuple>
#include "Transition.h"

void FiniteStateMachine::tick()
{
    check();
    if (currentState) { currentState->onUpdate(); }
}


void FiniteStateMachine::check()
{
    for (int i = 0; i < transitionList.size(); ++i)
    {
        const auto& vec = std::get<2>(transitionList[i]);
        int j = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[0]->condition())
            {
                j++;
            }
        }
        if (j == vec.size())
        {
            if (currentState != std::get<1>(transitionList[i]))
            {
                changeState(std::get<1>(transitionList[i]));
            }
        }
    }
}

void FiniteStateMachine::changeState(State* state)
{
    currentState->onExit();
    currentState = state;
    currentState->onEnter();
}

FiniteStateMachine::FiniteStateMachine()
{
}

void FiniteStateMachine::startFiniteStateMachine()const
{
    for (State* state : states)
    {
        state->onStart();
    }
    currentState->onEnter();
}


FiniteStateMachine& FiniteStateMachine::addState(State* state)
{
    if (state != nullptr)
    {
        states.emplace_back(state);
    }
    return *this;
}

FiniteStateMachine& FiniteStateMachine::setFirstState(State* state)
{
    currentState = state;
    return *this;
}

FiniteStateMachine& FiniteStateMachine::addTransition(State* from, State* to, std::vector<Transition*>& transitions)
{
    if (from != nullptr && to != nullptr && from != to)
    {
        if (std::find(states.begin(), states.end(), from) != states.end()
            && std::find(states.begin(), states.end(), to) != states.end())
        {
            transitionList.emplace_back(from, to, transitions);
        }
    }


    return *this;
}
