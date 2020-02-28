class Solution {
public:
    bool isPalindrome(int x) {
        long res = 0;
        int temp = x;
        if (x < 0) {
            return false;
        }
        while (temp != 0) {
            res = 10 * res + temp % 10;
            temp /= 10;
        }
        if (x == res) {
            return true;
        }
        return false;
    }
};