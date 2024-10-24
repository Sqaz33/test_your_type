#include <string>
#include <vector>
#include <stack>
#include <ranges>

#include <gtest/gtest.h>

#include "../src/include/incremental_string_comparer.hpp"

TEST(IncrementalStringComparer_TESTS, DEFAULT) {
    using namespace incremental_string_comparer;
    
    std::string expect = "1234abc";
    IncrementalStringComparer isc(expect);

    for (const auto& c : expect) {
        EXPECT_TRUE(isc.pushLetter(c));
    }
    EXPECT_EQ(isc.mistakes().size(), 0);
}

TEST(IncrementalStringComparer_TESTS, SIMPLE_ORDER_OF_CORRECT) {
    using namespace incremental_string_comparer;

    std::string expect = "1a1b1c1";
    IncrementalStringComparer isc(expect);

    

    std::string checked = "1x1y1z1";
    std::vector<bool> correct = {1, 0, 1, 0, 1, 0, 1};
    for (size_t i = 0; i < checked.length(); ++i) {
        EXPECT_EQ(isc.pushLetter(checked[i]), correct[i]);   
    } 

    std::vector<size_t> expectMistakes({1, 3, 5});
    EXPECT_TRUE(isc.mistakes() == expectMistakes);
}

TEST(IncrementalStringComparer_TESTS, CHECKED_MORE_THAN_EXPECT) {
    using namespace incremental_string_comparer;

    std::string expect = "1a1b1c1"; 
    IncrementalStringComparer isc(expect);

    std::string checked = "1x1y1z1z";
    std::vector<bool> correct = {1, 0, 1, 0, 1, 0, 1, 0};
    for (size_t i = 0; i < checked.length(); ++i) {
        EXPECT_EQ(isc.pushLetter(checked[i]), correct[i]);   
    }    

    std::vector<size_t> expectMistakes({1, 3, 5, 7});
    EXPECT_TRUE(isc.mistakes() == expectMistakes);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}