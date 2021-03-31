#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;

    x.re = 2;
    x.im = 2;

   WARN_THROWS(x/t);
}

TEST_CASE("LZespolona - wyswietlanie standard") {
    LZespolona x;

    x.re = 2;
    x.im = 2;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    CHECK("(2.00+2.00i)" == out.str() );
}

TEST_CASE("LZespolona - wyswietlanie zaokraglane") {
    LZespolona x;

    x.re = 2.0/3.0;
    x.im = 2.0/3.0;

    std::ostringstream out;

    out << x;
    std::cout << out.str() << std::endl;
    CHECK("(0.67+0.67i)" == out.str() );
}

TEST_CASE("LZespolona - wczytywanie standard") {
    LZespolona x;

    std::istringstream in("(10+10.10i)");
    in >> x;

    std::ostringstream out;
    out << x;

    CHECK("(10.00+10.10i)" == out.str() );
}

TEST_CASE("test LZespolona modul"){
    LZespolona x;
    double s=2;
    x.re = 1;
    x.im = 1;


    CHECK( Modul2(x) == s);
}

TEST_CASE("test LZespolona sprzezenie"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -1;

    CHECK(Sprzezenie(x) == y);
}
