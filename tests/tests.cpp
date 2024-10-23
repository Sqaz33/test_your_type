#include <string>

#include <gtest/gtest.h>

#include "../src/include/typo_checker.hpp"

TEST(TYPO_CHECKER_TESTS, DEFAULT) {
    using namespace typo_checker;
    
    std::string expct = "1234abc";
    TypoChecker tc(expct);

    for (const auto& c : expct) {
        EXPECT_TRUE(tc.pushLetter(c));
    }

    EXPECT_EQ(tc.checked(), expct);

    for (auto it = expct.crbegin(); it != expct.crend(); ++it) {
        EXPECT_EQ(tc.popLetter(), *it);
    }
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}