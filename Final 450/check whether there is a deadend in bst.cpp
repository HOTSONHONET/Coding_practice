// { Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void traverse(Node *root, unordered_set<int> &umap, unordered_set<int> &ln)
{
    if(!root) return;
    if(root->left == NULL && root->right == NULL){
        ln.insert(root->data);
        return;    
    }
    umap.insert(root->data);
    traverse(root->left, umap, ln);
    traverse(root->right, umap, ln);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_set<int> umap, ln;
    umap.insert(0); // to handle root->val == 1
    traverse(root, umap, ln);

    for(auto i: ln){
        // cout<<i<<endl;
        if(umap.find(i-1) != umap.end() && umap.find(i+1) != umap.end()){
            return true;
        }
    }
    
    return false;
}