#pragma once
#include "Queue.h"

template <typename E> 
void QueueTest(Queue<E>& Que) {
	E temp;

	Que.enqueue(10);
	Que.enqueue(20);
	Que.enqueue(30);
	cout << "Length is " << Que.length() << endl;

	if (Que.length() > 0) {
		temp = Que.frontValue();
		cout << "Front is " << temp << endl;
	}
	else
		cout << "Queue is empty" << endl;
	while (Que.length() > 0) {
		temp = Que.dequeue();
		cout << temp << " ";
	}
	cout << endl;
	cout << "Length is " << Que.length() << endl;
	if (Que.length() > 0) {
		temp = Que.frontValue();
		cout << "Front is " << temp << endl;
	}
	else
		cout << "Queue is empty" << endl;
	Que.clear();
	cout << "Length is " << Que.length() << endl;
	cout << "Test over" << endl;
}
