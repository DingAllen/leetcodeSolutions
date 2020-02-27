class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) {
            return s;
        }

        int num = 2 * numRows - 2;
        string res = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; i + num * j < s.size(); j ++) {
                res += s[i + num * j];
                if(num - i < num && num - i >= numRows && num - i + num * j < s.size()) {
                    res += s[num - i + num * j];
                }
            }
        }
        return res;
    }
};