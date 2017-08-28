#include "Application.h"
#include <iostream>
#include <algorithm>
#include "random.h"

Application::Application()
    : m_window({Consts::WIDTH, Consts::HEIGHT}, "GAEM!1")
    , m_stateManager(*this)
{
    Random::init();
    m_window.setFramerateLimit(60);
    m_stateManager.requestPushState(GameState::Playing);
}

void Application::run()
{
    while (m_window.isOpen())
    {
        m_stateManager.applyPending();
        auto & state = m_stateManager.currentState();
        state.pollEvents();

        m_currentTimePoint = std::chrono::high_resolution_clock::now();

        float delta = std::chrono::duration_cast
                     <std::chrono::duration<float, std::milli>>
                     (m_currentTimePoint - m_lastTimePoint).count();

        m_currTimeSlice += delta;

        for (; m_currTimeSlice > Consts::fixedTimestepMilli;
               m_currTimeSlice -= Consts::fixedTimestepMilli)
        {
            state.update(Consts::fixedTimestepMilli);
        }

        m_lastTimePoint = m_currentTimePoint;
        state.render();
    }
}

sf::RenderWindow& Application::window()
{
    return m_window;
}

StateManager& Application::stateManager()
{
    return m_stateManager;
}
