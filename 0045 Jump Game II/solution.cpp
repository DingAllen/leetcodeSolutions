class Solution {
public:
    int jump(vector<int>& nums) {

        int res = 0, rec = 0, r = 0;
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (i + nums[i] > rec) rec = i + nums[i];
            if (i == r) r = rec, res++;
        }
        return res;
    }
};