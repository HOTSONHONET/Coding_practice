// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    map<int, bool> visited;
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        
        if(head == NULL and head->next == NULL) return head;
        vector<Node *> v;
        map<int, int> visited;
        Node *tmp = head;
        while(tmp != NULL)
        {
            if(visited[tmp->data] == 0){
                v.push_back(tmp);
                visited[tmp->data] = 1;
            }
            
            tmp = tmp->next;
        }
        
        // cout<<v.size()<<endl;
        
        for(int i = 0; i<v.size() - 1; i++)
        {
            v[i]->next = v[i+1];
        }
        
        v[v.size() - 1]->next = NULL;
        
        return v[0];
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends