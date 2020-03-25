class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            int cs = 0, recNum = 0;
            string temp = "";
            char recChar = '*';
            for (char s: res) {
                if (s != recChar) {
                    if (recChar == '*') {
                        recChar = s;
                        recNum++;
                    } else {
                        temp += ('0' + recNum);
                        temp += recChar;
                        recChar = s;
                        recNum = 1;
                    }
                } else {
                    recNum++;
                }
            }
            temp += ('0' + recNum);
            temp += recChar;
            res = temp;
        }
        return res;
    }
};