class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n = nums.size(), delNum = 0;
        for (int i = 0; i + delNum < n; i++) {

            while (i + delNum < n && nums[i + delNum] == val) delNum++;
            if (i < n - delNum) nums[i] = nums[i + delNum];
        }
        return n - delNum;
    }
};