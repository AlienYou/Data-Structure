#pragma once

#include "BinNode.h"

class VarBinNode {
public:
    virtual ~VarBinNode() { }
    virtual bool isLeaf() = 0;
};

class LeafNode : public VarBinNode {
public:
    LeafNode(const Operand& val) { var = val; }
    bool isLeaf() { return true; }
    Operand value() { return var; }
private:
    Operand var;
};

class IntlNode : public VarBinNode {
public:
    IntlNode(const Operator& op, VarBinNode* l, VarBinNode* r) { opx = op; left = l; right = r; }
    bool isLeaf() { return false; }
    VarBinNode* leftChild() { return left; }
    VarBinNode* rightChild() { return right; }
    Operator value() { return opx; }
private:
    VarBinNode* left;
    VarBinNode* right;
    Operator opx;
};

void traverse(VarBinNode* root) {
    if (root == nullptr) return;
    if (root->isLeaf())
        cout << "Leaf: " << dynamic_cast<LeafNode*>(root)->value() << endl;
    else {
        IntlNode* cur = dynamic_cast<IntlNode*>(root);
        cout << "Internal: " << cur->value() << endl;
        traverse(cur->leftChild());
        traverse(cur->rightChild());
    }
}