#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Consts.h"

enum class Direction
{
    LEFT,
    RIGHT,
    UP
};

class Player : public sf::Drawable
{
public:
                Player(float pos_x, float pos_y);

    void        draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void        update(float delta);
    void        move(Direction dir);
    float       left() const;
    float       right() const;
    float       top() const;
    float       bottom() const;

private:


private:
    sf::RectangleShape      m_shape;
    sf::Vector2f            m_vel {0.0f, 0.0f};
    const sf::Vector2f&     m_pos;

    constexpr static float  a_x {0.01f},
                            a_sl_x {0.005f},
                            v0_y {1.5f},
                            g {0.0025f},
                            speedThreshold {Consts::fixedTimestepMilli * Player::a_x / 10.0f};

    float                   m_lastDelta {0.f};
    bool                    m_isFlying {false};
};

#endif // PLAYER_H
