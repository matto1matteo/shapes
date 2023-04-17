#include <shapes/shapes.h>


std::string Greet(std::string s)
{
    return "Hello " + s + "!";
}

#ifdef BUILD_TEST
#include <catch2/catch_test_macros.hpp>
TEST_CASE("Hello Greet simple test", "[Greet]")
{
    REQUIRE(Greet("Matteo") == "Hello Matteo!");
}

#endif // BUILD_TEST
