#pragma once
#include "huffnode.h"

template <typename E>
class HuffTree {
public:
	HuffTree(E& val, int freq) { Root = new LeafNode<E>(val, freq); }
	HuffTree(HuffTree<E>* l, HuffTree<E>* r) { Root = new IntlNode<E>(l->root(), r->root()); }
	~HuffTree() { }
	HuffNode<E>* root() { return Root; }
	int weight() { return Root->weight(); }
private:
	HuffNode<E>* Root;
};
