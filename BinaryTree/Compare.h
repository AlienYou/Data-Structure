#pragma once

#include <string.h>
#include "book.h"

class getintKey {
public:
	static int key(int x) { return x; }
};

class getIntKey {
public:
	static int key(Int x) { return x.key(); }
};

class getIntsKey {
public:
	static int key(Int* x) { return x->key(); }
};

class IntIntCompare {
public:
	static bool lt(Int x, Int y) { return x.key() < y.key(); }
	static bool eg(Int x, Int y) { return x.key() == y.key(); }
	static bool gt(Int x, Int y) { return x.key() > y.key(); }
};

class IntsIntsCompare {
public:
	static bool lt(Int* x, Int* y) { return x->key() < y->key(); }
	static bool eg(Int* x, Int* y) { return x->key() == y->key(); }
	static bool gt(Int* x, Int* y) { return x->key() > y->key(); }
};

class maxIntCompare {
public:
	static bool prior(Int x, Int y) { return x.key() > y.key(); }
};

class maxIntsCompare {
public:
	static bool prior(Int* x, Int* y) { return x->key() > y->key(); }
};

class minIntCompare {
public:
	static bool prior(Int x, Int y) { return x.key() < y.key(); }
};

class minIntsCompare {
public:
	static bool prior(Int* x, Int* y) { return x->key() < y->key(); }
};

class minintCompare {
public:
	static bool prior(int x, int y) { return x < y; }
};

class maxintCompare {
public:
	static bool prior(int x, int y) { return x > y; }
};

class intintCompare { 
public:
	static bool lt(int x, int y) { return x < y; }
	static bool eq(int x, int y) { return x == y; }
	static bool gt(int x, int y) { return x > y; }
};

class CCCompare { 
public:
	static bool lt(char* x, char* y)
	{
		return strcmp(x, y) < 0;
	}
	static bool eq(char* x, char* y)
	{
		return strcmp(x, y) == 0;
	}
	static bool gt(char* x, char* y)
	{
		return strcmp(x, y) > 0;
	}
};

class getCKey {
public:
	static char* key(char* x) { return x; }
};

