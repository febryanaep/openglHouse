#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector {
	private:
		double x;
		double y;
		double z;
    public:
        Vector();
		Vector(double x, double y, double z);
		Vector(Point ps, Point pe);
        ~Vector();

		void setVector(double x, double y, double z);
		void setVector(Point ps, Point pe);

		Vector getNormal(Vector p, Vector q);

		double getX();
		double getY();
		double getZ();
};

#endif
