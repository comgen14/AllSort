#include <iostream>
#include <queue>
#include "node.h"

node* Expand(node &n) {
	string temp;
	int sizeN = n.GetCurrentState().size();
	node *tempArray = new node[sizeN - 1];
	int xPos;
	//this for loop finds the 'x' character in the string and marks it's postion
	for (int i = 0; i < sizeN; i++) {	
		if (n.GetCurrentState()[i] == 'x') {
			xPos = i;
			break;
		}
	}
	//this for loop generates all the children for node n
	int j = 0;
	for (int i = 0; i < sizeN; i++) {
		if (n.GetCurrentState()[i] == 'x')
		{
		}
		else
		{
			temp = n.GetCurrentState();
			temp[xPos] = temp[i];
			temp[i] = 'x';
			tempArray[j] = node(temp);
			tempArray[j].SetParent(&n);
			j++;
		}
	}
	n.SetChildren(tempArray);
	return tempArray;
}

bool loopTest() {
	return false;
}

bool SolutionTest(std::string state) {
	int size = state.size();
	bool crossedOver = false;
	for (int i = 0; i < size; i++) {
		if (state[i] == 'x')
			crossedOver = true;
		else if (crossedOver == false && state[i] != 'B')
			return false;
		else if (crossedOver == true && state[i] != 'W')
			return false;
	};
	return true;
}

void BreadthFirstSearch(std::string startState) {
	std::queue<node> leafQueue;
	node root = node(startState, true);
	node placeholder;
	node *tempChildren;
	leafQueue.push(root);
	while (1) {
		int sizeQ = leafQueue.size();
		for (int i = 0; i < sizeQ; i++) {
			if (SolutionTest(leafQueue.front().GetCurrentState())) {//check for solution
				break;
			}
			tempChildren = Expand(leafQueue.front());			//add children to queue
			for (int j = 0; j < startState.size() - 1/*tempChildren.size()*/; j++) {
				leafQueue.push(tempChildren[j]);
			}
			leafQueue.pop();									//pop the node
		}
		if (SolutionTest(leafQueue.front().GetCurrentState())) {//check for solution
			break;
		}
	}
	return;
}

int main(char *argv[], char *argw[]) {
	system("PAUSE");
	return 0;
}