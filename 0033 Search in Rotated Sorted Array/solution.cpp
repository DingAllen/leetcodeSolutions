class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.empty()) return -1;
        
        int n = nums.size();
        if (target >= nums[0]) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) return i;
                if (i > 0 && nums[i] < nums[i - 1]) return -1;
            }
        } else {
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] == target) return i;
                if (i < n - 1 && nums[i] > nums[i + 1]) return -1;
            }
        }
        return -1;
    }
};