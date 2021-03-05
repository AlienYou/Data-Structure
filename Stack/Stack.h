#pragma once

template <class Elem>
class Stack {
public:
	enum { DefaultListSize = 0 };
	Stack() { }
	virtual ~Stack() { }
	
	virtual void clear() = 0;

	virtual bool push(const Elem& it) = 0;

	virtual bool pop(Elem&) = 0;

	virtual bool topValue(Elem&) const = 0;

	virtual int length() const = 0;
private:
	void operator =(const Stack&) { }
	Stack(const Stack&) { }
};
