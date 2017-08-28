#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <map>
#include <memory>
#include <stack>
#include <queue>
#include "State.h"
#include "PlayingState.h"
#include "../States.h"

class Application;

class StateManager
{
public:
    StateManager(Application& app);

    State& currentState();

    void requestPushState(GameState id);
    void requestPopState();
    void requestChangeState(GameState id);
    void requestChangeStateWithDelete(GameState id);
    void applyPending();

private:
    enum class Action { Push, Pop, PopAndDelete };
    struct PendingChange
    {
        Action action;
        GameState id;
        PendingChange(Action act, GameState id = GameState::Playing)
            : action(act), id(id) {}
    };

private:
    std::map<GameState, std::unique_ptr<State>> m_stateMap;
    std::stack<State*> m_statesStack;
    std::queue<PendingChange> m_pending;

    Application * m_app;
};

#endif // STATEMANAGER_H
