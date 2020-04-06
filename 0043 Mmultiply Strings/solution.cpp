class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, i_star = -1, j_star = -1, m = s.size(), n = p.size();
        
    while (i < m){
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                ++ i, ++ j;// 指针同时往后自增1，表示匹配
            }else if (j < n && p[j] == '*') {// 记录回溯的位置
                i_star = i;// 记录星号
                j_star = j++;// 并且j移到下一位,准备下个循环s[i]和p[j]的匹配
                             //(也就是匹配0个字符)
            }else if (i_star >= 0) {// 发现字符不匹配且没有星号出现,但是istar>0 
                                   // 说明*匹配的字符数可能出错 回溯
                i = ++ i_star;//i回溯到i_star+1，显然匹配字符的量出错，现在多匹配一个，且自身加一
                j = j_star + 1;//j回溯到j_star+1 重新使用p串*后的部分开始对齐s串i_star
            } else return false;
        }
        while (j < n && p[j] == '*') ++ j;// 去除多余星号

        return j == n;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> rec(n1 + n2, 0);
        string res = "";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                rec[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = n1 + n2 - 1; i > 0; i--) {
            rec[i - 1] += rec[i] / 10;
            rec[i] %= 10;
        }
        int t = 0;
        while (rec[t] == 0) t++;
        for (int i = t; i < n1 + n2; i++) {
            res.push_back('0' + rec[i]);
        }
        return res;
    }
};