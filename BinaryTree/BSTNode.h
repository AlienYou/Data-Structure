#pragma once
#include "BinNode.h"

template <typename Key, typename E>
class BSTNode : public BinNode<E> {
public:
	BSTNode() { lc = rc = nullptr; }
	BSTNode(Key k, E e, BSTNode* l = nullptr, BSTNode* r = nullptr) { this->k = k; it = e; lc = l; rc = r; }
	~BSTNode() { }

	E& element() { return it; }
	void setElement(const E& e) { it = e; };
	Key& key() { return k; }
	void setKey(const Key& k) { this->k = k; }

	BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = dynamic_cast<BSTNode*>(b); }
	BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = dynamic_cast<BSTNode*>(b); }

	bool isLeaf() { return (lc == nullptr) && (rc == nullptr); }
private:
	Key k;
	E it;
	BSTNode* lc;
	BSTNode* rc;
};
