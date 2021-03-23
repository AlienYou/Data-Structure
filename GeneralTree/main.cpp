// GeneralTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "GenTree.h"
#include "ParPtrTree.h"

namespace GenTreeTest {
	void genTreeTest() {
	    GenTree<int> tree;
		GTNode<int>* ptr;
		GenTree<int> tree2;
		GTNode<int>* ptr2;

		tree.newRoot(1, nullptr, nullptr);
		ptr = tree.root();
		cout << "Print the tree with one node\n";
		tree.print();
		ptr->insertFirst(new GTNode<int>(2));
		cout << "Print the tree with two nodes\n";
		tree.print();
		ptr = ptr->leftmostChild();
		cout << "ptr now at node " << ptr->value() << "\n";
		ptr->insertNext(new GTNode<int>(3));
		cout << "Print the tree with three nodes\n";
		tree.print();
		ptr->insertNext(new GTNode<int>(4));
		cout << "Print the tree with four nodes\n";
		tree.print();
		ptr = ptr->rightSibling();
		cout << "ptr now at node " << ptr->value() << "\n";
		ptr->insertFirst(new GTNode<int>(5));
		cout << "Print the tree with 5 nodes\n";
		tree.print();

		tree2.newRoot(11, nullptr, nullptr);
		ptr2 = tree2.root();
		ptr2->insertFirst(new GTNode<int>(12));
		ptr2 = ptr2->leftmostChild();
		ptr2->insertNext(new GTNode<int>(13));
	}
}

namespace UNIONFIND {
	void unionFindTest() {
		ParPtrTree* ppt = new ParPtrTree(10);
		ppt->UNION(1, 2);
		cout << "Relationship of 0 and 1: \n";
		cout << ppt->differ(0, 1) << endl;
		cout << "Relationship of 2 and 1: \n";
		cout << ppt->differ(2, 1) << endl;
	}
}

int main()
{
	UNIONFIND::unionFindTest();
}
