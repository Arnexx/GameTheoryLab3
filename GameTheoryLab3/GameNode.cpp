#include "GameNode.h"



GameNode::GameNode()
{
}

GameNode::GameNode(int player, GameNode * parent, bool isLeaf, int layer, string name)
{
	this->player = player;
	this->parent = parent;
	this->isLeaf = isLeaf;
	this->layer = layer;
	this->name = name;		
}

bool GameNode::checkChildrenGaines()
{
	for (auto child : this->children)
	{
		if (!child->gaines.size())
			return false;
	}
	return true;
}

vector<int> GameNode::getChildrenGaines()
{
	vector<int> res;
	for (auto child : this->children)
		for (auto gain : child->gaines)
			res.push_back(gain[player - 1]);
	return res;
}

int GameNode::getMaxGain()
{
	vector<int> gains = getChildrenGaines();
	int maxVal = 0;
	for (int gain : gains)
	{
		if (gain > maxVal)
			maxVal = gain;
	}
	return maxVal;
}

void GameNode::findOptimalChildern()
{
	int maxGain = getMaxGain();
	bool flag = false;
	for(int i = 0; i < children.size(); i++)
		for(int j = 0; j < children[i]->gaines.size(); j++)
			if (children[i]->gaines[j][player - 1] == maxGain)
			{
				for (auto child : optimalChildren)
					if (children[i] == child)
						flag = true;
				if (!flag)
					optimalChildren.push_back(children[i]);
				gaines.push_back(children[i]->gaines[j]);
			}							
}

bool GameNode::isOptimal()
{
	GameNode* node = this;
	bool flag = false;

	while (node)
	{
		if(node->parent)
			for(auto child : node->parent->optimalChildren )
				if (node == child)
					flag = true;
		if (node->parent && !flag)
			return false;
		node = node->parent;
	}
	return true;
}


GameNode::~GameNode()
{
}
