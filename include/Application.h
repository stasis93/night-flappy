#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include "../Consts.h"
#include "Player.h"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

class Application
{
public:
                        Application();
    void                run();

private:
    void                pollEvents();
    void                update(float deltaTime = Consts::fixedTimestepMilli);
    void                render();
    void                handleKbdInput();

private:
    sf::RenderWindow    m_window;
    TimePoint           m_lastTimePoint { std::chrono::high_resolution_clock::now() },
                        m_currentTimePoint;
    float               m_currTimeSlice { 0.f };

    Player              m_player { 10.f, Consts::HEIGHT - 10.f };
};

#endif // APPLICATION_H
