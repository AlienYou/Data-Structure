#pragma once
#include "BinNode.h"

class VarBinNodeTra {
public:
    virtual ~VarBinNodeTra() { }
    virtual bool isLeaf() = 0;
    virtual void traverse() const = 0;
};

class LeafNodeTra : public VarBinNodeTra {
public:
    LeafNodeTra(const Operand& val) { var = val; }
    bool isLeaf() { return true; }
    Operand value() const { return var; }
    void traverse() const { cout << "Leaf: " << value() << endl; }
private:
    Operand var;
};

class IntlNodeTra : public VarBinNodeTra {
public:
    IntlNodeTra(const Operator& op, VarBinNodeTra* l, VarBinNodeTra* r) { opx = op; left = l; right = r; }
    bool isLeaf() { return false; }
    VarBinNodeTra* leftChild() const { return left; }
    VarBinNodeTra* rightChild() const{ return right; }
    Operator value() const { return opx; }
    void traverse() const { 
        cout << "Internal: " << value() << endl; 
        if (leftChild() != nullptr) leftChild()->traverse();
        if (rightChild() != nullptr) rightChild()->traverse();
    }
private:
    VarBinNodeTra* left;
    VarBinNodeTra* right;
    Operator opx;
};

