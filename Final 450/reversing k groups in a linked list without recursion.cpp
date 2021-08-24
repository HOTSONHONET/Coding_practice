/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1) return head;
        
        int n = 0;
        ListNode* tmp = head;
        while(tmp){n++; tmp = tmp->next;}
        
        stack<ListNode*> st;
        vector<ListNode*> v;
        
        int i = 0, j = 0;
        tmp = head;
        
        cerr<<"n : "<<n<<endl;
        while(v.size() < n - (n%k) and tmp)
        {
            cerr<<"Stack Pushing..."<<endl;
            while(j<k)
            {   
                cerr<<tmp->val<<endl;
                j++;
                st.push(tmp); 
                tmp = tmp->next;                
            }
            
            cerr<<"Stack Poping..."<<endl;
            while(!st.empty()){
                cerr<<st.top()->val<<endl;
                v.push_back(st.top()); 
                st.pop(); 
                j = 0;
            }  
            
            
            cerr<<v.size()<<" "<<n - (n%k)<<endl;
        }
        
        while(tmp){v.push_back(tmp); tmp = tmp->next;}
        
        for(i = 0; i<v.size() - 1; i++) 
            v[i]->next = v[i+1];       
        
        v[v.size() - 1]->next = NULL;
        
        for(auto i : v) cerr<<i->val<<"-->";
        cerr<<endl;
        return v[0];
        
    }
};