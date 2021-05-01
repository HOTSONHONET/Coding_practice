class Solution {
public:
    string countAndSay(int n) {
        
        string s = "1";
        if (n == 1) return s;
        
        
        int k = 1;
        while(k < n){
            int len = s.length();
            cout<<"S : "<<s<<endl;            
            cout<<"len : "<<len<<endl;
            char prev = s[0];
            int cnt = 0;
            string res = "";
            for(int i = 0; i<len; i++){
                if(prev == s[i]){
                    cnt++;
                    cout<<"Cur Index: "<<i<<endl;
                }
                else{
                    cout<<"Cur Index: "<<i<<endl;
                    res += to_string(cnt) + prev;
                    prev = s[i];
                    cnt = 1;
                }
            }
            
            
            res += to_string(cnt) + prev;

            
            

            cout<<"res : "<<res<<endl;
            s = res;
            cout<<"===============\n"<<endl;
            k++;
        }
        
        return s;
    }
};