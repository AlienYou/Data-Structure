#pragma once

#include <iostream>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

static constexpr int DefaultSize = 10;

inline bool EVEN(int x) { return !(x & 1); }

inline bool ODD(int x) { return x & 1; }

void Assert(bool val, string s) {
	if (!val) {
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

template <typename E>
inline void swap(E A[], int i, int j) {
	E temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

inline void Randomize() { srand(1); }

inline int Random(int n) { return rand() % n; }

inline void swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
}

inline void swap(char* i, char* j) {
	char* temp = i;
	i = j;
	j = temp;
}


unsigned tstart = 0;

void setTime() { tstart = (unsigned)clock(); }

double getTime() {
	unsigned tCur = (unsigned)clock();
	return (double)(tCur - tstart) / (double)CLOCKS_PER_SEC;
}

class Int {
private:
	int val;
public:
	Int(int input = 0) { val = input; }

	int key() const { return val; }

	Int operator= (int input) { val = input; return val; }
};

ostream& operator<<(ostream& s, const Int& i) { return s << i.key(); }
ostream& operator<<(ostream& s, const Int* i) { return s << i->key(); }
