#include "../include/Color.h"

Color::Color() {
	setColor(0, 0, 0);
}

Color::~Color() {

}

void Color::setColor(int red, int green, int blue) {
	this->red   = (red   < 0 ? 0 : (red   > 255 ? 255 : red  ));
	this->green = (green < 0 ? 0 : (green > 255 ? 255 : green));
	this->blue  = (blue  < 0 ? 0 : (blue  > 255 ? 255 : blue ));
}

int Color::getColorRed() {
	return red;
}

int Color::getColorGreen() {
	return green;
}

int Color::getColorBlue() {
	return blue;
}
