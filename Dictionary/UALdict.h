#pragma once
#include "Dictionary.h"
#include "ArrayList.h"

/*
* unsorted array list 
*/
template <class Key, class Elem, class KEComp, class EEComp> 
class UALdict : public Dictionary<Key, Elem, KEComp, EEComp> {
public:
	UALdict(int size = DefaultListSize) { list = new ArrayList(size); }
	~UALdict() { delete list; }
	void clear() { delete list; }
	bool insert(const Elem& e) { return list->append(e); }
	bool remove(const Key& k, Elem& e) {
		for (list->setStart(); list->getValue(e); list->next()) {
			if (KEComp::equal(k, e)) {
				list->remove(e);
				return true;
			}
		}
		return false;
	}
	bool removeAny(Elem& e) {
		if (size() == 0) return false;
		list->setEnd();
		list->prev();
		list->remove(e);
		return true;
	}
	bool find(const Key& k, Elem& e) const {
		for (list->setStart(); list->getValue(e); list->next()) {
			if (KEComp::equal(k, e)) return true;
		}
		return false;
	}
	int size() { return list->leftLength() + list->rightLength(); }
private:
	ArrayList<Elem>* list;
};
