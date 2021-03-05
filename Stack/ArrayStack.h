#pragma once
#include "Stack.h"

template <class Elem>
class ArrayStack : public Stack<Elem> {
public:
	ArrayStack(int sz = Stack<Elem>::DefaultListSize) { size = sz; top = 0; listArray = new Elem[sz]; }
	~ArrayStack() { delete[]listArray; }

	void clear() { top = 0; }

	bool push(const Elem& it) {
		if (top == size) return false;
		else {
			listArray[top++] = it;
		}
		return true;
	}

	bool pop(Elem& it) {
		if (top == 0) return false;
		else
			it = listArray[--top];
		return true;
	}

	bool topValue(Elem& it) const {
		if (top == 0) return false;
		else
			it = listArray[top - 1];
		return true;
	}

	int length() const { return top; }
private:
	int size;
	int top;
	Elem* listArray;
};
