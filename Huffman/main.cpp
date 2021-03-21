#include "Huffman.h"

int main()
{
	HuffTree<char>* theTree;
	CodeTable<char>* theTable = new CodeTable<char>(CODETABLELEN);
	
	char prefix[MAXCODELEN + 1];
	double total = 0;
	FILE* fp;

	Assert((fp = fopen("hufftest.huff", "rt")) != NULL, "No such file");

	cout << "Read frequencies\n";
	int count = read_freqs(theTable, fp);

	cout << "Build the tree\n";
	theTree = buildHuff<char>(TreeArray, count);

	cout << "Output the tree\n";
	buildCode(theTree->root(), theTable, prefix, 0, total);
	cout << "Average code length is " << total / (double)theTree->weight() << "\n";

	do_commands(theTree, theTable, fp);
	return 0;
}

