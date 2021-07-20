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

    // (optional) calculate and print the distribution of the last decimal digits
    FAIL();
}

TEST_F(RanduTest, LastDecimalDigitContainsOnlyCertainValues)
{
    // calculate 5000 pseudo random values with the randu algorithm

    // for each value get the last hexadecimal digit

    // verify that only odd digits appear
    FAIL();
}
