class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int res = nums[0] + nums[1] + nums[2], resTemp;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i  = 0; i < n - 2; i++) {
            
            int l = i + 1, r = n - 1;
            while (l < r) {

                resTemp = nums[i] + nums[l] + nums[r];
                if (resTemp < target) l++;
                else if (resTemp > target) r--;
                else return target;
                if (abs(resTemp - target) < abs(res - target)) res = resTemp;
            }
        }
        return res;
    }
};