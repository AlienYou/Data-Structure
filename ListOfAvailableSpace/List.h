#pragma once
/*
*	该线性表具有"栅栏",分离出左区间和右区间
*	需要注意一下c++不支持对模板类的分离式编译
* 
*/

#include <iostream>
using std::cout;
using std::endl;

static constexpr int DefaultListSize = 0;

template <typename Elem>
class List {
public:
	//重新初始化线性表
	virtual void clear() = 0;
	
	virtual bool insert(const Elem&) = 0;

	virtual bool append(const Elem&) = 0;

	virtual bool remove(Elem&) = 0;

	virtual void setStart() = 0;

	virtual void setEnd() = 0;

	virtual void prev() = 0;

	virtual void next() = 0;

	virtual int leftLength() const = 0;

	virtual int rightLength() const = 0;

	virtual bool setPos(int pos) = 0;

	virtual bool getValue(Elem&) const = 0;

	virtual void print() const = 0;
};
