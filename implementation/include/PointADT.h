#ifndef POINTTADT_H
#define POINTTADT_H



/**
 * PointT is a class that creates objects to represent a point on a 2d plane.
 */
class PointT {
	private:
		/*****Attributes for the class PointT****/
		int xc;
		int yc;

	public:
		/**
			* PointT object no-argument constructor
			*/
		PointT();

		/**
			* PointT object Constructor
			* @param xc - x-coordinate
			* @param yc - y-coordinate
			*/
		PointT(int x, int y);

		/**
			* Getter method for xc
			*/
		int x();

		/**
			* Getter method for yc
			*/
		int y();

		/**
			* Translates the xc and yc of an existing PointT object by adding
			* how dx to xc and dy to yc, and returns a new PointT object with
			* the modified attributes.
			*/
		PointT translate(int dx, int dy);


};

#endif

