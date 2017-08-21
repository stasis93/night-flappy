#include "Application.h"
#include <iostream>

Application::Application()
    : m_window({Consts::WIDTH, Consts::HEIGHT}, "GAEM!1")
{
    m_window.setFramerateLimit(60);
}

void Application::run()
{
    while (m_window.isOpen())
    {
        //std::cout << "Main loop iteration" << std::endl;

        pollEvents();

        m_currentTimePoint = std::chrono::high_resolution_clock::now();

        float delta = std::chrono::duration_cast
                     <std::chrono::duration<float, std::milli>>
                     (m_currentTimePoint - m_lastTimePoint).count();

        m_currTimeSlice += delta;

        for (; m_currTimeSlice > Consts::fixedTimestepMilli;
               m_currTimeSlice -= Consts::fixedTimestepMilli)
        {
            //std::cout << "\tUpdate call" << std::endl;
            handleKbdInput();
            update(delta);
        }
        //std::cout << m_currTimeSlice << std::endl;

        m_lastTimePoint = m_currentTimePoint;

        render();
    }
}

void Application::pollEvents()
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            m_window.close();
    }
}

void Application::update(float deltaTime)
{
    m_player.update(deltaTime);
}

void Application::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}

void Application::handleKbdInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_player.move(Direction::LEFT);
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_player.move(Direction::RIGHT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_player.move(Direction::UP);
    }
}

