#include "gtest/gtest.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(impl_test, numerical_equality) {
	EXPECT_EQ(1, 1);
}

TEST(impl_test, failed) {
	EXPECT_NE(1, 2);
}