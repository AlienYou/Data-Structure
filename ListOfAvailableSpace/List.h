#pragma once
/*
*	�����Ա����"դ��",������������������
*	��Ҫע��һ��c++��֧�ֶ�ģ����ķ���ʽ����
* 
*/

#include <iostream>
using std::cout;
using std::endl;

static constexpr int DefaultListSize = 0;

template <typename Elem>
class List {
public:
	//���³�ʼ�����Ա�
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
