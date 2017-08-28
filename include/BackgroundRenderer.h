#ifndef BACKGROUNDRENDERER_H_INCLUDED
#define BACKGROUNDRENDERER_H_INCLUDED

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <array>

class ScrollingBackgroundRenderer : public Entity
{
public:
    void update(float delta) override;
    void addLayer(const sf::Texture& texture, float scrollingVelocity, float offset_y = 0.0f);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    struct Layer
    {
        Layer(const sf::Texture& texture, float scrollingVelocity, float offset_y);
        std::array<sf::Sprite, 2> sprites;
        float vel;
    };
    std::vector<Layer> m_layers; // of Fear
};

#endif // BACKGROUNDRENDERER_H_INCLUDED
