#include<bits/stdc++.h>

using namespace std;


int main()
{


	int tcs;
	cin>>tcs;

	while(tcs--)
	{
		int w, h, n;
		cin>>w>>h>>n;
		vector<int> ws, hs;
        ws.push_pack(0);
        hs.push_back(0);

		for(int i = 0; i<n; i++)
		{
			int i, j;
			cin>>i>>j;
			ws.push_back(i);
            hs.push_back(j);
		}

        ws.push_back(w+1);
        hs.push_back(h+1);
        sort(ws.begin(), ws.end());
        sort(hs.begin(), hs.end());


        int max_w = 0, max_h = 0;
        for(int i = 0; i<ws.size()-1; i++)
        {
            max_w = max(max_w, ws[i+1] - ws[i] - 1);
            max_h = max(max_h, hs[i+1] - hs[i] - 1);
        }

        cout<<(max_w*max_h)<<endl;



		

	}
}