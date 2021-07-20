#include "randu.hpp"
#include "randu_test.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace ::testing;

template <typename T>
void write_triples_file(std::vector<T>& values)
{
    std::ofstream out { "triples.dat" };
    for (auto i = 0; i != 1000; ++i) {
        out << values.at(i * 3 + 0) << " " << values.at(i * 3 + 1) << " " << values.at(i * 3 + 2)
            << "\n";
    }
}

TEST_F(RanduTest, WriteTriples)
{
    std::size_t const N = 3000;
    std::vector<std::uint32_t> values;
    for (auto i = 0u; i != N; ++i) {
        values.emplace_back(r.get());
        r.next();
    }

    write_triples_file(values);

    // !Manual verification!
    SUCCEED();
}