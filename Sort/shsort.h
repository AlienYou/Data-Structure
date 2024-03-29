#pragma once

#include "book.h"
#include "Compare.h"

template <typename E, typename Comp>
void inssort2(E A[], int n, int incr) {
	for (int i = incr; i < n; i += incr) {
		for (int j = i; (j >= incr) && Comp::prior(A[j], A[j - incr]); j -= incr)
			swap(A, j, j - incr);
	}
}

template <typename E, typename Comp>
void shellsort(E A[], int n) {
	for (int i = n / 2; i > 2; i /= 2) {
		for (int j = 0; j < i; ++j) {
			inssort2<E, Comp>(&A[j], n - j, i);
		}
	}
	inssort2<E, Comp>(A, n, 1);
}

template <typename E, typename Comp>
void shellsort3(E A[], int n) {
	int firstincr;
	for (firstincr = 1; firstincr <= n; firstincr = firstincr * 3 + 1);
	for (int i = firstincr / 3; i > 2; i /= 3) {
		for (int j = 0; j < i; ++j) {
			inssort2<E, Comp>(&A[j], n - j, i);
		}
	}
	inssort2<E, Comp>(A, n, 1);
}
