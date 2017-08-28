#ifndef STATE_H
#define STATE_H

class Application;

class State
{
public:
    explicit State(Application& app)
        : m_app(&app) {}

    virtual ~State() {}

    virtual void pollEvents() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() const = 0;

protected:
    Application* m_app;
};

#endif // STATE_H
