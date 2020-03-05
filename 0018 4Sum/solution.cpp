class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = n - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target){
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    while (nums[i] + nums[j] + nums[l] + nums[r] < target && l < r) l++;
                    while (nums[i] + nums[j] + nums[l] + nums[r] > target && l < r) r--;
                }
            }
        }
        return res;
    }
};