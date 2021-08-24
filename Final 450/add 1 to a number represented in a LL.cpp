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
        cout << node->data; 
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

class Solution
{
    public:
    bool carry = false;
    void allOneUtil(Node *head, bool &carry)
    {   
        if(head->next == NULL)
        {
            head->data = (head->data == 9) ? 0 : head->data + 1;
            if(head->data == 0) carry = true;
            return;
        }
        
        else{
            int prev_data = head->data;
            allOneUtil(head->next, carry);
            // cout<<"[Before Adding] head : "<<head->data<<", Next : "<<prev->data<<endl;
            head->data = (head->data + ((carry) ? 1 : 0))%10;
            carry = (prev_data > 0 and head->data % 10 == 0) ? true : false;
            // cout<<head->data<<" "<<((head->data%10) == 0)<<endl;
        }
        
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        allOneUtil(head, carry);
        if(carry)
        {
            Node* tmp = new Node(1);
            tmp->next = head;
            return tmp;
        }
        return head;
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends