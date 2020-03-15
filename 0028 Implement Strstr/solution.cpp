// 一道归属于简单的题型，但却废了我不少功夫
// 在我解题的过程中，我总是想将代码写的简短且优雅，可能这样反而容易忽视一些问题，因为结构有时可能不表现的那么明确了

// 这是一开始花了5分钟写出来的，执行通过了，但执行时间却要2000多ms
class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() == 0) return 0;

        int sz = haystack.size(), n = needle.size();
        for (int i = 0; i < sz; i++) {

            while (i < sz - 1 && haystack[i] != needle[0]) i++;

            int j;
            bool flag = true;
            for (j = 0; j < n && i + j < sz; j++)
                if (haystack[i + j] != needle[j])
                    flag = false;
            if (flag && j == n) return i;
        }
        return -1;
    }
};

// 这是优化后的代码，仅仅是修改了循环的上界，就优化了500多倍，我虽然写出来了，但仍然不知道为什么能优化这么多
class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() == 0 || haystack == needle) return 0;

        int sz = haystack.size(), n = needle.size();
        for (int i = 0; i <= sz - n; i++) {

            while (i < sz - n && haystack[i] != needle[0]) i++;

            int j;
            bool flag = true;
            for (j = 0; j < n; j++)
                if (haystack[i + j] != needle[j])
                    flag = false;
            if (flag && j == n) return i;
        }
        return -1;
    }
};