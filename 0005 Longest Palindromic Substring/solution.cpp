// 这道题，整整花了我一下午去思考。花了很多时间，但我觉得值得。
// 这个算法，不是我想的，这个算法名为Manachar算法。以我目前的水平只能惊叹于这个算法的天才。以此为目标奋斗吧！
class Solution {
public:
    string longestPalindrome(string input) {

        string s = "#";
        for(char c: input)
            s += c, s += '#';

        int id = 0, maxright = 0;
        int rescenter = 0, reslen = 0;
        vector<int> r(s.size(), 1);
        for(int i = 1; i < s.size() - 1; i ++){
            if(maxright > i) {
                r[i] = min(r[2 * id - i], maxright - i);
            }
            while(i - r[i] >= 0 && i + r[i] < s.size() && s[i + r[i]] == s[i - r[i]]) r[i] ++;
            r[i] --;

            if(i + r[i] > maxright) maxright = i + r[i], id = i;

            if(r[i] > reslen) reslen = r[i], rescenter = i;
        }

        return input.substr((rescenter - reslen) / 2, reslen);
    }
};