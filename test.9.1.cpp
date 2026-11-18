// lab_9.1_test.cpp
//               unit-тест для лабораторної роботи № 9 (варіант 1)
//               тестуються функції dod() та sum(): вони нічого не повертають,
//               а записують результат у глобальні змінні a, s, n (простір імен nsVar)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <cmath>

#define main program_main                // перейменовуємо main програми, щоб не було конфлікту з main doctest
#include "lab_9.1.cpp"
#undef main

TEST_CASE("Перевірка функції dod")
{
    // доданок a(n) = a(n-1) * (2n-1) / ((2n+1) * x^2)
    // при x = 2, n = 1, a = 1:  a = 1 * 1 / (3 * 4) = 1/12  (рахуємо вручну)
    x = 2;
    n = 1;
    a = 1;
    dod();
    CHECK(a == doctest::Approx(1.0 / 12.0));

    // при x = 2, n = 2, a = 1/12:  a = (1/12) * 3 / (5 * 4) = 1/80
    n = 2;
    a = 1.0 / 12.0;
    dod();
    CHECK(a == doctest::Approx(1.0 / 80.0));
}

TEST_CASE("Перевірка функції sum при x = 2")
{
    // ln((2+1)/(2-1)) = ln(3) = 1.098612...
    x = 2;
    e = 0.0001;
    sum();

    CHECK(s == doctest::Approx(log(3.0)).epsilon(0.0001));   // сума ряду збігається з ln(3)
    CHECK(std::fabs(s - log(3.0)) < e);                       // похибка менша за задану точність
    CHECK(n == 5);                                            // кількість просумованих доданків
}

TEST_CASE("Перевірка функції sum при x = 3")
{
    // ln((3+1)/(3-1)) = ln(2) = 0.693147...
    x = 3;
    e = 0.0001;
    sum();

    CHECK(s == doctest::Approx(log(2.0)).epsilon(0.0001));
    CHECK(n == 4);
}