#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "State.h"
#include "../Consts.h"
#include "ResourceHolder.h"
#include "Player.h"
#include "Wall.h"
#include "BackgroundRenderer.h"

class Application;


using TextureHolder = ResourceHolder<sf::Texture, Textures>;
using FontHolder = ResourceHolder<sf::Font, Fonts>;


class PlayingState : public State
{
public:
    explicit PlayingState(Application &app);

    void pollEvents() override;
    void update(float deltaTime = Consts::fixedTimestepMilli) override;
    void render() const override;

private:
    void loadResources();
    void handleKbdInput();

private:
    sf::RenderWindow&   m_window;
    Player              m_player { 300.0f, 50.0f };

    TextureHolder&      m_textureHolder;
    FontHolder&         m_fontHolder;

    ScrollingBackgroundRenderer m_backRenderer;

    sf::Sprite          m_backSprite;
    sf::Text            m_scoreText;

    std::vector<Wall>   m_walls;
    int                 m_wallsActive { 3 }, m_score { 0 };
    sf::Clock           m_wallClock;
    float               m_wallDistance { 0.4f },
                        m_wallDistanceCurrent { 0.0f };
};

#endif // PLAYINGSTATE_H
