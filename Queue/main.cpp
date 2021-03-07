
#include "ArrayQueue.h"
#include "QueueTest.h"
#include "LinkQueue.h"

void testArrayQueue() {
	ArrayQueue<int> q1(10);
	ArrayQueue<int*> q2(15);
	
	QueueTest<int>(q1);
}

void testLinkQueue() {
	LinkQueue<int> lq1;
	QueueTest<int>(lq1);
}

int main()
{
	testLinkQueue();
}

