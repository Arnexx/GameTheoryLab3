#pragma once
#include "GameTree.h"
#include "GameNode.h"
class TreeGenerator
{
private:
	int playersCount; 
	int maxStratCount;
	int maxGain;
	int minGain;
	float leafProb;
	int maxDepth;
public:
	TreeGenerator();
	TreeGenerator(int playersCount, int maxStratCount, int maxGain, int minGain, int maxDepth, int leafProb);
	GameTree generateTree();
	void fillNode(GameNode* node);
	~TreeGenerator();
};

