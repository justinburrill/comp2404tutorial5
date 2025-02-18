
#include "RGB.h"
#include "defs.h"
#include <iostream>

RGB::RGB(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

RGB::RGB(CuColour c) { // 32 bit unsigned long
	// 00000000 11111111 00000000 00000000
	// 0x  0   0    F   F    0   0    0   0
	// this->r = CuRed | c;
	// this->g = CuGreen | c;
	// this->b = CuBlue | c;
	setColour(c);
}

RGB::RGB() {
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

RGB RGB::BLACK() { return RGB(0); }
RGB RGB::WHITE() { return RGB(0xFFFFFF); }
RGB RGB::GREEN() { return RGB(CuGreen); }
RGB RGB::BLUE() { return RGB(CuBlue); }
RGB RGB::RED() { return RGB(CuRed); }

int RGB::getR() const { return this->r; }

int RGB::getG() const { return this->g; }

int RGB::getB() const { return this->b; }

void RGB::setR(int r) { this->r = r; }

void RGB::setG(int g) { this->g = g; }

void RGB::setB(int b) { this->b = b; }

CuColour RGB::getColour() const {
	return (getR() << 16) + (getG() << 8) + (getB() << 0);
}

void RGB::setColour(CuColour c) {
	this->r = (int)((c & CuRed) >> 16);
	this->g = (int)((c & CuGreen) >> 8);
	this->b = c & CuBlue;
}

void RGB::print() const {
	std::cout << "RGB colour: " << getR() << ", " << getG() << ", " << getB()
			  << std::endl;
}
