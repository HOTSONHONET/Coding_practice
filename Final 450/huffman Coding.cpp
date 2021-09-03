// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    struct MinHeapNode
        {
            char data;
            unsigned freq;
            
            MinHeapNode *left, *right;
            MinHeapNode(char data, unsigned freq)
            {
                left = right = NULL;
                this->data = data;
                this->freq = freq;
            }
        };
	
	    void populateAns(vector<string> &ans, struct MinHeapNode* root,  string str)
	    {
	        if(!root) return;
	        
	        if(root->data != '$')
	            ans.push_back(str);
            
            populateAns(ans, root->left, str + "0");
            populateAns(ans, root->right, str + "1");
	            
	    }
	    
	    struct compare{
	        
	        bool operator()(MinHeapNode* l, MinHeapNode* r)
	        {
	            return (l->freq > r->freq);
	        }
	    };
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    vector<string> ans;
		    
		    struct MinHeapNode *left, *right, *top;
		    
		    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
		    
		    for(int i = 0; i<N; i++)    
		        minHeap.push(new MinHeapNode(S[i], f[i]));
	        
	        while(minHeap.size() != 1)
	        {
	            left = minHeap.top();
	            minHeap.pop();
	            
	            right = minHeap.top();
	            minHeap.pop();
	            
	            top = new MinHeapNode('$', left->freq + right->freq);
                
                top->left = left;
                top->right = right;
                minHeap.push(top);
	            
	        }
	        
	        populateAns(ans, minHeap.top(), "");
	        
	        return ans;
		    
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends