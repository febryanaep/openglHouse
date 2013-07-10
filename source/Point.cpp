#include "../include/Point.h"

Point::Point() {
	setPoint(0, 0, 0);
}

Point::Point(double x, double y, double z) {
	setPoint(x, y, z);
}

Point::~Point() {

}

void Point::setPoint(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

double Point::getZ() {
	return z;
}
