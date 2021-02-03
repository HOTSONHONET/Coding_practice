/*

You are given student id and marks score for 5 subjects. You need to arrange eligible students based on students who pass(Scored atleast 35 in each subject) in all subjects and based on the total marks scored in subject s0,s1,s2. Incase of tie arrange them in the order of total marks scored in all subjects combined. If there is still a tie the student with greater student id will be considered more eligible.
The arrangement should have the most eligible student in the beginning followed by others in same order.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> engineeringCutoff(int n, vector<vector<int>> &marks)
{
    // Write your code here.
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> marks(n);
    int id, s0, s1, s2, s3, s4;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> s0 >> s1 >> s2 >> s3 >> s4;
        marks[i] = {id, s0, s1, s2, s3, s4};
    }
    vector<int> ans = engineeringCutoff(n, marks);
    for (int j : ans)
    {
        cout << j << " ";
    }
    cout << "\n";
}