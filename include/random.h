#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <random>
#include <ctime>

namespace Random
{
    void init();
    int intInRange(int min, int max);
    float floatInRange(float min, float max);
}

#endif // RANDOM_H_INCLUDED
