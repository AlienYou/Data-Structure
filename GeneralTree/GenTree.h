#pragma once

#include "book.h"
//左子节点\右兄弟节点表示法
template <typename E>
class GTNode {
private:
	E element;
	GTNode<E>* paren;
	GTNode<E>* leftChild;
	GTNode<E>* rightSib;
public:
	GTNode(const E& value) {
		paren = leftChild = rightSib = nullptr;
		element = value;
	}

	GTNode(const E& value, GTNode<E>* par, GTNode<E>* leftc, GTNode<E>* rights) {
		element = value;
		paren = par;
		leftChild = leftc;
		rightSib = rights;
	}

	~GTNode() { }

	E value() { return element; }

	bool isLeaf() { return leftChild == nullptr; }
	
	GTNode* parent() { return paren; }

	GTNode* leftmostChild() { return leftChild; }

	GTNode* rightSibling() { return rightSib; }

	void setValue(E&) { element = value; }

	void insertFirst(GTNode<E>* n) { 
		n->rightSib = leftChild;
		n->paren = this;
		leftChild = n;
	}

	void insertNext(GTNode<E>* n) {
		n->rightSib = rightSib;
		n->paren = paren;
		rightSib = n;
	}

	void removeFirst() {
		if (leftChild == nullptr) return;
		GTNode<E>* temp = leftChild;
		leftChild = leftChild->rightSib;
		delete temp;
	}

	void removeNext() {
		if (rightSib == nullptr) return;
		GTNode<E>* temp = rightSib;
		rightSib = rightSib->rightSib;
		delete temp;
	}
};

template <typename E>
class GenTree {
private:
	GTNode<E>* rt;

	void printHelp(GTNode<E>* root) {
		if (root->isLeaf()) cout << "Leaf: ";
		else cout << "Internal: ";
		cout << root->value() << "\n";
		
		for (GTNode<E>* temp = root->leftmostChild(); temp != nullptr; temp = temp->rightSibling())
			printHelp(temp);
	}
public:
	GenTree() { rt = nullptr; }

	~GenTree() { rt = nullptr; }

	void clear() { rt = nullptr; }

	GTNode<E>* root() { return rt; }

	void newRoot(const E& value, GTNode<E>* first, GTNode<E>* sib) {
		clear();
		rt = new GTNode<E>(value, nullptr, first, sib);
	}

	void print() { printHelp(rt); }
};
