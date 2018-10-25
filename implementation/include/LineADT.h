#ifndef LINETADT_H
#define LINETADT_H
#include "MapTypes.h"
#include "PointADT.h"


/**
 * LineT is a class that creates objects to represent a line on a 2d plane.
 * LineT uses the class PointT and MapTypes
 */
class LineT {
	private:
		/*****Attributes for the class PointT****/

		PointT s;
		CompassT o;
		int L;

	public:
		/**
			* LineT object no-argument constructor
			*/
		LineT();

		/**
			* LineT object constructor
			* @param st - start point of the line
			* @param ornt - orientation of the line
			* @param l - length of the line
			*/
		LineT(PointT st, CompassT ornt, unsigned int l);

		/**
			* Getter method for s
			*/
		PointT strt();

		/**
			* Method for calculating the point at the end of the line
			*/
		PointT end();

		/**
			* Getter method for the orientation of the line
			*/
		CompassT orient();

		/**
			* Getter method for the length of the Line
			*/
		int len();

		/**
			* Method for flipping the orientation of a line 180 degrees
			*/
		LineT flip();

		/**
			* Method for rotating the orientation of a line counter clockwise or
			* clockwise
			*/
		LineT rotate(RotateT r);

		/*

		*/
		/**
			* Translates a line by adding dx and dy to the lines start point x-coordinate
			* and y-coordinate respectively.
			*/
		LineT translate(int dx, int dy);

};

#endif
