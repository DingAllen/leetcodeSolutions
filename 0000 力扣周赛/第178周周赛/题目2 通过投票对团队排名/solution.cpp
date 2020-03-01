// 人生中第一次认识到lamda表达式，这个答案是我从榜一那偷来的，反正没人看我github[/抠鼻]
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size();
        string v = votes[0];
        map<char, map<int, int>> f;
        for (auto s : votes)
        {
            for (int i = 0; i < s.size(); ++ i)
                f[s[i]][i] ++;
        }
        sort(v.begin(), v.end(), [&](char a, char b) -> bool
        {
            for (int i = 0; i < v.size(); ++ i)
            {
                if (f[a][i] > f[b][i]) return 1;
                if (f[a][i] < f[b][i]) return 0;
            }
            return a < b;
        });
        return v;
    }
};