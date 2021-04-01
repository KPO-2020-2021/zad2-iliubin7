#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1;
    z.im = 1;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re =0.00009;
    x.im = 0.00009;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0;
    z.im = 0;

    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = 1;

    y.re = 2;
    y.im = -3;

    z.re = 1;
    z.im = 4;

    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1;
    z.im = 1;

    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re =0.49999;
    x.im = 0.49999;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.5;
    z.im = 0.5;

    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = -3;

    y.re = 1;
    y.im = 2;

    z.re = 9;
    z.im = 3;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;

    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 1;


    CHECK(x*y == z);
}


TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 2;


    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Iloczyn"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0;
    z.im = 0;


    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Iloraz"){
    LZespolona x, y, z;

    x.re = 3;
    x.im = -3;

    y.re = 1;
    y.im = 2;

    z.re = 9;
    z.im = 3;

    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dodawanie,znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dodaj,{1,1}};
    LZespolona t ={2,2};


    CHECK(Oblicz(x)== t);
}

TEST_CASE("Test LZespolona odejmowanie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Odejmij,{1,1}};
    LZespolona t ={0,0};


    CHECK(Oblicz(x)== t);
}

TEST_CASE("Test LZespolona mnozenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Mnoz,{1,1}};
    LZespolona t ={0,2};


    CHECK(Oblicz(x)== t);
}

TEST_CASE("Test LZespolona dzielenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dziel,{1,1}};
    LZespolona t ={1,0};


    CHECK(Oblicz(x)== t);
}

TEST_CASE("Test LZespolona +=, znany wynik") {
    WyrazenieZesp x{{2,-1},Op_Dodaj,{1,-1}};
    LZespolona t ={3,0};


    CHECK(Oblicz(x)== t);
}

TEST_CASE("Test LZespolona /=, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dziel,{1,1}};
    LZespolona t ={1,0};


    CHECK(Oblicz(x)== t);
}

