#include "../include/LineADT.h"
#include <iostream>
#include "../include/Exceptions.h"

/*
Implementation for the class LineT
*/

//No argument constructor
LineT::LineT() {
	this->s = PointT();
	this->o = N;
	this->L = 1;
}

//Constructor
LineT::LineT(PointT st, CompassT ornt, unsigned int l){
	try {
		if (l <= 0) {
			invalid_argument error;
			throw error;
		}
		else {
			this->s = st;
			this->o = ornt;
			this->L = l;
		}
	}
	catch (invalid_argument *e) {
		std::cout << "Please ensure the length of the line is \
				greater than 0." << std::endl << e;
	}
}

//Getter method for s
PointT LineT::strt(){ return PointT(this->s.x(), this->s.y()); }

//Method for calculating the point at the end of the line
PointT LineT::end() {
	CompassT otemp = this->o;
	int Ltemp = len();
	int xtemp = strt().x();
	int ytemp = strt().y();
	if (otemp == W) {
		return PointT(xtemp - (Ltemp - 1), ytemp);
	} else if (otemp == E) {
		return PointT(xtemp + (Ltemp - 1), ytemp);
	} else if (otemp == N) {
		return PointT(xtemp, ytemp + (Ltemp - 1));
	} else {
		return PointT(xtemp, ytemp - (Ltemp - 1));
	}
}

//Getter method for the orientation of the line
CompassT LineT::orient(){ 
	return o; 
}

//Getter method for the length of the Line
int LineT::len(){ 
	return this->L; 
}

//Method for flipping the orientation of a line 180 degrees
LineT LineT::flip(){ 
	return rotate(CW).rotate(CW);
}

/*
Method for rotating the orientation of a line counter clockwise or
clockwise
*/
LineT LineT::rotate(RotateT r){
	PointT ptemp = strt();
	CompassT otemp = orient();
	int Ltemp = len();
	if (r == CW) {
		if (otemp == N) {
			return LineT(ptemp, E, Ltemp);
		} else if (otemp == S) {
			return LineT(ptemp, W, Ltemp);
		} else if (otemp == W) {
			return LineT(ptemp, N, Ltemp);
		}else {
			return LineT(ptemp, S, Ltemp);
		}
	} else {
		if (otemp == N) {
			return LineT(ptemp, W, Ltemp);
		} else if (otemp == S) {
			return LineT(ptemp, E, Ltemp);
		} else if (otemp == W) {
			return LineT(ptemp, S, Ltemp);
		}else {
			return LineT(ptemp, N, Ltemp);
		}
	}
}

/*
Translates a line by adding dx and dy to the lines start point x-coordinate
and y-coordinate respectively.
*/
LineT LineT::translate(int dx, int dy){ return LineT(this->s.translate(dx, dy), o, L); }
