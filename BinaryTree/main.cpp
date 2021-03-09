// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "VarBinNode.h"
#include "VarBinNodeTraVersion.h"
#include "BST.h"
#include "Heap.h"
#include "Compare.h"

namespace TreeTest {
	void testTree() {
		VarBinNode* temp1;
		VarBinNode* temp2;
		VarBinNode* root;
		string string1 = "Hello1";
		string string2 = "Another string";
		temp1 = new LeafNode(string1);
		temp2 = new LeafNode(string2);
		root = new IntlNode('+', temp1, temp2);
		traverse(root);
	}
}

namespace TreeTraveseTest {
	void testTreeTra() {
		VarBinNodeTra* temp1;
		VarBinNodeTra* temp2;
		VarBinNodeTra* root;
		string string1 = "Hello1";
		string string2 = "Another string";
		temp1 = new LeafNodeTra(string1);
		temp2 = new LeafNodeTra(string2);
		root = new IntlNodeTra('+', temp1, temp2);
		root->traverse();
	}
}

namespace BSTTest {
	void testBST() {
		BST<int, Int*> tree;
		Int* it;
		
		cout << "Size: " << tree.size() << "\n";
		tree.insert(100, new Int(100));
		it = tree.remove(10);
		tree.print();
		cout << "Size: " << tree.size() << "\n";
		tree.clear();
		cout << "Cleared.\n";
		cout << "Size: " << tree.size() << "\n";
		tree.insert(15, new Int(15));
		cout << "Size: " << tree.size() << endl;
		if ((it = tree.find(20)) != NULL)
			cout << "Found " << it << endl;
		else
			cout << "No key 20\n";
		if ((it = tree.find(15)) != NULL)
			cout << "Found " << it << endl;
		else cout << "No key 15\n";
		tree.print();
		if ((it = tree.remove(20)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 20\n";
		cout << "Now, insert 20\n";
		tree.insert(20, new Int(20));
		tree.print();
		if ((it = tree.remove(20)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 20\n";
		tree.print();
		tree.insert(700, new Int(700));
		cout << "Size: " << tree.size() << "\n";
		tree.insert(350, new Int(350));
		tree.insert(201, new Int(201));
		tree.insert(170, new Int(170));
		tree.insert(164, new Int(164));
		tree.insert(1000, new Int(1000));
		tree.print();

		if ((it = tree.find(1000)) != NULL)
			cout << "Found " << it << endl;
		else cout << "No key 1000\n";
		if ((it = tree.find(999)) != NULL)
			cout << "Found " << it << endl;
		else cout << "No key 999\n";

		cout << "Now do some delete tests.\n";

		tree.print();
		if ((it = tree.remove(15)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 15\n";
		tree.print();
		if ((it = tree.remove(151)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 151\n";
		tree.print();
		if ((it = tree.remove(151)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 151\n";
		if ((it = tree.remove(700)) != NULL)
			cout << "Removed " << it << endl;
		else cout << "No key 700\n";
		tree.print();
		tree.clear();
		tree.print();
		cout << "Size: " << tree.size() << "\n";

		cout << "Finally, test iterator\n";
		tree.insert(3500, new Int(3500));
		tree.insert(2010, new Int(2010));
		tree.insert(1700, new Int(1700));
		tree.insert(1510, new Int(1510));
		tree.insert(9000, new Int(9000));
		tree.insert(9500, new Int(9500));
		tree.insert(100, new Int(100));
		tree.print();
		
		cout << "Start:\n";
		Int* temp;
		while (tree.size() > 0) {
			temp = tree.removeAny();
			cout << temp << " ";
		}
		cout << "\n";
	}
}

namespace HeapTest {
	template <typename E>
	void permute(E A[], int n) {
		for (int i = n; i > 0; --i)
			swap(A, i - 1, Random(i));
	}

	void testHeap() {
		int i, j;
		int n = 20;
		Int* A[20];
		Int* B[20];
		Int C[10] = { 73, 6, 57, 88, 60, 34, 83, 72, 48, 85 };
		Heap<Int*, maxIntsCompare> BH(B, 0, 20);
		Heap<Int, maxIntCompare> test(C, 10, 10);

		Randomize();

		for (int i = 0; i < n; ++i) {
			A[i] = new Int(i);
		}
		permute(A, n);

		cout << "Initial values: " << endl;;
		for (int i = 0; i < n; ++i) {
			cout << A[i] << " ";
			if (i == 9) cout << "\n";
		}
		cout << "\n\n";

		Heap<Int*, maxIntsCompare> AH(A, n, 20);
		Int* AHval = nullptr;

		for (int i = 0; i < AH.size(); ++i) {
			cout << A[i] << " ";
			if (i == 9) cout << "\n";
		}
		cout << "\n\n";

		AHval = AH.removeFirst();
		cout << "Max value: " << AHval << "\n";

		for (int i = 0; i < AH.size(); ++i) {
			cout << A[i] << " ";
			if (i == 9) cout << "\n";
		}
		cout << "\n\n";

		AHval = AH.removeFirst();
		cout << "Max value: " << AHval << "\n";

		for (int i = 0; i < AH.size(); ++i) {
			cout << A[i] << " ";
			if (i == 9) cout << "\n";
		}
		cout << "\n\n";

		AHval = AH.remove(2);
		cout << "Remove value: " << AHval << "\n";

		for (int i = 0; i < AH.size(); ++i) {
			cout << A[i] << " ";
			if (i == 9) cout << "\n";
		}
		cout << "\n";
		
		for (int i = 0; i < 10; ++i)
			cout << C[i] << " ";
		cout << "\n";

		Int Testval;
		for (j = 0; j < 10; ++j) {
			Testval = test.removeFirst();
			for (int i = 0; i < 10; ++i)
				cout << C[i] << " ";
			cout << "\n";
		}
	}
}

int main()
{
	HeapTest::testHeap();
	return 0;
}

