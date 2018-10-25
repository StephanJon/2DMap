#ifndef PATHTADT_H
#define PATHTADT_H
#include <vector>
#include "LineADT.h"

/**
 * PathT is a class that mimics a pathway on a 2d plane by appending lines.
 * PathT uses object types LineT, PointT, and MapTypes
 */
using namespace std;
class PathT {
	private:
		/*****Attributes for the class PathT****/

		std::vector<LineT> s;

		/**** Local Functions ****/


		/**
			* Returns the points of a line in a set of PointT objects
			* @param l - the line
			*/
		std::vector<PointT> pointsInLine(LineT l);

		/**
			* Returns the point adjacent to the last point of a path depending on the
			* orientation of the line the last point belongs to
			* @param ornt - the orientation
			*/
		PointT adjPt(CompassT ornt);


	public:
		/**
		* PathT object no-argument constructor
		*/
		PathT();

		/**
			* PathT object Constructor
			* @param st - the start point of the first line in the path
			* @param ornt - the orientation
			* @param l - the length of the first line in the path
			*/
		PathT(PointT st, CompassT ornt, int l);

		/**
			* Appends a line to the path but checks if the line to be appended is
			* already in the path
			* @param ornt - the orientation
			* @param l - the length of the first line in the path
			*/
		void append(CompassT ornt, int l);

		/**
			* Returns the starting point of a path
			*/
		PointT strt();

		/**
			* Returns the end point of a path
			*/
		PointT end();

		/**
			* Returns a Line in the path
			*/
		LineT line(int i);

		/**
			* Returns the number of lines in the path
			*/
		int size();

		/**
			* Returns the number of points in the path
			*/
		int len();

		/**
			* Translates a path by adding dx and dy to each lines' start point
			* x-coordinate and y-coordinate respectively in the path.
			*/
		PathT translate(int dx, int dy);

};

#endif


