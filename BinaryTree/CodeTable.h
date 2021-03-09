#pragma once
#include "book.h"
#include <cstdio>
#include <cstring>

#include "Heap.h"
#include "huffnode.h"
#include "HuffTree.h"

#define MAXCODELEN 20
#define CODETABLELEN 100

template <typename E>
class CodeTable {
public:
	CodeTable(int size) {
		obs = new E[size];
		codes = new char* [size];
		for (int i = 0; i < size; ++i) {
			codes[i] = new char[MAXCODELEN + 1];
			for (int j = 0; j <= MAXCODELEN; ++j)
				codes[i][j] = '-';
			codes[i][MAXCODELEN] = '\0';
		}
		maxSize = size;
		currsize = 0;
	}

	void addObject(E& obj) {
		Assert(currSize < maxSize, "CodeTable is full!");
		obs[currsize++] = obj;
	}
	char* getCode(E obj) {
		for (int i = 0; i < currSize; ++i)
			if (obj == obs[i]) return codes[i];
		return nullptr;
	}
private:
	E* obs;
	char** codes;
	int currSize;
	int maxSize;
};

HuffTree<char>** TreeArray = nullptr;

template <typename E>
ostream& operator <<(ostream& s, HuffTree<E>* z) {
	return s << z->weight();
}

class minTreeComp {
public:
	static bool prior(HuffTree<char>* x, HuffTree<char>* y) {
		return x->weight() < y->weight();
	}
};

int read_freqs(CodeTable<char>* ct, FILE* fp) {
	char buff[100];
	char buff2[100];
	char* ptr;
	char* ptr2;
	int freq;

	Assert(fgets(buff, 99, fp) != nullptr, "Couldn't read chararcter count");
	ptr = buff;
	Assert(isdigit(*ptr) != 0, "Must be a digit here.");
	int count = atoi(ptr);
	TreeArray = new HuffTree<char>*[count];
	for (int i = 0; i < count; ++i) {
		Assert(fgets(buff, 99, fp) != nullptr, "Ran out of codes too early");
		for (ptr = buff; *ptr == ' '; ptr++);
		Assert(*ptr == ' ', "First char was not a quote mark.");
		for (ptr2 = buff2, ptr++; *ptr != '"'; ptr++)
			*ptr2++ = *ptr;
		*ptr2 = '\0';
		for (ptr++; *ptr == ' '; ptr++);
		Assert(isdigit(*ptr) != 0, "Must be a digit here.");
		freq = atoi(ptr);
		ct->addObject(buff2[0]);
		TreeArray[i] = new HuffTree<char>(buff2[0], freq);
	}
	return count;
}

template <typename E>
HuffTree<E>* buildHuff(HuffTree<E>** TreeArray, int count) {
	Heap<HuffTree<E>*, minTreeComp>* forest = new Heap<HuffTree<E>*, minTreeComp>(TreeArray, count, count);
	
	HuffTree<char>* temp1, temp2, * temp3 = nullptr;
	while (forest->size() > 1) {
		temp1 = forest->removeFirst();
		temp2 = forest->removeFirst();
		temp3 = new HuffTree<E>(temp1, temp2);
		forest->insert(temp3);
		delete temp1;
		delete temp2;
	}
	return temp3;
}

void decode(HuffTree<char>* theTree, char* code, char& msg, int cnt) {
	HuffNode<char>* currNode = theTree->root();
	while (!currNode->isLeaf()) {
		cnt++;
		if (code[cnt - 1] == '0') currNode = ((IntlNode<char>*)currNode)->left();
		else if (code[cnt - 1] == '1') currNode = ((IntlNode<char>*)currNode)->right();
		else Assert(false, "Bad code character");
	}
	msg = ((LeafNode<char>*)currNode)->val();
}

void buildCode(HuffNode<char>* root, CodeTable<char>* ct, char* prefix, int level, double& total) {
	if (root->isLeaf()) {
		cout << ((LeafNode<char>*)root)->val() << "\t" << prefix << "\n";
		strcpy(ct->getCode(((LeafNode<char>*)root)->val()), prefix);
		total += level * root->weight();
	}
	else {
		prefix[level] = '0';
		prefix[level + 1] = '\0';
		buildCode(((IntlNode<char>*)root)->left(), ct, prefix, level + 1, total);
		prefix[level] = '1';
		prefix[level + 1] = '\0';
		buildCode(((IntlNode<char>*)root)->right(), ct, prefix, level + 1, total);
		prefix[level] = '\0';
	}
}

void do_commands(HuffTree<char>* theTree, CodeTable<char>* theTable, FILE* fp) {
	int currChar;
	char buff[80];

	while (fgets(buff, 99, fp)) {
		if (strncmp(buff, "decode", 6) == 0) {
			for (currChar = 0; buff[currChar] != '"'; currChar++);
			cout << "Decode " << &buff[currChar++];
			while (buff[currChar] != '"') {
				int cnt = 0;
				char msg;
				decode(theTree, &buff[currChar], msg, cnt);
				cout << msg << endl;
				currChar += cnt;
			}
		}
		else if (strncmp(buff, "encode", 6) == 0) {
			for (currChar = 0; buff[currChar] != '"'; currChar++);
			cout << "Encode " << &buff[currChar++];
			for (; buff[currChar] != '"'; currChar++) {
				if (buff[currChar] == ' ') cout << ' ';
				else cout << theTable->getCode(buff[currChar]);
			}
		}
		cout << "\n";
	}
}
