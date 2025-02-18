#ifndef TEXTAREA_H
#define TEXTAREA_H
#include "RGB.h"
#include "defs.h"
#include <X11/Xlib.h>
#include <string>
using namespace std;

class TextArea {
  private:
	Rectangle dim;
	std::string text, id;
	RGB fill, border;

  public:
	TextArea(int x, int y, int w, int h, const std::string &id,
			 const std::string &text, RGB fill = RGB::WHITE(),
			 RGB border = RGB::BLACK());

	TextArea(Rectangle d, const std::string id, const std::string &text,
			 RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
	TextArea();
	TextArea(const TextArea &other);

	void draw(Display *display, Window win, GC gc, int x, int y) const;

	bool overlaps(const TextArea &ta) const;
  bool equals(const std::string& id) const;
  bool equals(int ) const;

	void print() const;

	void setFill(RGB f);
	void setBorder(RGB b);
	int getX() const;
	int getY() const;
	int getW() const;
	int getH() const;
	CuColour getFill() const;
	CuColour getBorder() const;
	std::string getText() const;
  std::string getID() const;
};

#endif // TEXTAREA_H
