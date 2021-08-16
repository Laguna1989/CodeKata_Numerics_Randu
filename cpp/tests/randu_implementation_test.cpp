#include "randu.hpp"
#include "randu_test.h"

TEST_F(RanduTest, InitialValue) { EXPECT_EQ(r.get(), 1u); }

TEST_F(RanduTest, ConsecutiveValues)
{
    std::vector<std::uint32_t> values { r.get() };
    std::vector<std::uint32_t> values_expected { 1u, 65539u, 393225u, 1769499u, 7077969u, 26542323u,
        95552217u, 334432395u, 1146624417u, 1722371299u, 14608041u };
    for (auto i = 0u; i != 10u; ++i) {
        r.next();
        values.emplace_back(r.get());
    }

    ASSERT_EQ(values_expected, values);
}