#include<bits/stdc++.h>

using namespace std;


int main()
{
    int tcs;
    cin>>tcs;

    while(tcs--)
    {
        int m, n;
        cin>>m>>n;

        m--; n--;

        int x[m], y[n];

        for(int i = 0; i<m; i++) cin>>x[i];
        for(int i = 0; i<n; i++) cin>>y[i];

        sort(x, x + m, greater<int>());
        sort(y, y + n, greater<int>());

        int hor_cnt = 1, vert_cnt =1;

        int ans = 1;
        int i = 0, j = 0;

        while(i<m and j<n)
        {
            if(x[i] > y[j])
            {
                ans += x[i]*vert_cnt;
                hor_cnt++;
                i++;
            }
            else{
                ans += y[j]*hor_cnt;
                vert_cnt++;
                j++;
            }
        }

        while(i<m)
        {
            ans += x[i]*vert_cnt;
            i++;
        }

        while(j<n)
        {
            ans += y[j]*hor_cnt;
            j++;
        }

        cout<<ans<<endl;

    }


    return 0;
}