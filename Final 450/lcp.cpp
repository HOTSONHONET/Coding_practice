class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];
        
        for(auto i: strs){
            if(i == "") return "";
        }
        
        for(int i = 1; i<n; i++){
            if(strs[i][0] != strs[0][0]) return "";
        }
        
        int min_len = INT_MAX;
        string min_str;
        for(auto i: strs){
            if(i.length() < min_len){
                min_len = i.length();
                min_str = i;
            }            
        } 
        
        string lcp = "";
        
        for(int i = 0; i<min_str.length(); i++){
            char cur_char = min_str[i];
            for(auto j: strs){
                if(j[i] != cur_char) return lcp;
            }
            lcp += cur_char;
        }

        return lcp;
        
        
        
    }
};