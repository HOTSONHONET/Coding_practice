#include<bits/stdc++.h>

using namespace std;


int main()
{

    int tcs;
    cin>>tcs;
    while(tcs--)
    {
        int n;
        cin>>n;
        int a[n];
        int ones = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>a[i];
            fi(a[i] == 1) ones++;
        }

        sort(a, a + n, greater<int>());

        for(int i=0; i<ones; i++) cout<<"1 ";

        if((n-ones) == 2 and a[0] == 3 and a[1] == 2)
            cout<<"2 3 "<<endl;
        
        else
            for(int i=0; i<(n-ones); i++)
                cout<<a[i]<<" ";
    }


    return 0;

}


// T(n) = O(nlogn)
// S(n) = O(1)