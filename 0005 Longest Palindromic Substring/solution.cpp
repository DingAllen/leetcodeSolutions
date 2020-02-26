// ����⣬����������һ����ȥ˼�������˺ܶ�ʱ�䣬���Ҿ���ֵ�á�
// ����㷨����������ģ�����㷨��ΪManachar�㷨������Ŀǰ��ˮƽֻ�ܾ�̾������㷨����š��Դ�ΪĿ��ܶ��ɣ�
class Solution {
public:
    string longestPalindrome(string input) {

        string s = "#";
        for(char c: input)
            s += c, s += '#';

        int id = 0, maxright = 0;
        int rescenter = 0, reslen = 0;
        vector<int> r(s.size(), 1);
        for(int i = 1; i < s.size() - 1; i ++){
            if(maxright > i) {
                r[i] = min(r[2 * id - i], maxright - i);
            }
            while(i - r[i] >= 0 && i + r[i] < s.size() && s[i + r[i]] == s[i - r[i]]) r[i] ++;
            r[i] --;

            if(i + r[i] > maxright) maxright = i + r[i], id = i;

            if(r[i] > reslen) reslen = r[i], rescenter = i;
        }

        return input.substr((rescenter - reslen) / 2, reslen);
    }
};