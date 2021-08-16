#ifndef RANDU_HPP_GUARD
#define RANDU_HPP_GUARD

#include <cmath>
#include <cstdint>

class Randu {
public:
    std::uint32_t get() const;
    void next();

    static const std::uint32_t vMax;

private:
    std::uint32_t m_v { 1u };
};

#endif