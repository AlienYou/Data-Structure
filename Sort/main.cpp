﻿#include <iostream>
#include "insort.h"
#include "bubsort.h"
#include "selsort.h"
#include "shsort.h"
#include "qsort.h"
#include "mrgsort.h"
#include "heapsort.h"

int QUICKTHRESHOLD = 9;
int RADIXTHRESHOLD = 5;

#define ArrayLength(A) (sizeof(A) / sizeof(A[0]))

typedef void (*SP)(int*, int);

void checkSortedArray(int A[], int L) {
    for (int i = 1; i < L; ++i) {
        if (A[i] < A[i - 1])
            cout << "ERROR!!!" << "i=" << i << " value: " << A[i] << endl;
    }
}

void testArray(SP sp) {
    int A[] = { 1, 2, 3, 4, 5 };
    int B[] = { 5, 4, 3, 2, 1 };
    int C[] = { 3, 1, 4, 2, 5 };
    
    sp(A, ArrayLength(A));
    sp(B, ArrayLength(B));
    sp(C, ArrayLength(C));
    
    checkSortedArray(A, ArrayLength(A));
    checkSortedArray(B, ArrayLength(B));
    checkSortedArray(C, ArrayLength(C));
}

int main()
{
    SP sp = inssort<int, minintCompare>;
    cout << "Inssort: " << endl;
    testArray(sp);
    cout << "Bubsort: " << endl;
    sp = bubsort<int, minintCompare>;
    testArray(sp);
    cout << "Selsort: " << endl;
    sp = selsort<int, minintCompare>;
    testArray(sp);
    cout << "Shellsort(pow of 2): " << endl;
    sp = shellsort<int, minintCompare>;
    testArray(sp);
    cout << "Shellsort(incr is 3): " << endl;
    sp = shellsort3<int, minintCompare>;
    testArray(sp);
    cout << "Qsort: " << endl;
    sp = quicksort<int, minintCompare>;
    testArray(sp);
    cout << "Qsort in threshold: " << endl;
    sp = quicksortThreshold<int, minintCompare>;
    testArray(sp);
    cout << "mergesort: " << endl;
    sp = mrgsort<int, minintCompare>;
    testArray(sp);
    cout << "mergesort2: " << endl;
    sp = mrgsort2<int, minintCompare>;
    testArray(sp);
    cout << "heapsort: " << endl;
    sp = heapsort<int, maxintCompare>;
    testArray(sp);
    cout << "heapsort with fewer function calls: " << endl;
    sp = heapsort2<int, minintCompare>;
    testArray(sp);
}
