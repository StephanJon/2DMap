#include "../include/PathADT.h"
#include "../catch/catch.h"


TEST_CASE("PathT tests", "[PathT]") {
	PathT path1 = PathT(PointT(0, 0), N, 5);
	

	SECTION("PathT Accessors") {
		REQUIRE(path1.strt().x() == 0);
		REQUIRE(path1.strt().y() == 0);
		REQUIRE(path1.end().x() == 0);
		REQUIRE(path1.end().y() == 4);
		REQUIRE(path1.line(0).strt().x() == 0);
		REQUIRE(path1.line(0).strt().y() == 0);
		REQUIRE(path1.end().x() == 0);
		REQUIRE(path1.end().y() == 4);
		REQUIRE(path1.size() == 1);
		REQUIRE(path1.len() == 5);
	}

	SECTION("PathT Mutators") {
		path1.append(E, 10);
		REQUIRE(path1.end().x() == 10);
		REQUIRE(path1.end().y() == 4);
		REQUIRE(path1.size() == 2);
		REQUIRE(path1.size() == 2);
		REQUIRE(path1.size() == 2);
		PathT path2 = path1.translate(5, 5);
		REQUIRE(path2.strt().x() == 5);
		REQUIRE(path2.strt().y() == 5);
		REQUIRE(path2.end().x() == 15);
		REQUIRE(path2.end().y() == 9);
		REQUIRE(path2.line(0).orient() == N);
		REQUIRE(path2.line(1).orient() == E);
	}
}
