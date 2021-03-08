#pragma once

/*
*	Key: 关键码
*	Elem: 数据元素
*	KEComp: 关键码对应与元素相对
*	EEComp: 元素之间比较
*/
template <class Key,  class Elem>
class Dictionary {
private:
	void operator =(const Dictionary&) { }
	Dictionary(const Dictionary&) { }
public:
	Dictionary() { }

	virtual ~Dictionary() { }

	virtual void clear() = 0;

	virtual void insert(const Key& k, const Elem& e) = 0;

	virtual Elem remove(const Key& k) = 0;

	virtual Elem removeAny() = 0;

	virtual Elem find(const Key& k) const = 0;

	virtual int size() = 0;
};
