#include "../include/PathADT.h"
#include <iostream>
#include "../include/Exceptions.h"

/*
Implementation for the class PathT
*/


//no argument Constructor
PathT::PathT() {
	this->s;
}

//Constructors
PathT::PathT(PointT st, CompassT ornt, int l) {
	this->s.push_back(LineT(st, ornt, l));
}
/*
Appends a line to the path but checks if any point in the line to 
be appended is already in the path.
*/
void PathT::append(CompassT ornt, int l) {
	try {
		LineT addLine = LineT(adjPt(ornt), ornt, l);
		std::vector<PointT> addPoints = pointsInLine(addLine);
		for (int i = 0; i < this->s.size(); i++)
		{
			std::vector<PointT> temp = pointsInLine(this->s.at(i));
			for (int j = 0; j < addPoints.size(); j++)
		{
				for (int k = 0; k < temp.size(); k++)
				{
					if (addPoints.at(j).x() == temp.at(k).x() && addPoints.at(j).y() == temp.at(k).y())
					{ 
						throw outside_bounds();
					} 
				}
			}	
		} 
		this->s.push_back(addLine);
	}
	catch (outside_bounds *e) {
		std::cout << "The line you are trying to append to the path \
				has a point that intersects with a pre-existing \
				point on the path." << std::endl << e;
	}
}

//Returns the starting point of a path
PointT PathT::strt() { return this->s.at(0).strt(); }

//Returns the last point in the pathway
PointT PathT::end() { return this->s[this->s.size() - 1].end(); }

//Returns a Line in the path
LineT PathT::line(int i) {
	try {
		if (i < 0 || i >= this->s.size()) {
			throw outside_bounds();
		} return LineT(this->s.at(i).strt(), this->s.at(i).orient(), this->s.at(i).len());
	} 
	catch (const char *e) {
		std::cout << "The index of the path you are trying to access \
					does not exist." << std::endl << e;
	}
}

//Returns the number of lines in the pathway
int PathT::size() { return this->s.size(); }

//Returns the number of points in the pathway
int PathT::len() {
	int counter = 0;
	for (int i = 0; i < this->s.size(); i++) {
		counter += this->s.at(i).len();
	}
	return counter;
}

/*
Translates a path by adding dx and dy to each lines' start point
x-coordinate and y-coordinate respectively in the path.
*/
PathT PathT::translate(int dx, int dy) {
	LineT newFirst = this->s.at(0).translate(dx, dy);
	PathT newPath = PathT(newFirst.strt(), newFirst.orient(), newFirst.len());
	for (int i = 1; i < this->s.size(); i++) {
		LineT temp = this->s.at(i).translate(dx, dy);
		newPath.append(temp.orient(), temp.len());
	}
	return newPath;
}

/**** Local Functions ****/

//Returns the points of a line in a set of PointT objects
std::vector<PointT> PathT::pointsInLine(LineT l) {
	std::vector<PointT> Points;
	PointT temp = l.strt();
	Points.push_back(temp);
	if (l.orient() == N) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(0, 1);
			Points.push_back( temp );
		}
	}
	else if (l.orient() == S) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(0, -1);
			Points.push_back( temp );
		}
	}
	else if (l.orient() == E) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(1, 0);
			Points.push_back( temp );
		}
	}
	else {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(-1, 0);
			Points.push_back( temp );
		}
	}
	return Points;
}

/*
Returns the point adjacent to the last point of a path depending on the
orientation of the line the last point belongs to
*/
PointT PathT::adjPt(CompassT ornt) {
	PointT adjPt;
	if (ornt == N) {
		adjPt = this->s[this->s.size() - 1].end().translate(0, 1);
	}
	else if (ornt == S) {
		adjPt = this->s[this->s.size() - 1].end().translate(0, -1);
	}
	else if (ornt == W) {
		adjPt = this->s[this->s.size() - 1].end().translate(-1, 0);
	}
	else {
		adjPt = this->s[this->s.size() - 1].end().translate(1, 0);
	}
	return adjPt;
}