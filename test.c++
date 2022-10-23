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

