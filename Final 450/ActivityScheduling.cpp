// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/*

Sort all pairs(Meetings) in increasing order of second number(Finish time) of each pair.
Select first meeting of sorted pair as the first Meeting in the room and push it into result vector and set a variable time_limet(say) with the second value(Finishing time) of the first selected meeting.
Iterate from the second pair to last pair of the array and if the value of the first element(Starting time of meeting) of the current pair is greater then previously selected pair finish time (time_limit) then select the current pair and update the result vector (push selected meeting number into vector) and variable time_limit.
Print the Order of meeting from vector.


*/

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends


struct MeetTimes{
    int st, ed;
};

bool cmp(struct MeetTimes a, struct MeetTimes b){
    return a.ed<b.ed;
}


int maxMeetings(int start[], int end[], int n) {
    // Your code here
    struct MeetTimes slots[n];
    for(int i = 0; i<n; i++){
        slots[i].st = start[i];
        slots[i].ed = end[i];
    }
    
    sort(slots, slots + n, cmp);
    
    int curStart = slots[0].st;
    int curEnd = slots[0].ed;
    int max_meetings_pos = 1;
    for(int i = 1; i<n; i++){
        int tmpcurStart = slots[i].st;
        int tmpcurEnd = slots[i].ed;
        
        if(tmpcurStart > curEnd){
            max_meetings_pos++;
            curStart = tmpcurStart;
            curEnd = tmpcurEnd;
            // cout<<curStart<<" "<<curEnd<<endl;
        }
    }
    return max_meetings_pos;
    
}