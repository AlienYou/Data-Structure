#pragma once
#include "Stack.h"

template <typename Elem>
class LinkStack : public Stack<Elem> {
public:
	LinkStack(int size = Stack<Elem>::DefaultListSize) { top = nullptr; this->size = 0; }
	~LinkStack() { clear(); }
	void clear() {
		while (top != nullptr) {
			LinkNode* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}
	bool push(const Elem& it) {
		top = new LinkNode(it, top);
		size++;
		return true;
	}

	bool pop(Elem& it) {
		if (size == 0) return false;
		it = top->element;
		LinkNode* temp = top;
		top = top->next;
		delete temp;
		size--;
		return true;
	}
	bool topValue(Elem& it) const {
		if (size == 0) return false;
		it = top->element;
		return true;
	}
	int length() const{ return size; }
private:
	struct LinkNode {
		Elem element;
		LinkNode* next;
		LinkNode(Elem e, LinkNode* nextV = nullptr) : element(e), next(nextV){ }
		LinkNode(LinkNode* nextV = nullptr) : next(nextV) { }
		void* operator new(size_t);
		void operator delete(void*);
	};
	static LinkNode* freeList;
	
	LinkNode* top;
	int size;
};

template<typename Elem>
typename LinkStack<Elem>::LinkNode* LinkStack<Elem>::freeList = nullptr;

template <typename Elem>
void* LinkStack<Elem>::LinkNode::operator new(size_t) {
	if (freeList == nullptr) freeList = ::new LinkNode;
	LinkNode* temp = freeList;
	freeList = freeList->next;
	return temp;
}

template <typename Elem>
void LinkStack<Elem>::LinkNode::operator delete(void* ptr) {
	static_cast<LinkNode*>(ptr)->next = freeList;
	freeList = static_cast<LinkNode*>(ptr);
}
