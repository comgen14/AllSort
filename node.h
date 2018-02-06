#pragma once
#include <string>
using namespace std;

class node
{
private:
	node* parentPtr;
	node** childernPtr;
	string currentState;
	bool root = false;
	int costToMove = 0;
public:
	node();
	node(string);
	node(string, bool);
	~node();
	string GetCurrentState();
	void SetParent(node*);
	void SetChildren(node*);
};

