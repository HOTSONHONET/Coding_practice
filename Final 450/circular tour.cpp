// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int start, curr_petrol = 0, i;
        for(int i = 0; i<n; i++)
            if(p[i].petrol >= p[i].distance) {start = i; break;}
        
        for(i = start; i<n;)
        {
            curr_petrol += p[i].petrol - p[i].distance;
            
            if(curr_petrol < 0)
            {
                i++;
                for(; i<n; i++)if(p[i].petrol - p[i].distance >= 0)
                    {
                        start = i;
                        curr_petrol = 0;
                        break;
                    }
            }
            
            else i++;
        }
        
        if(curr_petrol < 0) return -1;
        
        for(int k = 0; k < start; k++)
        {
            curr_petrol += p[k].petrol - p[k].distance;
            if(curr_petrol < 0) return -1;
        }
        
        
        return start;
        
       
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends