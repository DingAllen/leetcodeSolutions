class Solution {

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

        vector<vector<int>> res;
        vector<int> rec;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, rec, res);
        return res;
    }

private:
    void solve(vector<int> &candidates, int index, int target, vector<int> &rec, vector<vector<int>> &res) {

        if (target == 0) {
            res.push_back(rec);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1]) continue;

            int temp = candidates[i];
            if (target >= temp) {
                rec.push_back(temp);
                solve(candidates, i + 1, target - temp, rec, res);
                rec.pop_back();
            }
        }
    }
};