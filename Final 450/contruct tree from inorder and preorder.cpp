// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

Node* newNode(int val)
{
    Node* node;
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

class Solution{
    public:
       int idx=0;
    Node* helper(int in[],int pre[], int s,int e)
    {
        
        if(s>e)
            return NULL;
        Node* root=new Node(pre[idx++]);
        if(s==e)
            return root;
        int i;
        for(i=s;i<=e;i++)
        {
            if(in[i]==root->data)
                break;
        }
        if(i<=e)
        {
            root->left=helper(in,pre,s,i-1);
            root->right=helper(in,pre,i+1,e);
        }
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return helper(in,pre,0,n-1);
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends