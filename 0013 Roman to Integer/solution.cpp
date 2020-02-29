class Solution {
public:
    int romanToInt(string s) {

        int res = 0;
        unordered_map<char, int> map= {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() && map[s[i + 1]] > map[s[i]]) {
                res += map[s[i + 1]] - map[s[i]];
                i++;
            } else {

                res += map[s[i]];
            }
        }
        return res;
    }
};

class Solution {
public:
    int romanToInt(string s) {

        int res = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i + 1 < s.size() && getValue(s[i + 1]) > getValue(s[i])) {
                res += getValue(s[i + 1]) - getValue(s[i]);
                i++;
            } else {
                res += getValue(s[i]);
            }
        }
        return res;
    }

private:
    int getValue(char &c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
};