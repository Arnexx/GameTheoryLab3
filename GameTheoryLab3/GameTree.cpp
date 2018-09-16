#include "GameTree.h"
using namespace std;


GameTree::GameTree()
{
}

GameTree::GameTree(GameNode* root)
{
	this->root = root;
}

vector<GameNode*> GameTree::getLeafs()
{
	vector<GameNode*> leafs;
	for (auto node : getNodes())
		if (node->isLeaf)
			leafs.push_back(node);

	return leafs;
}

vector<GameNode*> GameTree::getNodes()
{
	deque<GameNode*> nodeQueue;
	vector<GameNode*> res;
	GameNode* node;
	nodeQueue.push_back(root);

	while (nodeQueue.size())
	{
		node = nodeQueue[0];
		nodeQueue.pop_front();
		res.push_back(node);
		for (auto child : node->children)
			nodeQueue.push_back(child);
	}
	return res;
}

void GameTree::solveGame()
{
	deque<GameNode*> nodeQueue;
	GameNode* currentNode;
	for (auto leaf : getLeafs())
		nodeQueue.push_back(leaf);

	while (nodeQueue.size())
	{
		currentNode = nodeQueue[0];
		nodeQueue.pop_front();

		if (currentNode->gaines.size() && currentNode->parent)
		{
			nodeQueue.push_back(currentNode->parent);
			continue;
		}
		
		if (!currentNode->checkChildrenGaines())
		{
			nodeQueue.push_back(currentNode);
			continue;
		}
		currentNode->findOptimalChildern();
	}
}

string GameTree::drawGraph()
{
	string graph = "digraph G{";
	string nodeLabel;
	vector<string> COLORS = { "red", "green", "blue", "orange", "pink", "brown" , "yellow", "cyan"};
	for (auto node : getNodes())
	{
		if (node->isLeaf)
		{
			nodeLabel = "\n";
			for (auto x : node->gaines[0])
				nodeLabel += to_string(x);
		}
		else
		{
			nodeLabel = to_string(node->player);
		}
		graph += node->name + "[label=\"" + nodeLabel + "\"];";
	}
	for(auto node : getNodes())
		for (auto child : node->children)
			if (!child->isOptimal())
				graph += node->name + "->" + child->name + ";";

	int i = -1;
	
	for (auto leaf : getLeafs())
	{
		GameNode* node = leaf;
		if (leaf->isOptimal())
			i++;
		while (node && leaf->isOptimal())
		{
			if (node->parent)
			{
				string opt_way = node->parent->name + "->" + node->name + "[color=" + COLORS[i] + "]";
				cout << opt_way << endl;
				graph += opt_way;
			}
			node = node->parent;
		}
	}
	graph += '}';
	return graph;
}


GameTree::~GameTree()
{
}
