#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../src/include/incremental_string_comparer.hpp"

TEST(IncrementalStringComparer_TESTS, DEFAULT) {
    using namespace incremental_string_comparer;
    
    std::string expect = "1234abc";
    IncrementalStringComparer tc(expect);

    for (const auto& c : expect) {
        EXPECT_TRUE(tc.pushLetter(c));
    }
}

TEST(IncrementalStringComparer_TESTS, SIMPLE_ORDER_OF_CORRECT) {
    using namespace incremental_string_comparer;

    std::string expect = "1a1b1c1";
    IncrementalStringComparer tc(expect);

    std::string checked = "1x1y1z";
    std::vector<bool> correct = {1, 0, 1, 0, 1, 0, 1};
    for (size_t i = 0; i < checked.length(); ++i) {
        EXPECT_EQ(tc.pushLetter(checked[i]), correct[i]);   
    }    
}

TEST(IncrementalStringComparer_TESTS, CHECKED_MORE_THAN_EXPECT) {
    using namespace incremental_string_comparer;

    std::string expect = "1a1b1c1"; 
    IncrementalStringComparer tc(expect);

    std::string checked = "1x1y1z1z";
    std::vector<bool> correct = {1, 0, 1, 0, 1, 0, 1, 0};
    for (size_t i = 0; i < checked.length(); ++i) {
        EXPECT_EQ(tc.pushLetter(checked[i]), correct[i]);   
    }    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}