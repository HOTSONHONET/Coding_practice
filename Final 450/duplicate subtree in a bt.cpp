// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/



class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/

    string MARKER = "$";   
    unordered_set<string> subtrees;
     
    // This function returns empty string if tree
    // contains a duplicate subtree of size 2 or more.
    
    string dupSubUtil(Node *root)
    {
        string s = "";
     
        // If current node is NULL, return marker
        if (root == NULL)
            return s + MARKER;
     
        // If left subtree has a duplicate subtree.
        string lStr = dupSubUtil(root->left);
        if (lStr.compare(s) == 0)
        return s;
     
        // Do same for right subtree
        string rStr = dupSubUtil(root->right);
        if (rStr.compare(s) == 0)
        return s;
     
        // Serialize current subtree
        s = s + to_string(root->data) + lStr + rStr;
     
        // If current subtree already exists in hash
        // table. [Note that size of a serialized tree
        // with single node is 3 as it has two marker
        // nodes.
        if (s.length() > 3 && subtrees.find(s) != subtrees.end())
            return "";
     
        subtrees.insert(s);
        return s;
    }
    
    int dupSub(Node *root) {
         // code here
        string str = dupSubUtil(root);
 
        return (str.compare("") == 0);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends