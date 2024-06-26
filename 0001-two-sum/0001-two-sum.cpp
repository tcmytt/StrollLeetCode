class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (um.count(target - nums[i])) {
                return {um[target - nums[i]], i};
            }
            um[nums[i]] = i;
        }

        return {};
    }
};