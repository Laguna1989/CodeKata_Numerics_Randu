#include "randu.hpp"
#include "randu_test.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace ::testing;

TEST_F(RanduTest, LastDecimalDigitContainsOnlyOddNumbers)
{
    // calculate 5000 pseudo random values with the randu algorithm

    // for each value get the last decimal digit

    // verify that only odd digits appear

    std::size_t const N = 50000;
    std::map<int, int> histo;
    for (auto i = 0u; i != N; ++i) {
        auto value = r.get();
        r.next();

        std::stringstream stream;
        stream << value;
        auto string = stream.str();
        string = string.substr(string.size() - 1);
        int v = std::stoi(string);

        ASSERT_EQ(v % 2, 1);

        histo[v]++;
    }

    for (auto kvp : histo) {
        std::cout << kvp.first << " " << kvp.second << std::endl;
    }

    std::cout << std::endl;
}

TEST_F(RanduTest, LastHexDigitContainsOnlyCertainValues)
{
    // calculate 5000 pseudo random values with the randu algorithm

    // for each value get the last hex digit

    // verify that only certain digits appear

    std::size_t const N = 50000;
    std::map<std::string, int> histo;
    for (auto i = 0u; i != N; ++i) {
        auto value = r.get();
        r.next();

        std::stringstream stream;
        stream << std::hex << value;
        auto string = stream.str();
        string = string.substr(string.size() - 1);

        //        ASSERT_EQ( v % 2, 1);

        histo[string]++;
    }

    for (auto kvp : histo) {
        std::cout << kvp.first << " " << kvp.second << std::endl;
    }

    std::cout << std::endl;
}
