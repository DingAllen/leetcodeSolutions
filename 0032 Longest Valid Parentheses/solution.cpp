// 我了解动态规划算法，但我并不会应用
// 今天看到这道题，我第一时间没有反应出来要用动态规划
// 而下面我粘贴过来的那段代码让我体会到了动态规划算法的应用场景，为我今后使用动态规划算法打开了思路

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {

            if (s[i] == ')') continue;

            int rec = 0, lrec = 0, rrec = 0;
            for (int j = i; j < n; j++) {
                
                if (s[j] == '(') lrec++;
                else rrec++;
                if (rrec > lrec) break;
                if (lrec == rrec) rec = lrec;
            }
            if (rec > res) res = rec;
        }
        return 2 * res;
    }
};

// 这段代码是我在执行时间为4ms的示例程序中粘贴来的
// 这段代码写的十分优雅，值得我去学习
class Solution {
public:
    int longestValidParentheses(string s) {
        int strLen = s.size();
        vector<int> dp(strLen, 0);
        int max_len = 0;
        for (int i = 1; i < strLen; i++) {
            if (s[i] == '(')
                continue;
            else {
                if (s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else {
                    int tmp = dp[i - 1];
                    if (i - tmp - 1 >= 0 && s[i - tmp - 1] == '(')
                        dp[i] = (dp[i - 1] + 2) + (i - tmp - 1 == 0 ? 0 : dp[i - tmp - 2]);
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
