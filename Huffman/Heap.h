#pragma once
#include "book.h"

template <typename E, typename Comp>
class Heap {
public:
	Heap(E* h, int num, int max) {	heap = h; n = num; maxSize = max; buildHeap(); }
	int size() const { return n; }
	bool isLeaf(int pos) const { return (pos >= n / 2) && (pos < n); }
	int leftChild(int pos) const { return 2 * pos + 1; }
	int rightChild(int pos) const { return 2 * pos + 2; }
	int parent(int pos) const { return (pos - 1) >> 1; }
	void buildHeap() {
		for (int i = n / 2 - 1; i >= 0; --i) //n / 2 - 1的技巧可以从叶子节点数是内部节点数量 + 1推出
			siftdown(i);
	}

	void insert(const E& it) {
		Assert(n < maxSize, "Heap is full");
		int curr = n++;
		heap[curr] = it;
		while (curr != 0 && Comp::prior(heap[curr], heap[parent(curr)])) {
			swap(heap, curr, parent(curr));
			curr = parent(curr);
		}
	}

	E removeFirst() {
		Assert(n > 0, "Heap is empty");
		swap(heap, 0, --n);
		if (n != 0) siftdown2(0);
		return heap[n];
	}
	E remove(int pos) {
		Assert(pos >= 0 && pos < n, "Bad position");
		if (pos == n - 1) --n;
		else {
			while ((pos != 0) && Comp::prior(heap[pos], heap[parent(pos)])) {
				swap(heap, pos, parent(pos));
				pos = parent(pos);
			}
			if (n != 0) siftdown(pos);
		}
		return heap[n];
	}
private:
	E* heap;
	int maxSize;
	int n;

	void siftdown(int pos) {
		while (!isLeaf(pos)) {
			int j = leftChild(pos);
			int rc = rightChild(pos);
			if ((rc < n) && (Comp::prior(heap[rc], heap[j])))
				j = rc;
			if (Comp::prior(heap[pos], heap[j])) return;
			swap(heap, pos, j);
			pos = j;
		}
	}

	void siftdown2(int pos) {
		while (!isLeaf(pos)) {
			int j = leftChild(pos);
			int rc = rightChild(pos);
			if (rc < n && Comp::prior(heap[rc], heap[j]))
				j = rc;
			if (Comp::prior(heap[pos], heap[j])) return;
			swap(heap, pos, j);
			pos = j;
		}
	}
};
