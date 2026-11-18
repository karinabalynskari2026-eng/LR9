// test.9.2.cpp
//               unit-тест для лабораторної роботи № 9.2 (варіант 1)
//               у програмі немає функцій, тому тестуємо макроси та вираз w

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <cmath>

#define main program_main                // перейменовуємо main програми
#include "lab_9.2.cpp"
#undef main

TEST_CASE("Перевірка макросів SQR, MAX, MIN")
{
    CHECK(SQR(3) == 9);                 // 3^2 = 9
    CHECK(SQR(2 + 1) == 9);             // перевірка дужок: (2+1)^2 = 9
    CHECK(MAX(2, 5) == 5);
    CHECK(MIN(2, 5) == 2);
}

TEST_CASE("Перевірка виразу w для варіанту 1")
{
    // за замовчуванням Z = 3, тобто 0 < z < 5: w = max(x^2 + y + z, x*y*z)
    // x = 2, y = 3:  max(4 + 3 + 3, 2*3*3) = max(10, 18) = 18  (рахуємо вручну)
    float x = 2, y = 3;
    float w = MAX(SQR(x) + y + Z, x * y * Z);
    CHECK(w == doctest::Approx(18.0));
}
