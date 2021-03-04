#pragma once
#include "ArrayList.h"

/*
*sorted array list
*/
template <class Elem, class Compare>
class SAList : protected ArrayList<Elem> {
public:
	SAList(int size = DefaultListSize) : ArrayList<Elem>(size) { }
	~SAList() { }
	bool insert(const Elem& e) {
		Elem cur;
		for (setStart(); getValue(cur); next()) {
			if (!Compare::less(cur, e))
				break;
		}
		return ArrayList<Elem>::insert(e);
	}
	ArrayList<Elem>::clear;
	ArrayList<Elem>::setStart;
	ArrayList<Elem>::setEnd;
	ArrayList<Elem>::prev;
	ArrayList<Elem>::next;
	ArrayList<Elem>::leftLength;
	ArrayList<Elem>::rightLength;
	ArrayList<Elem>::setPos;
	ArrayList<Elem>::getValue;
	ArrayList<Elem>::print;
};

