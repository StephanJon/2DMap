#ifndef MAPTYPES_H
#define MAPTYPES_H

/*
CompassT is represents the four main cardinal directions of a compass
(North, South, West, and East)
*/
typedef enum {N, S, W, E} CompassT;

/*
RotateT represents 90 degrees of rotation direction
(Clockwise or Counter-clockwise)
*/
typedef enum {CW, CCW} RotateT;

/*
LanduseT represents the use for a plot of land
(Recreational, Transport, Agricultural, Residential, or Commercial)
*/
typedef enum { Recreational, Transport, Agricultural, Residential, Commercial } LanduseT;

#endif