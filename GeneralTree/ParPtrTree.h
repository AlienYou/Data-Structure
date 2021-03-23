#pragma once

#define ROOT -1

//UNION/FIND,并查集
class ParPtrTree {
private:
	int* array;
	int size;
	int FIND(int) const;
public:
	ParPtrTree(int);
	~ParPtrTree() { delete[] array; }
	void UNION(int, int);
	bool differ(int, int);
};

ParPtrTree::ParPtrTree(int sz) {
	size = sz;
	array = new int[sz];
	for (int i = 0; i < sz; ++i) array[i] = ROOT;
}

bool ParPtrTree::differ(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	return root1 != root2;
}

void ParPtrTree::UNION(int a, int b) {
	int root1 = FIND(a);
	int root2 = FIND(b);
	if (root1 != root2) array[root2] = root1;
}

//路径压缩
int ParPtrTree::FIND(int curr) const {
	if (array[curr] == ROOT) return curr;
	array[curr] = FIND(array[curr]);
	return array[curr];
}
