#pragma once

#include "book.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

typedef char Operator;
typedef string Operand;


template <typename E> 
class BinNode {
public:
	virtual ~BinNode() { }

	virtual E& element() = 0;

	virtual void setElement(const E&) = 0;

	virtual BinNode* left() const = 0;

	virtual void setLeft(BinNode*) = 0;

	virtual BinNode* right() const = 0;
	
	virtual void setRight(BinNode*) = 0;

	virtual bool isLeaf() = 0;
};
