class Solution {
public:
    // Helper funtions for calculating 
    // maximum and minimum values
    int max(int &a, int &b){
        if(a>b) return a;
        return b;
    }
    
    int min(int a, int b){
        if(a<b) return a;
        return b;
    }
    
    // main function
    // Calculating the leftmax and rightmax for each index
    // and then using the below formula to calucate water_content over that wall
    // min(leftmax, rightmax)-wall_height
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n==0) return 0;
        
        int left[n], right[n];
        
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i = 1; i<n; i++){            
            left[i] = max(left[i-1], height[i]);
            // cout<<"Left Value : "<<left[i]<<endl;
        }
        for(int i = n-2; i>=0; i--){            
            right[i] = max(right[i+1], height[i]);
            // cout<<"Right Value : "<<right[i]<<endl;
        }
        
        int total_water_content = 0;
        for(int i = 0; i<n; i++){
            cout<<"======================="<<endl;
            cout<<"Left[i] : "<<left[i]<<endl;
            cout<<"Right[i] : "<<right[i]<<endl;
            cout<<"min(left[i], right[i]) : "<<min(left[i], right[i])<<endl;
            cout<<"Cur height : "<< height[i]<<endl;
            cout<<"Cur Value : "<< total_water_content<<endl;
            total_water_content += min(left[i], right[i]) - height[i];
        }
        
        return total_water_content;
    }
};