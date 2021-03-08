#pragma once

/*
*	Key: �ؼ���
*	Elem: ����Ԫ��
*	KEComp: �ؼ����Ӧ��Ԫ�����
*	EEComp: Ԫ��֮��Ƚ�
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
