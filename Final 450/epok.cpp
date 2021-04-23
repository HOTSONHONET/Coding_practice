#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a[10000001];
 
bool solve(lli mid,lli n,lli m)
{
    lli i,collected=0;
    
    /* calculating how much metres of wood 
	we can collect fixing the saw 
	blade at height = mid */
    
	for(i=0;i<n;i++)
    {
    	/* if the height of the tree is greater than the
    	height of saw blade only then we can collect
		wood from the tree */ 

    	if( a[i] > mid )
    	{
    		collected+=(a[i]-mid);
		}
    }
    
	/*checking if we have collected 
    atleast m metres of wood
    if yes we return true because we can set the
	blade at mid height and collect atleast
	m metres of wood otherwise we return false*/
	
    if(collected>=m)
    {
    	return true;
    }
    else
    {
    	return false;
	}
}

int main(void)
{
    lli n,i,j,m,ans=0,l=0,h=-1,mid;
    //no of trees (n) and how much wood we have to collect(m) 
    cin>>n>>m;
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        
        /* h will store the maximum 
		of all tree heights*/
		 
        h=max(h,a[i]);
    }
    
    while(l<=h)
    {
        mid=(l+h)/2;
        
        /* checking if we can collect atleast
		 m metres of wood placing the blade
		 at height = mid */
        
		if(solve(mid,n,m))
        {
        	/* we entered here because we can place the blade 
        	at height = mid and can collect atleast 
        	m metres of wood so mid may be our answer
        	and for that reason we are storing mid in ans
        	and now we shall find better answer by placing the blade 
        	at some higher height than mid
        	because we have to maximize the height */
        	
            ans=mid;
            l=mid+1;
        }
        else
        {
        	/* we entered here because
        	by placing the bade at height = mid 
        	we cannot collect atleast m metres of wood
        	so we shall search for lower heights where we can place 
			our blade and satisfy the condition 
			of collecting atleast m metres of wood */
			
            h=mid-1;
        }
    }
    
    cout<<ans;
    
	return 0;
}