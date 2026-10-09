#include <gtest/gtest.h>
#include <iostream>
#include "5.h"

TEST(NormalTemper, IntKnownValues) {
    EXPECT_EQ(normal::temper<int>(0), 32);
    EXPECT_EQ(normal::temper<int>(100), 212);
    EXPECT_EQ(normal::temper<int>(-40), -40);
    EXPECT_EQ(normal::temper<int>(37), 98);   // 98.6 = 98
}

TEST(NormalTemper, DoubleKnownValues) {
    EXPECT_DOUBLE_EQ(normal::temper<double>(37.0), 98.6);
    EXPECT_DOUBLE_EQ(normal::temper<double>(36.6), 97.88);
    EXPECT_DOUBLE_EQ(normal::temper<double>(-40.0), -40.0);
}

// результат всегда от обычного до обычного + 50
TEST(ModifiedTemper, ResultInRange) {
    int base = normal::temper<int>(100);        // 212
    for (int i = 0; i < 100; ++i) {
        int r = modified::temper<int>(100);
        EXPECT_GE(r, base);         // не меньше 212
        EXPECT_LE(r, base + 50);    // не больше 262
    }
}

// EXPECT после ошибки тест идёт дальше
TEST(FailDemo, DISABLED_ExpectContinues) {
    EXPECT_EQ(normal::temper<int>(100), 200);   // неверно (на самом деле 212)
    EXPECT_EQ(normal::temper<int>(0), 0);       // неверно (на самом деле 32)
    std::cout << ">>> ExpectContinues: дошли до конца теста" << std::endl;
}

// ASSERT после ошибки тест сразу останавливается
TEST(FailDemo, DISABLED_AssertStops) {
    ASSERT_EQ(normal::temper<int>(100), 200);   // неверно -> выход из теста
    EXPECT_EQ(normal::temper<int>(0), 0);       // не выполнится
    std::cout << ">>> AssertStops: дошли до конца теста" << std::endl;
}