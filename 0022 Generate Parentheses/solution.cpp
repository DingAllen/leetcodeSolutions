// 以我糟糕的水平只能想出先遍历，再判断，阅读了两位的大神的代码之后我受到了很大的启发
// 我一开始没有考虑到这道题与0020题的差别，在这道题中，只要左右数量一致就能匹配成功
// 我的第一版代码太过拙劣，就不放在代码仓里了

// 这个解法使用了递归的写法，这为我以后使用递归开拓了思路，给了我很大的启发
class Solution {
public:

    int n;
    vector<string> ans;

    vector<string> generateParenthesis(int _n) {
        n = _n;
        dfs("", 0, 0);
        return ans;
    }

    void dfs(string path, int l, int r){
        if(l == n && r == n){
            ans.push_back(path);
            return;
        }
        if(l < n) dfs(path + '(', l + 1, r);
        if(l > r) dfs(path + ')', l, r + 1);
    }
};

// 这是上面写法的非递归形式
// 在递归的过程中，需要额外消耗一部分的内存，非递归的写法节约了将近一半的资源，在时间上和空间上都达到了一个不错的效果
class Solution {

public:
    vector<string> generateParenthesis(int n){

        if(n == 0)
            return {};

        vector<vector<string>> res(n + 1);
        res[0].push_back("");
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j <= i - 1; j ++)
                for(const string& l: res[j])
                    for(const string& r: res[i - j - 1])
                        res[i].push_back("(" + l + ")" + r);
        return res[n];
    }
};