class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int k = nums.size(); 
        sort(begin(nums), end(nums));

        for(int i=0;i<k;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int t = 0 - nums[i];
            int n =i+1,m=k-1;
            
            while(n<m && n>i){
                
                int sum = nums[n] + nums[m];
                if(sum <t){
                    n++;
                }
                else if(sum >t){
                    m--;
                }else{
                    if(n !=i && m != i ){
                        ans.push_back({nums[i],nums[n],nums[m]});
                        while (n < m && nums[n] == nums[n + 1]) n++;
                        while (n < m && nums[m] == nums[m - 1]) m--; 
                        n++;
                        m--;
                    }
                }

            }
        }
        return ans;

    }
};