class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        int res = 1, flag = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};