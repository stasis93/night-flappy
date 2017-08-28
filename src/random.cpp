#include "random.h"

namespace Random
{
    std::minstd_rand gen;

    void init()
    {
        gen.seed(std::time(nullptr));
    }

    int intInRange(int min, int max)
    {
        return std::uniform_int_distribution<int>{min, max}(gen);
    }

    float floatInRange(float min, float max)
    {
        return std::uniform_real_distribution<float>{min, max}(gen);
    }
}
