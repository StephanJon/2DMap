#ifndef LANDUSEMAP_H
#define LANDUSEMAP_H
#include "PathADT.h"

/*
Seq2D is a class that represents a map of a 2D plane with each entry
as an object of LanduseT
*/
class LandusemapT {
	private:
		/*****Attributes for the class Seq2D****/

		//s = 2D array of object type LanduseT
		std::vector<std::vector<LanduseT>> s;
		//scale = "scale" of the map (float)
		float scale;
		//nRow = Number of rows of s
		int nRow;
		//nCol = Number of coloumns of s
		int nCol;

		/**** Local Functions ****/

		//Returns true if row i exists in a 2D array
		bool validRow(int i);

		//Returns true if column i exists in a 2D array
		bool validCol(int i);

		//Returns true if the given point lies within the boundaries of the map
		bool validPoint(PointT p);

		/*
		Returns true if all of the points for the given line lie within the boundaries
		of the map.
		*/
		bool validLine(LineT l);

		/*
		Returns true if all of the points for the given path lie within the boundaries
		of the map.
		*/
		bool validPath(PathT pth);

		//Returns the points of a line in a set of PointT objects
		std::vector<PointT> pointsInLine(LineT l);

		//Returns The set of points that make up the input path
		std::vector<PointT> pointsInPath(PathT pth);

	public:
		/**
		* Seq2D object no-argument constructor
		*/
		LandusemapT();

		//Constructor
		LandusemapT(std::vector<std::vector<LanduseT>> S, float scl);

		//Sets an entry of s to an object of T
		void set(PointT p, LanduseT v);

		//Returns an entry of s
		LanduseT get(PointT p);

		//Returns the number of rows in s
		int getNumRow();

		//Returns the number of coloumns in s
		int getNumCol();

		//Returns the scale of s
		float getScale();

		/*
		Returns the number of occurences that t of Type T is
		in s
		*/
		int count(LanduseT t);

		/*
		Returns the number of occurences that t of Type T is
		in s, specifically on a line of entries
		*/
		int count(LineT l, LanduseT t);

		/*
		Returns the number of occurences that t of Type T is
		in s, specifically on a path of entries
		*/
		int count(PathT pth, LanduseT t);

		//Returns the length of a path on the map by its scale
		int length(PathT pth);

		/*
		Return true if a path exists between p1 and p2 with all of the points
		on the path being of the same value
		*/
		bool connected(PointT p1, PointT p2);
};

#endif

