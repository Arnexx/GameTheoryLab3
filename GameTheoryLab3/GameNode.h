#pragma once
#include <vector>
#include <string>

using namespace std;
class GameNode
{

public:
	GameNode();
	GameNode(int player, GameNode* parent, bool isLeaf = false, int layer = 0, string name = " ");
	bool checkChildrenGaines();
	vector<int> getChildrenGaines();
	int getMaxGain();
	void findOptimalChildern();
	bool isOptimal();
	~GameNode();

	bool isLeaf;
	vector<GameNode*> children;
	int player;
	GameNode* parent;
	int layer;
	string name;
	vector<GameNode*> optimalChildren;
	vector<vector<int>> gaines;

};

