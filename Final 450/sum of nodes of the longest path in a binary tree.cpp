#include <bits/stdc++.h>
using namespace std;

//Building a tree node having left and right pointers set to null initially
struct Node
{
Node* left;
Node* right;
int data;
//constructor to set the data of the newly created tree node
Node(int element){
	data = element;
	this->left = nullptr;
	this->right = nullptr;
}
};

int longestPathLeaf(Node* root){

/* structure to store current Node,it's level and sum in the path*/
struct Element{
	Node* data;
	int level;
	int sum;
};

/*
	maxSumLevel stores maximum sum so far in the path
	maxLevel stores maximum level so far
*/
int maxSumLevel = root->data,maxLevel = 0;

/* queue to implement level order traversal */

list<Element> que;
Element e;

/* Each element variable stores the current Node, it's level, sum in the path */

e.data = root;
e.level = 0;
e.sum = root->data;

/* push the root element*/
que.push_back(e);

/* do level order traversal on the tree*/
while(!que.empty()){

	Element front = que.front();
	Node* curr = front.data;
	que.pop_front();
	
	/* if the level of current front element is greater than the maxLevel so far then update maxSum*/
	if(front.level > maxLevel){
		maxSumLevel = front.sum;
		maxLevel = front.level;
	}
	/* if another path competes then update if the sum is greater than the previous path of same height*/
	else if(front.level == maxLevel && front.sum > maxSumLevel)
		maxSumLevel = front.sum;

	/* push the left element if exists*/
	if(curr->left){
		e.data = curr->left;
		e.sum = e.data->data;
		e.sum += front.sum;
		e.level = front.level+1;
		que.push_back(e);
	}
	/*push the right element if exists*/
	if(curr->right){
		e.data = curr->right;
		e.sum = e.data->data;
		e.sum += front.sum;
		e.level = front.level+1;
		que.push_back(e);
	}
}

/*return the answer*/
return maxSumLevel;
}
//Helper function
int main() {

Node* root = new Node(4);		
root->left = new Node(2);		
root->right = new Node(5);	
root->left->left = new Node(7);
root->left->right = new Node(1);
root->right->left = new Node(2);
root->right->right = new Node(3);
root->left->right->left = new Node(6);

cout << longestPathLeaf(root) << "\n";
	
return 0;
}
