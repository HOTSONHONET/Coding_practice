#include<bits/stdc++.h>

using namespace std;


bool solve(int a[], int n, int p, int mid)
{
    int time = 0;
    int  cp = 0;
    for(int i = 0; i<n; i++)
    {
        time = a[i];
        int j = 2;
        while(time<=mid)
        {
            cp++;
            time += (a[i]*j);
            j++;
        }

        if(cp>=p) return true;
    }


    return false;
}

# define MAX 1000000000
int main(){

    int tcs;
    cin>>tcs;
    while(tcs--)
    {
        int p;
        cin>>p;
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        int l = 0, r = MAX;
        while(l<=r)
        {   

            int mid = l + (r-l)/2;

            if(solve(a, n, p, mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }

        cout<<ans<<endl;
    }

    return 0;

}