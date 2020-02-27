class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return x;

        if(x == INT_MIN)
            return 0;

        int sign = x > 0 ? 1 : -1;

        x = abs(x);
        int reverseNum = 0;
        while(x){

            if(reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && x % 10 > 7))
                return 0;

            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return sign * reverseNum;
    }
};