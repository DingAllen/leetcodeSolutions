// 这道题想了一早上，却弄得焦头烂额没有头绪，参考别人答案写了一个
// 第一次接触到这种回溯算法，学到新东西总是让人开心的
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        res.clear();
        if(digits == "")
            return res;

        findCombination(digits, 0, "");

        return res;
    }

private:
    const string letterMap[10] = {
            "",    //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz"  //9
    };

    vector<string> res;

    void findCombination(const string &digits, int index, const string &s){

        if (index == digits.size()) {
            res.push_back(s);
            return;
        }

        char c = digits[index];
        string letters = letterMap[c - '0'];
        for (int i = 0; i < letters.size(); i++) {
            findCombination(digits, index + 1, s + letters[i]);
        }
    }

};