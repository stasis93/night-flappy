#include "PauseState.h"
#include "Application.h"
#include <cmath>

constexpr static float M_PI = 3.14159265f;

using FontHolder = ResourceHolder<sf::Font, Fonts>;


PauseState::PauseState(Application& app/*, const State* prevState*/)
    : State(app)
    , m_window(app.window())
{
    std::cout << __FUNCTION__ << std::endl;

    m_text.setFont(FontHolder::instance().get(Fonts::Default));
    m_text.setPosition(500.0f, 300.0f);
    m_text.setString("PAUSE");//. Press ESCAPE to continue or R to restart");
    m_text.setFillColor(sf::Color::White);

    auto box = m_text.getGlobalBounds();
    m_text.setOrigin(box.width / 2, box.height / 2);

    m_textAux.setFont(FontHolder::instance().get(Fonts::Default));
    m_textAux.setPosition(300.0f, 400.0f);
    m_textAux.setString("Press ESCAPE to continue\nR to restart\nQ to exit");
    m_textAux.setFillColor(sf::Color::White);

    createScaleVals();
}

void PauseState::pollEvents()
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            m_window.close();
        else
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
            m_app->stateManager().requestPopState();
        else
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Q)
            m_app->window().close();
        else
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::R)
        {
            m_app->stateManager().requestPopState();
            m_app->stateManager().requestChangeStateWithDelete(GameState::Playing);
        }

    }
}

void PauseState::update(float deltaTime)
{
    m_time += deltaTime;

    if (m_time > 1000.0f)
        m_time -= 1000.0f;

    float s = m_scaleVals[static_cast<int>(m_time / Consts::fixedTimestepMilli)];

    m_text.setScale(s, s);
}

void PauseState::render() const
{
    m_window.clear();
    //m_prevState->render();
    m_window.draw(m_text);
    m_window.draw(m_textAux);
    m_window.display();
}



/******************************************************************************/

void PauseState::createScaleVals()
{
    for (auto i = 0u; i < m_scaleVals.size(); i++)
        m_scaleVals[i] = 2.0f + 0.25f * std::cos(static_cast<float>(i) / scaleValSize * 2 * M_PI);
}
