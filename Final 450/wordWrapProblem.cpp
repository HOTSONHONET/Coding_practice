#include <bits/stdc++.h>
using namespace std;
int wordWrap (int wordSize[], int n, int lineSize) 
{ 
  int extraSpace[n+1][n+1];
  int minCost[n+1];
  for (int i=1;i<=n;i++) 
  { 
    extraSpace[i][i] = lineSize - wordSize[i-1];
    for (int j=i+1;j<=n;j++) 
        extraSpace[i][j] = extraSpace[i][j-1] - wordSize[j-1] - 1; 
  }
  
  minCost[0] = 0; 
  for (int i = 1; i <= n; i++) 
  { 
    minCost[i] = INT_MAX;
    for (int j = 1; j <= i; j++) 
    { 
        int cost; // stores cost of storing words[i,j] in single line
        
        //if extraSpace required is negative, then we can't place
        //words[i,j] in a single line, else if we placed our last
        //word, then we don't consider extraSpace, else calculate
        //cost as per given cost function.
        if(extraSpace[j][i]<0)cost = INT_MAX;
        else if(i==n && extraSpace[j][i]>=0)cost = 0;
        else cost = extraSpace[j][i]*extraSpace[j][i]*extraSpace[j][i];
        
      if (minCost[j-1] != INT_MAX && cost != INT_MAX
      && (minCost[j-1] + cost < minCost[i])) 
        minCost[i] = minCost[j-1] + cost;
    }
  }
  
  return minCost[n];
} 
int main() 
{
    int t;cin>>t;
    while(t--) {
       int n;cin>>n;
       int wordSize[n];
       for(int i=0;i<n;i++)
            cin>>wordSize[i];
       int lineSize;cin>>lineSize;
       int ans = wordWrap(wordSize, n, lineSize);
       cout<<ans<<endl;
    }
}