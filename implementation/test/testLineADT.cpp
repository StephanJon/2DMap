#include "../include/LineADT.h"
#include "../catch/catch.h"
TEST_CASE("tests for LineT", "[LineT]") {
	LineT Line0 = LineT();
	LineT Line1 = LineT(PointT(0, 1), N, 5);


	SECTION("LineT Accessors") {
		REQUIRE(Line0.strt().x() == 0);
		REQUIRE(Line0.strt().y() == 0);
		REQUIRE(Line0.orient() == N);
		REQUIRE(Line0.len() == 1);
		REQUIRE(Line1.strt().x() == 0);
		REQUIRE(Line1.strt().y() == 1);
		REQUIRE(Line1.end().x() == 0);
		REQUIRE(Line1.end().y() == 5);
		REQUIRE(Line1.orient() == N);
		REQUIRE(Line1.len() == 5);
	}

	SECTION("LineT Mutators") {
		LineT Line2 = Line1.flip();
		REQUIRE(Line2.orient() == S);
		LineT Line3 = Line2.rotate(CW);
		REQUIRE(Line3.orient() == W);
		LineT Line4 = Line1.translate(-10, 10);
		REQUIRE(Line4.strt().x() == -10);
		REQUIRE(Line4.strt().y() == 11);
		REQUIRE(Line4.orient() == N);
		REQUIRE(Line4.len() == 5);
	}
}
