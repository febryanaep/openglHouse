#include <math.h>

#include "../include/Vector.h"

Vector::Vector() {
	setVector(0, 0, 0);
}

Vector::Vector(double x, double y, double z) {
	setVector(x, y, z);
}

Vector::Vector(Point ps, Point pe) {
	setVector(ps, pe);
}

Vector::~Vector() {

}

void Vector::setVector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector::setVector(Point ps, Point pe) {
	x = pe.getX() - ps.getX();
	y = pe.getY() - ps.getY();
	z = pe.getZ() - ps.getZ();
}

Vector Vector::getNormal(Vector p, Vector q) {
	x = p.y * q.z - q.y * p.z;
	y = p.z * q.x - q.z * p.x;
	z = p.x * q.y - q.x * p.y;

	double L = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    L = L == 0 ? 1 : L;

	x = x / L;
	y = y / L;
	z = z / L;
	
	return Vector(x, y, z);
}

double Vector::getX() {
	return x;
}

double Vector::getY() {
	return y;
}

double Vector::getZ() {
	return z;
}
