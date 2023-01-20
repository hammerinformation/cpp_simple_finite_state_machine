#include<iostream>
#include "FiniteStateMachine.h"
#include "State.h"
#include "Actor.h"
#include "Transition.h"


 Actor* const actor = new Actor;

class AState : public State
{
public:
    void onStart() override
    {
        std::cout << "AState::onStart() \n";

    }
    void onEnter() override
    {
        std::cout << "AState::onEnter() \n";
    }

    void onUpdate() override
    {
        std::cout << "AState::onUpdate() \n";
    }

    void onExit() override
    {
        std::cout << "AState::onExit() \n";
    }

   
};

class BState : public State
{
public:
    void onStart() override
    {
        std::cout << "BState::onStart() \n";

    }
    void onEnter() override
    {
        std::cout << "BState::onEnter() \n";
    }

    void onUpdate() override
    {
        std::cout << "BState::onUpdate() \n";
    }

    void onExit() override
    {
        std::cout << "BState::onExit() \n";
    }
};

class AToB : public Transition
{
public:
    bool condition() const override
    {
        return actor->value != 0;
    }
};


class BToA : public Transition
{
public:
    bool condition() const override
    {
        return actor->value == 0;
    }
};

int main(int argc, char* argv[])
{
    FiniteStateMachine* const fsm = new FiniteStateMachine;
    State* const aState = new AState;
    State* const bState = new BState;
    fsm->addState(aState).addState(bState);
    std::vector<Transition*>   atob;
    atob.emplace_back(new AToB);
    std::vector<Transition*> btoa;
    btoa.emplace_back(new  BToA);
    fsm->addTransition(aState, bState, atob);
    fsm->addTransition(bState, aState, btoa);
    fsm->setFirstState(bState);
    fsm->startFiniteStateMachine();
    

    actor->value=22;
    int i = 1;
    while (true)
    {
        (void)getchar();
        ++i;
        (*fsm).tick();
        if (i > 5)
        {
            actor->value = 0;
        }
        if (i > 10)
        {
            actor->value = 20;
        }
        
    }


    return 0;
}
