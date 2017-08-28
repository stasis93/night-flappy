#include "Wall.h"
#include <iostream>
#include "random.h"
#include "../Consts.h"

float Wall::vel = 0.4f;
float Wall::hole_height = 400.0f;

Wall::Wall()
{
    m_bottom.setFillColor(sf::Color::Black);
    m_bottom.setOutlineColor(sf::Color::Blue);
    m_bottom.setOutlineThickness(4.0f);

    m_top.setFillColor(sf::Color::Black);
    m_top.setOutlineColor(sf::Color::Blue);
    m_top.setOutlineThickness(4.0f);
}

void Wall::update(float delta)
{
    //std::cout << "Wall::update " << delta << std::endl;
    if (!m_isActive)
        return;

    move(delta * vel);

    if (m_bottom.getPosition().x + m_bottom.getGlobalBounds().width < 0)
        m_isActive = false;
}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!m_isActive)
        return;

    target.draw(m_bottom, states);
    target.draw(m_top, states);
}

void Wall::setPosition(const sf::Vector2f& pos)
{
    m_bottom.setPosition(pos);
}

void Wall::move(float amount)
{
    m_bottom.move(-amount, 0.f);
    m_top.move(-amount, 0.f);
    //std::cout << m_shape.getPosition().x << std::endl;
}

bool Wall::isActive() const
{
    return m_isActive;
}

bool Wall::isPassed() const
{
    return m_isPassed;
}

void Wall::setPassed()
{
    m_isPassed = true;
}

float Wall::getPositionX() const
{
    return m_bottom.getPosition().x;
}

float Wall::width() const
{
    return m_bottom.getGlobalBounds().width;
}

void Wall::respawn()
{
//    std::cout << __FUNCTION__ << std::endl;
    sf::FloatRect hole;

    hole.left = Consts::WIDTH + Random::intInRange(0, 200);
    hole.top = Random::floatInRange(50.0f, Consts::HEIGHT - 50.0f - hole_height);
    hole.width = 100.0f;
    hole.height = hole_height;

    m_bottom.setPosition(hole.left, hole.top + hole.height);
    m_bottom.setSize({hole.width, Consts::HEIGHT - hole.top + hole.height});

    m_top.setPosition(hole.left, 0.0f);
    m_top.setSize({hole.width, hole.top});

    m_isActive = true;
    m_isPassed = false;
}

bool Wall::intersects(const sf::FloatRect& rect) const
{
    return (m_bottom.getGlobalBounds().intersects(rect) ||
               m_top.getGlobalBounds().intersects(rect));
}

