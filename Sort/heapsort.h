#pragma once

#include "Heap.h"
#include "book.h"
#include "Compare.h"

template <typename E, typename Comp>
void heapsort(E A[], int n) {
	E maxval;
	Heap<E, Comp> h(A, n, n);
	for (int i = 0; i < n; ++i) {
		maxval = h.removeFirst();
	}
}

template <typename E, typename Comp>
void heapsort2(E A[], int n) {
	int size = n;
	int pos;
	for (int i = n / 2 - 1; i >= 0; --i) {
		pos = i;
		while (pos < n / 2) {
			int j = 2 * pos + 1;
			if (j + 1 < n && Comp::prior(A[j], A[j + 1])) ++j;
			if (!(Comp::prior(A[pos], A[j])))
				break;
			swap(A, pos, j);
			pos = j;
		}
	}

	for (n--; n > 0; --n) {
		swap(A, 0, n);
		pos = 0;
		while (pos < n / 2) {
			int j = pos * 2 + 1;
			while (j + 1 < n && Comp::prior(A[j], A[j + 1])) ++j;
			if (!(Comp::prior(A[pos], A[j])))
				break;
			swap(A, pos, j);
			pos = j;
		}
	}
}
