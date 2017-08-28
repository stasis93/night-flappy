#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <sstream>

namespace Utils
{
    template<typename T>
    std::string toString(const T& t)
    {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }
}

#endif // UTILS_H_INCLUDED
