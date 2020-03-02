class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {

            int target = nums[i], l = i + 1, r = n - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (target > 0) break;
            
            while (l < r) {
                if (nums[l] + nums[r] + target > 0) {
                    r--;
                } else if (nums[l] + nums[r] + target < 0) {
                    l++;
                } else {
                    res.push_back({target, nums[l], nums[r]});
                    l++, r--;
                    while (nums[l] == nums[l - 1] && l < r) l++;
                    while (nums[r] == nums[r + 1] && l < r) r--;
                }
            }
        }
        return res;
    }
};
