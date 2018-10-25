#include "../include/Seq2D.h"
#include <iostream>
#include "../include/Exceptions.h"
/*
Implementation for the class Seq2D
*/


/**
* Seq2D object no-argument constructor
*/
template <class T>
Seq2D<T>::Seq2D() {
	this->s;
	this->scale = 0;
	this->nRow = 0;
	this->nCol = 0;
}

//Constructor
template <class T>
Seq2D<T>::Seq2D(std::vector<vector<T>> S, float scl) {
	try {
		if (scl <= 0 || S.size() == 0 || S.at(0).size() == 0)
		{
			throw outside_bounds();
		}
		for (int i = 0; i < S.size(); i++)
		{
			if (S.at(i).size() != S.at(0).size())
			{
				throw outside_bounds();
			}
		}
		this->s = S;
		this->scale = scl;
		this->nRow = S.size();
		this->nCol = S.at(0).size();
		this->marked.resize(s.size());
		for (int i = 0; i < marked.size(); i++) {
			marked.at(i).resize(s.at(0).size());
			for (int j = 0; j < marked.at(i).size(); j++) {
				marked[i][j] = false;
			}
		}
	}
	catch (outside_bounds *e) {
		std::cout << "Please ensure that sequence of sequence of T has rows and \
				columns greater than 0, and that the number of rows and columns \
				are the same.\n \
				Also, ensure that the scale passed is greater than 0." << std::endl << e;
	}

}


//Sets an entry of s to an object of T
template <class T>
void Seq2D<T>::set(PointT p, T v) {
	try {
		if (!(validPoint(p)))
		{
			throw outside_bounds();
		}
		this->s.at(p.y()).at(p.x()) = v;
	}
	catch (outside_bounds *e) {
		std::cout << "Point passed is invalid." << std::endl << e;
	}
}

//Returns an entry of s
template <class T>
T Seq2D<T>::get(PointT p) {
	try {
		if (!(validPoint(p)))
		{
			throw outside_bounds();
		} return this->s.at(p.y()).at(p.x());
	}
	catch (outside_bounds *e) {
		std::cout << "Point passed is invalid." << std::endl << e;
	}
}

//Returns the number of rows in s
template <class T>
int Seq2D<T>::getNumRow() { return this->nRow; }

//Returns the number of coloumns in s
template <class T>
int Seq2D<T>::getNumCol() { return this->nCol; }

//Returns the scale of s
template <class T>
float Seq2D<T>::getScale() { return this->scale; }

/*
Returns the number of occurences that t of Type T is
in s
*/
template <class T>
int Seq2D<T>::count(T t) {
	int count = 0;
	for (int i = 0; i < getNumRow(); i++)
	{
		for (int j = 0; j < getNumCol(); j++)
		{
			if (this->s.at(i).at(j) == t)
			{
				count++;
			}
		}
	} return count;
}

/*
Returns the number of occurences that t of Type T is
in s, specifically on a line of entries
*/
template <class T>
int Seq2D<T>::count(LineT l, T t) {
	try {
		if (!(validLine(l)))
		{
			throw outside_bounds();
		}
		int count = 0;
		std::vector<PointT> points = pointsInLine(l);
		for (int i = 0; i < points.size(); i++)
		{
			if (this->s.at(points.at(i).y()).at(points.at(i).x()) == t)
			{
				count++;
			}
		} return count;
	}
	catch (outside_bounds *e) {
		std::cout << "One or more points on the line passed are invalid." << std::endl << e;
	}
}

/*
Returns the number of occurences that t of Type T is
in s, specifically on a path of entries
*/
template <class T>
int Seq2D<T>::count(PathT pth, T t) {
	try {
		if (!(validPath(pth)))
		{
			throw outside_bounds();
		}
		int count = 0;
		for (int i = 0; i < pth.size(); i++)
		{
			int add = 0;
			std::vector<PointT> points = pointsInLine(pth.line(i));
			for (int i = 0; i < points.size(); i++)
			{
				if (this->s.at(points.at(i).y()).at(points.at(i).x()) == t)
				{
					add++;
				}
			} 
			count += add;
	
		} return count;
	}
	catch (outside_bounds *e) {
		std::cout << "One or more points on the path passed are invalid." << std::endl << e;
	}
}

//Returns the length of a path on the map by its scale
template <class T>
int Seq2D<T>::length(PathT pth) {
	try {
		if (!(validPath(pth)))
		{
			throw outside_bounds();
		} return pth.len()*getScale();
	}
	catch (outside_bounds *e) {
		std::cout << "One or more points on the path passed are invalid." << std::endl << e;
	}
}

/*
Return true if a path exists between p1 and p2 with all of the points
on the path being of the same value
*/
template <class T>
bool Seq2D<T>::connected(PointT p1, PointT p2) {
	try {
		if (!(validPoint(p1)) || !(validPoint(p2)))
		{
			throw outside_bounds();
		}
		
		for (int i = 0; i < getNumRow(); i++)
		{
			for (int j = 0; j < getNumCol(); j++)
			{
				marked.at(i).push_back(false);
			}
		}

		bool check = false;
		if (p1.x() == p2.x() && p1.y() == p2.y())
		{
			return true;
		}
		PointT Np1 = p1.translate(0, 1);
		PointT Sp1 = p1.translate(0, -1);
		PointT Wp1 = p1.translate(-1, 0);
		PointT Ep1 = p1.translate(1, 0);
		if (validPoint(Np1) && !check) {
			if (get(Np1) == get(p2)) {
				marked[Np1.y()][Np1.x()] = true;
				check = connectedMarked(Np1, p2, marked);
			}
		}
		if (validPoint(Sp1) && !check) {
			if (get(Sp1) == get(p2)) {
				marked[Sp1.y()][Sp1.x()] = true;
				check = connectedMarked(Sp1, p2, marked);
			}
		}
		if (validPoint(Wp1) && !check) {
			if (get(Wp1) == get(p2)) {
				marked[Wp1.y()][Wp1.x()] = true;
				check = connectedMarked(Wp1, p2, marked);
			}
		}
		if (validPoint(Ep1) && !check) {
			if (get(Ep1) == get(p2)) {
				marked[Ep1.y()][Ep1.x()] = true;
				check = connectedMarked(Sp1, p2, marked);
			}
		}
		if (check) {
			return check;
		} return false;
	}
	catch (outside_bounds *e) {
		std::cout << "Point 1 or 2 are invalid points." << std::endl << e;
	}
	
}

/*
Helper function for connected
*/
template <class T>
bool Seq2D<T>::connectedMarked(PointT p1, PointT p2, std::vector<std::vector<bool>> marked) {
	
	bool check = false;
	if (p1.x() == p2.x() && p1.y() == p2.y())
	{
		return true;
	}
	PointT Np1 = p1.translate(0, 1);
	PointT Sp1 = p1.translate(0, -1);
	PointT Wp1 = p1.translate(-1, 0);
	PointT Ep1 = p1.translate(1, 0);
	if (validPoint(Np1) && !marked.at(p1.y()).at(p1.x()) && !check) {
		if (get(Np1) == get(p2)) {
			marked[Np1.y()][Np1.x()] = true;
			check = connectedMarked(Np1, p2, marked);
		}
	}
	if (validPoint(Sp1) && !marked.at(p1.y()).at(p1.x()) && !check) {
		if (get(Sp1) == get(p2)) {
			marked[Sp1.y()][Sp1.x()] = true;
			check = connectedMarked(Sp1, p2, marked);
		}
	}
	if (validPoint(Wp1) && !marked.at(p1.y()).at(p1.x()) && !check) {
		if (get(Wp1) == get(p2)) {
			marked[Wp1.y()][Wp1.x()] = true;
			check = connectedMarked(Wp1, p2, marked);
		}
	}
	if (validPoint(Ep1) && !marked.at(p1.y()).at(p1.x()) && !check) {
		if (get(Ep1) == get(p2)) {
			marked[Ep1.y()][Ep1.x()] = true;
			check = connectedMarked(Ep1, p2, marked);
		}
	}
	if (check) {
		return check;
	} return false;
}

/**** Local Functions ****/

//Returns true if row i exists in a 2D array
template <class T>
bool Seq2D<T>::validRow(int i) {
	if (0 <= i && i <= this->nRow - 1)
	{
		return true;
	} return false;
}

//Returns true if column i exists in a 2D array
template <class T>
bool Seq2D<T>::validCol(int i) {
	if (0 <= i && i <= this->nCol - 1)
	{
		return true;
	} return false;
}

//Returns true if the given point lies within the boundaries of the map
template <class T>
bool Seq2D<T>::validPoint(PointT p) { return (validRow(p.y()) && validCol(p.x())); }

/*
Returns true if all of the points for the given line lie within the boundaries
of the map.
*/
template <class T>
bool Seq2D<T>::validLine(LineT l) {
	std::vector<PointT> points = pointsInLine(l);
	for (int i = 0; i < points.size(); i++)
	{
		if (!(validPoint(points.at(i))))
		{
			return false;
		}
	} return true;
}

/*
Returns true if all of the points for the given path lie within the boundaries
of the map.
*/
template <class T>
bool Seq2D<T>::validPath(PathT pth) {
	for (int i = 0; i < pth.size(); i++)
	{
		if (!(validLine(pth.line(i))))
		{
			return false;
		}
	} return true;
}

//Returns the points of a line in a set of PointT objects
template <class T>
std::vector<PointT> Seq2D<T>::pointsInLine(LineT l) {
	std::vector<PointT> Points;
	PointT temp = l.strt();
	Points.push_back(temp);
	if (l.orient() == N) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(0, 1);
			Points.push_back(temp);
		}
	}
	else if (l.orient() == S) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(0, -1);
			Points.push_back(temp);
		}
	}
	else if (l.orient() == E) {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(1, 0);
			Points.push_back(temp);
		}
	}
	else {
		for (int i = 0; i < l.len(); i++) {
			temp = temp.translate(-1, 0);
			Points.push_back(temp);
		}
	}
	return Points;
}

//Returns The set of points that make up the input path
template <class T>
std::vector<PointT> Seq2D<T>::pointsInPath(PathT pth) {
	std::vector<PointT> Points;
	std::vector<PointT> LinePoints;
	for (int i = 0; i < pth.size(); i++)
	{
		LinePoints = pointsInLine(pth.line(i));
		for (int j = 0; i < LinePoints.size(); i++)
		{
			Points.push_back(LinePoints.at(j));
		} return Points;
	}
	
}

template class Seq2D<LanduseT>;
template class Seq2D<int>;