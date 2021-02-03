/*

You are given student id and marks score for 5 subjects. You need to arrange eligible students based on students who pass(Scored atleast 35 in each subject) in all subjects and based on the total marks scored in subject s0,s1,s2. Incase of tie arrange them in the order of total marks scored in all subjects combined. If there is still a tie the student with greater student id will be considered more eligible.
The arrangement should have the most eligible student in the beginning followed by others in same order.

*/
#include <bits/stdc++.h>
using namespace std;

struct Student{
  int id, s0, s1, s2, s3, s4;
};

bool cmp(struct Student a, struct Student b){
    if((a.s0+a.s1+a.s2) != (b.s0+b.s1+b.s2)) return (a.s0+a.s1+a.s2) > (b.s0+b.s1+b.s2);
    
    else{
        if((a.s0+a.s1+a.s2+a.s3+a.s4) != (b.s0+b.s1+b.s2+b.s3+b.s4)){
            return (a.s0+a.s1+a.s2+a.s3+a.s4) > (b.s0+b.s1+b.s2+b.s3+b.s4);
        }
        return a.id > b.id;        
    }
}


vector<int> engineeringCutoff(int n, vector<vector<int>> &marks)
{
    // Write your code here.
    vector<int> ans;
    vector<Student> stds;
    
    for(auto i : marks){
        if(i[1]<35 || i[2]<35 || i[3]<35 || i[4]<35 || i[5]<35) continue;
        else{
            struct Student std;
            std.id = i[0];
            std.s0 = i[1];
            std.s1 = i[2];
            std.s2 = i[3];
            std.s3 = i[4];
            std.s4 = i[5];
            stds.push_back(std); 
        }
           
    }
    
    sort(stds.begin(), stds.end(), cmp);
    
    for (auto i : stds){
        // cout<<i.id<<endl;
        ans.push_back(i.id);
    }
    
    return ans;
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
}#include <bits/stdc++.h>
using namespace std;

struct Student{
  int id, s0, s1, s2, s3, s4;
};

bool cmp(struct Student a, struct Student b){
    if((a.s0+a.s1+a.s2) != (b.s0+b.s1+b.s2)) return (a.s0+a.s1+a.s2) > (b.s0+b.s1+b.s2);
    
    else{
        if((a.s0+a.s1+a.s2+a.s3+a.s4) != (b.s0+b.s1+b.s2+b.s3+b.s4)){
            return (a.s0+a.s1+a.s2+a.s3+a.s4) > (b.s0+b.s1+b.s2+b.s3+b.s4);
        }
        return a.id > b.id;        
    }
}


vector<int> engineeringCutoff(int n, vector<vector<int>> &marks)
{
    // Write your code here.
    vector<int> ans;
    vector<Student> stds;
    
    for(auto i : marks){
        if(i[1]<35 || i[2]<35 || i[3]<35 || i[4]<35 || i[5]<35) continue;
        else{
            struct Student std;
            std.id = i[0];
            std.s0 = i[1];
            std.s1 = i[2];
            std.s2 = i[3];
            std.s3 = i[4];
            std.s4 = i[5];
            stds.push_back(std); 
        }
           
    }
    
    sort(stds.begin(), stds.end(), cmp);
    
    for (auto i : stds){
        // cout<<i.id<<endl;
        ans.push_back(i.id);
    }
    
    return ans;
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