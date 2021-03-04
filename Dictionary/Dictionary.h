#pragma once

/*
*	Key: 关键码
*	Elem: 数据元素
*	KEComp: 关键码对应与元素相对
*	EEComp: 元素之间比较
*/
template <class Key,  class Elem, class KEComp, class EEComp>
class Dictionary {
public:
	virtual void clear() = 0;

	virtual bool insert(const Elem&) = 0;

	virtual bool remove(const Key&, Elem&) = 0;

	virtual bool removeAny(Elem&) = 0;

	virtual bool find(const Key&, Elem&) const = 0;

	virtual int size() = 0;
};
