#include "Player.h"
#include <iostream>

Player::Player(float pos_x, float pos_y)
    : m_shape({20, 20})
    , m_pos(m_shape.getPosition())
{
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setOrigin({m_shape.getSize() / 2.f});
    m_shape.setPosition(pos_x, pos_y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}

void Player::update(float delta)
{
    //std::cout << delta << std::endl;

    //if (!m_isFlying)
    //{
        if (m_vel.x < 0)
            m_vel.x += a_sl_x * delta;
        else if (m_vel.x > 0)
            m_vel.x -= a_sl_x * delta;

        if (std::abs(m_vel.x) < speedThreshold)
            m_vel.x = 0.f;
    //}
    //std::cout << top() << " " << bottom() << std::endl;

    if (m_isFlying)
    {
        //std::cout << "Yahoooo! We're in air now! :p" << std::endl;
        m_vel.y += g * delta;
    }

    sf::Vector2f newPos = m_pos + m_vel * delta;

    if (newPos.y >= Consts::HEIGHT - m_shape.getSize().y / 2.0f)
        newPos.y = Consts::HEIGHT - m_shape.getSize().y / 2.0f;
    if (newPos.x < m_shape.getSize().x / 2.0f)
    {
        newPos.x = m_shape.getSize().x / 2.0f;
        m_vel.x = 0.0f;
    }
    if (newPos.x >= Consts::WIDTH - m_shape.getSize().x / 2)
    {
        newPos.x = Consts::WIDTH - m_shape.getSize().x / 2;
        m_vel.x = 0.0f;
    }

    m_shape.setPosition(newPos);

    if (m_isFlying && bottom() == Consts::HEIGHT - 1)
    {
        m_isFlying = false;
        m_vel.y = 0.0f;
    }

    m_lastDelta = delta;
}

void Player::move(Direction dir)
{
    switch (dir)
    {
    case Direction::LEFT:
        m_vel.x -= m_lastDelta * a_x;

        break;
    case Direction::RIGHT:
        m_vel.x += m_lastDelta * a_x;

        break;
    case Direction::UP:
        if (!m_isFlying)
        {
            m_isFlying = true;
            std::cout << "Nu tut tipo prigaem" << std::endl;
            m_vel.y = -v0_y;
        }
        break;
    default:
        break;
    }
}

float Player::left() const
{
    return m_shape.getGlobalBounds().left;
}

float Player::right() const
{
    return m_shape.getGlobalBounds().left + m_shape.getSize().x - 1;
}

float Player::top() const
{
    return m_shape.getGlobalBounds().top;
}

float Player::bottom() const
{
    return m_shape.getGlobalBounds().top + m_shape.getSize().y - 1;
}

