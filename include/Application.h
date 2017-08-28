#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include "../Consts.h"
#include "StateManager.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

class Application
{
public:
                        Application();
    void                run();
    sf::RenderWindow&   window();
    StateManager&       stateManager();

private:
    sf::RenderWindow    m_window;

    TimePoint           m_lastTimePoint { std::chrono::high_resolution_clock::now() },
                        m_currentTimePoint;

    float               m_currTimeSlice { 0.f };

    StateManager        m_stateManager;
};

#endif // APPLICATION_H
