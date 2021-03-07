#pragma once
#include "Queue.h"

template <typename E>
class LinkQueue : public Queue<E> {
public:
	LinkQueue(int sz = DefaultSize) { front = rear = new LinkNode; size = 0; }

	~LinkQueue() { clear(); delete front; rear = front = nullptr; }

	void clear() {
		while (front->next != nullptr) {
			rear = front;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	void enqueue(const E& it) {
		rear = rear->next = new LinkNode(it, nullptr);
		size++;
	}

	E dequeue() {
		Assert(size != 0, "Queue is empty");
		E it = front->next->element;
		LinkNode* temp = front->next;
		front->next = temp->next;
		if (rear == temp) rear = front;
		delete temp;
		size--;
		return it;
	}

	const E& frontValue() const {
		Assert(size != 0, "Queue is empty");
		return front->next->element;
	}

	int length() const { return size; }
private:
	struct LinkNode {
		E element;
		LinkNode* next;
		LinkNode(E e, LinkNode* nextV = nullptr) : element(e), next(nextV) { }
		LinkNode(LinkNode* nextV = nullptr) : next(nullptr) { }
		void* operator new(size_t) {
			if (freeList == nullptr) return ::new LinkNode;
			LinkNode* tmp = freeList;
			freeList = freeList->next;
			return tmp;
		}
		void operator delete(void* ptr) {
			static_cast<LinkNode*>(ptr)->next = freeList;
			freeList = static_cast<LinkNode*>(ptr);
		}
	};
	
	static LinkNode* freeList;
	
	LinkNode* front;
	LinkNode* rear;
	int size;
};

template <typename E>
typename LinkQueue<E>::LinkNode* LinkQueue<E>::freeList = nullptr;
