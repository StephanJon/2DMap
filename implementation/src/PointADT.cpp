#include "../include/PointADT.h"

/*
Implementation for the class PointT
*/

//No argument Constructor for PointT objects
PointT::PointT(){
	this->xc = 0;
	this->yc = 0;
}

//Constructor for PointT objects
PointT::PointT(int x, int y){
	this->xc = x;
	this->yc = y;
}

//Getter method for xc
int PointT::x() { return this->xc; }

//Getter method for yc
int PointT::y() { return this->yc; }

/*Translates the xc and yc of an existing PointT object by adding
how dx to xc and dy to yc, and returns a new PointT object with
the modified attributes.
*/
PointT PointT::translate(int dx, int dy){ return PointT(x()+dx, y()+dy); }
