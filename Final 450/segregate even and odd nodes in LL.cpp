// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        vector<Node*> even, odd;
        if(N == 1) return head;
        Node* tmp = head;
        while(tmp)
        {
            if(tmp->data%2) odd.push_back(tmp);
            else even.push_back(tmp);
            tmp = tmp->next;
        }
        
        if(even.size() == 0 ||  odd.size() == 0) return head;

        for(int i = 1; i<even.size(); i++) even[i-1]->next = even[i];
        even[even.size() -1]->next = NULL;
        
        for(int i = 1; i<odd.size(); i++) odd[i-1]->next = odd[i];
        odd[odd.size() -1]->next = NULL;

        if(even.size() == 0) return odd[0];
        
        even[even.size() - 1]->next = odd[0];
        return even[0];

    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends