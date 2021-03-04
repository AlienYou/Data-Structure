#pragma once
#include <string.h>

class Payroll {
public:
	int ID;
	char* name;
};

class IDCompare {
public:
	static bool less(Payroll& x, Payroll& y) { return x.ID < y.ID; }
	static bool equal(Payroll& x, Payroll& y) { return x.ID == y.ID; }
	static bool greater(Payroll& x, Payroll& y) { return x.ID == y.ID; }
};

class NameCompare {
public:
	static bool less(Payroll& x, Payroll& y) { return strcmp(x.name, y.name) < 0; }
	static bool equal(Payroll& x, Payroll& y) { return strcmp(x.name, y.name) == 0; }
	static bool greater(Payroll& x, Payroll& y) { return strcmp(x.name, y.name) > 0; }
};
