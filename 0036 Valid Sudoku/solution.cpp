// 也只能这么做了，遍历
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int hashtable[9][9];

        // check for every row
        memset(hashtable, 0, sizeof(hashtable));
        for(int i = 0 ; i < 9 ; i ++)
            for(int j = 0 ; j < 9 ; j ++)
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(hashtable[i][num] > 0)
                        return false;
                    hashtable[i][num]++;
                }

        // check for every col
        memset(hashtable, 0, sizeof(hashtable));
        for(int i = 0 ; i < 9 ; i ++)
            for(int j = 0 ; j < 9 ; j ++)
                if(board[j][i] != '.'){
                    int num = board[j][i] - '1';
                    if(hashtable[i][num] > 0)
                        return false;
                    hashtable[i][num]++;
                }

        // check for every block
        memset(hashtable, 0, sizeof(hashtable));
        for(int i = 0 ; i < 9 ; i ++){
            int br = i/3;
            int bc = i%3;
            for(int ii = 0 ; ii < 3 ; ii ++)
                for(int jj = 0 ; jj < 3 ; jj ++){
                    int r = br*3 + ii;
                    int c = bc*3 + jj;
                    if(board[r][c] != '.'){
                        int num = board[r][c] - '1';
                        if (hashtable[i][num] > 0)
                            return false;
                        hashtable[i][num]++;
                    }
                }
        }
        return true;
    }
};