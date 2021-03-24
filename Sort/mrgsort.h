#pragma once
#include "book.h"
#include "Compare.h"

template <typename E, typename Comp>
void mergesort(E A[], E temp[], int left, int right) {
	if (left == right)	return;
	int mid = (left + right) / 2;
	mergesort<E, Comp>(A, temp, left, mid);
	mergesort<E, Comp>(A, temp, mid + 1, right);

	for (int i = left; i <= right; ++i)
		temp[i] = A[i];
	int i1 = left, i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1)
			A[curr] = temp[i2++];
		else if (i2 > right)
			A[curr] = temp[i1++];
		else if (Comp::prior(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else
			A[curr] = temp[i2++];
	}
}
template <typename E, typename Comp>
void mrgsort(E A[], int n) {
	static E* temp = nullptr;
	if (temp == nullptr) temp = new E[n];
	mergesort<E, Comp>(A, temp, 0, n - 1);
}

template <typename E, typename Comp>
void mergesort2(E A[], E temp[], int left, int right) {
	if (left == right) return;
	int i, j, k, mid = (left + right) / 2;
	mergesort2<E, Comp>(A, temp, left, mid);
	mergesort2<E, Comp>(A, temp, mid + 1, right);
	
	for (i = left; i <= mid; ++i) temp[i] = A[i];
	for (j = 1; j <= right - mid; ++j) temp[right - j + 1] = A[j + mid];
	for (i = left, j = right, k = left; k <= right; ++k) {
		if (Comp::prior(temp[i], temp[j])) A[k] = temp[i++];
		else A[k] = temp[j--];
	}
}

template <typename E, typename Comp>
void mrgsort2(E A[], int n) {
	static E* temp = nullptr;
	if (temp == nullptr) temp = new E[n];
	mergesort2<E, Comp>(A, temp, 0, n - 1);
}
