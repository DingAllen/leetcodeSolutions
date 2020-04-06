class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> rec;
        vector<vector<string>> res;
        for (auto& e : strs){
            string temp = e;
            std::sort(e.begin(), e.end());
            rec[e].emplace_back(temp);
        }
        for (auto& e : rec){
            res.emplace_back(e.second);
        }

        return res;
    }
};