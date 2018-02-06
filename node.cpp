#include "node.h"

node::node()
{
}

node::node(string)
{
}


node::node(string s, bool b)
{
	currentState = s;
	root = b;
}

node::~node()
{
}

string node::GetCurrentState()
{
	return currentState;
}

void node::SetParent(node *)
{
}

void node::SetChildren(node *)
{
}
