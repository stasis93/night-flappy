#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"
#include "../Consts.h"
#include <SFML/Graphics.hpp>
#include <memory>

constexpr static int scaleValSize = static_cast<int>(1000.0f / Consts::fixedTimestepMilli);

class Application;

class PauseState : public State
{
public:
    PauseState(Application& app/*, const State* prevState*/);

    void pollEvents() override;
    void update(float deltaTime) override;
    void render() const override;

private:
    void createScaleVals();

private:
    sf::RenderWindow&   m_window;
    sf::Text            m_text;
    sf::Text            m_textAux;

    float               m_time { 0.0f };

    std::array<float, scaleValSize> m_scaleVals;
};

#endif // PAUSESTATE_H
