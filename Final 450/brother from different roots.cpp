// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
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

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
void inorder(Node* root, vector<int> &v, set<int> &s){
    if(!root) return;
    inorder(root->left, v, s);
    v.push_back(root->data);
    s.insert(root->data);
    inorder(root->right, v, s);
}
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    vector<int> v;
    set<int> s1, s2;
    inorder(root1, v, s1);
    inorder(root2, v, s2);
    
    sort(v.begin(), v.end());
    int l = 0, r = v.size()-1, cnt = 0;
    while(l<r){
          
        if((v[l] + v[r]) == x){
                if((s1.count(v[l])>0 && s2.count(v[r])>0) || (s2.count(v[l])>0 && s1.count(v[r])>0))
                { 
                    cnt++;
                }
                // cout<<v[l]<<"+"<<v[r]<<"="<<v[l] + v[r]<<",  x:"<<x<<endl;
                l++;
                r--;
        }
        
        else if((v[l] + v[r]) > x) r--;
        else l++;
                
    }
    
    return cnt;
    
}



