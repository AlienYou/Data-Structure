#pragma once

#include "List.h"

template <typename Elem>
class LinkList : public List<Elem> {
public:
	LinkList(int size = DefaultListSize) { init(); }
	~LinkList() { removeAll(); }
	void clear() { removeAll(); init(); }
	bool insert(const Elem&);
	bool append(const Elem&);
	bool remove(Elem&);
	void setStart() { fence = head; rightCnt += leftCnt; leftCnt = 0; }
	void setEnd() { fence = tail; leftCnt += rightCnt; rightCnt = 0; }
	void prev();
	void next() {
		if (fence != tail) {
			fence = fence->next;
			rightCnt--;
			leftCnt++;
		}
	}
	int leftLength() const { return leftCnt; }
	int rightLength() const { return rightCnt; }
	bool setPos(int pos);
	bool getValue(Elem& it) const {
		if (rightLength() == 0) return false;
		it = fence->next->element;
		return true;
	}
	void print() const;
private:
	struct LinkNode
	{
	private:
	public:
		Elem element;
		LinkNode* next;
		LinkNode* prev;
		LinkNode(const Elem& elemVal, LinkNode* prevVal = nullptr, LinkNode* nextVal = nullptr) {
			element = elemVal;
			prev = prevVal;
			next = nextVal;
		}
		LinkNode(LinkNode* preVal = nullptr, LinkNode* nextVal = nullptr) { prev = preVal; next = nextVal; }
		void* operator new(size_t);	//重载new和delete,手动分配
		void operator delete(void*);
	};

	//可利用空间表节点
	static LinkNode* freeList;
private:
	LinkNode* head;
	LinkNode* tail;
	LinkNode* fence;
	int leftCnt;
	int rightCnt;
	
	void init() {
		fence = tail = head = new LinkNode;
		leftCnt = rightCnt = 0;
	}

	void removeAll() {
		while (head != nullptr) {
			fence = head;
			head = head->next;
			delete fence;
		}
	}
};
template <typename Elem>
typename LinkList<Elem>::LinkNode* LinkList<Elem>::freeList = nullptr;

template <typename Elem>
void* LinkList<Elem>::LinkNode::operator new(size_t) {		
	if (freeList == nullptr) return ::new LinkNode;
	LinkNode* temp = freeList;
	freeList = freeList->next;
	return temp;
}

template <typename Elem>
void LinkList<Elem>::LinkNode::operator delete(void* ptr) {
	static_cast<LinkNode*>(ptr)->next = freeList;
	freeList = static_cast<LinkNode*>(ptr);
}

template <typename Elem>
bool LinkList<Elem>::insert(const Elem& item) {
	fence->next = new LinkNode(item, fence, fence->next);
	if (fence->next->next != nullptr)
		fence->next->next->prev = fence->next;
	if (tail == fence) tail = fence->next;
	rightCnt++;
	return true;
}

template <typename Elem>
bool LinkList<Elem>::append(const Elem& item) {
	tail = tail->next = new LinkNode(item, tail, nullptr);
	rightCnt++;
	return true;
}

template <typename Elem>
bool LinkList<Elem>::remove(Elem& it) {
	if (fence->next == nullptr) return false;
	it = fence->next->element;
	LinkNode* nodeTemp = fence->next;
	if (nodeTemp->next != nullptr) nodeTemp->next->prev = fence;
	else tail = fence;
	fence->next = nodeTemp->next;
	delete nodeTemp;
	rightCnt--;
	return true;
}

template <typename Elem>
void LinkList<Elem>::prev() {
	if (fence != head) {
		fence = fence->prev;
		leftCnt--;
		rightCnt++;
	}
}

template <typename Elem>
bool LinkList<Elem>::setPos(int pos) {
	if (pos < 0 || pos > rightCnt + leftCnt) return false;
	fence = head;
	for (int i = 0; i < pos; ++i) fence = fence->next;
	return true;
}

template <typename Elem>
void LinkList<Elem>::print() const {
	LinkNode* temp = head;
	cout << "< ";
	while (temp != fence) {
		cout << temp->next->element << " ";
		temp = temp->next;
	}
	cout << "| ";
	while (temp->next != nullptr) {
		cout << temp->next->element << " ";
		temp = temp->next;
	}
	cout << ">\n";
}

