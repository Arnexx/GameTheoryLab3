#include <iostream>
#include <fstream>
#include "TreeGenerator.h"
using namespace std;



int main()
{
	TreeGenerator treeGen = TreeGenerator(3, 3, 10, -5, 4, 0.1);
	GameTree tree = treeGen.generateTree();
	ofstream fout;
	fout.open("out.txt");
	tree.solveGame();
	fout.write(tree.drawGraph().c_str(), tree.drawGraph().size());
	fout.close();
	system("pause");
	return 0;
}