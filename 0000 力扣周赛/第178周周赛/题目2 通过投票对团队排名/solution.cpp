// �����е�һ����ʶ��lamda���ʽ����������ҴӰ�һ��͵���ģ�����û�˿���github[/�ٱ�]
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