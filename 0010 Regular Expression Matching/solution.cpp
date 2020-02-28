class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }

private:
    bool match(string &s, int sl, string &p, int pl) {

        if (sl == s.size()) return finish(p, pl);
        if (pl == p.size()) return false;

        if (pl + 1 < p.size() && p[pl + 1] == '*') {
            if (s[sl] == p[pl] || p[pl] == '.') {
                return match(s, sl + 1, p, pl) || match(s, sl, p, pl + 2);
            } else {
                return match(s, sl, p, pl + 2);
            }
        } else if (s[sl] == p[pl] || p[pl] == '.') {
            return match(s, sl + 1, p, pl + 1);
        }
        return false;
    }

    bool finish(string &p, int pl) {

        int i;
        for (i = pl; i < p.size(); i += 2) {
            if (i + 1 < p.size() && p[i + 1] != '*') return false;
        }
        return i == p.size();
    }
};