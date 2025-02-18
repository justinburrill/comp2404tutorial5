#include <iostream>
#include <string>

#include "TAArray.h"
#include "TextArea.h"
#include "defs.h"

using namespace std;

TAArray::TAArray() {
	size = 0;
	elements = new TextArea *[MAX_COMPONENTS];
}

TAArray::~TAArray() { delete[] elements; }

bool TAArray::add(TextArea *s) {
	if (this->isFull()) {
		return false;
	}
	this->elements[this->size] = s;
	this->size += 1;

	return true;
}

bool TAArray::add(TextArea *s, int index) {
	cout << "Adding to index " << index << endl;
	if (this->isFull() || index < 0 || index > this->size) {
		return false;
	}

	for (int i = this->size; i > index; i--) {
		this->elements[i] = this->elements[i - 1];
	}

	this->elements[index] = s;

	this->size += 1;
	return true;
}

TextArea *TAArray::get(const string &id) const {
	for (int i = 0; i < size; ++i) {
		if (elements[i]->getID() == id) {
			return elements[i];
		}
	}
	return NULL;
}

TextArea *TAArray::get(int index) const {
	cout << "Getting from index " << index << endl;
	if (index < 0 || index >= size)
		return NULL;
	return elements[index];
}

TextArea *TAArray::remove(const string &id) {

	int index = 0;
	// we want to find the index of the element to remove
	while (!(elements[index]->getID() == id) && index < size) {
		++index;
	}

	return remove(index);
}

TextArea *TAArray::remove(int index) {

	// did we fall off the end of the TAArray?
	if (index < 0 || index >= size)
		return nullptr;

	// we have found what we wanted to remove,
	// assign the output value
	TextArea *ta = elements[index];

	// copy everything after index left one position
	while (index < size - 1) {
		elements[index] = elements[index + 1];
		++index;
	}
	--size;
	return ta;
}

void TAArray::print() const {
	cout << endl << endl << "TextAreas:" << endl;
	for (int i = 0; i < size; ++i)
		elements[i]->print();

	cout << endl;
}
