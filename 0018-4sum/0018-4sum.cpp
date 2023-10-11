class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i =0;i<n - 3;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n - 2;j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int x = j+1, y= n-1;
                
                while(x<y){
                long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[x] + nums[y];
                    
                    if(x > j + 1 && nums[x] == nums[x-1]) {
                        x++; continue;
                    }
                    if(y < n - 1 && nums[y] == nums[y+1]) {
                        y--; continue;
                    }
                    
                    if(sum==target){
                        ans.push_back({nums[i], nums[j], nums[x], nums[y]});
                        x++,y--;
                    }else if(sum > target){
                        y--;
                    }else{
                        x++;
                    }
                
                }
            }
        }
        
        return ans;
    }
};