#pragma once
#include <vector>
#include <tuple>

class State;
class Transition;

class FiniteStateMachine
{
private:
    void check();
    void changeState(State* state);
    State* firstState{};
    State* currentState{};
    std::vector<State*> states;
    std::vector<std::tuple<State*, State*, std::vector<Transition*>>> transitionList;

public:
    FiniteStateMachine();
    void startFiniteStateMachine()const;
    FiniteStateMachine& addState(State* state);
    FiniteStateMachine& setFirstState(State* state);
    FiniteStateMachine& addTransition(State* from, State* to, std::vector<Transition*>& transitions);
    void tick();
};
