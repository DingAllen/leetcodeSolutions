// 最优解法 效率上最高
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int last[256];
        memset(last, -1, sizeof(last));

        int l = 0, r = -1;
        int res = 0;
        while(r + 1 < s.size()){

            r ++;
            if(last[s[r]] != -1)
                l = max(l, last[s[r]] + 1);

            res = max(res, r - l + 1);
            last[s[r]] = r;
        }

        return res;
    }
};

// 另一个也很不错的解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;

        while(r + 1 < s.size()) {

            if(freq[s[r + 1]] == 0) {
                freq[s[++r]] ++;
            } else {
                freq[s[l++]] --;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};