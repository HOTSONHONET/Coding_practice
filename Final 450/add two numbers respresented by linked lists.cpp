// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {

        Node* prev = NULL;
        // Create 3 stacks
        stack<Node*> s1, s2, s3;

        while (first != NULL) {s1.push(first); first = first->next;}
        while (second != NULL) {s2.push(second); second = second->next;}
        
        int carry = 0;

        while (!s1.empty() && !s2.empty())
        {
            int sum = s1.top()->data + s2.top()->data + carry;
            
            Node* temp = new Node(sum % 10);
            s3.push(temp);
            carry = (sum > 9) ? 1 : 0;
            
            s1.pop();  s2.pop();
        }
        
        while (!s1.empty()) {
            int sum = carry + s1.top()->data;
            Node* temp = new Node(sum % 10);
            s3.push(temp);
            carry = (sum > 9) ? 1 : 0;
            
            s1.pop();
        }
        while (!s2.empty()) {
            int sum = carry + s2.top()->data;
            Node* temp = new Node(sum % 10);
            s3.push(temp);
            carry = (sum > 9) ? 1 : 0;
            
            s2.pop();
        }

        if (carry == 1) {
            Node* temp = new Node(1);
            s3.push(temp);
        }

        if (!s3.empty()) prev = s3.top();
        
        while (!s3.empty()) 
        {
            Node* temp = s3.top();
            s3.pop();
            
            temp->next = (s3.size() == 0) ? NULL : s3.top();
        }
        
        return prev;

    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends