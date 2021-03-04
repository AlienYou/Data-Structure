#pragma once
#include "Dictionary.h"
#include "SAList.h"

template <class Key, class Elem, class KEComp, class EEComp>
class SALdict : public Dictionary<Key, Elem, KEComp, EEComp>{
public:
	SALdict(int size = DefaultListSize) { list = new SAList<Elem, EEComp>(size); }
	~SALdict() { delete list; }
	void clear() { list->clear(); }
	bool insert(const Elem& e) { return list->insert(e); }
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
		int l = -1;
		int r = list->leftLength() + list->rightLength();
		while (l + 1 != r) {
			int i = l + ((r - l) >> 1);
			list->setPos(i);
			list->getValue(e);
			if (KEComp::less(k, e)) r = i;
			if (KEComp::equal(k, e)) return true;
			if (KEComp::greater(k, e)) l = i;
		}
		return false;
	}
	int size() { return list->leftLength() + list->rightLength(); }
private:
	SAList<Elem, EEComp>* list;
};
