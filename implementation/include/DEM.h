#ifndef DEM_H
#define DEM_H
#include "PathADT.h"

/**
 * Seq2D is a generic class that represents a map of a 2D plane with each entry
 * as an object of int
 */
class DEMT {
	private:
		/*****Attributes for the class Seq2D****/

		std::vector<std::vector<int>> s;
		float scale;
		int nRow;
		int nCol;

		/**** Local Functions ****/

		/**
		 * Returns true if row i exists in a 2D array
		 * @param i - the row
		 */
		bool validRow(int i);

		/**
		 * Returns true if column i exists in a 2D array
		 * @param i - the column
	 	 */
		bool validCol(int i);

		/**
		 * Returns true if the given point lies within the boundaries of the map
		 * @param p - the point
	  	 */
		bool validPoint(PointT p);

		/**
		 * Returns true if all of the points for the given line lie within the boundaries
		 * of the map.
		 * @param l - the line
		 */
		bool validLine(LineT l);

		/**
		 * Returns true if all of the points for the given path lie within the boundaries
		 * of the map.
		 * @param pth - the path
		 */
		bool validPath(PathT pth);

		/**
		 * Returns the points of a line in a set of PointT objects
		 * @param l - the line
		 */
		std::vector<PointT> pointsInLine(LineT l);

		/**
		 * Returns The set of points that make up the input path
		 * @param pth - the path
		 */
		std::vector<PointT> pointsInPath(PathT pth);

	public:
		/**
		* Seq2D object no-argument constructor
		*/
		DEMT();

		/**
		* Seq2D object constructor
		* @param S - the sequence of sequence of int
		* @param scl - the scale
		*/
		DEMT(std::vector<std::vector<int>> S, float scl);

		/**
		 * Sets an entry of s to an object of int
		 * @param p - the entry point of s
		 * @param v - the object of int
		 */
		void set(PointT p, int v);

		/**
		 * Returns an entry of s
		 * @param p - the entry point of s
		 */
		int get(PointT p);

		/**
		 * Returns the number of rows in s
		 */
		int getNumRow();

		/**
		 * Returns the number of columns in s
		 */
		int getNumCol();

		/**
		 * Returns the scale of s
		 */
		float getScale();

		/**
		 * Returns the number of occurences that t of generic
		 * Type T is in s
		 * @param t - the object of int
		 */
		int count(int t);

		/**
		 * Returns the number of occurences that t of Type T is
		 * in s, specifically on a line of entries
		 * @param l - the line
		 * @param t - the object of int
		 */
		int count(LineT l, int t);

		/**
		 * Returns the number of occurences that t of Type T is
		 * in s, specifically on a path of entries
		 * @param pth - the path
		 * @param t - the object of int
		 */
		int count(PathT pth, int t);

		/**
		 * Returns the length of a path on the map by its scale
		 * @param pth - the path
		 */
		int length(PathT pth);

		/**
		 * Return true if a path of entries exists between p1 and p2, 
		 * with all of the points on the path being of the same value
		 * @param p1 - point 1
		 * @param p2 - point 2
		 */
		bool connected(PointT p1, PointT p2);
};

#endif
