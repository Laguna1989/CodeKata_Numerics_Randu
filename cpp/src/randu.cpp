#include "randu.hpp"

std::uint32_t const Randu::vMax { static_cast<std::uint32_t>(std::pow(2u, 31u)) };

std::uint32_t Randu::get() const { return m_v; }

void Randu::next() { m_v = (65539 * m_v) % vMax; }