
#ifndef RGB_H
#define RGB_H
#define CuRed 0xFF0000
#define CuGreen 0x00FF00
#define CuBlue 0x0000FF

#include "defs.h"

class RGB {
  private:
	int r, g, b;

  public:
	static RGB WHITE();
	static RGB BLACK();
	static RGB RED();
	static RGB GREEN();
	static RGB BLUE();

	RGB(int r, int g, int b);
	RGB(CuColour c);
	RGB();

	int getR() const;
	int getG() const;
	int getB() const;

	void setR(int r);
	void setG(int g);
	void setB(int b);

	CuColour getColour() const;
	void setColour(CuColour c);

	void print() const;
};

#endif
