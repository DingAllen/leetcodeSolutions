// 再次碰到了盲点，再次学到了新东西。代码不是自己写的，一开始还没看懂，调试了一下才完全明白
class Solution {

public:  

    int divide(int dividend, int divisor)
    {
        int res = 0;
        if (dividend == 0)
            return 0;
        else if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        else if (dividend == INT_MIN && divisor == INT_MIN)
            return 1;
        else if (divisor == INT_MIN)
            return 0;

        bool negative = (dividend ^ divisor) < 0;

        if (dividend == INT_MIN)
        {
            dividend += abs(divisor);
            res++;
        }
        int t = abs(dividend);
        int d = abs(divisor);

        for (int i = 31; i >= 0; i--) {
            if((t >> i) >= d) {
                res += 1 << i;
                t -= d << i;
            }
        }

        if (res == INT_MIN)
            return INT_MAX;
        else
            return negative ? -res : res;
        return 0;
    }
};