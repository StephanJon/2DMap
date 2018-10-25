#include "../include/Seq2D.h"
#include "../catch/catch.h"
TEST_CASE("tests for Seq2D", "[Seq2D]") {
	std::vector < std::vector<LanduseT>> S{ { Recreational, Recreational, Recreational, Recreational, Recreational },\
											{ Transport, Transport, Transport, Transport, Transport },\
											{ Agricultural, Agricultural, Agricultural, Agricultural, Agricultural },\
											{ Residential, Residential, Residential, Residential, Residential }, \
											{ Commercial, Commercial, Commercial, Commercial, Commercial } };

	Seq2D<LanduseT> seq0 = Seq2D<LanduseT>();
	Seq2D<LanduseT> seq1 = Seq2D<LanduseT>(S, 3);
	LineT Line1 = LineT(PointT(0, 0), E, 4);
	PathT path1 = PathT(PointT(0, 0), E, 4);
	path1.append(N, 1);


	SECTION("Seq2D Accessors") {
		REQUIRE(seq1.get(PointT(0, 0)) == Recreational);
		REQUIRE(seq1.getNumRow() == 5);
		REQUIRE(seq1.getNumCol() == 5);
		REQUIRE(seq1.getScale() == 3);
		REQUIRE(seq1.count(Residential) == 5);
		REQUIRE(seq1.count(Residential) == 5);
		REQUIRE(seq1.count(Line1, Recreational) == 5);
		REQUIRE(seq1.length(path1) == 15);
		REQUIRE(!seq1.connected(PointT(0, 0), PointT(0, 3)));
	}

	SECTION("Seq2D Mutators") {
		seq1.set(PointT(0, 0), Transport);
		REQUIRE(seq1.get(PointT(0, 0)) == Transport);
	}
}
