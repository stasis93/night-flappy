#ifndef CONSTS_H_INCLUDED
#define CONSTS_H_INCLUDED

namespace Consts
{
    constexpr int WIDTH {1152}, HEIGHT {864};
    constexpr float fixedTimestepMilli = 1000.f/60.f;
}

enum class Textures
{
    Background,
    BackgroundScroll,
    BackgroundScroll1
};

enum class Fonts
{
    Default
};
#endif // CONSTS_H_INCLUDED
