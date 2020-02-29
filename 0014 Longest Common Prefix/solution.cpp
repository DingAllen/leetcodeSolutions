class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }
        
        string res = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < res.size() && strs[i][j] == res[j]) j++;
            res = res.substr(0, j);
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0) {
            return "";
        }
        
        string res = strs[0];

        for (int i = 1; i < strs.size() && res.size() != 0; i++) {
            int j = 0;
            while (j < res.size() && strs[i][j] == res[j]) j++;
            res = res.substr(0, j);
        }
        return res;
    }
};