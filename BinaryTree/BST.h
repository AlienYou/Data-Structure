#pragma once

#include "BSTNode.h"
#include "Dictionary.h"

template <typename Key, typename E>
class BST : public Dictionary<Key, E> {
public:
	BST() { root = nullptr; nodeCount = 0; }
	~BST() { clearHelp(root); }

	void clear() { clearHelp(root); root = nullptr; nodeCount = 0; }
	void insert(const Key& k, const E& e) { 
		root = insertHelp(root, k, e);
		nodeCount++;
	}
	
	E remove(const Key& k) {
		E temp = findHelp(root, k);
		if (temp != NULL) {
			root = removeHelp(root, k);
			nodeCount--;
		}
		return temp;
	}

	E removeAny() {
		if (root == nullptr) Assert(root != nullptr, "Tree is empty\n");
		E temp = root->element();
		root = removeHelp(root, root->key());
		nodeCount--;
		return temp;
	}
	E find(const Key& k) const { return findHelp(root, k); }
	int size() { return nodeCount; }

	void print() {
		if (root == nullptr) cout << "BST is empty.\n";
		else printHelp(root, 0);
	}
private:
	BSTNode<Key, E>* root;
	int nodeCount;

	void clearHelp(BSTNode<Key, E>*);
	BSTNode<Key, E>* insertHelp(BSTNode<Key, E>*, const Key&, const E&);
	BSTNode<Key, E>* deleteMin(BSTNode<Key, E>*);
	BSTNode<Key, E>* getMin(BSTNode<Key, E>*);
	BSTNode<Key, E>* removeHelp(BSTNode<Key, E>*, const Key&);
	E findHelp(BSTNode<Key, E>*, const Key&) const;
	void printHelp(BSTNode<Key, E>*, int) const;
};

template <typename Key, typename E>
void BST<Key, E>::clearHelp(BSTNode<Key, E>* root) {
	if (root == nullptr) return;
	clearHelp(root->left());
	clearHelp(root->right());
	delete root;
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::insertHelp(BSTNode<Key, E>* root, const Key& k, const E& it) {
	if (root == nullptr) return new BSTNode<Key, E>(k, it, nullptr, nullptr);
	if (k < root->key())
		root->setLeft(insertHelp(root->left(), k, it));
	else
		root->setRight(insertHelp(root->right(), k, it));
	return root;
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::getMin(BSTNode<Key, E>* rt) {
	if (rt->left() == nullptr)
		return rt;
	return getMin(root->left());
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::deleteMin(BSTNode<Key, E>* rt) {
	if (rt->left() == nullptr)
		return rt->right();
	else {
		rt->setLeft(deleteMin(rt->left()));
		return rt;
	}
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::removeHelp(BSTNode<Key, E>* rt, const Key& k) {
	if (rt == nullptr) return nullptr;
	else if (k < rt->key())
		rt->setLeft(removeHelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removeHelp(rt->right(), k));
	else {
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == nullptr) {
			rt = rt->right();
			delete temp;
		}
		else if (rt->right() == nullptr) {
			rt = rt->left();
			delete temp;
		}
		else {
			BSTNode<Key, E>* temp = getMin(rt->right());
			rt->setElement(temp->element());
			rt->setKey(temp->key());
			rt->setRight(deleteMin(rt->right()));
			delete temp;
		}
	}
	return rt;
}

template <typename Key, typename E>
E BST<Key, E>::findHelp(BSTNode<Key, E>* root, const Key& k) const {
	if (root == nullptr) return NULL;
	if (k < root->key())
		return findHelp(root->left(), k);
	else if (k > root->key())
		return findHelp(root->right(), k);
	else return root->element();
}

template <typename Key, typename E>
void BST<Key, E>::printHelp(BSTNode<Key, E>* root, int level) const {
	if (root == nullptr) return;
	printHelp(root->left(), level + 1);
	for (int i = 0; i < level; ++i)
		cout << " ";
	cout << level << " " << root->key() << endl;
	printHelp(root->right(), level + 1);
}
