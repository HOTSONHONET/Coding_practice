/*

last 3 tcs showed runtime error


*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
}

vector<int> string_process(int N, string S, vector<int> Dict)
{
    // Write your code here
    char maxx;
    vector<int> store(N + 1, 0);
    vector<char> alphabets;
    for (char i = 'a'; i <= 'z'; i++)
        alphabets.push_back(i);
    set<char> finder;
    for (int i = 0; i < N; i++)
    {
        finder.insert(S[i]);
        maxx = *(finder.rbegin());

        store[i] = Dict[maxx - 'a'];

        vector<int> tmp;
        for (auto &ele : finder)
        {
            tmp.push_back(ele);
        }

        finder.clear();
        for (auto &c : tmp)
        {
            finder.insert(((26 + (c - 'a') + store[i]) % 26) + 'a');
        }
        // cout<<maxx<<endl;
        // print(store);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        store[i] += store[i + 1];
    }

    for (int i = 0; i < N; i++)
        S[i] = alphabets[(26 + (S[i] - 'a') + store[i]) % 26];

    vector<int> charCount(26, 0);
    for (char &c : S)
        charCount[c - 'a']++;

    return charCount;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> Dict(26);
        for (int i_Dict = 0; i_Dict < 26; i_Dict++)
        {
            cin >> Dict[i_Dict];
        }

        vector<int> out_;
        out_ = string_process(N, S, Dict);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
            cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}