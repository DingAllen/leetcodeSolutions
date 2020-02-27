class Solution {
public:
    int myAtoi(string str) {

        int firstNotBlank = 0;
        int sign = 1;
        long res = 0;

        for(char c: str) {
            if(firstNotBlank) {
                if(c < '0' || c > '9') {
                    return sign * res;
                }
                if((res > INT_MAX / 10 || res == INT_MAX / 10 && (c - '0') > 7) && sign == 1) {
                        return INT_MAX;
                }
                if((res > (-INT_MIN) / 10 || res == (-INT_MIN) / 10 && (c - '0') > 8) && sign == -1){
                        return INT_MIN;
                }
                res = res * 10 + (c - '0');
            }
            if(c != ' ' && !firstNotBlank) {
                firstNotBlank = 1;
                if(c == '-' || c == '+' || c >= '0' && c <= '9') {
                    if(c == '-'){
                        sign = -1;
                    } else if(c != '+') {
                        res += c - '0';
                    }
                } else {
                    return 0;
                }
            } 
        }
        return sign * res;
    }  
};


// 这个解法并非自己想到，但这个解法确实对人有所启发，学到了学到了
class Solution {
public:
    int myAtoi(string str) {
        int n;
        n = str.find_first_not_of(" ");
        if(n==string::npos)
            return 0;
        if(str[n]=='-'||str[n]=='+'||str[n]>='0'&&str[n]<='9'){
            int i = str.find_first_not_of("0123456789",n+1);
            if(i!=string::npos){
                str.erase(i,str.size());
            }
        }else{
            return 0;
        }
        stringstream s;
        s<<str;
        int re;
        s>>re;
        return re;
    }
};