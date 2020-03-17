// 写出来了，但效率奇差。我的思路是正确的，但也许由于我没有系统学习过c++语言导致我在一些语法上运用的不够随心所欲
// 我计划在30天内将系统学习c++提上日程

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;
        if (words.empty()) return res;

        int sn = s.size();
        int n = words.size();
        int sz = words[0].size();

        for (int i = 0; i <= sn - n * sz; i++) {

            int c = 0;
            vector<int> rec(n);
            string temp = s.substr(i, n * sz);
            for (int j = 0; j < n; j++) {

                if (c < j) break;

                string t = temp.substr(j * sz, sz);
                for (int k = 0; k < n; k++) {
                    if (words[k] == t) {
                        if (rec[k] > 0) continue;
                        rec[k]++, c++;
                        break;
                    }
                }
            }
            if (c == n) res.push_back(i);
        }
        return res;
    }
};