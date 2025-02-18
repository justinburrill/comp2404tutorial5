
#include "TextArea.h"
#include "RGB.h"
#include "defs.h"
#include <X11/Xlib.h>
#include <string>
#include <iostream>

TextArea::TextArea(int x, int y, int w, int h, const std::string &id,
				   const std::string &text, RGB fill, RGB border) {
	this->dim = {x, y, w, h};
	this->id = id;
	this->text = text;
	this->fill = fill;
	this->border = border;
}

TextArea::TextArea(Rectangle d, const std::string id, const std::string &text,
				   RGB fill, RGB border) {
	this->dim = d;
	this->id = id;
	this->text = text;
	this->fill = fill;
	this->border = border;
}

TextArea::TextArea() {
	this->dim = {0, 0, 50, 50};
	this->id = "default id";
	this->text = "default text";
	this->fill = RGB::WHITE();
	this->border = RGB::BLACK();
}

TextArea::TextArea(const TextArea &other) {
	this->dim = other.dim;
	this->id = other.id;
	this->text = "DUPLICATE";
	this->fill = other.fill;
	this->border = other.border;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) const {
	// TODO: for assignment 2
}

bool TextArea::overlaps(const TextArea &ta) const {
	return dim.overlaps(ta.dim);
}

void TextArea::print() const {
	std::cout << "TextArea id:\t\t" << this->id;
	std::cout << "\nPreferred location:\t\t" << this->dim.x << ", "
			  << this->dim.y;
	std::cout << "\nSize:\t\t" << this->dim.width << ", " << this->dim.height;
	std::cout << "\nText:\t\t" << this->text << std::endl;
}

std::string TextArea::getID() const {return this->id;}
int TextArea::getX() const { return this->dim.x; }
int TextArea::getY() const { return this->dim.y; }
int TextArea::getW() const { return this->dim.width; }
int TextArea::getH() const { return this->dim.height; }
CuColour TextArea::getFill() const { return this->fill.getColour(); }
CuColour TextArea::getBorder() const { return this->border.getColour(); }
void TextArea::setFill(RGB f) { this->fill = f; }
void TextArea::setBorder(RGB b) { this->border = b; }
std::string TextArea::getText() const { return this->text; }
