#ifndef WALL_H
#define WALL_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "../Consts.h"


class Wall : public Entity
{
public:
                Wall();

    void        update(float delta = Consts::fixedTimestepMilli) override;
    void        setPosition(const sf::Vector2f& pos);

    float       getPositionX() const;
    float       width() const;
    const       float getPosition() const;

    bool        isActive() const;
    bool        isPassed() const;
    void        setPassed();
    bool        intersects(const sf::FloatRect& rect) const;
    void        respawn();

    static float vel, hole_height;

private:
    void        draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void        move(float amount);


private:
    sf::RectangleShape  m_bottom, m_top;
    bool                m_isActive { false }, m_isPassed { false };

};

#endif // WALL_H
