 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b){return a[0] < b[0];});
        
        
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while(i<n){
            vector<int> cur_int;
            cur_int.push_back(intervals[i][0]);
            int end = intervals[i][1];
            int j = i+1;
            
            while(j<n && end >= intervals[j][0]){ 
                end = max(end, intervals[j][1]);
                j++;
            }         
            cur_int.push_back(end);
            ans.push_back(cur_int);
            i+=(j-i);
        }
        
        
        return ans;
    }