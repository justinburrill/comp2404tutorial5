

#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include "defs.h"
#include <string>

using namespace std;

class TAArray {
  public:
	TAArray();
	~TAArray();

	bool add(TextArea *s);
	bool add(TextArea *s, int index);

	TextArea *get(const string &name) const;
	TextArea *get(int index) const;

	TextArea *remove(const string &name);
	TextArea *remove(int index);

	bool isFull() const { return size == MAX_COMPONENTS; }
	int getSize() const { return size; }
	void print() const;

  private:
	TextArea **elements;
	int size;
};

#endif
