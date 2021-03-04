#pragma once
#include "List.h" 

template <typename Elem>
class ArrayList : public List<Elem> {
public:
	ArrayList(int size = DefaultListSize) {
		maxSize = size;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	~ArrayList() { delete[] listArray; }
	void clear() {
		delete[] listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	bool insert(const Elem&);
	bool append(const Elem&);
	bool remove(Elem&);
	void setStart() { fence = 0; }
	void setEnd() { fence = listSize; }
	void prev() { if (fence != 0) fence--; }
	void next() { if (fence <= listSize) fence++; }
	int leftLength() const { return fence; }
	int rightLength() const { return listSize - fence; }
	bool setPos(int pos) {
		if (pos >= 0 && pos <= listSize) fence = pos;
		return pos >= 0 && pos <= listSize;
	}
	bool getValue(Elem& it) const {
		if (rightLength() == 0) return false;
		else { it = listArray[fence]; return true; }
	}
	void print() const {
		int temp = 0;
		cout << "< ";
		while (temp < fence) cout << listArray[temp++] << " ";
		cout << "|";
		while (temp < listSize) cout << listArray[temp++] << " ";
		cout << ">\n";
	}
private:
	int maxSize;
	int listSize;
	int fence;
	Elem* listArray;
};

template <typename Elem>
bool ArrayList<Elem>::insert(const Elem& item) {
	if (listSize == maxSize) return false;
	for (int i = listSize; i > fence; --i) {
		listArray[i] = listArray[i - 1];
	}
	listArray[fence] = item;
	listSize++;
	return true;
}

template <typename Elem>
bool ArrayList<Elem>::append(const Elem& item) {
	if (listSize == maxSize) return false;
	listArray[listSize++] = item;
	return true;
}

template <typename Elem>
bool ArrayList<Elem>::remove(Elem& it) {
	if (rightLength() == 0) return false;
	it = listArray[fence];
	for (int i = fence; i < listSize - 1; ++i) {
		listArray[i] = listArray[i + 1];
	}
	listSize--;
	return true;
}
