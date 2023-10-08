class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int check = INT_MAX;
        int ans;
        for(int i =0; i< n;i++){
            int x = i+1, y=n-1;
            while(x<y){
                int sum =nums[i] + nums[x]+ nums[y];
                if(target - sum == 0){
                    return target;
                }
                
                if(abs(target - sum ) < check){
                    check = abs(target - sum );
                    ans = sum;
                }
                
                if(sum > target ){
                    y--;
                }else{
                    x++;
                }
            }
        }
        return ans;
    }
};