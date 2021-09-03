#include<bits/stdc++.h>

using namespace std;


#define ipair pair<int,int>


int main()
{

    int tcs;
    cin>>tcs;

    while(tcs--)
    {

        int n;
        cin>>n;

        vector<int> v(n);
        for(int i= 0; i<n; i++)cin>>v[i];

        vector<ipair> buy, sell;

        for(int i=0; i<n; i++)
        {
            if(v[i] > 0) buy.push_back({v[i], i});
            else sell.push_back({v[i], i});
        }        

        int ans = 0;
        int i = 0, j = 0;

        while(i < buy.size() and j<sell.size())
        {
            int x = min(buy[i].first, -sell[j].first);
            buy[i].first -= x;
            sell[j].first += x;

            int diff = abs(buy[i].second - sell[j].second);

            ans += (x*diff);

            if(buy[i].first == 0) i++;
            if(sell[j].first == 0) j++;

        }

        cout<<ans<<endl;
        cin>>n;

        if(n == 0) break;
        


    }

    return 0;
}

// T(n) = O(N)
// S(n) = O(N)