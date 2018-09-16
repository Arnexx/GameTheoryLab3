#include "TreeGenerator.h"



TreeGenerator::TreeGenerator()
{
}

TreeGenerator::TreeGenerator(int playersCount, int maxStratCount, int maxGain, int minGain, int maxDepth, int leafProb)
{
	this->playersCount = playersCount;
	this->maxStratCount = maxStratCount;
	this->maxGain = maxGain;
	this->minGain = minGain;
	this->maxDepth = maxDepth;
	this->leafProb = leafProb;
}

GameTree TreeGenerator::generateTree()
{
	GameNode* root = new GameNode(1, nullptr, false, 0);
	deque<GameNode*> nodeQueue;
	nodeQueue.push_back(root);
	int i = 0;
	while (nodeQueue.size())
	{
		GameNode* node = nodeQueue[0];
		nodeQueue.pop_front();
		node->name = "a" + to_string(i);
		fillNode(node);
		if (node->layer <= maxDepth)
		{
			for (auto child : node->children)
				nodeQueue.push_back(child);
		}
		i++;
	}
	return *(new GameTree(root));
}

void TreeGenerator::fillNode(GameNode* node)
{
	if (node->parent)
		node->layer = node->parent->layer + 1;

	node->player = (node->layer % playersCount) + 1;

	if ( ((rand() % 100)/0.01) < leafProb || node->layer >= maxDepth)
		node->isLeaf = true;

	if (node->isLeaf)
	{
		node->gaines.push_back(vector<int>());
		for (int i = 0; i < playersCount; i++)
			node->gaines[0].push_back(rand() % (maxGain - minGain) + minGain);
	}
	else
	{
		int stratCount = rand() % (maxStratCount - 2) + 2;
		for (int i = 0; i < stratCount; i++)
			node->children.push_back(new GameNode(0, node, false, 0, string()));
	}
}


TreeGenerator::~TreeGenerator()
{
}
