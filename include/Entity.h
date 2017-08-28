#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
    Entity() {};
    virtual ~Entity() {};
    virtual void update(float delta) = 0;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif // ENTITY_H
