#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ipair pair<int, int>
#define llpair pair<long long, long long>

void print(vector<int> v)
{
	    for(auto i : v) cout<<i<<" ";
	        cout<<endl;
}


int main()
{
	    int n, k;
	        cin>>n>>k;
		    int upl = 240;
		        int l = 1, r = n;
			    int ans = 0;
			    while(l<=r)
					    {
						            int mid=l+(r-l)/2;
							            if(5*mid*(mid+1)/2 <= 240-k)
									            {
											                ans = mid;
													            l++;
														            }
								            else r = mid-1;
									        }
				    
				    
				    cout<<ans<<endl;
				        
				        return 0;
}


