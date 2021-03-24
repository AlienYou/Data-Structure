#pragma once

#include "book.h"
#include "Compare.h"
#include "insort.h"

extern int QUICKTHRESHOLD;

template <typename E>
inline int findPivot(E A[], int left, int right) {
	return (left + right) / 2;
}

template <typename E, typename Comp>
inline int partition(E A[], int left, int right, E& pivot) {
	do {
		while (Comp::prior(A[++left], pivot));
		while (left < right && Comp::prior(pivot, A[--right]));
		swap(A, left, right);
	} while (left < right);
	return left;
}

template <typename E, typename Comp>
void myqsort(E A[], int left, int right) {
	if (left >= right) return;
	int pivotindex = findPivot(A, left, right);
	swap(A, pivotindex, right);
	int k = partition<E, Comp>(A, left - 1, right, A[right]);
	swap(A, k, right);
	myqsort<E, Comp>(A, left, k - 1);
	myqsort<E, Comp>(A, k + 1, right);
}

template <typename E, typename Comp>
void quicksort(E A[], int n) {
	myqsort<E, Comp>(A, 0, n - 1);
}

template <typename E, typename Comp>
void qsortInThreshold(E A[], int left, int right) {
	if ((right - left) <= QUICKTHRESHOLD) return;
	int pivotindex = findPivot(A, left, right);
	swap(A, right, pivotindex);
	int k = partition<E, Comp>(A, left - 1, right, A[right]);
	swap(A, k, right);
	qsortInThreshold<E, Comp>(A, left, k - 1);
	qsortInThreshold<E, Comp>(A, k + 1, right);
}

template <typename E, typename Comp>
void quicksortThreshold(E A[], int n) {
	qsortInThreshold<E, Comp>(A, 0, n - 1);
	inssort<E, Comp>(A, n);
}
