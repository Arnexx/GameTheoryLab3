#pragma once
#include <deque>
#include <iostream>
#include "GameNode.h"

class GameTree
{
private:
	GameNode* root;
public:
	GameTree();
	GameTree(GameNode* root);
	vector<GameNode*> getLeafs();
	vector<GameNode*> getNodes();
	void solveGame();
	string drawGraph();
	~GameTree();
};

