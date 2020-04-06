class Solution {
public:
    vector<vector<int>> permute(vector<int>& data) {
        
        n = nums.size();
        nums = data;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        dfs();
        return res;
    }

private:
    int n;
    vector<int> nums;
    vector<vector<int>> res;

    void dfs() {
        
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                for (int j = n - 1; j >= i; j--) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                sort(nums.begin() + i, nums.end());
                res.push_back(nums);
                dfs();
            }
        }
        return;
    }
};