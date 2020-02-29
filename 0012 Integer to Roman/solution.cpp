class Solution {
public:
    string intToRoman(int num) {

        string res = "";
        int flag;
        string one[] = {"I", "X", "C", "M", ""}, five[] = {"V", "L", "D", ""};
        for (int i = 3; i >= 0; i --) {
            flag = (int)pow(10, i);
            if (num >= flag) {
                res += rome(num / flag, one[i], five[i], one[i + 1]);
                num %= flag;
            }
        }
        return res;
    }

private:
    string rome(int temp, string one, string five, string ten) {
        if (temp <= 3) {
            return string(temp, one[0]);
        } else if (temp == 4) {
            return one + five;
        } else if (temp <= 8) {
            return five + string(temp - 5, one[0]);
        }
        return one + ten;
    }
};