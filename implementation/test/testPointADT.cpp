#include "../include/PointADT.h"
#include "../catch/catch.h"
TEST_CASE("tests for PointT", "[PointT]") {
	PointT p0;
	PointT p1(3, -4);
	

	SECTION("PointT Accessors") {
		REQUIRE(p0.x() == 0);
		REQUIRE(p0.y() == 0);
		REQUIRE(p1.x() == 3);
		REQUIRE(p1.y() == -4);
		
	}

	SECTION("PointT Mutators") {
		PointT p2 = p1.translate(2, 0);
		REQUIRE(p2.x() == 5);
		REQUIRE(p2.y() == -4);
	}
}


