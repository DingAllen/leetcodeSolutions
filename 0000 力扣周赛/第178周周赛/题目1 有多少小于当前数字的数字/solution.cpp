class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int temp = 0;
            for(int j = 0; j < nums.size(); j++)
                temp += nums[i] > nums[j] ? 1 : 0;
            res.push_back(temp);
        }
        return res;
    }
};