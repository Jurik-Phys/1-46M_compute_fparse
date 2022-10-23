#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fparser.h"

TEST_CASE("FParser"){
    std::string func_for_test="x";
    FParser parser(5);
    CHECK(parser.parse(func_for_test) == 5);
}

TEST_CASE("FParser"){
    std::string func_for_test="2+cos(0)";
    FParser parser(5);
    CHECK(parser.parse(func_for_test) == 3);
}

TEST_CASE("FParser"){
    std::string func_for_test="cos(0) + 2";
    FParser parser(5);
    CHECK(parser.parse(func_for_test) == 3);
}


TEST_CASE("FParser"){
    std::string func_for_test="sin(cos(3.141592653589/2))";
    FParser parser(5);
    CHECK(parser.parse(func_for_test) < 0.00001);
}

TEST_CASE("FParser"){
    std::string func_for_test="exp(0) + cos(0)";
    FParser parser(5);
    CHECK(parser.parse(func_for_test) - 2 < 0.00001);
}

TEST_CASE("FParser V2_1 <x>=1"){
    std::string func_for_test="(x + x*x - x*x*x - 1)/(1 + x*x)";
    FParser parser(1);
    CHECK(parser.parse(func_for_test) - 0 < 0.00001);
}

TEST_CASE("FParser V2_1 <x>=2"){
    std::string func_for_test="(x + x*x - x*x*x - 1)/(1 + x*x)";
    FParser parser(1);
    CHECK(parser.parse(func_for_test) + 1 < 0.00001);
}

TEST_CASE("FParser V2_2 <x>=3.14/4"){
    std::string func_for_test="cos(x)*cos(x)*cos(x)*sin(2*x)";
    FParser parser(3.14/4);
    CHECK(parser.parse(func_for_test) - 0.3535534 < 0.00001);
}

