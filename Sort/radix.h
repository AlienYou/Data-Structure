#pragma once
#include "book.h"
#include "Compare.h"

extern int RADIXTHRESHOLD;

int POW2[9] = { 1, 2, 4, 8, 16, 64, 128, 256 };

#define pow2(X) POW2[X]

template <typename E, typename getKey>
void radix(E A[], E B[], int n, int k, int r, int cnt[]) {
	int j;

	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r) {
		for (j = 0; j < r; ++j) cnt[j] = 0;
		
		for (j = 0; j < n; ++j) cnt[(getKey::key(A[j]) / rtoi) % r]++;

		for (j = 1; j < r; ++j) cnt[j] = cnt[j - 1] + cnt[j];

		for (j = n - 1; j >= 0; --j)
			B[--cnt[(getKey::key(A[j]) / rtoi) % r]] = A[j];

		for (j = 0; j < n; ++j) A[j] = B[j];
	}
}

template <typename E, typename Comp>
void radix(E A[], int n) {
	static E* temp = nullptr;
	static int* cnt = nullptr;
	Assert(RADIXTHRESHOLD > 0, "Need to set THRESHOLD");
	if (temp == nullptr) temp = new E[n];
	if (cnt == nullptr) cnt = new int[pow2(RADIXTHRESHOLD)];
	radix<E, Comp>(A, temp, n, (sizeof(E) * 8) / RADIXTHRESHOLD, pow2(RADIXTHRESHOLD), cnt);
}
