#include "StateManager.h"
#include <cassert>
#include <iostream>
#include "PlayingState.h"
#include "PauseState.h"

StateManager::StateManager(Application& app)
    : m_app(&app)
{
}

State& StateManager::currentState()
{
    assert(!m_statesStack.empty());
    return *m_statesStack.top();
}

void StateManager::requestPushState(GameState id)
{
    std::cout << __FUNCTION__ << std::endl;
    m_pending.emplace(Action::Push, id);
}

void StateManager::requestPopState()
{
    std::cout << __FUNCTION__ << std::endl;
    m_pending.emplace(Action::Pop);
}

void StateManager::requestChangeState(GameState id)
{
    std::cout << __FUNCTION__ << std::endl;
    m_pending.emplace(Action::Pop);
    m_pending.emplace(Action::Push, id);
}

void StateManager::requestChangeStateWithDelete(GameState id)
{
    std::cout << __FUNCTION__ << std::endl;
    m_pending.emplace(Action::PopAndDelete);
    m_pending.emplace(Action::Push, id);
}

void StateManager::applyPending()
{
    while (!m_pending.empty())
    {
        std::cout << __FUNCTION__ << " " << "queue len: " << m_pending.size() << std::endl;
        PendingChange& c = m_pending.front();

        if (c.action == Action::PopAndDelete)
        {
            auto it = m_stateMap.begin();
            for (; it != m_stateMap.end(); ++it)
            {
                if (it->second.get() == m_statesStack.top())
                    break;
            }
            assert(it != m_stateMap.end());
            m_stateMap.erase(it);
            m_statesStack.pop();
        }
        else if (c.action == Action::Pop)
        {
            m_statesStack.pop();
        }
        else if (c.action == Action::Push)
        {
            auto it = m_stateMap.find(c.id);
            if (it != m_stateMap.end())
                m_statesStack.push(it->second.get());
            else
            {
                std::cout << "Creating new state" << std::endl;
                std::unique_ptr<State> newState;
                switch (c.id)
                {
                case GameState::GameOver:

                    std::cout << "GameOver state stub" << std::endl;
                    break;

                case GameState::Playing:

                    newState = std::make_unique<PlayingState>(*m_app);
                    break;

                case GameState::Pause:

                    newState = std::make_unique<PauseState>(*m_app);
                    break;

                default:

                    std::cerr << "Unknown state request" << std::endl;
                    break;
                }

                m_statesStack.push(newState.get());
                auto ins = m_stateMap.insert(std::make_pair(c.id, std::move(newState)));
                assert(ins.second);
            }
        }
        m_pending.pop();
    }
}

