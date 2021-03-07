#pragma once
#include <iostream>
using std::cout;
using std::endl;
void Assert(bool val, const char* s) {
	if (!val) {
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}
static constexpr int DefaultSize = 0;

template <typename E> 
class Queue {
private:
	void operator=(const Queue&) { }
	Queue(const Queue&) { }
public:
	Queue() { }
	virtual ~Queue() { }

	virtual void clear() = 0;

	virtual void enqueue(const E&) = 0;

	virtual E dequeue() = 0;

	virtual const E& frontValue() const = 0;

	virtual int length() const = 0;
};
