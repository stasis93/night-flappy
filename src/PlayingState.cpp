#include "PlayingState.h"
#include "random.h"
#include "Application.h"
#include "Utils.h"


PlayingState::PlayingState(Application &app)
    : State(app)
    , m_window(app.window())
    , m_textureHolder(TextureHolder::instance())
    , m_fontHolder(FontHolder::instance())
{
    std::cout << __FUNCTION__ << std::endl;

    loadResources();
    m_walls.resize(m_wallsActive);

    Wall::vel = 0.4f;
    Wall::hole_height = 350.0f;

    m_backSprite.setTexture(m_textureHolder.get(Textures::Background));
    m_scoreText.setFont(m_fontHolder.get(Fonts::Default));
    m_scoreText.setPosition(50.0f, 50.0f);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setOutlineColor(sf::Color::Black);
    m_scoreText.setOutlineThickness(1.0f);
    m_scoreText.setScale(1.0f, 1.0f);
}

void PlayingState::loadResources()
{
    m_textureHolder.load(Textures::Background, "assets/background.png");
    m_textureHolder.load(Textures::BackgroundScroll, "assets/background_scroll.png");
    m_textureHolder.load(Textures::BackgroundScroll1, "assets/background_scroll1.png");
    m_fontHolder.   load(Fonts::Default, "assets/font.ttf");

    m_backRenderer.addLayer(m_textureHolder.get(Textures::BackgroundScroll1), 0.02f, 100.0f);
    m_backRenderer.addLayer(m_textureHolder.get(Textures::BackgroundScroll), 0.05f);
}

void PlayingState::pollEvents()
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            m_window.close();
        else
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
            m_app->stateManager().requestPushState(GameState::Pause);
        else
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::R)
            m_app->stateManager().requestChangeStateWithDelete(GameState::Playing);
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Q)
            m_app->window().close();
    }
}

void PlayingState::handleKbdInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_player.move(Direction::LEFT);
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_player.move(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_player.move(Direction::UP);
    }
}

void PlayingState::update(float deltaTime)
{
    handleKbdInput();

    m_player.update(deltaTime);
    m_backRenderer.update(deltaTime);

    m_wallDistanceCurrent += deltaTime / 1000.0f * Wall::vel;

    int wallsActive { 0 };
    for (Wall& wall : m_walls)
    {
        if (wall.isActive())
            wallsActive++;
    }

    //std::cout << wallsActive << std::endl;

    if (wallsActive < m_wallsActive && m_wallDistanceCurrent > m_wallDistance)
    {
        auto it = std::find_if(m_walls.begin(), m_walls.end(),
                               [](const Wall& w)
                                {
                                    return !w.isActive();
                                });
        it->respawn();
        m_wallDistanceCurrent = 0.0f;
        m_wallDistance = Random::floatInRange(0.6f, 0.8f);
    }

    for (Wall& wall : m_walls)
    {
        wall.update(deltaTime);
        if (wall.isActive() && !wall.isPassed() &&
            m_player.left() > wall.getPositionX() + wall.width())
        {
            wall.setPassed();

            if (Wall::hole_height > 100.0f)
                Wall::hole_height -= 2.0f;

            Wall::vel += 0.003f;
            m_score++;
        }
        if (wall.intersects(m_player.getBounds()) ||
            m_player.bottom() > Consts::HEIGHT - 2)
        {
            //m_score = 0;
            // handle game over here (show score, restart, etc.)
            std::cout << "You LOOSA :p. Your score is " << m_score << std::endl;
            m_app->stateManager().requestChangeStateWithDelete(GameState::Playing);
            return;
        }
    }
    m_scoreText.setString("Score: " + Utils::toString<int>(m_score));
}

void PlayingState::render() const
{
    m_window.clear();
    m_window.draw(m_backSprite);
    m_window.draw(m_backRenderer);
    m_window.draw(m_player);

    for (const Wall& wall : m_walls)
        m_window.draw(wall);

    m_window.draw(m_scoreText);
    m_window.display();
}
