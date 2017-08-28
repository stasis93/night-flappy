#include "BackgroundRenderer.h"
#include "../Consts.h"

void ScrollingBackgroundRenderer::update(float delta)
{
    for (Layer& l : m_layers)
    for (auto i = 0u; i < l.sprites.size(); i++)
    {
        l.sprites[i].move(-l.vel * delta, 0.0f);

        sf::FloatRect bounds = l.sprites[i].getGlobalBounds();

        if (bounds.left + bounds.width < 0.0f)
            l.sprites[i].setPosition(bounds.left + 2 * bounds.width - 1.0f, bounds.top);
    }
}

void ScrollingBackgroundRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& l : m_layers)
    {
        target.draw(l.sprites[0], states);
        target.draw(l.sprites[1], states);
    }
}

void ScrollingBackgroundRenderer::addLayer(const sf::Texture& texture, float scrollingVelocity, float offset_y)
{
    m_layers.emplace_back(texture, scrollingVelocity, offset_y);
}

ScrollingBackgroundRenderer::Layer::Layer(const sf::Texture& texture, float scrollingVelocity, float offset_y)
    : vel(scrollingVelocity)
{
    const sf::Vector2u& sz = texture.getSize();

    sprites[0].setTexture(texture, true);
    sprites[1].setTexture(texture, true);

    sprites[0].setPosition(0, Consts::HEIGHT - sz.y - offset_y);
    sprites[1].setPosition(sz.x - 1.0f, Consts::HEIGHT - sz.y - offset_y);
}
