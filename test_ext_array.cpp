#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

#include "ExtArray.h"

TEST_CASE("stats on empty array return 0")
{
    ExtArray<int>  ie(0);
    ExtArray<bool> be{};
    REQUIRE(ie.mean()   == 0.0);
    REQUIRE(ie.median() == 0.0);
    REQUIRE(ie.mode()   == std::pair<int,int>{0,0});
    REQUIRE(be.mean()   == 0.0);
}

TEST_CASE("mean(range) normal & invalid")
{
    ExtArray<int> arr{1,2,3,4,5};
    CHECK(arr.mean(0,5) == Catch::Approx(3.0));
    CHECK(arr.mean(1,4) == Catch::Approx(3.0));
    CHECK_THROWS_AS(arr.mean(3,2), std::invalid_argument);
    CHECK_THROWS_AS(arr.mean(0,6), std::invalid_argument);
}

TEST_CASE("checkSum")
{
    ExtArray<bool>  bArr{true,false,true,true};
    ExtArray<int>   iArr{1,0,0,1,1};
    CHECK(bArr.checkSum() == 3);
    CHECK(iArr.checkSum() == 3);

    ExtArray<int> badInt{0,2,1};
    CHECK_THROWS_AS(badInt.checkSum(), std::logic_error);

    ExtArray<double> dArr{0.0,1.0};
    CHECK_THROWS_AS(dArr.checkSum(), std::bad_typeid);
}